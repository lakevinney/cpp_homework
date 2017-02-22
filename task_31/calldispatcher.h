#ifndef CALLDISPATCHER_H
#define CALLDISPATCHER_H

#include <string>
#include <memory>
#include <map>
//#include "object.h"

class Object;

class CallDispatcher
{
private:

    typedef std::multimap<std::pair<Object*, std::string>, std::pair<Object*, std::string>> Mmp;
    Mmp m_routingTable;

public:
    typedef std::shared_ptr<CallDispatcher> Ptr;
    typedef std::multimap<std::pair<Object*, std::string>, std::pair<Object*, std::string>>::iterator Mmp_iter;
    CallDispatcher();

    void connect(Object* sender, const std::string& singal, Object* receiver, const std::string& slot);
    void disconnect(Object* sender, const std::string& singal, Object* receiver, const std::string& slot);

    void sendSignal(Object* sender, const std::string& singal);
};

#endif // CALLDISPATCHER_H
