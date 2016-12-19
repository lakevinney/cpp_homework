#include <iostream>
#define _USE_MATH_DEFINES

#include <math.h>

using namespace std;

//--------------------------------------------------------
class Shape
{

public:
    float m_x;
    float m_y;

    Shape()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        m_x = 0;
        m_y = 0;
    }

    virtual ~Shape()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    virtual float Square() = 0;

};

//--------------------------------------------------------
class Rectangle : public Shape
{
    float m_width;
    float m_height;

public:
    Rectangle()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        m_width = 0;
        m_height = 0;

    }

    Rectangle(const float width, const float height)
    {
        cout << __PRETTY_FUNCTION__ << endl;
        m_width = width;
        m_height = height;
    }

    ~Rectangle()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    float Square() override
    {
        return m_width * m_height;
    }


};

//--------------------------------------------------------
class Triangle : public Shape
{
    float m_sideA;
    float m_sideB;
    float m_sideC;

public:
    Triangle()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        m_sideA = 0;
        m_sideB = 0;
        m_sideC = 0;

    }

    Triangle(const float a, const float b, const float c)
    {
        cout << __PRETTY_FUNCTION__ << endl;
        m_sideA = a;
        m_sideB = b;
        m_sideC = c;
    }

    ~Triangle()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    float Square() override
    {
        float p = 0.5 * (m_sideA + m_sideB + m_sideC);
        return sqrt(p * (p - m_sideA) * (p - m_sideB) * (p - m_sideC));
    }

};

//--------------------------------------------------------
class Circle : public Shape
{
    float m_radius;

public:
    Circle()
    {
        cout << __PRETTY_FUNCTION__ << endl;
        m_radius = 0;

    }

    Circle(const float r)
    {
        cout << __PRETTY_FUNCTION__ << endl;
        m_radius = r;
    }

    ~Circle()
    {
        cout << __PRETTY_FUNCTION__ << endl;
    }

    float Square() override
    {
        return M_PI * pow(m_radius, 2);
    }


};

//--------------------------------------------------------
int main()
{
    Rectangle* pRectObj = new Rectangle(10, 15);
    Triangle* pTriObj = new Triangle(3, 4, 5);
    Circle* pCircObj = new Circle(3.14);

    const int arrSize = 3;
    float sumOfSq = 0;
    Shape* pArrOfObj[arrSize] = {pRectObj, pTriObj, pCircObj};

    cout << "Squares of the objects:"<< endl;
    for(size_t i = 0; i != arrSize; i++)
    {
        cout << pArrOfObj[i]->Square() << endl;
        sumOfSq += pArrOfObj[i]->Square();
    }

    cout << "Combined area: " << sumOfSq << endl;

    for(size_t i = 0; i != arrSize; i++)
        delete pArrOfObj[i];

    return 0;
}

