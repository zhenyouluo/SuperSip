#include "startpagecontroller.h"
#include "httpresponse.h"
#include "httprequest.h"
#include "httpsession.h"
#include "requestmapper.h"

StartpageController::StartpageController(QObject* parent):HttpRequestHandler(parent)
{
  // empty
}

void StartpageController::service(HttpRequest &request, HttpResponse &response)
{
  HttpSession session=RequestMapper::sessionStore->getSession(request,response,true);

  if (session.contains("authenticated"))
  {
  }
}
