#include "packet.h"

Packet::Packet() : m_id(0), m_data()
{

}

Packet::Packet(const int& id, const char* data) : m_id(id), m_data(data)
{

}

Packet::~Packet()
{

}

