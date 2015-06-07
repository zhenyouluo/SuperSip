#ifndef SIPSERVER_H
#define SIPSERVER_H

#include <QObject>

#include "networkreaderthread.h"

class SipServer : public QObject
{
  Q_OBJECT

private:
  NetworkReaderThread* workerThread;
  bool waitForRestart;

public:
  explicit SipServer(QObject *parent = 0);

signals:

public slots:
  void restart();
  void workerhasfinished();
};

#endif // SIPSERVER_H
