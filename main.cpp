#include <QCoreApplication>
#include <QSettings>
#include "networkreaderthread.h"

#include "httplistener.h"
#include "requestmapper.h"
#include "httpsessionstore.h"
#include "appsettings.h"

int main(int argc, char *argv[])
{
  QCoreApplication app(argc, argv);
  NetworkReaderThread* workerThread = new NetworkReaderThread();
  workerThread->start();

  AppSettings::initialize();






  RequestMapper::sessionStore=new HttpSessionStore(AppSettings::sessionSettings,&app);


  // Start the HTTP server
  new HttpListener(AppSettings::httpSettings, new RequestMapper(&app), &app);
  return app.exec();
}







