#ifndef SIPURI_H
#define SIPURI_H

#include <QObject>
#include <QHash>

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
  QHash<QString, QString> uriParameters;

public:
  QString getUriHost();
  QString getUriText();
  void setUriText(QString);
  void setUriScheme(QString);
  void setUriUserinfo(QString);
  void setUriHost(QString);
  void setUriPort(QString);
  void setUriPath(QString);
  void setUriQuery(QString);
  void setUriFragment(QString);
  void addParams(QString, QString);
  QString toString();

signals:

public slots:
};

#endif // SIPURI_H
