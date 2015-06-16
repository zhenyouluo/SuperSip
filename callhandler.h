#ifndef CALLHANDLER_H
#define CALLHANDLER_H

#include <QObject>
#include <QHostAddress>

class CallHandler : public QObject
{
  Q_OBJECT

private:
  QByteArray privateKey;
  QByteArray opaque;  // TODO store in database?

public:
  explicit CallHandler(QObject *parent = 0);

signals:
  void sendResponse(QByteArray);

public slots:
  void processCallData(QByteArray, QHostAddress);
};

#endif // CALLHANDLER_H
