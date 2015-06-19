#include <QDebug>

#include "headerlineparser_from.h"
#include "sipuri.h"
#include "sipparser.h"

HeaderLineParser_From::HeaderLineParser_from()
{

}

HeaderLineParser_From::parse(QString fieldvalues, SipMessage* sipmessage)
{
  qDebug() << "parse from: " << fieldvalues;

  SipAdress* from_adress = new SipAdress(sipmessage);

  int result = SipParser::parseSipAdress(fieldvalues, from_adress);
  if (result != 0)
  {
    return result;
  }

  sipmessage->setFromAdress(from_adress);

  return 0;
}
