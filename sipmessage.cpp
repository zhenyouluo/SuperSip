#include "sipmessage.h"
#include "sipuri.h"

SipMessage::SipMessage()
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
