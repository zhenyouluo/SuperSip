#include <QtDebug>
#include "callhandler.h"
#include "sipmessage.h"
#include "sipparser.h"
#include "sipdefinitions.h"

CallHandler::CallHandler(QObject *parent) : QObject(parent)
{

}

void CallHandler::processCallData(QByteArray callData)
{
  //qDebug() << callData;
  SipMessage* sipmessage = new SipMessage(this);
  if (SipParser::parse(callData, sipmessage) == 0)
  {
    qDebug() << callData;
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
