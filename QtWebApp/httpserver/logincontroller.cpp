#include <QCryptographicHash>
#include <QByteArray>
#include <QTime>

#include "logincontroller.h"
#include "appsettings.h"
#include "httpsession.h"
#include "requestmapper.h"

LoginController::LoginController(QObject* parent):HttpRequestHandler(parent)
{
  // empty
}

void LoginController::service(HttpRequest &request, HttpResponse &response)
{
  HttpSession session = RequestMapper::sessionStore->getSession(request, response, true);
  QByteArray pw = request.getParameter("pw");
  response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");
  if (!pw.isEmpty())
  {
    // check password

    QByteArray salt = QByteArray::fromBase64(AppSettings::appSettings->value("passwordsalt").toByteArray());
    QByteArray ba(pw);
    ba.append(salt);
    QByteArray hash = QCryptographicHash::hash(ba, QCryptographicHash::Sha3_512);
    QByteArray saved_hash = QByteArray::fromBase64(AppSettings::appSettings->value("passwordhash").toByteArray());

    if (hash == saved_hash)
    {
      session.set("logintime",QTime::currentTime());
      if (session.contains("redirected"))
      {
        response.redirect(session.get("redirected").toByteArray());
        session.remove("redirected");
      }
      else
      {
        response.redirect("/");
      }
      return;
    }
  }
  else
  {
    // display login page
    response.write("<html><body>");
    if (!pw.isEmpty())
    {
      response.write("Please try again!<br><br>");
    }

    response.write("<form method='POST' action='/login'>");

    response.write("Please log in:<br>");
    response.write("Password: <input type='password' name='pw'><br>");
    response.write("<input type='submit'>");
    response.write("</form");
    response.write("</body></html>",true);
  }
}

