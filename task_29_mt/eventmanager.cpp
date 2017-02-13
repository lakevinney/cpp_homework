#include "eventmanager.h"
#include <algorithm>
#include <iostream>

using namespace std;

EventManager& EventManager::getInstance()
{
    static EventManager inst;
    return inst;
}

void EventManager::publishEvent(const Event& ev)
{   
    for(auto& listener: m_listeners)
    {
        if (!listener.expired())
        {
            shared_ptr<EventListener> tmp = listener.lock();
            if(tmp)

                tmp->notify(ev);
        }
    }
}

void EventManager::addListener(shared_ptr<EventListener>& listener)
{
    lock_guard<mutex> lock(m_lock);

    auto it = find_if(m_listeners.begin(),
                      m_listeners.end(),
                      [&listener](weak_ptr<EventListener>& elem)
                      { shared_ptr<EventListener> tmp = elem.lock();
                        return tmp.get() == listener.get(); } );

    if (it == m_listeners.end())
    {
        cout << __PRETTY_FUNCTION__ << endl;
        m_listeners.push_back(listener);
    }

}

void EventManager::removeListener(shared_ptr<EventListener>& listener)
{
    lock_guard<mutex> lock(m_lock);

    if (listener)
    {
        cout << __PRETTY_FUNCTION__ << endl;
        m_listeners.erase( remove_if( m_listeners.begin(),
                                    m_listeners.end(),
                                    [&listener](weak_ptr<EventListener>& elem)
                        { shared_ptr<EventListener> tmp = elem.lock();
                          return tmp.get() == listener.get() || elem.expired(); } ), m_listeners.end() );
    }


}



