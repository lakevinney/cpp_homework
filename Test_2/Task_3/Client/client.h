#ifndef CLIENT_H
#define CLIENT_H

#include <QObject>
#include <QTcpSocket>
#include <QTimer>
#include <QTime>
#include <QDateTime>
#include "packet.h"


class Client : public QObject
{
    Q_OBJECT
public:
    explicit Client(QObject *parent = 0);
    ~Client();
    void Connect();

signals:
    void sender_ready();
    void dataRead(int);

public slots:

    void Transmit();
    void onReadyRead();
    void onBytesWritten(qint64 bytes);

private:

    QTcpSocket* m_socket;
    size_t m_startT;
    size_t m_stopT;
};

#endif // CLIENT_H
