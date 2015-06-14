#ifndef CALLINPUTTER_H
#define CALLINPUTTER_H

#include <QObject>
#include <QHostAddress>

class NetworkReader;

class CallInputter : public QObject
{
  Q_OBJECT

private:
  NetworkReader* networkreader;
  QHostAddress sender;
  quint16 senderPort;

public:
  explicit CallInputter(QObject *parent = 0);
  void forwardCallData(QByteArray);
  void setClientIp(QHostAddress, quint16);

signals:
  void sendCallData(QByteArray);

public slots:
  void responseToClient(QByteArray);
};

#endif // CALLINPUTTER_H
