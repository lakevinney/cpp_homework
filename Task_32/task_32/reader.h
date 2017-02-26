#ifndef READER_H
#define READER_H

#include <QObject>
#include <QTcpSocket>

class Reader : public QObject
{
    Q_OBJECT
public:
    explicit Reader(qintptr socketDescr, QObject *parent = 0);
    ~Reader();

signals:
    void DataReady(QByteArray data);

public slots:
    void onConnected();
    void onDisconnected();
    void onReadyRead();
    void onError(QAbstractSocket::SocketError err);
    void onStateChanged(QAbstractSocket::SocketState state);

private:
    QTcpSocket* m_socket;
};

#endif // READER_H
