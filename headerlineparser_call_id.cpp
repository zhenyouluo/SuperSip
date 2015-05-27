#include <QDebug>

#include "headerlineparser_call_id.h"
#include "sipmessage.h"

HeaderLineParser_Call_Id::HeaderLineParser_Call_Id()
{

}

int HeaderLineParser_Call_Id::parse(QString fieldvalues, SipMessage* sipmessage)
{
  qDebug() << "parse: " << fieldvalues;

  if (fieldvalues.trimmed().size() < 1)
  {
    return 1;
  }

  sipmessage->setSipCallId(fieldvalues.trimmed());
  return 0;
}
