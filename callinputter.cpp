#include "callinputter.h"

CallInputter::CallInputter(QObject *parent) : QObject(parent)
{
}

void CallInputter::forwardCallData(QByteArray callData)
{
  emit sendCallData(callData);
}

