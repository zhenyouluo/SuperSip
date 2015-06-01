#ifndef HEADERLINEPARSER_MAX_FORWARDS_H
#define HEADERLINEPARSER_MAX_FORWARDS_H

#include "headerlineparser.h"

class HeaderLineParser_Max_Forwards : public HeaderLineParser
{
public:
  HeaderLineParser_Max_Forwards();
  int parse(QString, SipMessage*);
};

#endif // HEADERLINEPARSER_MAX_FORWARDS_H
