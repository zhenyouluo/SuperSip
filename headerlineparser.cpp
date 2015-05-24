#include <QDebug>
#include "headerlineparser.h"
#include "sipmessage.h"

HeaderLineParser::HeaderLineParser(QObject *parent) : QObject(parent)
{

}

int HeaderLineParser::parse(QString fieldvalues, SipMessage* sipmessage)
{
  qDebug() << "parse general: " << fieldvalues;
}
