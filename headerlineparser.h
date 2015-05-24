#ifndef HEADERLINEPARSER_H
#define HEADERLINEPARSER_H

#include <QObject>
#include "sipmessage.h"

class HeaderLineParser : public QObject
{
  Q_OBJECT
public:
  explicit HeaderLineParser(QObject *parent = 0);
  static int parse(QString, SipMessage*);

signals:

public slots:
};

#endif // HEADERLINEPARSER_H
