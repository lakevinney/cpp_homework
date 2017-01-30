#include <iostream>
#include <cassert>
#include <ctime>

using namespace std;

template<typename T, int N=16>
class stack
{
private:
    T m_data[N];
    int m_last;
public:
    stack() : m_data(), m_last(0) {}

    void push(const T& value)
    {
        m_data[m_last++] = value;
    }

    T pop()
    {
        return m_data[--m_last];
    }
};



template<int N>
class stack<bool, N>
{
private:
    char m_data[N];
    int m_last;
public:
    stack() : m_data(), m_last(0) {}

    void push(const bool& value)
    {
        int num_elem = (m_last) / 8;
        int offset_elem = (m_last) % 8;

        m_data[num_elem] ^= (-value ^ m_data[num_elem]) & (1 << (7 - offset_elem));
        m_last++;
    }

    bool pop()
    {
        int num_elem = (--m_last)/ 8;
        int offset_elem = m_last % 8;
        bool res = 1 & (m_data[num_elem] >> (7-offset_elem));

        return res;
    }
};

int main()
{
    srand(time(NULL));
    const size_t stackSize = 32;
    stack<char, stackSize> ethalon_stack;
    stack<bool, stackSize/8> special_stack;

    bool random_bool;

    for (size_t i=0; i<stackSize; ++i)
    {
        random_bool = rand()%2;
        special_stack.push(random_bool);
        ethalon_stack.push(random_bool);
    }

    cout << "\n\n-----------POPing-----------------\n" << endl;

    for (size_t i=0; i<stackSize; ++i)
    {
        bool bool_value1 = special_stack.pop();
        bool bool_value2 = ethalon_stack.pop();
        cout << bool_value1 << " " << bool_value2 << endl;
        assert(bool_value1 == bool_value2);
    }

    return 0;
}
