#ifndef NETWORKREADERTHREAD_H
#define NETWORKREADERTHREAD_H

#include <QThread>
#include "networkreader.h"

class NetworkReaderThread : public QThread
{
  Q_OBJECT
public:
  explicit NetworkReaderThread(QObject *parent = 0);
  void run();

private:
   NetworkReader* networkreader;

signals:

};

#endif // NETWORKREADERTHREAD_H
