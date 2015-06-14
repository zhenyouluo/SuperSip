#ifndef NETWORKREADER_H
#define NETWORKREADER_H

#include <QObject>
#include <QUdpSocket>

#include "callinputter.h"

class NetworkReader : public QObject
{
  Q_OBJECT
public:
  explicit NetworkReader();
  void sendToClient(QHostAddress, quint16, QByteArray);

private:
  QUdpSocket* udpSocket;
  QHash<QString, CallInputter*> calls;
  int nrOfCallHandlingThreads;
  QThread** callHandlingThreads;
  int threadChoser;

signals:

public slots:
  void readPendingDatagrams();
};

#endif // NETWORKREADER_H
