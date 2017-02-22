#include <iostream>
#include <memory>

#include "object.h"
#include "calldispatcher.h"

using namespace std;

class A : public Object
{
private:
    void dispatchMethod(const string& methodName) override
    {
        if ("Act1" == methodName)
        {
            Act1();
        }
        else if ("Act2" == methodName)
        {
            Act2();
        }
        else if ("Act3" == methodName)
        {
            Act3();
        }
        else
        {

        }
    }

public:

    A(CallDispatcher::Ptr& dispatcher)
        : Object(dispatcher)
    {
    }

public /*slots*/:

    void Act1()
    {
        cout << __PRETTY_FUNCTION__ << ": " << this << endl;
    }

    void Act2()
    {
        cout << __PRETTY_FUNCTION__ << ": " << this << endl;
    }

    void Act3()
    {
        cout << __PRETTY_FUNCTION__ << ": " << this << endl;
    }
};


class B : public Object
{

public:
    B(CallDispatcher::Ptr& dispatcher)
        : Object(dispatcher)
    {
    }

public /*signals*/:

    void Ev1()
    {
        m_dispatcher->sendSignal(this, "Ev1");
    }

    void Ev2()
    {
        m_dispatcher->sendSignal(this, "Ev2");
    }

    void Ev3()
    {
        m_dispatcher->sendSignal(this, "Ev3");
    }
};




int main()
{
    auto d = make_shared<CallDispatcher>();

    A a1(d);
    A a2(d);
    B b1(d);
    B b2(d);

    d->connect(&b1, "Ev1", &a1, "Act1");

    // 1 signal => many slots
    d->connect(&b1, "Ev2", &a1, "Act2");
    d->connect(&b1, "Ev2", &a1, "Act3"); //names shouldn't nesseraly match
    d->connect(&b1, "Ev2", &a2, "Act2");

    // 2 signals => 1 slot
    d->connect(&b1, "Ev3", &a2, "Act3");
    d->connect(&b2, "Ev3", &a2, "Act3");

    b1.Ev1(); // a1.Act1()
    b1.Ev2(); // a1.Act2(), a1.Act3(), a2.Act2()
    b1.Ev3(); // a2.Act3()

    b2.Ev1(); // <nothing>
    b2.Ev2(); // <nothing>
    b2.Ev3(); // a2.Act3()

    d->disconnect(&b1, "Ev1", &a1, "Act1");
    b1.Ev1(); // <nothing>

    return 0;
}
