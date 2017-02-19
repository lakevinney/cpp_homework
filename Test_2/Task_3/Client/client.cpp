#include "client.h"
#include "packet.h"
Client::Client(QObject *parent)
    : QObject(parent)
    , m_socket(new QTcpSocket(this)) , m_startT(0), m_stopT(0)
{

}

Client::~Client()
{
    delete m_socket;
}

void Client::Connect()
{
    m_socket->connectToHost("127.0.0.1", 9999);
}

void Client::Transmit()
{
    QByteArray packet = "Hello, Server!";
    qDebug() << packet;
    m_startT = QDateTime::currentMSecsSinceEpoch();
    m_socket->write(packet);
    connect(m_socket, SIGNAL(bytesWritten(qint64)), this, SLOT(onBytesWritten(qint64)));
    connect(m_socket, SIGNAL(readyRead()), this, SLOT(onReadyRead()));
}

void Client::onBytesWritten(qint64 bytes)
{
    qDebug() << "We wrote: " << bytes << " bytes";
}

void Client::onReadyRead()
{

    QByteArray data = m_socket->readAll();
    m_stopT = QDateTime::currentMSecsSinceEpoch();
    size_t elapsed = m_stopT - m_startT;
    QString s_data = QString::fromUtf8(data.data());

    qDebug() << "Read: " << s_data;
    qDebug() << "Elapsed time: " << elapsed << "ms";
    m_socket->close();

    emit dataRead(data.size());
}



