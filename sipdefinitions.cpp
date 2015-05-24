#include "sipdefinitions.h"
#include <QStringList>

SipDefinitions::SipDefinitions()
{

}

const QStringList SipDefinitions::sipMethods = (QStringList() << "INVITE" << "REGISTER" << "ACK" << "CANCEL" << "BYE" << "OPTIONS");
const QStringList SipDefinitions::sipFieldnames = (QStringList()
  << "Accept"
  << "Accept-Encoding"
  << "Accept-Language"
  << "Alert-Info"
  << "Allow"
  << "Authentication-Info"
  << "Authorization"
  << "Call-ID"
  << "Call-Info"
  << "Contact"
  << "Content-Disposition"
  << "Content-Encoding"
  << "Content-Language"
  << "Content-Length"
  << "Content-Type"
  << "CSeq"
  << "Date"
  << "Error-Info"
  << "Expires"
  << "From"
  << "In-Reply-To"
  << "Max-Forwards"
  << "MIME-Version"
  << "Min-Expires"
  << "Organization"
  << "Priority"
  << "Proxy-Authenticate"
  << "Proxy-Authorization"
  << "Proxy-Require"
  << "Record-Route"
  << "Reply-To"
  << "Require"
  << "Retry-After"
  << "Route"
  << "Server"
  << "Subject"
  << "Supported"
  << "Timestamp"
  << "To"
  << "Unsupported"
  << "User-Agent"
  << "Via"
  << "Warning"
  << "WWW-Authenticate");
