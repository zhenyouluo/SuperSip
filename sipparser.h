#ifndef SIPPARSER_H
#define SIPPARSER_H

#include <QObject>
#include <QString>
#include <QSet>
#include "sipmessage.h"
#include "sipuri.h"

class SipParser : public QObject
{
  Q_OBJECT
public:
  explicit SipParser(QObject *parent = 0);
  static QString getCallId(QByteArray);
  static int parse(QByteArray, SipMessage*);
  static QSet<QString> sipMethods;
  static int parseSipURI(QString, SipURI*);

signals:

public slots:
};



#endif // SIPPARSER_H
