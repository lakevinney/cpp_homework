#include <iostream>
#include <list>
#include <unordered_map>
#include <cassert>
using namespace std;

template<typename K, typename V>
class LRUCache
{
public:

    typedef list <std::pair<K,V>> cache_list;
    typedef unordered_map<K, typename cache_list::iterator> cache_map;
    LRUCache(size_t max_size) : m_size(max_size)
    {

    }

    void Put(const K& key, const V& value)
    {
        auto it = m_keyMap.find(key);

        if(it != m_keyMap.end())
        {
            m_keyList.erase(it->second);
            m_keyMap.erase(it);
        }

        m_keyList.push_front(make_pair(key,value));
        m_keyMap.insert(make_pair(key,m_keyList.begin()));

        if(m_keyMap.size() > m_size)
        {
            auto last = m_keyList.end();
            last--;
            m_keyMap.erase(last->first);
            m_keyList.pop_back();
        }
    }

    bool Exists(const K& key)
    {
        return m_keyMap.find(key) != m_keyMap.end();
    }

     const V& Get(const K& key)
     {
        if(!Exists(key))

            throw std::range_error("No such value!");

        auto it = m_keyMap.find(key);
        m_keyList.splice(m_keyList.begin(), m_keyList, it->second);
        return it->second->second;
     }

     size_t Size() const
     {
         return m_keyMap.size();
     }

     void Clear()
     {
         while(m_keyList.size() != 0)
         {
             m_keyList.pop_back();
         }

         m_keyMap.clear();
     }

private:

    size_t m_size;
    cache_list m_keyList;
    cache_map m_keyMap;

};

int main()
{
    LRUCache<int, string> cache(3);
    cache.Put(1, "1");
    cache.Put(2, "2");
    cache.Put(3, "3");

    assert(cache.Exists(1) && cache.Exists(2) && cache.Exists(3));
    assert(cache.Get(1) == "1");
    cache.Get(2);
    cache.Get(1);
    cache.Put(4, "4");

    assert(!cache.Exists(3));

    bool exception_thrown = false;
    try
    {
        cache.Get(5);
    }
    catch (exception& ex)
    {
        exception_thrown = true;
    }

    assert(exception_thrown == true);
    cache.Put(5, "5");
    assert(!cache.Exists(2) && cache.Exists(5));

    cache.Clear();
    assert(cache.Size() == 0);

    cache.Put(1, "1");
    assert(cache.Get(1) == "1");
    cout << "PASSED!" << endl;
    return 0;
}

