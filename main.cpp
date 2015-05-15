#include <QCoreApplication>

#include "networkreaderthread.h"

int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  NetworkReaderThread* workerThread = new NetworkReaderThread();
  workerThread->start();

  return a.exec();
}







