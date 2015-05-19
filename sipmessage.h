#ifndef SIPMESSAGE_H
#define SIPMESSAGE_H

#include <QObject>
#include <QHash>
#include <QString>
#include <QStringList>

#include "sipuri.h"

class SipMessage : public QObject
{
  Q_OBJECT
public:
  explicit SipMessage();
  bool addField(QString, QString);
  void setIsRequest(bool);
  void setSipVersion(QString);
  void setStatusCode(QString);
  void setReasonPhrase(QString);
  void setSipMethod(QString);
  void setSipURI(SipURI*);

private:
  QHash<QString, QStringList> fields;
  QByteArray body;
  bool isRequest;
  QString sipVersion;
  QString statusCode;
  QString reasonPhrase;
  QString sipMethod;
  SipURI *sipURI;

signals:

public slots:
};

#endif // SIPMESSAGE_H
