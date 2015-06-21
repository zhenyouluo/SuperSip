#include "sipadress.h"

SipAdress::SipAdress(QObject *parent) : QObject(parent)
{
  adressURI = new SipURI(this);
}

void SipAdress::addParams(QString paramname, QString paramvalue)
{
  adressParameters.insert(paramname, paramvalue);
}

void SipAdress::setDisplayname(QString name)
{
  displayName = name;
}

SipURI* SipAdress::getUri()
{
  return adressURI;
}

void SipAdress::setText(QString text)
{
  adressText = text;
}

QString SipAdress::getText()
{
  return adressText;
}
