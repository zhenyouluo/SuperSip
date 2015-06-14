#include <QHash>
#include <QString>

#include "sipmessage.h"
#include "sipuri.h"

SipMessage::SipMessage(QObject *parent) : QObject(parent)
{

}

//
// To be called with the requestmessage as the parent of the responsemessage
// Deleting the requestmessage will automatically delete the responsemessage!
//
SipMessage::SipMessage(int returncode, QObject *parent) : QObject(parent)
{
  isRequest = false;
  returnCode = returncode;
}

//
// Request and response message will share some data
//
void SipMessage::copyFromRequest(SipMessage* requestmessage)
{
  // copy from request message to response message
  sipCallId = requestmessage->getSipCallId();
  cseqNr = requestmessage->getCseqNr();
  fromParameters = requestmessage->getFromParams();
  fromDisplayname = requestmessage->getSipFromDisplayname();
  toParameters = requestmessage->getToParams();
  toDisplayname = requestmessage->getSipToDisplayname();
  sipVias = requestmessage->getSipVias();
  fromURI = requestmessage->getSipFromUri();
  toURI = requestmessage->getSipToUri();
  // TODO copy require parameters

}

SipURI* SipMessage::getSipUri()
{
  return sipURI;
}

QString SipMessage::getSipCallId()
{
  return sipCallId;
}

qlonglong SipMessage::getCseqNr()
{
  return cseqNr;
}

SipURI* SipMessage::getSipToUri()
{
  return toURI;
}

QHash<QString, QString> SipMessage::getFromParams()
{
  return fromParameters;
}

QHash<QString, QString> SipMessage::getToParams()
{
  return toParameters;
}

QString SipMessage::getSipFromDisplayname()
{
  return fromDisplayname;
}

QString SipMessage::getSipToDisplayname()
{
  return toDisplayname;
}

QList<SipVia*> SipMessage::getSipVias()
{
  return sipVias;
}

SipURI* SipMessage::getSipFromUri()
{
  return fromURI;
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

void SipMessage::setSipCallId(QString callid)
{
  sipCallId = callid;
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

void SipMessage::setSipFromUri(SipURI* uri)
{
  fromURI = uri;
}

void SipMessage::setSipFromDisplayname(QString display)
{
  fromDisplayname = display;
}

void SipMessage::addFromParams(QString name, QString value)
{
  fromParameters.insert(name, value);
}

void SipMessage::setSipToUri(SipURI* uri)
{
  toURI = uri;
}

void SipMessage::setSipToDisplayname(QString display)
{
  toDisplayname = display;
}

void SipMessage::addToParams(QString name, QString value)
{
  toParameters.insert(name, value);
}

void SipMessage::setSipContactUri(SipURI* uri)
{
  contactURI = uri;
}

void SipMessage::setSipContactDisplayname(QString display)
{
  contactDisplayname = display;
}

void SipMessage::addContactParams(QString name, QString value)
{
  contactParameters.insert(name, value);
}

void SipMessage::setCseqNr(qlonglong seqnr)
{
  cseqNr = seqnr;
}

void SipMessage::setContentLenght(qlonglong length)
{
  contentLength = length;
}

void SipMessage::setExpires(qlonglong expires)
{
  expiresSecs = expires;
}

void SipMessage::setCseqMethod(QString cseqmethod)
{
  cseqMethod = cseqmethod;
}

void SipMessage::setMaxForwards(int forwards)
{
  maxForwards = forwards;
}

void SipMessage::setWWW_AuthenticateNonce(QByteArray nonce)
{
  wwwAuthNonce = nonce;
}

void SipMessage::setWWW_AuthenticateRealm(QString realm)
{
  wwwAuthRealm = realm;
}

void SipMessage::setWWW_Authenticate(QByteArray opaque)
{
  wwwAuthOpaque = opaque;
}

QByteArray SipMessage::toBytes()
{

}

