#include <iostream>
#include <cstring>
using namespace std;

//Task 7
const char* cat(char* str1, char* str2)
{
    char* res=new char[20];
    for(int i=0; i!=strlen(str1); ++i)
        res[i]=str1[i];
    for(int i=0; i!=strlen(str2); ++i)
        res[i+strlen(str1)]=str2[i];
    return res;
    //delete res;
}

int main()
{
    //======================================================
    //Task 7
    char str1[]="Fabrika ";
    char str2[]="C++";
    cout<<cat(str1,str2)<<endl;
    cout<<"============================================"<<endl;
    return 0;
}

