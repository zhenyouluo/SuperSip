#ifndef HEADERLINEPARSER_CONTENT_LENGTH_H
#define HEADERLINEPARSER_CONTENT_LENGTH_H

#include "headerlineparser.h"

class HeaderLineParser_Content_Length : public HeaderLineParser
{
public:
  HeaderLineParser_Content_Length();
  int parse(QString, SipMessage*);
};

#endif // HEADERLINEPARSER_CONTENT_LENGTH_H
