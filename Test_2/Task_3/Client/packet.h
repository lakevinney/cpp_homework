#ifndef PACKET_H
#define PACKET_H

#include <QObject>

class Packet
{
public:
    Packet();
    Packet(const int& id, const char* data);
    const QByteArray& GetData() const
    {
        return m_data;
    }
    const int& GetID() const
    {
        return m_id;
    }

    ~Packet();

private:

    int m_id;
    QByteArray m_data;
};

#endif // PACKET_H
