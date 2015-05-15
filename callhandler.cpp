#include <QtDebug>
#include "callhandler.h"

CallHandler::CallHandler(QObject *parent) : QObject(parent)
{

}

void CallHandler::processCallData(QByteArray callData)
{
  qDebug() << callData;
}
