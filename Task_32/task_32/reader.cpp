#include "reader.h"
#include <QThread>


Reader::Reader(qintptr socketDescr, QObject *parent)
    : QObject(parent)
    , m_socket(new QTcpSocket(this))
{
    m_socket->setSocketDescriptor(socketDescr);

    connect(m_socket, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
    connect(m_socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(onError(QAbstractSocket::SocketError)));
    connect(m_socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(onStateChanged(QAbstractSocket::SocketState)));
}

Reader::~Reader()
{
    delete m_socket;
}

void Reader::onConnected()
{
    qDebug() << __PRETTY_FUNCTION__;
}

void Reader::onDisconnected()
{
    qDebug() << "Reader disconnected";
    thread()->quit();
}

void Reader::onReadyRead()
{
    QByteArray data = m_socket->readAll();
    emit DataReady(data);
}

void Reader::onError(QAbstractSocket::SocketError err)
{
    qWarning() << "Error: " << err;
}

void Reader::onStateChanged(QAbstractSocket::SocketState state)
{
    qWarning() << "State changed to: " << state;
}

