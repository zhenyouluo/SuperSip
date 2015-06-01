#ifndef HEADERLINEPARSER_CONTACT_H
#define HEADERLINEPARSER_CONTACT_H

#include "headerlineparser.h"

class HeaderLineParser_Contact : public HeaderLineParser
{
public:
  HeaderLineParser_Contact();
  int parse(QString, SipMessage*);
};

#endif // HEADERLINEPARSER_CONTACT_H
