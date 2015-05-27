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
  bool addField(QString, QString);
  void setIsRequest(bool);
  void setSipVersion(QString);
  void setStatusCode(QString);
  void setReasonPhrase(QString);
  void setSipMethod(QString);
  void setSipBody(QString);
  void setSipCallId(QString);
  void setSipURI(SipURI*);
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
  QString sipBody;
  QList<SipVia*> sipVias;
  QString sipCallId;

signals:

public slots:
};

#endif // SIPMESSAGE_H
