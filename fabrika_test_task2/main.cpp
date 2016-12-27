#include <iostream>
#include <cassert>

using namespace std;


//----------------------------Task2----------------------------
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

};

class HTMLButtonElement : public HTMLElement
{
    string m_title;
public:

    HTMLButtonElement() : HTMLElement(), m_title("None")
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    HTMLButtonElement(unsigned wid, unsigned hei, unsigned hid, const string& title) : HTMLElement(wid, hei, hid), m_title(title)
    {
        cout << __PRETTY_FUNCTION__ << endl;
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
};

class HTMLImageElement: public HTMLElement
{
    string m_url;

public:
    HTMLImageElement() : HTMLElement(), m_url("None")
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    HTMLImageElement(unsigned wid, unsigned hei, unsigned hid, const string& url) : HTMLElement(wid, hei, hid), m_url(url)
    {
        cout << __PRETTY_FUNCTION__ << endl;
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
};

class HTMLTextAreaElement : public HTMLElement
{
    string m_content;

public:

    HTMLTextAreaElement() : HTMLElement(), m_content("None")
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    HTMLTextAreaElement(unsigned wid, unsigned hei, unsigned hid, const string& content) : HTMLElement(wid, hei, hid), m_content(content)
    {
        cout << __PRETTY_FUNCTION__ << endl;
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

};


int main()
{

    HTMLButtonElement* but = new HTMLButtonElement(10, 20, false, "Register");
    HTMLImageElement* img = new HTMLImageElement(50, 50, true, "http://www.pictures.com/picture.jpg");
    HTMLTextAreaElement* txt = new HTMLTextAreaElement(20, 100, false, "Some text");

    cout << but->Title() << endl;
    cout << img->Url() << endl;
    cout << txt->Content() << endl;

    const int arrSize = 3;
    HTMLElement* elems[arrSize] = {but, img, txt};

    for(size_t i = 0; i != arrSize; ++i)
        assert(cout << elems[i]->Render() << endl);

    for(size_t i = 0; i != arrSize; ++i)
        delete elems[i];
    return 0;
}
