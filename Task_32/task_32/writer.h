#ifndef WRITER_H
#define WRITER_H

#include <QObject>
#include <QTcpSocket>

class Writer : public QObject
{
    Q_OBJECT
public:
    Writer(qintptr descriptor, QObject *parent = 0);
    ~Writer();

public slots:
    void onConnected();
    void onDisconnected();
    void OnError(QAbstractSocket::SocketError err);
    void OnStateChanged(QAbstractSocket::SocketState state);
    void SendResponse(QByteArray data);

private:
    QTcpSocket* m_socket;
};

#endif // WRITER_H
