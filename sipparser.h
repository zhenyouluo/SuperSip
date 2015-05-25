#ifndef SIPPARSER_H
#define SIPPARSER_H

#include <QObject>
#include <QString>
#include <QStringList>
#include <QSet>
#include "sipmessage.h"
#include "sipuri.h"
#include "headerlineparser.h"

class SipParser : public QObject
{
  Q_OBJECT
private:
  static QHash<QString, HeaderLineParser*> headerlineparsers;
  static void initHeaderlineparsers();

public:
  explicit SipParser(QObject *parent = 0);
  static QString getCallId(QByteArray);
  static int parse(QByteArray, SipMessage*);
  static QSet<QString> sipMethods;
  static int parseSipURI(QString, SipURI*);
  static int parseHeader(QStringList, SipMessage*);
  static HeaderLineParser* getHeaderlineparser(QString);
  static void splitBy(QString, QChar, QStringList*);
  static int findLWS(QString);

signals:

public slots:
};



#endif // SIPPARSER_H
