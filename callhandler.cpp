#include <QtDebug>
#include "callhandler.h"
#include "sipmessage.h"
#include "sipparser.h"

CallHandler::CallHandler(QObject *parent) : QObject(parent)
{

}

void CallHandler::processCallData(QByteArray callData)
{
  //qDebug() << callData;
  SipMessage* sipmessage = SipParser::parse(callData);
}
