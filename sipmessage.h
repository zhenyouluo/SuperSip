#ifndef SIPMESSAGE_H
#define SIPMESSAGE_H

#include <QObject>
#include <QHash>
#include <QString>
#include <QStringList>

#include "sipuri.h"
#include "sipvia.h"

class SipMessage : public QObject
{
  Q_OBJECT
public:
  explicit SipMessage(QObject *parent = 0);
  explicit SipMessage(int, QObject *parent = 0);
  void copyFromRequest(SipMessage*);
  void setIsRequest(bool);
  SipURI* getSipUri();
  QString getSipCallId();
  qlonglong getCseqNr();
  QHash<QString, QString> getFromParams();
  QHash<QString, QString> getToParams();
  QString getSipFromDisplayname();
  QString getSipToDisplayname();
  QList<SipVia*> getSipVias();
  SipURI* getSipToUri();
  SipURI* getSipFromUri();

  void setSipVersion(QString);
  void setStatusCode(QString);
  void setReasonPhrase(QString);
  void setSipMethod(QString);
  void setSipBody(QString);
  void setSipCallId(QString);
  void setSipURI(SipURI*);
  void setSipFromUri(SipURI*);
  void setSipFromDisplayname(QString);
  void addFromParams(QString, QString);
  void setSipToUri(SipURI*);
  void setSipToDisplayname(QString);
  void addToParams(QString, QString);
  void setSipContactUri(SipURI*);
  void setSipContactDisplayname(QString);
  void addContactParams(QString, QString);
  void setExpires(qlonglong);
  void setCseqNr(qlonglong);
  void setContentLenght(qlonglong);
  void setCseqMethod(QString);
  void setMaxForwards(int);
  void setWWW_AuthenticateNonce(QByteArray nonce);
  void setWWW_AuthenticateRealm(QString realm);
  void setWWW_Authenticate(QByteArray opaque);
  QByteArray toBytes();

  QString toString();
  void addVia(SipVia*);

  bool getIsRequest();
  QString getSipMethod();

private:
  QHash<QString, QStringList> fields;
  QByteArray body;
  bool isRequest;
  QString sipVersion;
  QString statusCode;
  QString reasonPhrase;
  QString sipMethod;
  SipURI *sipURI;
  SipURI *fromURI;
  SipURI *toURI;
  QHash<QString, QString> fromParameters;
  QString fromDisplayname;
  SipURI *contactURI;
  QHash<QString, QString> contactParameters;
  QString contactDisplayname;
  QHash<QString, QString> toParameters;
  QString toDisplayname;
  QString sipBody;
  QList<SipVia*> sipVias;
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

signals:

public slots:
};

#endif // SIPMESSAGE_H
