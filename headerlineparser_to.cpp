#include <QDebug>
#include <QString>
#include "headerlineparser_to.h"
#include "sipmessage.h"

HeaderLineParser_To::HeaderLineParser_To()
{

}

int HeaderLineParser_To::parse(QString fieldvalues, SipMessage* sipmessage)
{
  qDebug() << "parse: " << fieldvalues;
}
