#include <QDebug>

#include "headerlineparser_contact.h"
#include "sipuri.h"
#include "sipparser.h"
#include "sipadress.h"

HeaderLineParser_Contact::HeaderLineParser_Contact()
{

}

int HeaderLineParser_Contact::parse(QString fieldvalues, SipMessage* sipmessage)
{
  qDebug() << "parse contact: " << fieldvalues;

  if (fieldvalues.trimmed() == "*")
  {
    sipmessage->setContactAll(true);
    return 0;
  }
  QString leftToParse = fieldvalues;
  QString parseNow;
  while (leftToParse.trimmed() != "")
  {
    int commapos = SipParser::findFirstLiteral(leftToParse, ',');
    if (commapos < 0)
    {
      parseNow = leftToParse;
      leftToParse = "";
    }
    else
    {
      parseNow = leftToParse.left(commapos);
      leftToParse = leftToParse.mid(commapos+1);
    }

    SipAdress* contact_adress = new SipAdress(sipmessage);

    int result = SipParser::parseSipAdress(parseNow, contact_adress);
    if (result != 0)
    {
      return result;
    }

    sipmessage->addContactAdress(contact_adress);
  }
  return 0;
}
