#include <iostream>
#include <string>
#include <memory>
#include <cassert>
#include <thread>
#include <cstddef>
#include <ostream>
#include <sstream>

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
    shared_ptr<EventListener> evListener4 = make_shared<EventHandler>();


    Event ev("File creation");

//    EventManager::getInstance().addListener(evListener1);
    thread th1 { [&]()
         {
            cout << "Thread 1" << endl;
            EventManager::getInstance().addListener(evListener1);
            EventManager::getInstance().addListener(evListener2);
         }
       };

    thread th2 { [&]()
         {
            cout << "Thread 2" << endl;
            EventManager::getInstance().addListener(evListener3);
            EventManager::getInstance().addListener(evListener4);
            EventManager::getInstance().addListener(evListener2);
         }
       };

     th1.join();
     th2.join();

     EventManager::getInstance().publishEvent(ev);

    return 0;
}

