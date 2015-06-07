#include "networkreader.h"
#include "networkreaderthread.h"

NetworkReaderThread::NetworkReaderThread(QObject *parent) : QThread(parent)
{
}

void NetworkReaderThread::run()
{
  // create network reader object
  networkreader = new NetworkReader();

  connect(this, &NetworkReaderThread::finished, networkreader, &QObject::deleteLater);

  // start event queue
  exec();
}

