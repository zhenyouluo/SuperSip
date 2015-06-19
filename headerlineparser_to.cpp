#include <QDebug>
#include <QString>
#include "headerlineparser_to.h"
#include "sipmessage.h"
#include "sipuri.h"
#include "sipparser.h"

HeaderLineParser_To::HeaderLineParser_To()
{
  //parse("test", NULL);
}

int HeaderLineParser_To::parse(QString fieldvalues, SipMessage* sipmessage)
{
  qDebug() << "parse to: " << fieldvalues;

  SipAdress* to_adress = new SipAdress(sipmessage);

  int result = SipParser::parseSipAdress(fieldvalues, to_adress);
  if (result != 0)
  {
    return result;
  }

  sipmessage->setToAdress(to_adress);

  return 0;
}
