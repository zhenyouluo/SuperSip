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

QString SipURI::toString()
{
  return "s: "+uriScheme+" u: "+uriUserinfo+" h: "+uriHost+uriPort+uriPath;
}
