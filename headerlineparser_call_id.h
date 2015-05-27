#ifndef HEADERLINEPARSER_CALL_ID_H
#define HEADERLINEPARSER_CALL_ID_H

#include "headerlineparser.h"

class HeaderLineParser_Call_Id : public HeaderLineParser
{
public:
  HeaderLineParser_Call_Id();
  int parse(QString, SipMessage*);
};

#endif // HEADERLINEPARSER_CALL_ID_H
