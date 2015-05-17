#ifndef SIPMESSAGE_H
#define SIPMESSAGE_H

#include <QObject>
#include <QHash>
#include <QString>
#include <QStringList>

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

private:
  QHash<QString, QStringList> fields;
  QByteArray body;
  bool isRequest;
  QString sipVersion;
  QString statusCode;
  QString reasonPhrase;

signals:

public slots:
};

#endif // SIPMESSAGE_H
