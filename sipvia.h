#ifndef SIPVIA_H
#define SIPVIA_H

#include <QObject>
#include <QHash>

class SipVia : public QObject
{
  Q_OBJECT
public:
  explicit SipVia(QObject *parent = 0);
  void setHost(QString);
  void setPort(int);
  void setProtocolName(QString);
  void setProtocolVersion(QString);
  void setTransport(QString);
  void addParams(QString, QString);
  QByteArray toBytes();

private:
  QString viaHost;
  int viaPort;
  QHash<QString, QString> viaParams;
  QString viaProtocolName;
  QString viaProtocolVersion;
  QString viaTransport;

signals:

public slots:
};

#endif // SIPVIA_H
