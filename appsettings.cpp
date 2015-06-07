#include <QSettings>

#include "appsettings.h"

QSettings* AppSettings::httpSettings = new QSettings(QSettings::SystemScope, "tools4all", "SuperSip");
QSettings* AppSettings::sessionSettings = new QSettings(QSettings::SystemScope, "tools4all", "SuperSip");
QSettings* AppSettings::appSettings = new QSettings(QSettings::SystemScope, "tools4all", "SuperSip");
QSettings* AppSettings::sipSettings = new QSettings(QSettings::SystemScope, "tools4all", "SuperSip");

AppSettings::AppSettings(QObject *parent) : QObject(parent)
{

}

void AppSettings::initialize()
{
  AppSettings::httpSettings->setValue("minThreads", 1);
  AppSettings::httpSettings->setValue("maxThreads", 100);
  AppSettings::httpSettings->setValue("cleanupInterval", 1000);
  AppSettings::httpSettings->setValue("readTimeout", 60000);
  AppSettings::httpSettings->setValue("maxRequestSize", 16000);
  AppSettings::httpSettings->setValue("maxMultiPartSize", 10000000);

  AppSettings::sessionSettings->setValue("expirationTime", 3600000);
  AppSettings::sessionSettings->setValue("cookieName", "sessionid");
  AppSettings::sessionSettings->setValue("cookieDomain", "");
  AppSettings::sessionSettings->setValue("cookiePath", "/");
  AppSettings::sessionSettings->setValue("cookieComment", "Identifies the user");
}
