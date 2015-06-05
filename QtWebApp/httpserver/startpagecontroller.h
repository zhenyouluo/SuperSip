#ifndef STARTPAGECONTROLLER_H
#define STARTPAGECONTROLLER_H

#include "httprequesthandler.h"
#include "httpresponse.h"
#include "httprequest.h"

class StartpageController: public HttpRequestHandler
{
  Q_OBJECT
public:
  StartpageController(QObject* parent=0);
  void service(HttpRequest& request, HttpResponse& response);
};

#endif // STARTPAGECONTROLLER_H
