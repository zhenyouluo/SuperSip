#ifndef CALLHANDLER_H
#define CALLHANDLER_H

#include <QObject>

class CallHandler : public QObject
{
  Q_OBJECT
public:
  explicit CallHandler(QObject *parent = 0);

signals:

public slots:
  void processCallData(QByteArray);
};

#endif // CALLHANDLER_H
