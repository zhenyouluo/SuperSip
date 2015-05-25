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
