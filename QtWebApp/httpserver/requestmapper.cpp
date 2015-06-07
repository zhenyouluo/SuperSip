#include "requestmapper.h"
#include "httpsessionstore.h"
#include "startpagecontroller.h"
#include "logincontroller.h"
#include "setpasswordcontroller.h"
#include "appsettings.h"

HttpSessionStore* RequestMapper::sessionStore=0;

RequestMapper::RequestMapper(QObject* parent)
    : HttpRequestHandler(parent) {
    // empty
}

void RequestMapper::service(HttpRequest& request, HttpResponse& response)
{
  QByteArray path = request.getPath();
  HttpSession session=RequestMapper::sessionStore->getSession(request, response, true);
  if (!AppSettings::appSettings->contains("passwordhash"))
  {
    if (path != "/setpassword")
    {
      response.redirect("/setpassword");
      return;
    }
  }
  else
  {
    if (!session.contains("logintime") && path != "/login")
    {
      qDebug("RequestMapper: redirect to login page");
      session.set("redirected", path);
      response.redirect("/login");
      return;
    }
  }
  qDebug("RequestMapper: path=%s",path.data());

//  if (path == "/restartsipserver")
//  {
//    emit restartSipServer();
//    response.redirect("/");
//    return;
//  }
  if (path == "/")
  {
    StartpageController().service(request, response);
  }
  else if (path == "/setpassword")
  {
    SetPasswordController().service(request, response);
  }
  else if (path == "/login")
  {
    LoginController().service(request, response);
  }
  else
  {
    response.setStatus(404,"Not found");
    response.write("The URL is wrong, no such document.",true);
  }

  qDebug("RequestMapper: finished request");
}

