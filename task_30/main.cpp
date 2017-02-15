#include <iostream>
#include <array>
#include <cassert>
#include <vector>
#include <memory>
#include <thread>
#include <condition_variable>
#include <cstddef>
#include <mutex>
#include <chrono>
#include <ostream>
#include <sstream>

using namespace std;

template<typename T, size_t N>
class RingBuffer
{
    array<T, N> m_data;
    std::mutex m_lock;
    std::condition_variable m_cond;

    typedef unsigned long long tSize;

    unsigned long long m_start = 0;
    unsigned long long m_end = 0;

    bool empty_unsafe()
    {
        return (m_start == m_end);
    }

    bool full_unsafe()
    {
        return (N == m_start - m_end);
    }

public:

    size_t size() const
    {
        return N;
    }

    size_t count() const
    {
        return m_start - m_end;
    }

    bool empty() const
    {
        lock_guard<mutex> lock(m_lock);

        return empty_unsafe();
    }

    bool full() const
    {
        lock_guard<mutex> lock(m_lock);

        return full_unsafe();
    }

    void push_back(const T& elem)
    {
        unique_lock<mutex> lock{m_lock};

        while(full_unsafe())
        {
            m_cond.wait(lock);
        }

        tSize start = m_start%N;
        m_data[start] = elem;
        ++m_start;

        m_cond.notify_one();
    }

    T& front()
    {
        unique_lock<mutex> lock{m_lock};

        while (empty_unsafe())
        {
            m_cond.wait(lock);
        }

        return m_data[m_end%N];
    } 

    void pop_front()
    {
        unique_lock<mutex> lock(m_lock);

        if (!empty_unsafe())
        {
            ++m_end;
            m_cond.notify_one();
        }

    }



};


int main()
{
    const size_t N = 10;
    RingBuffer<int, N> ringBuffer;

    thread th1 {[&]()
    {
         int counter = 40;

         while(counter)
         {
             ringBuffer.push_back(--counter);
             cout << "Pushing ->" << counter << endl;
         }
    }
    };

    thread th2 {[&]()
    {
        int val;
        while(val)
        {
            val = ringBuffer.front();
            ringBuffer.pop_front();
            cout << "Popping <-" << val << endl;
            std::chrono::milliseconds timeout(80);
            std::this_thread::sleep_for(timeout);
        }
    }
    };

    th1.join();
    th2.join();

    return 0;

}
