#ifndef HEADERLINEPARSER_TO_H
#define HEADERLINEPARSER_TO_H

#include "headerlineparser.h"

class HeaderLineParser_To : public HeaderLineParser
{
public:
  HeaderLineParser_To();
  static int parse(QString, SipMessage*);
};

#endif // HEADERLINEPARSER_TO_H
