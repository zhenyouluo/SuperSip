#include <QDebug>
#include <QUdpSocket>
#include "networkreader.h"
#include "sipparser.h"
#include "callinputter.h"
#include "callhandler.h"

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

    QString callId = SipParser::getCallId(datagram);

    // check if this is known call, if so forward the data to the rigth thread,
    // otherwise start new thread
    if (calls.contains(callId))
    {
      calls.value(callId)->forwardCallData(datagram);
    }
    else
    {
      CallInputter* inputter = new CallInputter();
      calls.insert(callId, inputter);
      CallHandler* handler = new CallHandler();
      QObject::connect(inputter, &CallInputter::sendCallData, handler, &CallHandler::processCallData);
      inputter->forwardCallData(datagram);
    }
  }
}

