#include "headerlineparser_from.h"

HeaderLineParser_From::HeaderLineParser_from()
{

}

HeaderLineParser_From::::parse(QString fieldvalues, SipMessage* sipmessage)
{
  qDebug() << "parse: " << fieldvalues;

  int laquotpos = SipParser::findFirstLiteral(fieldvalues, "<");
  int semipos = SipParser::findFirstLiteral(fieldvalues, ";");
  if (semipos < 0)
  {
    int endof_uri_pos = fieldvalues.size();
  }
  else
  {
    int endof_uri_pos = semipos;
  }
  if (laquotpos < 0)
  {
    // only uri
    display_name = "";
  }
  else
  {
    displayname = fieldvalues.left(laquotpos);
    // check if starts with double quotes
  }
  if (fieldvalues.trimmed().size() < 1)
  {
    return 1;
  }

  sipmessage->setSipCallId(fieldvalues.trimmed());
  return 0;
}
