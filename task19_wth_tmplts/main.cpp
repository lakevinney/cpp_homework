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
void Map(T (*pFunc)(const T&), T* arr, size_t size)
{
    cout << __PRETTY_FUNCTION__ << endl;

    for(size_t i = 0; i != size; ++i)
        arr[i] = pFunc(arr[i]);
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
T Sum(const T& lhs, const T& rhs)
{
   return lhs + rhs;
}

//template<typename T>
int ByTen(const int& elem)
{
    return elem * 10;
}

float ByTen(const float& elem)
{
    return elem * 10;
}

//template<typename T>
int PlusSelf(const int& elem)
{
    return elem + elem;
}

//template<typename T>
float Square(const float& elem)
{
    return elem * elem;
}
//-------------------------Filter--------------------------------------

template<typename T>
T* Filter(bool (*pFunc)(const T&), T* arr, int size, int& newSize)
{
    cout << __PRETTY_FUNCTION__ << endl;

    newSize = 0;
    T* newArr = new T[size];
    for(int i = 0; i < size; i++)
        if(pFunc(arr[i]))
        {
            newArr[newSize] = arr[i];
            newSize++;
        }


    return newArr;
}

template<typename T>
bool IsPositive(const T& value)
{
    return value > 0;
}

template<typename T>
bool IsNegative(const T& value)
{
    return value < 0;
}

//-------------------------Reduce--------------------------------------

template<typename T>
T Reduce(T (*pFunc)(const T&, const T&), T* arr, size_t size)
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

//    Map<float>(PlusSelf, a1, ARRAY_SIZE(a1));
//    PrintArray(a1, ARRAY_SIZE(a1));

    Map<int>(ByTen, a2, ARRAY_SIZE(a2));
    PrintArray(a2, ARRAY_SIZE(a2));

    Map<float>(Square, a1, ARRAY_SIZE(a1));
    PrintArray(a1, ARRAY_SIZE(a1));

    Map<int>(PlusSelf, a2, ARRAY_SIZE(a2));
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

    int* p1 = Filter<int>(IsPositive, a2, ARRAY_SIZE(a2), newSize);
    PrintArray(p1, newSize);
    delete[] p1;

    int* p2 = Filter<int>(IsNegative, a2, ARRAY_SIZE(a2), newSize);
    PrintArray(p2, newSize);
    delete[] p2;

    float* p3 = Filter<float>(IsPositive, a1, ARRAY_SIZE(a1), newSize);
    PrintArray(p3, newSize);
    delete[] p3;

    float* p4 = Filter<float>(IsNegative, a1, ARRAY_SIZE(a1), newSize);
    PrintArray(p4, newSize);
    delete[] p4;

    cout << Reduce<float>(Sum, a1, ARRAY_SIZE(a1)) << endl;
    cout << Reduce<int>(Sum, a2, ARRAY_SIZE(a2)) << endl;

    return 0;
}

