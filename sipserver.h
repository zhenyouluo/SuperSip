#ifndef SIPSERVER_H
#define SIPSERVER_H

#include <QObject>

class SipServer : public QObject
{
  Q_OBJECT
public:
  explicit SipServer(QObject *parent = 0);

signals:

public slots:
};

#endif // SIPSERVER_H
