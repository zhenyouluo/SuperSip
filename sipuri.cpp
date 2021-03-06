#include "sipuri.h"

SipURI::SipURI(QObject *parent) : QObject(parent)
{
  setUriText("");
  setUriScheme("");
  setUriHost("");
  setUriPort("");
  setUriPath("");
  setUriQuery("");
  setUriFragment("");
}

QString SipURI::getUriHost()
{
  return uriHost;
}

QString SipURI::getUriText()
{
  return uriText;
}

void SipURI::setUriText(QString uritext)
{
  uriText = uritext;
}

void SipURI::setUriScheme(QString urischeme)
{
  uriScheme = urischeme;
}

void SipURI::setUriUserinfo(QString uriuserinfo)
{
  uriUserinfo = uriuserinfo;
}

void SipURI::setUriHost(QString urihost)
{
  uriHost = urihost;
}

void SipURI::setUriPort(QString uriport)
{
  uriPort = uriport;
}

void SipURI::setUriPath(QString uripath)
{
  uriPath = uripath;
}

void SipURI::setUriQuery(QString uriquery)
{
  uriQuery = uriquery;
}

void SipURI::setUriFragment(QString urifragment)
{
  uriFragment = urifragment;
}

void SipURI::addParams(QString paramname, QString paramvalue)
{
  uriParameters.insert(paramname, paramvalue);
}

QString SipURI::toString()
{
  return "s: "+uriScheme+" u: "+uriUserinfo+" h: "+uriHost+uriPort+uriPath;
}
