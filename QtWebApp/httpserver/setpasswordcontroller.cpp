#include <QTime>
#include <QCryptographicHash>
#include <QByteArray>

#include "setpasswordcontroller.h"
#include "appsettings.h"

SetPasswordController::SetPasswordController(QObject* parent):HttpRequestHandler(parent)
{
  // empty
}

void SetPasswordController::service(HttpRequest &request, HttpResponse &response)
{
  QByteArray pw1 = request.getParameter("pw1");
  QByteArray pw2 = request.getParameter("pw2");

  if (!pw1.isEmpty() && pw1 == pw2)
  {
    // create hash

    QByteArray ba(pw1);
    qsrand(QTime::currentTime().msec());

    // Create salt
    QByteArray salt("");
    for (int i = 1; i < 100; i++)
    {
      char c = rand() % 256;
      salt.append(c);
    }
    AppSettings::appSettings->setValue("passwordsalt", salt.toBase64());

    ba.append(salt);
    QByteArray hash = QCryptographicHash::hash(ba, QCryptographicHash::Sha3_512);
    AppSettings::appSettings->setValue("passwordhash", hash.toBase64());

    response.redirect("/");
    return;
  }

  response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");
  response.write(
  "<html>"
  "<body>"
  "<form method='POST' action='/setpassword'>");
  if (pw1 != pw2)
  {
    response.write("Passwords do not match, Please try again!<br><br>");
  }
  response.write(
  "Please enter password:<br>"
  "Password:  <input type='password' name='pw1'><br>"
  "Password again: <input type='password' name='pw2'><br>"
  "<input type='submit'>"
  "</form"
  "</body>"
  "</html>"
                 );
  response.write("",true);
}
