#include <QDebug>

#include "headerlineparser_expires.h"
#include "sipmessage.h"
#include "sipparser.h"

HeaderLineParser_Expires::HeaderLineParser_Expires()
{

}

int HeaderLineParser_Expires::parse(QString fieldvalues, SipMessage* sipmessage)
{
  qDebug() << "parse: " << fieldvalues;

  if (fieldvalues.trimmed().size() > 10)
  {
    return 1;
  }

  bool ok;
  qlonglong expires = fieldvalues.trimmed().toLongLong(&ok);
  if (!ok || expires > 4294967295LL) // (2^32)-1
  {
    return 2;
  }
  sipmessage->setExpires(expires);
  return 0;
}
