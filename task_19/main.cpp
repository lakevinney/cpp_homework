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

typedef bool (*act_2)(int, int&);

bool FilterEven(int elem, int& count)
{
    if(elem%2 == 0)
    {
        count++;
        return true;
    }

    return false;
}

bool FilterOdd(int elem, int& count)
{
    if(elem%2 != 0)
    {
        count++;
        return true;
    }

    return false;
}

int* Filter(act_2 action, int* arr, int size, int& newSize)
{
    newSize = 0;
    int count = 0;
    int* newArr = new int[size];
    for(int i = 0; i < size; i++)
        if(action(arr[i], newSize) == true)
        {
            newArr[count] = arr[i];
            count++;
        }


    return newArr;
}

//------------------------------------------------------------

typedef int (*act_3)(int*, int);

int RdcSum(int* arr, int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
        arr[0] = sum;
    }

    return arr[0];
}

int RdcMult(int* arr, int size)
{
    int mult = 1;
    for(int i = 0; i < size; i++)
    {
        mult *= arr[i];
        arr[0] = mult;
    }

    return arr[0];
}

int Reduce(act_3 action, int* arr, int size)
{
    return action(arr, size);
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

    typedef bool (*act_2)(int, int&);
    int* (*pFilter)(act_2, int*, int, int&);
    pFilter = Filter;
    int newSize;
    int arr_2[10];
    InitArray(arr_2, 10);

    cout<<"\n\n-------------Source array 2---------------------------"<<endl;
    PrintArray(arr_2, 10);

    cout<<"--------------------FilterEven------------------------"<<endl;
    int* pEven = pFilter(FilterEven, arr_2, 10, newSize);
    PrintArray(pEven, newSize);
    delete[] pEven;

    cout<<"--------------------FilterOdd-------------------------"<<endl;
    int* pOdd = pFilter(FilterOdd, arr_2, 10, newSize);
    PrintArray(pOdd, newSize);
    delete[] pOdd;

    //Testing the Reduce() function

    typedef int (*act_3)(int*, int);
    int (*pReduce)(act_3, int*, int);
    pReduce = Reduce;
    int arr_3[10];
    InitArray(arr_3, 10);

    cout<<"\n\n-------------Source array 3---------------------------"<<endl;
    PrintArray(arr_3, 10);

    cout<<"--------------------Reduced by sum------------------------"<<endl;
    cout<<"Reduced array: "<<pReduce(RdcSum, arr_3, 10)<<endl;

    cout<<"--------------------Reduced by multiply------------------------"<<endl;
    cout<<"Reduced array: "<<pReduce(RdcMult, arr_3, 10)<<endl;

    return 0;
}

