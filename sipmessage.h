#ifndef SIPMESSAGE_H
#define SIPMESSAGE_H

#include <QObject>

class SipMessage : public QObject
{
  Q_OBJECT
public:
  explicit SipMessage();
  bool addField(QString, QString);
  void setIsRequest(bool);

private:
  QHash<QString, QStringList> fields;
  QByteArray body;
  bool isRequest;

signals:

public slots:
};

#endif // SIPMESSAGE_H
