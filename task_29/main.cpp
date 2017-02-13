#include <iostream>
#include <string>
#include <memory>
#include <cassert>

#include "event.h"
#include "eventlistener.h"
#include "eventmanager.h"

using namespace std;


struct FileLogger : EventListener
{
    void notify(const Event& ev) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << ev.getDescription() << endl;
    }
};

struct ConnectionMgr : EventListener
{
    void notify(const Event& ev) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << ev.getDescription() << endl;
    }
};


struct EventHandler : EventListener
{
    void notify(const Event& ev) override
    {
        cout << __PRETTY_FUNCTION__ << endl;
        cout << ev.getDescription() << endl;
    }
};


int main()
{
    shared_ptr<EventListener> evListener1 = make_shared<FileLogger>();
    shared_ptr<EventListener> evListener2 = make_shared<ConnectionMgr>();
    shared_ptr<EventListener> evListener3 = make_shared<EventHandler>();

    Event ev("File creation");

    EventManager::getInstance().addListener(evListener1);
    EventManager::getInstance().addListener(evListener2);
    EventManager::getInstance().addListener(evListener3);
    EventManager::getInstance().addListener(evListener3);
    EventManager::getInstance().addListener(evListener2);

    EventManager::getInstance().publishEvent(ev);

    EventManager::getInstance().removeListener(evListener2);
    EventManager::getInstance().removeListener(evListener3);
    EventManager::getInstance().publishEvent(ev);

    EventManager::getInstance().addListener(evListener2);
    EventManager::getInstance().addListener(evListener3);
    EventManager::getInstance().publishEvent(ev);

    return 0;
}
