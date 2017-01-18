#include <iostream>
#include <map>
#include <string>
#include <cassert>

using namespace std;

class RomanNumber
{

public:

    RomanNumber() : m_roman(""), m_numeral(0)
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    RomanNumber(const string& roman) : m_roman(roman), \
        m_numeral(RomanToArabic(roman))
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
        return m_roman;
    }

    const int& GetNumeral() const
    {
        return m_numeral;
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
        int num = m_numeral + rhs.m_numeral;
        RomanNumber tmp(ArabicToRoman(num));
        *this = tmp;

        return *this;
    }

    RomanNumber& operator+=(const int& rhs)
    {
        int num = m_numeral + rhs;
        RomanNumber tmp(ArabicToRoman(num));
        *this = tmp;

        return *this;
    }

    RomanNumber& operator-=(const RomanNumber& rhs)
    {
        int num = m_numeral - rhs.m_numeral;
        RomanNumber tmp(ArabicToRoman(num));
        *this = tmp;

        return *this;
    }

    RomanNumber& operator-=(const int& rhs)
    {
        int num = m_numeral - rhs;
        RomanNumber tmp(ArabicToRoman(num));
        *this = tmp;

        return *this;
    }

    RomanNumber& operator*=(const RomanNumber& rhs)
    {
        int num = m_numeral * rhs.m_numeral;
        RomanNumber tmp(ArabicToRoman(num));
        *this = tmp;

        return *this;
    }

    RomanNumber& operator*=(const int& rhs)
    {
        int num = m_numeral * rhs;
        RomanNumber tmp(ArabicToRoman(num));
        *this = tmp;

        return *this;
    }

    RomanNumber& operator/=(const RomanNumber& rhs)
    {
        int num = m_numeral / rhs.m_numeral;
        RomanNumber tmp(ArabicToRoman(num));
        *this = tmp;

        return *this;
    }

    RomanNumber& operator/=(const int& rhs)
    {
        int num = m_numeral / rhs;
        RomanNumber tmp(ArabicToRoman(num));
        *this = tmp;

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
        if(m_numeral == rhs.m_numeral)

            return true;

        return false;
    }

    bool operator==(const int& rhs)
    {
        if(m_numeral == rhs)

            return true;

        return false;
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

        if(m_numeral < rhs.m_numeral)

            return true;

        return false;
    }

    bool operator<(const int& rhs)
    {
        if(m_numeral < rhs)

            return true;

        return false;
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

    friend ostream& operator<<(ostream& os, const RomanNumber& obj);
    friend istream& operator>>(istream& is, RomanNumber& c);

    operator int() const
    {
        return m_numeral;
    }

private:

    string m_roman;
    int m_numeral;

    int RomanToArabic(const string& rom)
        {
            map<char, int> dConvert = { {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };

            int res = 0;
            int prvs = 0;

            for(auto i = rom.rbegin(); i != rom.rend(); ++i)

               for(auto j = dConvert.begin(); j != dConvert.end(); ++j)

                   if(*i == j->first)
                   {
                      if(j->second >= prvs)
                      {
                        res += j->second;
                        prvs = j->second;
                      }

                      else

                        res -= j->second;
                   }

            return res;
        }

    const string ArabicToRoman(int arabic)
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
    obj.m_numeral = obj.RomanToArabic(obj.m_roman);

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

    RomanNumber r3;
    cin >> r3;
    cout << r3;
    cout << int(r3) << endl;
    return 0;
}

