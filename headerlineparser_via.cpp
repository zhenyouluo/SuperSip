#include <QDebug>

#include "headerlineparser_via.h"
#include "sipmessage.h"
#include "sipparser.h"

HeaderLineParser_Via::HeaderLineParser_Via()
{

}

int HeaderLineParser_Via::parse(QString fieldvalues, SipMessage* sipmessage)
{
  qDebug() << "parse: " << fieldvalues;
  QStringList via_parm_list = QStringList();

  // test with: \\i,"a\\","b\",c",d
  SipParser::splitBy(fieldvalues, ',', &via_parm_list);
  for (int i=0; i < via_parm_list.size(); i++)
  {
    qDebug() << via_parm_list[i];

    via_parm_list[i] = via_parm_list[i].trimmed();
    int lwspos = SipParser::findLWS(via_parm_list[i]);
    if (lwspos < 2)
    {
      return 1;
    }
    QString sent_protocol = via_parm_list[i].left(lwspos);
    QStringList protocolparts = sent_protocol.split("/");
    if (protocolparts.size() < 3)
    {
      return 2;
    }
    SipVia* sipvia = new SipVia(sipmessage);
    sipvia->setProtocolName(protocolparts[0].trimmed());
    sipvia->setProtocolVersion(protocolparts[1].trimmed());
    sipvia->setTransport(protocolparts[1].trimmed());

    QStringList via_params = via_parm_list[i].mid(lwspos).trimmed().split(";");
    QString send_by = via_params[0];
    QString host = "";
    int portpos = send_by.indexOf(':');
    if (portpos < 0)
    {
      host = send_by.trimmed();
    }
    else
    {
      host = send_by.left(portpos).trimmed();
      QString strport = send_by.mid(portpos+1).trimmed();
      bool ok;
      int port = strport.toInt(&ok);
      if (ok)
      {
        sipvia->setPort(port);
      }
    }
    sipvia->setHost(host);

    for (int j=1; j < via_params.size(); j++)
    {
      int equalpos = via_params[j].indexOf('=');
      if (equalpos > 0)
      {
        QString paramname = via_params[j].left(equalpos).trimmed().toLower();
        QString paramvalue = via_params[j].mid(equalpos+1).trimmed();
        sipvia->addParams(paramname, paramvalue);
      }
    }
    sipmessage->addVia(sipvia);
  }
  return 0;
}
