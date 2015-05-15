#include <QDebug>
#include <QUdpSocket>
#include "networkreader.h"
#include "sipparser.h"

NetworkReader::NetworkReader()
{
  udpSocket = new QUdpSocket();
  if (udpSocket->bind(QHostAddress::Any, 5060))
  {
    qDebug() << "bound";
  }
  else
  {
    qDebug() << "not bound";
  }
  connect(udpSocket, SIGNAL(readyRead()), this, SLOT(readPendingDatagrams()));
  qDebug() << "connected";
}

void NetworkReader::readPendingDatagrams()
{
  qDebug() << "incoming";
  while (udpSocket->hasPendingDatagrams())
  {
    QByteArray datagram;
    datagram.resize(udpSocket->pendingDatagramSize());
    QHostAddress sender;
    quint16 senderPort;

    udpSocket->readDatagram(datagram.data(), datagram.size(),
                            &sender, &senderPort);

    qDebug() << SipParser::getCallId(datagram);
  }
}

