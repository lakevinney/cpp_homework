#include <iostream>
#include <cassert>
using namespace std;

class Device
{

public:

    Device() : m_brand("unknown"), m_isOn(false)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    Device(const string& brand, bool status): m_brand(brand), m_isOn(status)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    virtual ~Device()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void TurnOn()
    {
        m_isOn = true;
    }

    void TurnOff()
    {
        m_isOn = false;
    }

    virtual bool GetStatus()const=0;

 protected:

    string m_brand;
    bool m_isOn;

};

class Printer : public virtual Device
{

public:

    Printer() : Device(), m_type("unknown")
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    Printer(const string& brand, bool status, const string& type) :
        Device(brand, status), m_type(type)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    Printer(const Printer& rhs) :
        Device(rhs.m_brand, rhs.m_isOn), m_type(rhs.m_type)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~Printer()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void Print()
    {
        if(GetStatus() != false)
            cout << "Printing..." << endl;
        else
            cout << "Turn your device on!" << endl;
    }

    bool GetStatus() const override
    {
//        cout << __PRETTY_FUNCTION__ << endl;
        return m_isOn;
    }

protected:

    string m_type;
};

class Scanner : public virtual Device
{

public:

    Scanner(): Device()
    {
      cout << __PRETTY_FUNCTION__ << endl;
    }

    Scanner(const string& brand, bool status) :
        Device(brand, status)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    Scanner(const Scanner& rhs) : Device(rhs.m_brand, rhs.m_isOn)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~Scanner()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void Scan()
    {
        if(GetStatus() != false)
            cout << "Scanning..." << endl;
        else
            cout << "Turn your device on!" << endl;
    }

    bool GetStatus() const override
    {
//        cout << __PRETTY_FUNCTION__ << endl;
        return m_isOn;
    }
};

class MFU : public Printer, public Scanner
{

public:

    MFU() :
        Device(), Printer(), Scanner()
    {
       cout << __PRETTY_FUNCTION__ << endl;
    }

    MFU(const string& brand, bool status, const string& type) :
        Device(brand, status), Printer(brand, status, type),
        Scanner(brand, status)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    MFU(const MFU& rhs):
        Device(rhs.m_brand, rhs.m_isOn), Printer(rhs.m_brand, rhs.m_isOn, rhs.m_type),
        Scanner(rhs.m_brand, rhs.m_isOn)
    {
       cout << __PRETTY_FUNCTION__ << endl;
    }

    ~MFU()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    bool GetStatus() const override
    {
//        cout << __PRETTY_FUNCTION__ << endl;
        return m_isOn;
    }
};

int main()
{
    Printer p("Canon", true, "Inkjet");
    Scanner s("Epson", false);
    MFU m("HP", false, "Laser");

    p.Print();
    p.TurnOff();
    assert(p.GetStatus() == false);

    s.Scan();
    s.TurnOn();
    assert(s.GetStatus() == true);
    s.Scan();

    m.TurnOn();
    assert(m.GetStatus() == true);
    m.Print();
    m.Scan();
    m.TurnOff();
    assert(m.GetStatus() == false);

    return 0;
}

