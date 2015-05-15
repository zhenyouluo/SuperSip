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


private:
  QUdpSocket* udpSocket;
  QHash<QString, CallInputter*> calls;

signals:

public slots:
  void readPendingDatagrams();
};

#endif // NETWORKREADER_H
