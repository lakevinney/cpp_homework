#include "server.h"
#include "reader.h"
#include "writer.h"

#include <QTcpSocket>
#include <QThread>

Server::Server(QObject *parent)
    : QObject(parent)
    , m_server(new QTcpServer(this))
    , m_writer(nullptr)
    , m_reader(nullptr)
    , m_clientReady(true)
{

}

Server::~Server()
{
    delete m_server;
}

void Server::Start()
{
    connect(m_server, SIGNAL(newConnection()), this, SLOT(onNewConnection()));
    if(!m_server->listen(QHostAddress::Any, 1234))
    {
        qDebug() << "Server could not start!";
    }
    else
    {
        qDebug() << "Server started!";
    }
}

void Server::onNewConnection()
{
    qDebug() << "Connected (server)!";

    QTcpSocket *socket = m_server->nextPendingConnection();
    QThread* thread = new QThread();
    if (m_clientReady)
    {
        qDebug() << "Writer inited";
        m_writer = new Writer(socket->socketDescriptor());
        m_writer->moveToThread(thread);
        m_writer->connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        m_writer->connect(thread, SIGNAL(finished()), m_writer,   SLOT(deleteLater()));
        m_clientReady = false;

    }
    else
    {
        qDebug() << "Reader inited";
        m_reader = new Reader(socket->socketDescriptor());
        m_reader->moveToThread(thread);
        m_reader->connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
        m_reader->connect(thread, SIGNAL(finished()), m_reader,   SLOT(deleteLater()));
        m_reader->connect(m_reader, SIGNAL(DataReady(QByteArray)), m_writer, SLOT(SendResponse(QByteArray)));
    }

    thread->start();
}

void Server::onDisconnected()
{
    qDebug() << "Disconnected (server)!";
}


void Server::InitSession()
{
    m_clientReady = true;
}


