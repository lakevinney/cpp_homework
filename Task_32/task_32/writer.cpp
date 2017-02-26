#include "writer.h"
#include <QThread>

Writer::Writer(qintptr descriptor, QObject *parent) :
    QObject(parent)
   , m_socket(new QTcpSocket(this))
{
    m_socket->setSocketDescriptor(descriptor);
    connect(m_socket, SIGNAL(connected()), this, SLOT(onConnected()));
    connect(m_socket, SIGNAL(disconnected()), this, SLOT(onDisconnected()));
    connect(m_socket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(OnError(QAbstractSocket::SocketError)));
    connect(m_socket, SIGNAL(stateChanged(QAbstractSocket::SocketState)), this, SLOT(OnStateChanged(QAbstractSocket::SocketState)));

}

Writer::~Writer()
{
    delete m_socket;
}

void Writer::onConnected()
{
    qDebug() << __PRETTY_FUNCTION__;
}

void Writer::onDisconnected()
{
    qDebug() << "Writer disconnected";
    thread()->quit();
}

void Writer::OnError(QAbstractSocket::SocketError err)
{
    qWarning() << "Error: " << err;
}

void Writer::OnStateChanged(QAbstractSocket::SocketState state)
{
    qWarning() << "State changed to: " << state;
}

void Writer::SendResponse(QByteArray data)
{
    m_socket->write(data);
}

