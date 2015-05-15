#ifndef SIPPARSER_H
#define SIPPARSER_H

#include <QObject>

class SipParser : public QObject
{
  Q_OBJECT
public:
  explicit SipParser(QObject *parent = 0);
  static QString getCallId(QByteArray);

signals:

public slots:
};

#endif // SIPPARSER_H
