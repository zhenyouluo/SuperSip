#ifndef SETPASSWORDCONTROLLER_H
#define SETPASSWORDCONTROLLER_H

#include "httprequesthandler.h"
#include "httpresponse.h"
#include "httprequest.h"


class SetPasswordController : public HttpRequestHandler
{
  Q_OBJECT
public:
  SetPasswordController(QObject* parent=0);
  void service(HttpRequest& request, HttpResponse& response);
};

#endif // SETPASSWORDCONTROLLER_H
