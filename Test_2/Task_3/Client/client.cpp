#include "client.h"
#include "packet.h"
Client::Client(QObject *parent)
    : QObject(parent)
    , m_socket(new QTcpSocket(this))
{
//    connect(m_socket, SIGNAL(connected(const Packet&)),          this, SLOT(onConnected(const Packet&)));
//    connect(m_socket, SIGNAL(disconnected()),       this, SLOT(onDisconnected()));
//    connect(m_socket, SIGNAL(readyRead()),          this, SLOT(onReadyRead()));
//    connect(m_socket, SIGNAL(bytesWritten(qint64)), this, SLOT(onBytesWritten(qint64)));
}

Client::~Client()
{
    delete m_socket;
}

void Client::Connect()
{
    connect(m_socket, SIGNAL(connected()), this, SLOT(onConnected()));
    m_socket->connectToHost("127.0.0.1", 9999);
}

void Client::onConnected()
{
    qDebug() << "Connected (client)!";
    m_socket->write("test connection\n\n");
    qDebug() << "Written!";

    connect(m_socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(m_socket, SIGNAL(readyRead()),  this, SLOT(onReadyRead()));
}

void Client::onBytesWritten(qint64 bytes)
{
    qDebug() << "We wrote: " << bytes << " bytes";
}

void Client::onReadyRead()
{
    qDebug() << "Reading...";
    qDebug() << m_socket->readAll();

    m_socket->close();
    connect(m_socket, SIGNAL(bytesWritten(qint64)), this, SLOT(onBytesWritten(qint64)));
    emit dataRead();
}

void Client::onDisconnected()
{
    qDebug() << "Disconnected!";
}


//void Client::Connect()
//{
//    m_socket->connectToHost("127.0.0.1", 9999);
//}

////void Client::setValue(int newValue)
////{
////    m_value = newValue;
////    emit valueSet(m_value);
////}

//void Client::onConnected(const Packet& packet)
//{
//    qDebug() << "Connected (client)!";

//    // send
//    m_socket->write(packet.GetData());

//    qDebug() << "Written!";
//}

//void Client::onDisconnected()
//{
//    qDebug() << "Disconnected!";
//}

//void Client::onBytesWritten(qint64 bytes)
//{
//    qDebug() << "We wrote: " << bytes << " bytes";
//}

//void Client::onReadyRead()
//{
//    qDebug() << "Reading...";
//    qDebug() << m_socket->readAll();

//    m_socket->close();
//}
