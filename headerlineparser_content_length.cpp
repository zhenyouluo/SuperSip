#include <QDebug>

#include "headerlineparser_content_length.h"
#include "sipmessage.h"
#include "sipparser.h"

HeaderLineParser_Content_Length::HeaderLineParser_Content_Length()
{

}

int HeaderLineParser_Content_Length::parse(QString fieldvalues, SipMessage* sipmessage)
{
  qDebug() << "parse: " << fieldvalues;

  // there is no maximum value for content_length in the rfc, so we make sure
  // we can handle a very large value

  if (fieldvalues.trimmed().size() > 10)
  {
    return 1;
  }

  bool ok;
  qlonglong length = fieldvalues.trimmed().toLongLong(&ok);
  if (!ok || length > 4294967295LL) // (2^32)-1
  {
    return 2;
  }
  sipmessage->setContentLenght(length);
  return 0;
}

