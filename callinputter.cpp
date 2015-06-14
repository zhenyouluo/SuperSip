#include "callinputter.h"
#include "networkreader.h"

CallInputter::CallInputter(QObject *parent) : QObject(parent)
{
  networkreader = (NetworkReader *) parent;
}

void CallInputter::forwardCallData(QByteArray callData)
{
  emit sendCallData(callData);
}

void CallInputter::responseToClient(QByteArray responsedata)
{
  networkreader->sendToClient(sender, senderPort, responsedata);
}

void CallInputter::setClientIp(QHostAddress sender_in, quint16 senderport)
{
  sender = sender_in;
  senderPort = senderport;
}
