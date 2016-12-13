#include <iostream>

using namespace std;

void InitArray(int* arr, int size)
{
    for(int i = 0; i < size; i++)
        arr[i] = rand()% 50;
}

void PrintArray(int* arr, int size)
{
    for(int i = 0; i != size; ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}
//------------------------------------------------------------

typedef int (*act_1)(int);

int ByTen(int elem)
{
    return elem * 10;
}

int PlusSelf(int elem)
{
    return elem + elem;
}

int Square(int elem)
{
    return elem * elem;
}

int* Map(act_1 action, int* arr, int size)
{
    for(int i = 0; i < size; i++)
        arr[i] = action(arr[i]);
    return arr;
}

//------------------------------------------------------------

typedef bool (*act_2)(int);

bool IsEven(int elem)
{
    if(elem%2 == 0)
        return true;


    return false;
}

bool IsOdd(int elem)
{
    if(elem%2 != 0)
        return true;


    return false;
}

int* Filter(act_2 action, int* arr, int size, int& newSize)
{
    newSize = 0;
    int count = 0;
    int* newArr = new int[size];
    for(int i = 0; i < size; i++)
        if(action(arr[i]) == true)
        {
            newSize++;
            newArr[count] = arr[i];
            count++;
        }


    return newArr;
}

//------------------------------------------------------------

typedef int (*act_3)(int, int);

int Sum(int first, int second)
{
    return first + second;

}

int SumAndDouble(int first, int second)
{

    return 2 * (first + second);

}

int Reduce(act_3 action, int* arr, int size)
{

    for(int i = 1; i < size; i++)
    {
        arr[0] = action(arr[0], arr[i]);
    }

    return arr[0];
}

int main()
{
    //Testing the Map() function

    typedef int (*act_1)(int);
    int* (*pMap)(act_1, int*, int);
    pMap = Map;
    int arr_1[10];
    InitArray(arr_1, 10);

    cout<<"-------------Source array 1-------------------------"<<endl;
    PrintArray(arr_1, 10);

    cout<<"--------------------ByTen---------------------------"<<endl;
    int* pByTen = pMap(ByTen, arr_1, 10);
    PrintArray(pByTen, 10);

    cout<<"--------------------PlusSelf------------------------"<<endl;
    int* pPlusSelf = pMap(PlusSelf, arr_1, 10);
    PrintArray(pPlusSelf, 10);

    cout<<"--------------------Square--------------------------"<<endl;
    int* pSquare = pMap(Square, arr_1, 10);
    PrintArray(pSquare, 10);

    //Testing the Filter() function

    typedef bool (*act_2)(int);
    int* (*pFilter)(act_2, int*, int, int&);
    pFilter = Filter;
    int newSize;
    int arr_2[10];
    InitArray(arr_2, 10);

    cout<<"\n\n-------------Source array 2---------------------------"<<endl;
    PrintArray(arr_2, 10);

    cout<<"--------------------IsEven------------------------"<<endl;
    int* pEven = pFilter(IsEven, arr_2, 10, newSize);
    PrintArray(pEven, newSize);
    delete[] pEven;

    cout<<"--------------------IsOdd-------------------------"<<endl;
    int* pOdd = pFilter(IsOdd, arr_2, 10, newSize);
    PrintArray(pOdd, newSize);
    delete[] pOdd;

    //Testing the Reduce() function

    typedef int (*act_3)(int, int);
    int (*pReduce)(act_3, int*, int);
    pReduce = Reduce;
    int arr_3[10];
    InitArray(arr_3, 10);

    cout<<"\n\n-------------Source array 3---------------------------"<<endl;
    PrintArray(arr_3, 10);

    cout<<"--------------------Reduced by sum------------------------"<<endl;
    int sum = pReduce(Sum, arr_3, 10);
    cout<<"Reduced array: "<<sum<<endl;

    cout<<"--------------------Reduced by multiply------------------------"<<endl;
    int doubleSum = pReduce(SumAndDouble, arr_3, 10);
    cout<<"Reduced array: "<<doubleSum<<endl;

    return 0;
}

