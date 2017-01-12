#include <iostream>
#include <cstring>
#include <cassert>

using namespace std;

class String
{
    char* m_buffer;
    size_t* m_refCounter;

public:
    String()
        : m_buffer(nullptr)
        ,m_refCounter(new size_t(0))
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    String(const char* value)
        : m_buffer(new char[strlen(value)+1])
        , m_refCounter(new size_t(0))
    {
        cout << __PRETTY_FUNCTION__ << endl;
        strcpy(m_buffer, value);
        (*m_refCounter)++;
    }

    String(const String& rhs)
        : m_buffer(rhs.m_buffer)
        , m_refCounter(rhs.m_refCounter)
    {
        cout << __PRETTY_FUNCTION__ << endl;
        (*m_refCounter)++;
    }

    size_t GetCount() const
    {
        return *m_refCounter;
    }

    const size_t* GetCounterAddr() const
    {
        return m_refCounter;
    }

    const char* GetBuffer() const
    {
        return m_buffer;
    }

    String& operator=(const String& rhs)
    {

//       cout << __PRETTY_FUNCTION__ << endl;

       if (&rhs != this)
       {
           String tmp(rhs);
           swap(tmp);
       }

       return *this;
    }

    void swap(String& src)
    {
        std::swap(src.m_buffer, m_buffer);
        std::swap(src.m_refCounter, m_refCounter);
    }

    String& operator=(const char* value)
    {
        if(strcmp(m_buffer, value) != 0)
        {
            String tmp(value);
            swap(tmp);
        }

        return *this;
    }

    String& operator+=(const String& obj)
    {
        char* tmpBuffer = new char[strlen(m_buffer) + strlen(obj.m_buffer) + 1];
        strcpy(tmpBuffer, m_buffer);
        strcat(tmpBuffer, obj.m_buffer);

        String tmp(tmpBuffer);

        *this = tmp;
        delete[] tmpBuffer;

        return *this;
    }

    const char& operator[](size_t idx)const
    {
        return m_buffer[idx];
    }

    void SetElem(size_t idx, const char& c)
    {
       if(idx < strlen(m_buffer))
       {
           char* tmpBuffer = new char[strlen(m_buffer) + 1];
           strcpy(tmpBuffer, m_buffer);
           String tmp(tmpBuffer);
           tmp.m_buffer[idx] = c;

           *this = tmp;
           delete[] tmpBuffer;
//           String tmp(*this);
//           tmp.m_buffer[idx] = c;
//           *this = tmp;
       }
    }

    ~String()
    {
        cout << __PRETTY_FUNCTION__ << endl;

        (*m_refCounter)--;

        if(*m_refCounter == 0)
        {
            if (m_buffer)
            {
                delete[] m_buffer;
                m_buffer = nullptr;
            }
        }
    }

};

String operator+(const String& lhs, const String& rhs)
{
    String tmp(lhs);
    tmp += rhs;

    return tmp;
}

int main()
{

    String s1("abc");
//    cout << s1.GetBuffer() << endl;
    assert(s1.GetCount()==1);

    {
        String s2 = s1;        
//        cout << s2.GetBuffer() << endl;
        assert(s1.GetCount()==2);
        assert(s2.GetCount()==2);
        s2 = "ABC";

        assert(s1.GetCount()==1);
        assert(s2.GetCount()==1);

        cout << s2.GetBuffer() << endl;
        assert(s1.GetCounterAddr() != s2.GetCounterAddr());
    }

    assert(s1.GetCount()==1);

    String s3 = "def";    
    s3.SetElem(0, 'e');
    cout << s3.GetBuffer() << endl;
    assert(s1.GetCount()==1 && s3.GetCount()==1);

    s1 += s3;
    assert(s1.GetCount()==1 && s3.GetCount()==1);

    {
        String s4 = s1;
        assert(s1.GetCounterAddr() == s4.GetCounterAddr());

        s4.SetElem(0, 'x');
        assert(strcmp(s1.GetBuffer(), "abceef")==0);
        assert(s4.GetCount() == 1);
        assert(s1.GetCount() == 1);

        String s5;
        s5 = s3 + s4;
        cout << s5.GetBuffer() << endl;

    }

    assert(s1.GetCount()==1);
//    cout << s1.GetBuffer() << endl;



    cout << "Success!" << endl;
    return 0;
}
