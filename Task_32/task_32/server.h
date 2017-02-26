#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <QTcpServer>
#include "reader.h"
#include "writer.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = 0);
    ~Server();

signals:
 //----------------------

public slots:
    void onNewConnection();
    void onDisconnected();
    void Start();
    void InitSession();

private:
    QTcpServer* m_server;
    Writer* m_writer;
    Reader* m_reader;
    bool m_clientReady;
};

#endif // SERVER_H
