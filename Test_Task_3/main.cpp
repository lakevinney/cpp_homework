#include <iostream>
#include <cassert>

using namespace std;


//----------------------------Task3----------------------------
class HTMLElement
{

private:

    unsigned m_width;
    unsigned m_height;
    bool hidden;

public:

    HTMLElement(): m_width(0), m_height(0), hidden(false)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    HTMLElement(unsigned wid, unsigned hei, bool hid): m_width(wid), m_height(hei), hidden(hid)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    virtual ~HTMLElement()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    unsigned Width() const
    {
        return m_width;
    }

    unsigned Height() const
    {
        return m_height;
    }

    bool Hidden() const
    {
        return hidden;
    }

    virtual string Render()=0;

    virtual HTMLElement* Duplicate()=0;

};

class HTMLButtonElement : public HTMLElement
{
    string m_title;
public:

    HTMLButtonElement() : HTMLElement(), m_title("None")
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    HTMLButtonElement(unsigned wid, unsigned hei, bool hid, const string& title) : HTMLElement(wid, hei, hid), m_title(title)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    HTMLButtonElement(const HTMLButtonElement& rhs): HTMLElement(rhs.Width(), rhs.Height(), rhs.Hidden())
    {
        cout << __PRETTY_FUNCTION__ << endl;
        m_title = rhs.m_title;
    }

    ~HTMLButtonElement()
    {
       cout << __PRETTY_FUNCTION__ << endl;
    }

    const string& Title() const
    {
        return m_title;
    }

    string Render() override
    {
        return "<button>" + m_title + "</button>:";

    }

    HTMLElement* Duplicate() override
    {
        return new HTMLButtonElement(*this);
    }
};

class HTMLImageElement: public HTMLElement
{
    string m_url;

public:
    HTMLImageElement() : HTMLElement(), m_url("None")
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    HTMLImageElement(unsigned wid, unsigned hei, bool hid, const string& url) : HTMLElement(wid, hei, hid), m_url(url)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    HTMLImageElement(const HTMLImageElement& rhs) : HTMLElement(rhs.Width(), rhs.Height(), rhs.Hidden())
    {
        cout << __PRETTY_FUNCTION__ << endl;
        m_url = rhs.m_url;
    }

    ~HTMLImageElement()
    {
       cout << __PRETTY_FUNCTION__ << endl;
    }

    const string& Url() const
    {
        return m_url;
    }

    string Render() override
    {
        return "<img src=" + m_url + " height=" + to_string(Height()) + " width=" + to_string(Width()) +">";

    }

    HTMLElement* Duplicate() override
    {
        return new HTMLImageElement(*this);
    }
};

class HTMLTextAreaElement : public HTMLElement
{
    string m_content;

public:

    HTMLTextAreaElement() : HTMLElement(), m_content("None")
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    HTMLTextAreaElement(unsigned wid, unsigned hei, bool hid, const string& content) : HTMLElement(wid, hei, hid), m_content(content)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    HTMLTextAreaElement(const HTMLTextAreaElement& rhs) : HTMLElement(rhs.Width(), rhs.Height(), rhs.Hidden())
    {
        cout << __PRETTY_FUNCTION__ << endl;
        m_content  = rhs.m_content;
    }

    ~HTMLTextAreaElement()
    {
       cout << __PRETTY_FUNCTION__ << endl;
    }

    const string& Content() const
    {
        return m_content;
    }

    string Render() override
    {
        return "<textarea>\n" + m_content + "\n</textarea>";

    }

    HTMLElement* Duplicate() override
    {
        return new HTMLTextAreaElement(*this);
    }

};


int main()
{

    HTMLButtonElement* but = new HTMLButtonElement(10, 20, false, "Log In");
    HTMLImageElement* img = new HTMLImageElement(30, 30, true, "http://www.pictures.com/picture.jpg");
    HTMLTextAreaElement* txt = new HTMLTextAreaElement(100, 100, false, "Do not copy me");

    const int arrSize = 3;
    HTMLElement* elems[arrSize] = {but, img, txt};

    HTMLElement* elemsCpy[arrSize];

    for(size_t i = 0; i != arrSize; ++i)
        assert(elemsCpy[i] = elems[i]->Duplicate());

    for(size_t i = 0; i != arrSize; ++i)
        assert(cout << elemsCpy[i]->Render() << endl);

    for(size_t i = 0; i != arrSize; ++i)
    {
        delete elems[i];
        delete elemsCpy[i];
    }

    return 0;
}
