#include "sipmessage.h"
#include "sipuri.h"

SipMessage::SipMessage(QObject *parent) : QObject(parent)
{

}

bool SipMessage::addField(QString fieldname, QString fieldvalue)
{

}

void SipMessage::setIsRequest(bool isrequest)
{
  isRequest = isrequest;
}

void SipMessage::setSipVersion(QString sipversion)
{
  sipVersion = sipversion;
}

void SipMessage::setSipBody(QString sipbody)
{
  sipBody = sipbody;
}

void SipMessage::setStatusCode(QString statuscode)
{
  statusCode = statuscode;
}

void SipMessage::setReasonPhrase(QString reasonphrase)
{
  reasonPhrase = reasonphrase;
}

void SipMessage::setSipMethod(QString sipmethod)
{
  sipMethod = sipmethod;
}

void SipMessage::setSipURI(SipURI* sipuri)
{
  sipURI = sipuri;
}

bool SipMessage::getIsRequest()
{
  return isRequest;
}

QString SipMessage::getSipMethod()
{
  return sipMethod;
}

QString SipMessage::toString()
{
  return sipVersion+statusCode+"uri: "+sipURI->toString();
}

void SipMessage::addVia(SipVia* sipvia)
{
  sipVias.append(sipvia);
}
