#include <QDebug>

#include "sipserver.h"
#include "networkreaderthread.h"
#include "appsettings.h"

SipServer::SipServer(QObject *parent) : QObject(parent)
{
  workerThread = new NetworkReaderThread(this);

  // check if sip domain is set
  if (AppSettings::sipSettings->contains("sipdomain"))
  {
    workerThread->start();
    qDebug() << "Sip server started";
  }
  waitForRestart = false;
  connect(workerThread, QThread::finished, this, SipServer::workerhasfinished);
}

void SipServer::restart()
{
  if (workerThread->isRunning())
  {
    waitForRestart = true;
    workerThread->exit(0);
  }
  else
  {
    workerThread->start();
    qDebug() << "Sip server started";
  }
}

void SipServer::workerhasfinished()
{
  if (waitForRestart)
  {
    workerThread->start();
    qDebug() << "Sip server restarted";
    waitForRestart = false;
  }
}
