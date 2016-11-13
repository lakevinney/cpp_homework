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
    return 0;
}

