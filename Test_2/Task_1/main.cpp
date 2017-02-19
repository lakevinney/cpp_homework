#include <iostream>
#include <algorithm>
#include <cassert>

using namespace std;

template<typename T>
struct range_iterator : public std::iterator<std::forward_iterator_tag, T>
{
    range_iterator()
        : m_value(0), m_step(0)
    {
    }

    range_iterator(const T& value, const T& step)
        : m_value(value), m_step(step)
    {
    }

    range_iterator(const range_iterator&) = default;
    range_iterator(range_iterator&&) = default;
    range_iterator& operator=(const range_iterator&) = default;
    ~range_iterator() = default;

    T& operator*()
    {
        return m_value;
    }

    range_iterator& operator++()
    {
        m_value += m_step;
        return *this;
    }

    range_iterator operator++(int)
    {
        range_iterator tmp(*this);
        ++(*this);
        return tmp;
    }

    bool operator==(const range_iterator& rhs)
    {
        return m_value==rhs.m_value;
    }

    bool operator!=(const range_iterator& rhs)
    {
        return !(*this==rhs);
    }

private:
    T m_value;
    T m_step;
};


template<size_t B, size_t E, size_t S=1>
class Range
{
public:

    typedef range_iterator<size_t> iterator;

    Range() : m_min(B), m_max(E), m_step(S)
    {

    }

    size_t size()
    {
        return ((m_max - m_min) / m_step);
    }

    iterator begin()
    {
        return iterator(m_min, m_step);
    }

    iterator end()
    {
        if(size() <= 1)

            return ++begin();

        else

            return iterator((m_min + size() * m_step), m_step);
    }

    size_t operator[](const size_t& idx)
    {
        return (m_min + idx * m_step);
    }

private:
    size_t m_min;
    size_t m_max;
    size_t m_step;
};

int main()
{
    for (auto& elem : Range<1, 5>())
    {
        cout << elem << " "; // 1 2 3 4
    }

    for (auto& elem : Range<0, 10, 2>())
    {
        cout << elem << " "; //0 2 4 6 8
    }

    for (auto& elem : Range<20, 50, 1000>())
    {
        cout << elem << " "; // 20
    }

    auto r = Range<1,30>();
    cout << count_if(r.begin(), r.end(), [](int e){return e>20;}) << endl; // 9

    assert(*(r.begin()) == 1);
    assert(*(++r.begin()) == 2);
    assert(r[9] == 10);

    auto it = find(r.begin(), r.end(), 30);
    assert(it == r.end());

    return 0;
}

