#include <QDebug>

#include "headerlineparser_cseq.h"
#include "sipmessage.h"
#include "sipparser.h"
HeaderLineParser_Cseq::HeaderLineParser_Cseq()
{

}

int HeaderLineParser_Cseq::parse(QString fieldvalues, SipMessage* sipmessage)
{
  qDebug() << "parse: " << fieldvalues;

  int lwspos = SipParser::findLWS(fieldvalues);
  if (lwspos < 0)
  {
    return 1;
  }

  QString cseqnumberstr = fieldvalues.left(lwspos).trimmed();
  QString cseqmethod = fieldvalues.mid(lwspos+1).trimmed();

  if (cseqnumberstr.size() > 10)
  {
    return 2;
  }

  bool ok;
  qlonglong cseqnumber = cseqnumberstr.toLongLong(&ok);
  if (!ok || cseqnumber > 4294967295LL) // (2^32)-1
  {
    return 3;
  }
  sipmessage->setCseqNr(cseqnumber);
  sipmessage->setCseqMethod(cseqmethod);
  return 0;
}
