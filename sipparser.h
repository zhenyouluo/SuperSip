#ifndef SIPPARSER_H
#define SIPPARSER_H

#include <QObject>
#include <QString>
#include <QSet>
#include "sipmessage.h"

class SipParser : public QObject
{
  Q_OBJECT
public:
  explicit SipParser(QObject *parent = 0);
  static QString getCallId(QByteArray);
  static SipMessage* parse(QByteArray);
  static QSet<QString> sipMethods;

signals:

public slots:
};



#endif // SIPPARSER_H
