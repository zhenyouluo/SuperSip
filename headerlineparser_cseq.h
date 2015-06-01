#ifndef HEADERLINEPARSER_CSEQ_H
#define HEADERLINEPARSER_CSEQ_H

#include "headerlineparser.h"

class HeaderLineParser_Cseq : public HeaderLineParser
{
public:
  HeaderLineParser_Cseq();
  int parse(QString, SipMessage*);
};

#endif // HEADERLINEPARSER_CSEQ_H
