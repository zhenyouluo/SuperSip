#include "sipmessage.h"

SipMessage::SipMessage()
{
  fields = NULL;
}

bool SipMessage::addField(QString fieldname, QString fieldvalue)
{

}

void SipMessage::setIsRequest(bool isrequest)
{
  isRequest = isrequest;
}
