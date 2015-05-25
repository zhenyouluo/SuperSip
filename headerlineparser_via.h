#ifndef HEADERLINEPARSER_VIA_H
#define HEADERLINEPARSER_VIA_H

#include "headerlineparser.h"

class HeaderLineParser_Via : public HeaderLineParser
{
public:
  HeaderLineParser_Via();
  int parse(QString, SipMessage*);
};

#endif // HEADERLINEPARSER_VIA_H
