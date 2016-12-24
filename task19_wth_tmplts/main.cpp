#include <iostream>

using namespace std;

template<typename T>
void PrintArray(T* arr, size_t size)
{

    cout << __PRETTY_FUNCTION__ << endl;
    for(size_t i = 0; i != size; ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
    cout << "-------------------------------------------------------------" << endl;
}

//-------------------------Map--------------------------------------

template<typename T>
void Map(T (*pFunc)(T&, T&), T* arr, size_t size)
{
    cout << __PRETTY_FUNCTION__ << endl;

    for(size_t i = 1; i != size; ++i)
        arr[i] = pFunc(arr[0], arr[i]);
}

template<typename T>
void Map(T& data, size_t size)
{
    cout << __PRETTY_FUNCTION__ << endl;

    for(size_t i = 0; i != size; ++i)
        data[i] = toupper(data[i]);
}

template<>
void Map<string>(string& data, size_t size)
{
    cout << __PRETTY_FUNCTION__ << endl;

    for(size_t i = 0; i != size; ++i)
        data[i] = toupper(data[i]);
}

template<typename T>
T Sum(T& lhs, T& rhs)
{
   return lhs + rhs;
}

template<typename T>
T Mult(T& lhs, T& rhs)
{
   return lhs * rhs;
}

//-------------------------Filter--------------------------------------

template<typename T>
T* Filter(bool (*pFunc)(T&, T&), T* arr, int size, int& newSize)
{
    cout << __PRETTY_FUNCTION__ << endl;

    newSize = 0;
    T* newArr = new T[size];
    for(int i = 0; i < size; i++)
        if(pFunc(arr[i], arr[size/2]) == true)
        {
            newArr[newSize] = arr[i];
            newSize++;
        }


    return newArr;
}

template<typename T>
bool GreaterThan(T& lhs, T& rhs)
{
    return lhs > rhs;
}

template<typename T>
bool LessOrEq(T& lhs, T& rhs)
{
    return !GreaterThan(lhs, rhs);
}

//-------------------------Reduce--------------------------------------

template<typename T>
T Reduce(T (*pFunc)(T&, T&), T* arr, size_t size)
{
    cout << __PRETTY_FUNCTION__ << endl;
    for(size_t i = 1; i < size; i++)
    {
        arr[0] = pFunc(arr[0], arr[i]);
    }

    return arr[0];
}

#define ARRAY_SIZE(a) (sizeof(a)/sizeof(a[0]))

int main()
{
    float a1[] = {0.1, -0.2, -0.3, 0.4, -0.5, 0.6, 0.7, 0.8, -0.9, 1.0};
    int a2[] = {3, 14, 15, 92, 6, 53, 58, 97, 93, 99};
    string a3 = "Fabrika C++ course";

    //using namespace print_arr;

    PrintArray<float>(a1, ARRAY_SIZE(a1));
    PrintArray<int>(a2, ARRAY_SIZE(a2));
    cout << a3 << endl;
    cout << "-------------------------------------------------------------" << endl;

    //using namespace map;

    Map<float>(Sum, a1, ARRAY_SIZE(a1));
    PrintArray(a1, ARRAY_SIZE(a1));

    Map<int>(Sum, a2, ARRAY_SIZE(a2));
    PrintArray(a2, ARRAY_SIZE(a2));

    Map<float>(Mult, a1, ARRAY_SIZE(a1));
    PrintArray(a1, ARRAY_SIZE(a1));

    Map<int>(Mult, a2, ARRAY_SIZE(a2));
    PrintArray(a2, ARRAY_SIZE(a2));

    Map<string>(a3, a3.length());
    cout << a3 << endl;
    cout << "-------------------------------------------------------------" << endl;

    string a = "Bjarne";
    string b = " Stroustrup";
    string c;

    c = Sum(a, b);
    cout << c << endl;

    //using namespace filter;

    int newSize;

    int* p1 = Filter<int>(GreaterThan, a2, ARRAY_SIZE(a2), newSize);
    PrintArray(p1, newSize);
    delete[] p1;

    int* p2 = Filter<int>(LessOrEq, a2, ARRAY_SIZE(a2), newSize);
    PrintArray(p2, newSize);
    delete[] p2;

    float* p3 = Filter<float>(GreaterThan, a1, ARRAY_SIZE(a1), newSize);
    PrintArray(p3, newSize);
    delete[] p3;

    float* p4 = Filter<float>(LessOrEq, a1, ARRAY_SIZE(a1), newSize);
    PrintArray(p4, newSize);
    delete[] p4;

    cout << Reduce<float>(Sum, a1, ARRAY_SIZE(a1)) << endl;
    cout << Reduce<int>(Sum, a2, ARRAY_SIZE(a2)) << endl;

    return 0;
}

