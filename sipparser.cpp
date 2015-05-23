#include <QStringList>
#include <QString>
#include <QSet>
#include <QDebug>
#include <QRegExp>
#include "sipparser.h"
#include "sipuri.h"
#include "sipmessage.h"
#include "sipdefinitions.h"

SipParser::SipParser(QObject *parent) : QObject(parent)
{

}

int SipParser::parseSipURI(QString uritext, SipURI* sipuri)
{
  // use regex
  QRegExp rx("^(([^:/?#]+):)?(//([^/?#]*))?([^?#]*)(\\?([^#]*))?(#(.*))?");
  if (rx.indexIn("http://user@www.ics.uci.edu:9001/pub/ietf/uri/#Related") == -1)
  {
    return 1;
  }
  QStringList list = rx.capturedTexts();
  if (list.size() < 10)
  {
    return 2;
  }
  sipuri->setUriText(uritext);
  if (list[2] == "")
  {
    return 3;
  }
  else
  {
    sipuri->setUriScheme(list[2]);
  }
  QString server;

  if (list[3].startsWith("//"))
  {
    // absolute url
    server = list[4];
    sipuri->setUriPath(list[5]);
  }
  else
  {
    // opaque: list[5] contains host and possibly path
    int pathpos = list[5].indexOf('/');
    if (pathpos < 0)
    {
      server = list[5];
    }
    else
    {
      if (pathpos < 1)
      {
        // no host
        return 4;
      }
      server = list[5].left(pathpos);
      sipuri->setUriPath(list[5].mid(pathpos));
    }
  }
  QString hostport;
  int atpos = server.indexOf('@');
  if (atpos < 0)
  {
    // no user info in server
    hostport = server;
  }
  else
  {
    sipuri->setUriUserinfo(server.left(atpos));
    hostport = server.mid(atpos+1);
  }
  int portpos = hostport.indexOf(':');
  if (portpos < 0)
  {
    sipuri->setUriHost(hostport);
  }
  else
  {
    sipuri->setUriHost(hostport.left(portpos));
    sipuri->setUriPort(hostport.mid(portpos+1));
  }
  sipuri->setUriQuery(list[7]);
  sipuri->setUriFragment(list[9]);

  return 0;
}

QString SipParser::getCallId(QByteArray sipheader)
{
  QString message = QString::fromUtf8(sipheader.data());
  QStringList messagelines = message.split("\n");
  for (int i = 0; i < messagelines.size(); ++i)
  {
    // TODO call id on multiple lines?
    if (messagelines[i].startsWith("Call-ID", Qt::CaseInsensitive))
    {
      QStringList lineparts = messagelines[i].split(":");
      if (lineparts.size() > 1)
      {
        return lineparts[1].trimmed();
      }
    }
  }
  return NULL;
}

int SipParser::parse(QByteArray sipdata, SipMessage* sipmessage)
{
  QString message = QString::fromUtf8(sipdata.data());
  QStringList messagelines = message.split("\n");

  // discard messages that do not at least contain a startline and a CRLF line between header and body
  if (messagelines.size() < 2)
  {
    return 1;
  }

  QString startline = messagelines[0];

  // responses start with SIP
  if (startline.startsWith("SIP", Qt::CaseInsensitive))
  {
    // Response message
    sipmessage->setIsRequest(false);

    // Parse response startline, must be: SIP-Version SP Status-Code SP Reason-Phrase

    int firstspacepos = startline.indexOf(" ");
    if (firstspacepos < 1)
    {
      return 2;
    }
    sipmessage->setSipVersion(startline.left(firstspacepos));
    int secondspacepos = startline.indexOf(" ", firstspacepos+1);
    if (secondspacepos < firstspacepos+2)
    {
      return 3;
    }
    sipmessage->setStatusCode(startline.mid(firstspacepos+1, secondspacepos-(firstspacepos+1)));

    QString reason = startline.mid(secondspacepos+1).trimmed();
    if (reason.isNull() || reason.isEmpty())
    {
      return 4;
    }
    sipmessage->setReasonPhrase(reason);
  }
  else
  {
    // Request message
    sipmessage->setIsRequest(true);

    // Parse response startline, must be: Method SP Request-URI SP SIP-Version
    QStringList startlineparts = startline.split(" ");

    // all parts available?
    if (startlineparts.size() < 3)
    {
      return 5;
    }

    // check if sip method can be recognized
    if (!SipDefinitions::sipMethods.contains(startlineparts[0]))
    {
      qDebug() << "method not recognized";
      return 6;
    }

    sipmessage->setSipMethod(startlineparts[0]);

    // Parse sip URI
    qDebug() << "parse uri";
    SipURI* sipuri = new SipURI(sipmessage);
    int result = parseSipURI(startlineparts[1], sipuri);
    if (result != 0)
    {
      return 7;
    }
    sipmessage->setSipURI(sipuri);

    sipmessage->setSipVersion(startlineparts[2]);

  }



  for (int i = 0; i < messagelines.size(); ++i)
  {
    int colonpos = messagelines[i].indexOf(':');
    if (colonpos > 0)
    {
      // QString fieldname = messagelines[i].left(colonpos).trimmed();
      // QString values = messagelines[i].midRef(colonpos+1).trimmed();
    }
    if (messagelines[i].startsWith("Call-ID", Qt::CaseInsensitive))
    {
      QStringList lineparts = messagelines[i].split(":");
      if (lineparts.size() > 1)
      {
       //return lineparts[1].trimmed();
      }
    }
  }
  return 0;
}

