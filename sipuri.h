#ifndef SIPURI_H
#define SIPURI_H

#include <QObject>

class SipURI : public QObject
{
  Q_OBJECT
public:
  explicit SipURI(QObject *parent = 0);

private:
  QString uriText;
  QString uriScheme;
  QString uriUserinfo;
  QString uriHost;
  QString uriPort;
  QString uriPath;
  QString uriQuery;
  QString uriFragment;

public:
  void setUriText(QString);
  void setUriScheme(QString);
  void setUriUserinfo(QString);
  void setUriHost(QString);
  void setUriPort(QString);
  void setUriPath(QString);
  void setUriQuery(QString);
  void setUriFragment(QString);
  QString toString();

signals:

public slots:
};

#endif // SIPURI_H
