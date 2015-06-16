#include "sipvia.h"

SipVia::SipVia(QObject *parent) : QObject(parent)
{
  viaParams = QHash<QString, QString>();
}

void SipVia::setHost(QString host)
{
  viaHost = host;
}

void SipVia::setPort(int port)
{
  viaPort = port;
}

void SipVia::setProtocolName(QString name)
{
  viaProtocolName = name;
}

void SipVia::setProtocolVersion(QString version)
{
  viaProtocolVersion = version;
}

void SipVia::setTransport(QString transport)
{
  viaTransport = transport;
}

void SipVia::addParams(QString name, QString value)
{
  viaParams.insert(name, value);
}

QByteArray SipVia::toBytes()
{
  QByteArray txt("Via ");
  txt.append(viaProtocolName);
  txt.append("/").append(viaProtocolVersion);
  txt.append("/").append(viaTransport);
  txt.append(" ").append(viaHost);
  txt.append(":").append(QString::number(viaPort));
  QHashIterator<QString, QString> i(viaParams);
  while (i.hasNext())
  {
    i.next();
    txt.append(";").append(i.key());
    txt.append("=").append(i.value());
  }
  return txt.append("\n");
}
