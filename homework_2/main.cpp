#include <iostream>
#include <cstring>
#include <string>
#include <cstdio>
#include <ctime>
#include <map>
using namespace std;

//Task 7
const char* cat(char* str1, char* str2)
{
    char* res=new char[strlen(str1) + strlen(str2) + 1];
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

//Task 9
void Encrypt(const char* input, char* output)
{
    char table[]="abcdefghijklmnopqrstuvwxyz0123456789-";
    int shift=5;
    for(unsigned int i=0; i!=strlen(input); i++)
        for(unsigned int j=0; j!=strlen(table); j++)
            if(input[i]==table[j])
                output[i]=table[(j+shift)%strlen(table)];
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

//Task 13
void task13_func()
{
    int* a=new int[50];
    int j=0, i=0, k[50];
    while(j<100)
    {
       a[i]=j+1;
       j+=2;
       i++;
    }

    for(int i=0; i!=50; i++)
        cout<<a[i]<<" ";
    cout<<endl;
    cout<<"============================================"<<endl;
    srand(time(NULL));
    //Trying to randomize output
    //for(int i=0; i!=50; i++)
    //{
      //  k[i]=rand()%50;
        //for(int t=0; t<i; ++t)
          //  if(k[i] == k[t]){i-=1; break;}
    //}
    //for(int i=0; i!=50; ++i)
      //  cout<<a[k[i]]<<" ";
    for(int i=0; i!=50; i++)
    {
        int j=rand()%50;
        int temp=a[i];
        a[i]=a[j];
        a[j]=temp;

    }

    for(int i=0; i!=50; i++)
        cout<<a[i]<<" ";
     cout<<endl;
}

int main()
{
    //======================================================
    //Task 7
    char str1[]="Fabrika ";
    char str2[]="C++";
    const char* catStr = cat(str1,str2);
    cout<<catStr<<endl;
    delete[] catStr;
    cout<<"============================================"<<endl;

    //======================================================
    //Task 8
    char s[100];
    cout<<"Enter the string: ";
    cin>>s;
    count_reps(s);
    cout<<"============================================"<<endl;

    //======================================================
    //Task 9
    char input[24];
    cout<<"Enter the random symbols (a-e, 0-9, -): ";
    cin>>input;
    cout<<endl;
    char output[strlen(input)+1];
    Encrypt(input, output);
    cout<<"Encrypted line: ";
    cout<<output<<endl;
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

    //======================================================
    //Task 13
    task13_func();
    return 0;
}

