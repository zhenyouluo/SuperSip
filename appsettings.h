#ifndef APPSETTINGS_H
#define APPSETTINGS_H

#include <QObject>
#include <QSettings>

class AppSettings : public QObject
{
  Q_OBJECT
public:
  explicit AppSettings(QObject *parent = 0);
  static QSettings* httpSettings;
  static QSettings* sessionSettings;
  static QSettings* appSettings;
  static void initialize();
signals:

public slots:
};

#endif // APPSETTINGS_H
