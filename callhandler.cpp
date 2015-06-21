#include <QtDebug>
#include <QDateTime>
#include <QCryptographicHash>

#include "callhandler.h"
#include "sipmessage.h"
#include "sipparser.h"
#include "sipdefinitions.h"
#include "appsettings.h"

CallHandler::CallHandler(QObject *parent) : QObject(parent)
{
  // Create private key
  qsrand(QTime::currentTime().msec());
  privateKey = "";
  for (int i = 0; i < 100; i++)
  {
    char c = rand() % 256;
    privateKey.append(c);
  }

}

void CallHandler::processCallData(QByteArray callData, QHostAddress sender)
{
  qDebug() << callData;
  SipMessage* sipmessage = new SipMessage(this);
  if (SipParser::parse(callData, sipmessage) == 0)
  {
    //qDebug() << callData;
    if (sipmessage->getIsRequest())
    {
      switch(SipDefinitions::sipMethods.indexOf(sipmessage->getSipMethod()))
      {
        case 0: // INVITE
        {
          break;
        }
        case 1: // REGISTER
        {
          // check domain
          SipURI* sipuri = sipmessage->getSipUri();
          if (!sipuri)
          {
            // TODO

            return;
          }
          QString domain = sipuri->getUriHost().toLower();
          if (domain != QString(AppSettings::sipSettings->value("sipdomain").toByteArray()).toLower())
          {
            // TODO
            qDebug() << domain <<" Domain NOK " << QString(AppSettings::sipSettings->value("sipdomain").toByteArray()).toLower();
            return;
          }
          qDebug() << "Domain OK";

          // TODO check required extensions 8.2.2

          // Authentication

    //      if (message contains auth)
    //      {
    //        // Check the response
    //      }
    //      else
    //      {
              //
              // Send challenge
              //

              SipMessage responseMessage(401, sender, sipmessage);
              responseMessage.copyFromRequest(sipmessage);

              qint64 timestamp = QDateTime::currentMSecsSinceEpoch();
              QByteArray ts = QByteArray::number(timestamp);
              QByteArray tohash = ts.append(":").append(privateKey);
              QByteArray hash = QCryptographicHash::hash(tohash, QCryptographicHash::Md5);
              QByteArray nonce = ts.append(":").append(hash).toBase64();

              // generate opaque field
              opaque = "";
              for (int i = 0; i < 20; i++)
              {
                char c = rand() % 256;
                opaque.append(c);
              }
              responseMessage.setWWW_AuthenticateNonce(nonce);
              responseMessage.setWWW_AuthenticateRealm(domain);
              responseMessage.setWWW_Authenticate(opaque.toBase64());
              emit sendResponse(responseMessage.toBytes());
    //      }

          qDebug() << "rge";
          break;
        }
      }
    }
    else
    {

    }
  }
}
