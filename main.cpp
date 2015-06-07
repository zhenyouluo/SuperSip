#include <QCoreApplication>
#include <QSettings>
#include <QDebug>

#include "sipserver.h"
#include "httplistener.h"
#include "requestmapper.h"
#include "httpsessionstore.h"
#include "appsettings.h"

int main(int argc, char *argv[])
{
  QCoreApplication app(argc, argv);

  AppSettings::initialize();

  bool portfromcommandline = false;
  int port;
  if (argc > 1)
  {
    // only webserver port can be set on commandline
    QString portstr(argv[1]);
    port = portstr.toInt(&portfromcommandline);
    if (!portfromcommandline)
    {
      qWarning() << "Could not parse " << portstr << " as webserver port.";
    }
  }
  if (!portfromcommandline)
  {
    port = AppSettings::httpSettings->value("webserverport", 8080).toInt();
  }

  if (!AppSettings::sipSettings->contains("sipdomain"))
  {
    qWarning() << "Sip server domain not set. Point your webbrowser to this server at port " << port << " and add the necessary settings.";
  }

  SipServer* sipserver = new SipServer(&app);

  RequestMapper* requestmapper = new RequestMapper(&app);

  // allow restart of sipserver from web interface
  QObject::connect(requestmapper, RequestMapper::restartSipServer, sipserver, SipServer::restart);

  RequestMapper::sessionStore=new HttpSessionStore(AppSettings::sessionSettings,&app);


  // Start the HTTP server
  new HttpListener(AppSettings::httpSettings, port, requestmapper, &app);
  return app.exec();
}







