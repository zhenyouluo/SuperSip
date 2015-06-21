#include <QHash>
#include <QString>

#include "sipmessage.h"
#include "sipuri.h"

SipMessage::SipMessage(QObject *parent) : QObject(parent)
{
  contactAll = false;
}

//
// To be called with the requestmessage as the parent of the responsemessage
// Deleting the requestmessage will automatically delete the responsemessage!
//
SipMessage::SipMessage(int returncode, QHostAddress sender, QObject *parent) : QObject(parent)
{
  isRequest = false;
  returnCode = returncode;
  senderIP = sender;
  contactAll = false;
}

//
// Request and response message will share some data
//
void SipMessage::copyFromRequest(SipMessage* requestmessage)
{
  // copy from request message to response message
  sipMethod = requestmessage->getSipMethod();
  sipCallId = requestmessage->getSipCallId();
  cseqNr = requestmessage->getCseqNr();
  sipContactAdresses = requestmessage->getContactAdresses();
  sipToAdress = requestmessage->getToAdress();
  sipFromAdress = requestmessage->getFromAdress();
  sipVias = requestmessage->getSipVias();
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

QList<SipVia*> SipMessage::getSipVias()
{
  return sipVias;
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

void SipMessage::setContactAll(bool contactall)
{
  contactAll = contactall;
}

void SipMessage::addContactAdress(SipAdress* adress)
{
  sipContactAdresses.append(adress);
}

void SipMessage::setFromAdress(SipAdress* adress)
{
  sipFromAdress = adress;
}

void SipMessage::setToAdress(SipAdress* adress)
{
  sipToAdress = adress;
}

SipAdress* SipMessage::getToAdress()
{
  return sipToAdress;
}

SipAdress* SipMessage::getFromAdress()
{
  return sipFromAdress;
}

QList<SipAdress*> SipMessage::getContactAdresses()
{
  return sipContactAdresses;
}

QByteArray SipMessage::toBytes()
{
  QByteArray txt("SIP/2.0");
  if (returnCode == 401)
  {
    txt.append(" 401 Unauthorized\n");
  }

  // add the via line(s)
  for (int i=0; i < sipVias.size(); i++)
  {
    txt.append(sipVias[i]->toBytes());
  }

  // add sender ip
  txt.append(";received=").append(senderIP.toString()).append("\n");

  txt.append("To: ").append(sipToAdress->getText()).append("\n");
  txt.append(" ;tag=2493k59kd\n"); //TODO

  txt.append("From: ").append(sipFromAdress->getText().append("\n"));

  txt.append("Call-ID: ").append(sipCallId).append("\n");

  txt.append("CSeq: ").append(QString::number(cseqNr));
  txt.append(" ").append(sipMethod).append("\n");

  if (returnCode == 401)
  {
    txt.append("WWW-Authenticate: Digest\n");
    txt.append(" realm=\"").append(wwwAuthRealm).append("\",\n");
    txt.append(" qop=\"auth,auth-int\",\n");
    txt.append(" nonce=\"").append(wwwAuthNonce).append("\",\n");
    txt.append(" opaque=\"").append(wwwAuthOpaque).append("\"\n");
  }
  txt.append("\n");
  qDebug() << txt;
  return txt;
}

