#ifndef SIPMESSAGE_H
#define SIPMESSAGE_H

#include <QObject>
#include <QHash>
#include <QString>
#include <QStringList>
#include <QHostAddress>

#include "sipuri.h"
#include "sipvia.h"
#include "sipadress.h"

class SipMessage : public QObject
{
  Q_OBJECT
public:
  explicit SipMessage(QObject *parent = 0);
  explicit SipMessage(int, QHostAddress, QObject *parent = 0);
  void copyFromRequest(SipMessage*);
  void setIsRequest(bool);
  SipURI* getSipUri();
  QString getSipCallId();
  qlonglong getCseqNr();
  QList<SipVia*> getSipVias();

  void setSipVersion(QString);
  void setStatusCode(QString);
  void setReasonPhrase(QString);
  void setSipMethod(QString);
  void setSipBody(QString);
  void setSipCallId(QString);
  void setSipURI(SipURI*);
  void setExpires(qlonglong);
  void setCseqNr(qlonglong);
  void setContentLenght(qlonglong);
  void setCseqMethod(QString);
  void setMaxForwards(int);
  void setWWW_AuthenticateNonce(QByteArray nonce);
  void setWWW_AuthenticateRealm(QString realm);
  void setWWW_Authenticate(QByteArray opaque);
  void setContactAll(bool);
  void addContactAdress(SipAdress*);
  void setToAdress(SipAdress*);
  void setFromAdress(SipAdress*);
  SipAdress* getToAdress();
  SipAdress* getFromAdress();
  QList<SipAdress*> getContactAdresses();
  QByteArray toBytes();

  QString toString();
  void addVia(SipVia*);

  bool getIsRequest();
  QString getSipMethod();

private:
  bool contactAll;
  QHostAddress senderIP;
  QByteArray body;
  bool isRequest;
  QString sipVersion;
  QString statusCode;
  QString reasonPhrase;
  QString sipMethod;
  SipURI *sipURI;
  QString sipBody;
  QList<SipVia*> sipVias;
  QList<SipAdress*> sipContactAdresses;
  QString sipCallId;
  qlonglong cseqNr;
  qlonglong expiresSecs;
  qlonglong contentLength;
  QString cseqMethod;
  int maxForwards;
  QByteArray wwwAuthNonce;
  QByteArray wwwAuthOpaque;
  QString wwwAuthRealm;
  int returnCode;
  SipAdress* sipToAdress;
  SipAdress* sipFromAdress;

signals:

public slots:
};

#endif // SIPMESSAGE_H
