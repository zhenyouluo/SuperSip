#ifndef HEADERLINEPARSER_FROM_H
#define HEADERLINEPARSER_FROM_H

#include "headerlineparser.h"

class HeaderLineParser_From : public HeaderLineParser
{
public:
  HeaderLineParser_from();
  int parse(QString, SipMessage*);
};

#endif // HEADERLINEPARSER_FROM_H
