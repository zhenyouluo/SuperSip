#ifndef REQUESTMAPPER_H
#define REQUESTMAPPER_H

#include "httprequesthandler.h"
#include "httpsessionstore.h"

class RequestMapper : public HttpRequestHandler
{
  Q_OBJECT

public:
  RequestMapper(QObject* parent=0);
  void service(HttpRequest& request, HttpResponse& response);
  static HttpSessionStore* sessionStore;

signals:
   void restartSipServer();
};

#endif // REQUESTMAPPER_H
