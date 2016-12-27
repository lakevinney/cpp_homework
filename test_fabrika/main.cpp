#include <iostream>
#include <cassert>
using namespace std;

//-----------------------------Task--1-----------------------------------------------

template<class T>
class ImmutableBuffer
{

private:
    T* m_array;
    size_t m_size;

    ImmutableBuffer& operator=(const ImmutableBuffer& rhs)
    {
        m_array = rhs.m_array;
        m_size = rhs.m_size;
        return *this;
    }

public:
    ImmutableBuffer(): m_array(NULL), m_size(0)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ImmutableBuffer(const T* arr, size_t size): m_size(size)
    {
        cout << __PRETTY_FUNCTION__ << endl;
        m_array = new T[m_size];
        for(size_t i = 0; i != m_size; ++i)
            m_array[i] = arr[i];
    }


    ImmutableBuffer(const ImmutableBuffer& obj)
    {
        cout << __PRETTY_FUNCTION__ << endl;
        m_array = obj.m_array;
        m_size = obj.m_size;
    }

    ~ImmutableBuffer()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        if(m_array)
        {
            delete[] m_array;
            m_array = nullptr;
        }
    }

   template<typename U>
   friend ostream& operator<<(ostream& os, const ImmutableBuffer<U>& buf);

   const T& operator[](size_t idx)
   {
       return  m_array[idx];
   }

   bool operator==(const ImmutableBuffer& rhs) const
   {
       for(size_t i = 0; i != this->m_size; ++i)
           if(this->m_array[i] == rhs.m_array[i])
               return true;

       return false;
   }

    bool operator!=(const ImmutableBuffer& rhs) const
    {
        return !(operator ==(rhs));
    }
};

template<class T>
ostream& operator<<(ostream &os, const ImmutableBuffer<T>& buf)
{
    for(size_t i = 0; i != buf.m_size; ++i)
    {
        os << buf.m_array[i] << " ";

    }

    return os;
}

#define ARR_SIZE(a) (sizeof(a)/sizeof(a[0]))
int main(int argc, char *argv[])
{
    double arr[] = {1.0, 2.0, 3.0};
    ImmutableBuffer<double> buff(arr, ARR_SIZE(arr));
    ImmutableBuffer<double> buff2 = buff;
    arr[0] = 0;

    cout << buff << endl;
    assert(buff == buff2);

    //buff[0] = 42.0;
    //c = b;
    return 0;
}
