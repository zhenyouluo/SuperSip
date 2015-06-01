#ifndef HEADERLINEPARSER_EXPIRES_H
#define HEADERLINEPARSER_EXPIRES_H

#include "headerlineparser.h"

class HeaderLineParser_Expires : public HeaderLineParser
{
public:
  HeaderLineParser_Expires();
  int parse(QString, SipMessage*);
};

#endif // HEADERLINEPARSER_EXPIRES_H
