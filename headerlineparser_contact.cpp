#include <QDebug>

#include "headerlineparser_contact.h"
#include "sipuri.h"
#include "sipparser.h"

HeaderLineParser_Contact::HeaderLineParser_Contact()
{

}

HeaderLineParser_Contact::parse(QString fieldvalues, SipMessage* sipmessage)
{
  qDebug() << "parse from: " << fieldvalues;

  int laquotpos = SipParser::findFirstLiteral(fieldvalues, '<');
  int semipos = SipParser::findFirstLiteral(fieldvalues, ';');
  qDebug() << laquotpos << semipos;

  QString display_name;

  if (fieldvalues.trimmed().size() < 1)
  {
    return 1;
  }

  int startof_uri_pos = 0;
  int endof_uri_pos;
  if (semipos < 0)
  {
    endof_uri_pos = fieldvalues.size();
  }
  else
  {
    endof_uri_pos = semipos;
  }
  if (laquotpos < 0)
  {
    // only uri
    display_name = "";
  }
  else
  {
    int raquotpos = SipParser::findFirstLiteral(fieldvalues, '>');
    if (raquotpos < laquotpos)
    {
      return 2;
    }
    display_name = fieldvalues.left(laquotpos).trimmed();
    // check if starts with double quotes
    if (display_name.left(1) == "\"")
    {
      if (display_name.right(1) != "\"")
      {
        return 3;
      }
      else
      {
        display_name = display_name.mid(1, display_name.size()-2);
      }
    }
    startof_uri_pos = laquotpos+1;
    endof_uri_pos = raquotpos;
  }
  QString uritext = fieldvalues.mid(startof_uri_pos, endof_uri_pos-startof_uri_pos);
  SipURI* uri = new SipURI(sipmessage);
  if (SipParser::parseSipURI(uritext, uri) != 0)
  {
    return 4;
  }
  // qDebug() << "from uri" << uritext;

  while (semipos > 0)
  {
    int start = semipos+1;

    // find next semicolon
    semipos = SipParser::findFirstLiteral(fieldvalues.mid(start), ';');
    int end;
    if (semipos > 0)
    {
      end = semipos;
    }
    else
    {
      end = fieldvalues.size();
    }
    QString paramstr = fieldvalues.mid(start, end-start);
    int equalpos = paramstr.indexOf('=');
    if (equalpos > 0)
    {
      QString paramname = paramstr.left(equalpos).trimmed().toLower();
      QString paramvalue = paramstr.mid(equalpos+1).trimmed();
      sipmessage->addContactParams(paramname, paramvalue);
    }
  }

  sipmessage->setSipContactDisplayname(display_name);
  sipmessage->setSipContactUri(uri);
  return 0;
}
