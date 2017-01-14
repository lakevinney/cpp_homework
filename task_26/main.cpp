#include <iostream>
#include <cassert>
using namespace std;

class Device
{

public:

    Device() : m_brand("unknown"), m_status("off")
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    Device(const string& brand, const string& status): m_brand(brand), m_status(status)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    virtual ~Device()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void TurnOn()
    {
        m_status = "on";
    }

    void TurnOff()
    {
        m_status = "off";
    }

    virtual const string& GetStatus()=0;

 protected:

    string m_brand;
    string m_status;

};

class Printer : public virtual Device
{

public:

    Printer() : Device(), m_type("unknown")
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    Printer(const string& brand, const string& status, const string& type) :
        Device(brand, status), m_type(type)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    Printer(const Printer& rhs) :
        Device(rhs.m_brand, rhs.m_status), m_type(rhs.m_type)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~Printer()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void Print()
    {
        if(GetStatus() != "off")
            cout << "Printing..." << endl;
        else
            cout << "Turn your device on!" << endl;
    }

    const string& GetStatus() override
    {
//        cout << __PRETTY_FUNCTION__ << endl;
        return m_status;
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

    Scanner(const string& brand, const string& status) :
        Device(brand, status)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    Scanner(const Scanner& rhs) : Device(rhs.m_brand, rhs.m_status)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~Scanner()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    void Scan()
    {
        if(GetStatus() != "off")
            cout << "Scanning..." << endl;
        else
            cout << "Turn your device on!" << endl;
    }

    const string& GetStatus() override
    {
//        cout << __PRETTY_FUNCTION__ << endl;
        return m_status;
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

    MFU(const string& brand, const string& status, const string& type) :
        Device(brand, status), Printer(brand, status, type),
        Scanner(brand, status)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    MFU(const MFU& rhs):
        Device(rhs.m_brand, rhs.m_status), Printer(rhs.m_brand, rhs.m_status, rhs.m_type),
        Scanner(rhs.m_brand, rhs.m_status)
    {
       cout << __PRETTY_FUNCTION__ << endl;
    }

    ~MFU()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    const string& GetStatus() override
    {
//        cout << __PRETTY_FUNCTION__ << endl;
        return m_status;
    }
};

int main()
{
    Printer p("Canon", "on", "Inkjet");
    Scanner s("Epson", "off");
    MFU m("HP", "off", "Laser");

    p.Print();
    p.TurnOff();
    assert(p.GetStatus() == "off");

    s.Scan();
    s.TurnOn();
    assert(s.GetStatus() == "on");
    s.Scan();

    m.TurnOn();
    assert(m.GetStatus() == "on");
    m.Print();
    m.Scan();
    m.TurnOff();
    assert(m.GetStatus() == "off");

    return 0;
}

