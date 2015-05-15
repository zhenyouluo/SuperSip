#ifndef NETWORKREADERTHREAD_H
#define NETWORKREADERTHREAD_H

#include <QThread>
#include "networkreader.h"

class NetworkReaderThread : public QThread
{
  Q_OBJECT
public:
  void run();

private:
   NetworkReader* networkreader;

signals:

};

#endif // NETWORKREADERTHREAD_H
