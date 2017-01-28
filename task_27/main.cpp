#include <iostream>
#include <algorithm>
#include <list>
#include <map>
#include <unordered_set>
#include <fstream>
#include <iterator>
#include <cctype>
using namespace std;

struct TextAnalyzer
{
    vector<string> m_text;
    string m_filename;
    map<string, int> m_countTable;

    TextAnalyzer() : m_filename("")
    {

    }

    TextAnalyzer(const string& filename) : m_filename(filename)
    {
        ifstream file(m_filename);

        if (file.good() && file.is_open())
        {
            string s;
            while(file >> s)
            {
                ToLower(s);
                m_text.push_back(s);
            }
        }

        else

            cout << "ERROR! THE FILE HAS FAILED TO OPEN OR DOESN'T EXIST" << endl;

    }

    TextAnalyzer(const TextAnalyzer& rhs) :
        m_text(rhs.m_text), m_filename(rhs.m_filename), \
        m_countTable(rhs.m_countTable)
    {

    }

    ~TextAnalyzer()
    {

    }


    void PrintText()
    {
        for(auto i = m_text.begin(); i != m_text.end(); ++i)
            cout << *i << endl;
    }

    void PrintTable()
    {
        for(auto i = m_countTable.begin(); i != m_countTable.end(); ++i)

            cout << i->second << ": " << i->first << endl;
    }

    void ToLower(string& word)
    {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    }

    const string Filter(const string& elem)
    {
        string tmp = elem;
        tmp.erase(remove_if(tmp.begin(), tmp.end(), [](const char& c){return !isalpha(c);}), tmp.end());

        return tmp;
    }

    void CountWords()
    {
        static const unordered_set<string> exc = {

            "am",
            "is",
            "are",
            "do",
            "did",
            "does",
            "have",
            "has",
            "had",
            "been",
            "got",
            "i",
            "he",
            "she",
            "it",
            "we",
            "you",
            "they",
            "a",
            "an",
            "the",
            "was",
            "were",
            "what",
            "where",
            "when",
            "that",
            "those",
            "which",
            "their",
            "those",
            "at",
            "as",
            "up",
            "down",
            "on",
            "and",
            "to",
            "not",
            "no",
            "if",
            "but",
            "of",
            "in",
            "was",
            "for",
            "with",
            "be",
            "all",
            "by",
            "from",
            "so",
            "or",
            "them",
            "this",
            "who",
            "whom",
            "would",
            "there",
            "out",
            "my",
            "say",
            "said",
            "now",
            "will",
            "me",
            "one"
        };

        for(auto i = m_text.begin(); i != m_text.end(); ++i)
             {
                auto it = find(exc.begin(), exc.end(), *i);
                if(it == exc.end())

                    ++m_countTable[Filter(*i)];

            }


    }

    template<typename A, typename B>
    multimap<B,A> FlipMap(const map<A,B> &src)
    {
        multimap<B,A> flipped;
        transform(src.begin(), src.end(), inserter(flipped, flipped.begin()),
                  [](const pair<A,B> &p) {return pair<B,A>(p.second, p.first);});
        return flipped;
    }

    void WordsChart(const size_t& n)
    {
        multimap<int, string> sorted = FlipMap(m_countTable);

        if(n <= sorted.size())
        {
            auto it = sorted.rbegin();
            for(size_t i  = 0; i != n; ++i)
            {
                cout << it->first << ": " << it->second << endl;
                ++it;
            }

        }

    }

};



int main()
{
    TextAnalyzer t("/home/evgeniy/Downloads/war-and-peace.txt");
    t.CountWords();
//    t.PrintTable();
    t.WordsChart(/*t.m_countTable.size()*/10);
    return 0;
}


