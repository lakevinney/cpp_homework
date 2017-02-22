#include <algorithm>
#include "calldispatcher.h"
#include "object.h"

CallDispatcher::CallDispatcher()
{
    //...
}

void CallDispatcher::connect(Object *sender, const std::string& signal, Object *receiver, const std::string& slot)
{
    m_routingTable.insert({{sender,signal}, {receiver, slot}});
}

void CallDispatcher::disconnect(Object *sender, const std::string& signal, Object *receiver, const std::string& slot)
{
    auto it = m_routingTable.find({sender,signal});

    if(it != m_routingTable.end())
    {
        std::pair<Mmp_iter, Mmp_iter> recvs = m_routingTable.equal_range({sender,signal});
        for (Mmp_iter i = recvs.first; i != recvs.second; ++i)
        {
            if(i->second.first == receiver && i->second.second == slot)
            {
                m_routingTable.erase(i);
                break;
            }
        }
    }
}

void CallDispatcher::sendSignal(Object *sender, const std::string& signal)
{
    auto it = m_routingTable.find({sender,signal});

    if(it != m_routingTable.end())
    {
        std::pair<Mmp_iter, Mmp_iter> recvs = m_routingTable.equal_range({sender,signal});
        for (Mmp_iter i = recvs.first; i != recvs.second; ++i)
        {
            std::pair<Object*, std::string> j = i->second;
            j.first->dispatchMethod(j.second);
        }
    }
}
