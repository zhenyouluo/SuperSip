#include <QStringList>
#include <QString>
#include <QSet>
#include <QDebug>
#include "sipparser.h"
#include "sipmessage.h"
#include "sipdefinitions.h"

SipParser::SipParser(QObject *parent) : QObject(parent)
{

}

QString SipParser::getCallId(QByteArray sipheader)
{
  QString message = QString::fromUtf8(sipheader.data());
  QStringList messagelines = message.split("\n");
  for (int i = 0; i < messagelines.size(); ++i)
  {
    if (messagelines[i].startsWith("Call-ID", Qt::CaseInsensitive))
    {
      QStringList lineparts = messagelines[i].split(":");
      if (lineparts.size() > 1)
      {
        return lineparts[1].trimmed();
      }
    }
  }
  return NULL;
}

SipMessage* SipParser::parse(QByteArray sipheader)
{
  SipMessage* sipmessage = new SipMessage();
  QString message = QString::fromUtf8(sipheader.data());
  QStringList messagelines = message.split("\n");

  // discard messages that do not at least contain a startline and a CRLF line between header and body
  if (messagelines.size() < 2)
  {
    return NULL;
  }

  QString startline = messagelines[0];

  // responses start with SIP
  if (startline.startsWith("SIP", Qt::CaseInsensitive))
  {
    // Response message
    sipmessage->setIsRequest(false);

    // Parse response startline, must be: SIP-Version SP Status-Code SP Reason-Phrase
    QStringList startlineparts = startline.split(" ");

    // allow to omit Reason-Phrase?
    if (startlineparts.size() < 2)
    {
      return NULL;
    }
    sipmessage->setSipVersion(startlineparts[0]);
    sipmessage->setStatusCode(startlineparts[1]);
    if (startlineparts.size() > 2)
    {
      sipmessage->setReasonPhrase(startlineparts[2].trimmed());
    }
  }
  else
  {
    // Request message
    sipmessage->setIsRequest(true);

    // Parse response startline, must be: Method SP Request-URI SP SIP-Version
    QStringList startlineparts = startline.split(" ");

    // all parts available?
    if (startlineparts.size() < 3)
    {
      return NULL;
    }

    // check if sip method can be recognized
    if (!SipDefinitions::sipMethods.contains(startlineparts[0]))
    {
      return NULL;
    }
    qDebug() << startlineparts[0];
    sipmessage->setSipVersion(startlineparts[2]);

  }



  for (int i = 0; i < messagelines.size(); ++i)
  {
    int colonpos = messagelines[i].indexOf(':');
    if (colonpos > 0)
    {
      // QString fieldname = messagelines[i].left(colonpos).trimmed();
      // QString values = messagelines[i].midRef(colonpos+1).trimmed();
    }
    if (messagelines[i].startsWith("Call-ID", Qt::CaseInsensitive))
    {
      QStringList lineparts = messagelines[i].split(":");
      if (lineparts.size() > 1)
      {
       //return lineparts[1].trimmed();
      }
    }
  }
  return sipmessage;
}

