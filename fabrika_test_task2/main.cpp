#include <iostream>

using namespace std;


//----------------------------Task2----------------------------
class HTMLElement
{

    unsigned m_width;
    unsigned m_height;
    bool hidden;
public:

    HTMLElement(): m_width(0), m_height(0), hidden(false)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    HTMLElement(unsigned w, unsigned h, bool h): m_width(w), m_height(h), hidden(h)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }


    unsigned Width() const;
    unsigned Height() const;
    bool Hidden() const;
    virtual string Render()=0;

};

int main(int argc, char *argv[])
{
    cout << "Hello World!" << endl;
    return 0;
}
