#include <QDebug>

#include "headerlineparser_max_forwards.h"
#include "sipmessage.h"
#include "sipparser.h"

HeaderLineParser_Max_Forwards::HeaderLineParser_Max_Forwards()
{

}

int HeaderLineParser_Max_Forwards::parse(QString fieldvalues, SipMessage* sipmessage)
{
  qDebug() << "parse: " << fieldvalues;

  if (fieldvalues.trimmed().size() > 3)
  {
    return 1;
  }

  bool ok;
  int forwards = fieldvalues.trimmed().toInt(&ok);
  if (!ok || forwards > 255 || forwards < 0)
  {
    return 2;
  }
  sipmessage->setMaxForwards(forwards);
  return 0;
}
