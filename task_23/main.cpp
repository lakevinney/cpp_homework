#include <iostream>
#include <map>
#include <string>
#include <cassert>
#include <algorithm>
using namespace std;

class RomanNumber
{

public:

    RomanNumber() : m_roman(""), m_numeral(0), m_synchronized(true)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    RomanNumber(const string& roman) : m_roman(roman), \
        m_numeral(ToArabic(roman)), m_synchronized(true)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    RomanNumber(const RomanNumber& obj) : m_roman(obj.m_roman), m_numeral(obj.m_numeral)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    ~RomanNumber()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    const string& GetRoman() const
    {
        if(!IsSync())
        {
            m_roman = ToRoman(m_numeral);
            m_synchronized = true;
        }

        return m_roman;
    }

    const int& GetNumeral() const
    {
        return m_numeral;
    }

    static const string ToRoman(int arabic)
    {

        struct uConvert { int value; char const* numeral; };
        static uConvert const convMap[] =
         { 1000, "M",
            900, "CM",
            500, "D",
            400, "CD",
            100, "C",
             90, "XC",
             50, "L",
             40, "XL",
             10, "X",
              9, "IX",
              5, "V",
              4, "IV",
              1, "I",
              0, NULL };

        string res;
        for (uConvert const* current = convMap; current->value > 0; ++current)

          while (arabic >= current->value)
          {
              res += current->numeral;
              arabic  -= current->value;
          }

        return res;
    }

    static int ToArabic(const string& rom)
    {
        static const map<char, int> dConvert = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };

        int res = 0;
        int prvs = 0;

        for(auto i = rom.rbegin(); i != rom.rend(); ++i)
        {
            auto j = dConvert.find(*i);
            if(j != dConvert.end())
            {
                if(j->second >= prvs)
                  {
                    res += j->second;
                    prvs = j->second;
                  }

                  else

                    res -= j->second;
            }
        }

        return res;
    }

    RomanNumber& operator=(const RomanNumber& rhs)
    {
        if (&rhs != this)
        {
            RomanNumber tmp(rhs);
            swap(tmp);
        }

        return *this;
    }

    RomanNumber& operator=(const string& rhs)
    {
        if(rhs != m_roman)
        {
            RomanNumber tmp(rhs);
            swap(tmp);
        }

        return *this;
    }

    void swap(RomanNumber& src)
    {
        std::swap(src.m_roman, m_roman);
        std::swap(src.m_numeral, m_numeral);
    }

    RomanNumber& operator+=(const RomanNumber& rhs)
    {
        m_synchronized = false;
        return (*this += rhs.m_numeral);
    }

    RomanNumber& operator+=(const int& rhs)
    {
        m_numeral += rhs;
        m_synchronized = false;

        return *this;
    }

    RomanNumber& operator-=(const RomanNumber& rhs)
    {
        m_synchronized = false;
        return (*this -= rhs.m_numeral);
    }

    RomanNumber& operator-=(const int& rhs)
    {
        m_numeral -= rhs;
        m_synchronized = false;

        return *this;
    }

    RomanNumber& operator*=(const RomanNumber& rhs)
    {
        m_synchronized = false;
        return (*this *= rhs.m_numeral);
    }

    RomanNumber& operator*=(const int& rhs)
    {
        m_numeral *= rhs;
        m_synchronized = false;

        return *this;
    }

    RomanNumber& operator/=(const RomanNumber& rhs)
    {
        m_synchronized = false;
        return (*this /= rhs.m_numeral);
    }

    RomanNumber& operator/=(const int& rhs)
    {
        m_numeral /= rhs;
        m_synchronized = false;

        return *this;
    }

    //This works with IV +(*) 10
    RomanNumber operator+(const RomanNumber& rhs)
    {
        return RomanNumber(*this) += rhs;
    }

    RomanNumber operator+(const int& rhs)
    {
        return RomanNumber(*this) += rhs;
    }

    RomanNumber operator*(const RomanNumber& rhs)
    {
        return RomanNumber(*this) *= rhs;
    }

    RomanNumber operator*(const int& rhs)
    {
        return RomanNumber(*this) *= rhs;
    }

    //---------------------------------------

    bool operator==(const RomanNumber& rhs)
    {
        return m_numeral == rhs.m_numeral;
    }

    bool operator==(const int& rhs)
    {
        return m_numeral == rhs;
    }

    bool operator!=(const RomanNumber& rhs)
    {
        return !(*this == rhs);
    }

    bool operator!=(const int& rhs)
    {
        return !(*this == rhs);
    }

    bool operator<(const RomanNumber& rhs)
    {
        return m_numeral < rhs.m_numeral;
    }

    bool operator<(const int& rhs)
    {
        return m_numeral < rhs;
    }

    bool operator<=(const RomanNumber& rhs)
    {
        return (*this < rhs || *this == rhs);
    }

    bool operator<=(const int& rhs)
    {
        return (*this < rhs || *this == rhs);
    }

    bool operator>(const RomanNumber& rhs)
    {
        return !(*this < rhs);
    }

    bool operator>(const int& rhs)
    {
        return !(*this < rhs);
    }

    bool operator>=(const RomanNumber& rhs)
    {
        return !(*this <= rhs);
    }

    bool operator>=(const int& rhs)
    {
        return !(*this <= rhs);
    }

    RomanNumber& operator++()
    {
        *this += 1;

        return *this;
    }

    RomanNumber& operator--()
    {
        *this -= 1;

        return *this;
    }

    RomanNumber operator++(int)
    {
        RomanNumber old(*this);
        ++*this;

        return old;
    }

    RomanNumber operator--(int)
    {
        RomanNumber old(*this);
        --*this;

        return old;
    }

    friend ostream& operator<<(ostream& os, const RomanNumber&);
    friend istream& operator>>(istream& is, RomanNumber&);

    explicit operator int() const
    {
        return m_numeral;
    }

private:

    mutable string m_roman;
    int m_numeral;
    mutable bool m_synchronized;

    const bool& IsSync() const
    {
        return m_synchronized;
    }

};

//RomanNumber operator+(const RomanNumber& lhs, const RomanNumber& rhs)
//{
//    RomanNumber tmp(lhs);
//    tmp += rhs;

//    return tmp;
//}

//RomanNumber operator-(const RomanNumber& lhs, const RomanNumber& rhs)
//{
//    RomanNumber tmp(lhs);
//    tmp -= rhs;

//    return tmp;
//}

//RomanNumber operator*(const RomanNumber& lhs, const RomanNumber& rhs)
//{
//    RomanNumber tmp(lhs);
//    tmp *= rhs;

//    return tmp;
//}

//RomanNumber operator/(const RomanNumber& lhs, const RomanNumber& rhs)
//{
//    RomanNumber tmp(lhs);
//    tmp /= rhs;

//    return tmp;
//}

ostream& operator<<(ostream& os, const RomanNumber& obj)
{
    os << obj.GetRoman() << ": " << obj.GetNumeral() << endl;

    return os;
}

istream& operator>>(istream &is, RomanNumber& obj)
{
    is >> obj.m_roman;
    std::transform(obj.m_roman.begin(), obj.m_roman.end(), obj.m_roman.begin(), ::toupper);
    obj.m_numeral = obj.ToArabic(obj.m_roman);

    return is;
}

int main()
{    
    RomanNumber r1 = RomanNumber("MDIL"); //1549
    RomanNumber r2 ("MCDXLIX"); //1449

    assert(r1 == 1549);
    assert(r1+1 == 1550);
    assert(r1+r2 >= r2);
    assert(r2+r2 == r2*2);
    assert(r1 >  r2);
    assert(r1 != r2);

    r1 -= r2;
    cout << r1;
//    RomanNumber r3;
//    cin >> r3;
//    cout << r3;
//    cout << int(r3) << endl;


    return 0;
}

