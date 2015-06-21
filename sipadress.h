#ifndef SIPADRESS_H
#define SIPADRESS_H

#include <QObject>
#include <QHash>

#include "sipuri.h"

class SipAdress : public QObject
{
  Q_OBJECT

private:
  QString displayName;
  SipURI* adressURI;
  QHash<QString, QString> adressParameters;
  QString adressText;

public:
  explicit SipAdress(QObject *parent = 0);
  void setDisplayname(QString);
  SipURI* getUri();
  void addParams(QString, QString);
  void setText(QString);
  QString getText();

signals:

public slots:
};

#endif // SIPADRESS_H
