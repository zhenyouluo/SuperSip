#ifndef CALLINPUTTER_H
#define CALLINPUTTER_H

#include <QObject>

class CallInputter : public QObject
{
  Q_OBJECT
public:
  explicit CallInputter(QObject *parent = 0);
  void forwardCallData(QByteArray);

signals:
  void sendCallData(QByteArray);
public slots:
};

#endif // CALLINPUTTER_H
