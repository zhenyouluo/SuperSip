#include "sipdefinitions.h"
#include <QStringList>

SipDefinitions::SipDefinitions()
{

}

const QStringList SipDefinitions::sipMethods = (QStringList() << "INVITE" << "REGISTER" << "ACK" << "CANCEL" << "BYE" << "OPTIONS");
