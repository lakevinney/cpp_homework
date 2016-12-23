#include <iostream>
#define _USE_MATH_DEFINES

#include <math.h>

using namespace std;

//--------------------------------------------------------
class Shape
{

protected:

    float m_x;
    float m_y;

public:

    Shape() : m_x(0), m_y(0)
    {
        cout << __PRETTY_FUNCTION__ << endl;

    }

    Shape(float x, float y) :  m_x(x), m_y(y)
    {

        cout << __PRETTY_FUNCTION__ << endl;
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
    Rectangle() : Shape(), m_width(0), m_height(0)
    {
        cout << __PRETTY_FUNCTION__ << endl;

    }

    Rectangle(float x, float y, \
              float width, float height) : \
        Shape(x, y), m_width(width), m_height(height)
    {
        cout << __PRETTY_FUNCTION__ << endl;

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
    Triangle() : Shape(), m_sideA(0), m_sideB(0), m_sideC(0)
    {
        cout << __PRETTY_FUNCTION__ << endl;

    }

    Triangle(float x, float y, \
             float a, float b, float c) : \
        Shape(x, y), m_sideA(a), m_sideB(b), m_sideC(c)
    {
        cout << __PRETTY_FUNCTION__ << endl;

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
    Circle() : Shape(), m_radius(0)
    {
        cout << __PRETTY_FUNCTION__ << endl;

    }

    Circle(float x, float y, float r) : Shape(x, y)
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
    Rectangle* pRectObj = new Rectangle(1, 1, 10, 15);
    Triangle* pTriObj = new Triangle(2, 2, 3, 4, 5);
    Circle* pCircObj = new Circle(0, 0, 3.14);


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

