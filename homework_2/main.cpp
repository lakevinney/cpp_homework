#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

//Task 7
const char* cat(char* str1, char* str2)
{
    char* res=new char[20];
    for(unsigned int i=0; i!=strlen(str1); ++i)
        res[i]=str1[i];
    for(unsigned int i=0; i!=strlen(str2); ++i)
        res[i+strlen(str1)]=str2[i];
    return res;
    //delete res;
}

//Task 8
void count_reps(char* str)
{
    map <char,int> characters;
    map <char,int>::iterator begin, at, end;

    for(unsigned int i=0; i<strlen(str); i++)
        characters[str[i]]++;

    begin = characters.begin();
    end  = characters.end();
    for(at = begin; at != end; at++)
        cout << at->first << '\t'<< at->second << endl;
}

//Task 10
void lower_to_upper(string s)
{
    for(int i=0; i!=s.length(); i++)
            if((i==0) || (s[i-1]==' '))
            s[i]=toupper(s[i]);

    cout<<s<<endl;
}

//Task 11
void remove_char(string s)
{
    for(int i=0; i!=s.length(); i++)
            if((i==0) || (s[i-1]==' '))
            s.erase(i,1);

    cout<<s<<endl;
}

//Task 12
int* swap_values(int* arr, int size)
{
    for (int i=0; i!=size; i+=2)
     {
     int temp = arr[i];
     arr[i] = arr[i+1];
     arr[i+1] = temp;
     }

    return arr;
}

int main()
{
    //======================================================
    //Task 7
    char str1[]="Fabrika ";
    char str2[]="C++";
    cout<<cat(str1,str2)<<endl;
    cout<<"============================================"<<endl;

    //======================================================
    //Task 8
    char s[100];
    cout<<"Enter the string: ";
    cin>>s;
    count_reps(s);
    cout<<"============================================"<<endl;

    //======================================================
    //Task 10
    string line="fabrika c++ course";
    lower_to_upper(line);
    cout<<"============================================"<<endl;

    //======================================================
    //Task 11
    remove_char(line);
    cout<<"============================================"<<endl;

    //======================================================
    //Task 12
    int N=12;
    int* arr=new int[N];
    for(int i=0; i!=N; ++i)
    {
        arr[i]=i+1;
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    int* new_arr=swap_values(arr,N);
    for(int i=0; i!=N; ++i)
        cout<<new_arr[i]<<" ";
    cout<<endl;
    delete arr;
    cout<<"============================================"<<endl;

    return 0;
}

