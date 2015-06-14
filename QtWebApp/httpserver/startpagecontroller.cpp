#include "startpagecontroller.h"
#include "httpresponse.h"
#include "httprequest.h"
#include "httpsession.h"
#include "requestmapper.h"
#include "appsettings.h"

StartpageController::StartpageController(QObject* parent):HttpRequestHandler(parent)
{
  // empty
}

void StartpageController::service(HttpRequest &request, HttpResponse &response)
{
  HttpSession session=RequestMapper::sessionStore->getSession(request,response,true);
  response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");

  QByteArray sipdomain = request.getParameter("sipdomain");
  if (!sipdomain.isEmpty())
  {
    AppSettings::sipSettings->setValue("sipdomain", sipdomain);
  }

  if (!AppSettings::sipSettings->contains("sipdomain"))
  {
    response.write("<html><body>");

    response.write("<form method='POST' action='/'>");

    response.write("Please enter sip domain:<br>");
    response.write("Domain: <input type='text' name='sipdomain'><br>");
    response.write("<input type='submit'>");
    response.write("</form");
    response.write("</body></html>",true);
  }
  else
  {
    response.write("blabla");
  }
}
