#include <iostream>
#include <cstring>
#include <time.h>

using namespace std;

//=============================================Task18===========================================
struct professor{
    char name[20];
    unsigned short age;
    unsigned int salary;
};


struct student{
    char name[20];
    unsigned short age;
    float gpa;
    professor* supervisor;
};



void prof_init(professor*& pr, int num)
{
    for(int i=0; i!=num; ++i)
    {
        cout<<i+1<<".----------"<<endl;
        cout<<"name: ";
        cin>>pr[i].name;
        cout<<"age: ";
        cin>>pr[i].age;
        cout<<"salary: ";
        cin>>pr[i].salary;
        cout<<endl;
    }
}

void struct_init(student*& st, professor*& pr, int num)
{
    for(int i=0; i!=num; ++i)
    {
        cout<<"Student "<<i+1<<endl;
        cout<<"name: ";
        cin>>st[i].name;
        cout<<"age: ";
        cin>>st[i].age;
        cout<<"gpa: ";
        srand(time(NULL));
        cin>>st[i].gpa;
        st[i].supervisor=&pr[rand()% 3];
        cout<<"supervisor: "<<st[i].supervisor->name<<endl;
       cout<<"-----------------------------"<<endl;
    }
}

float average_gpa(student*& st, int num)
{
    float sum_gpa=0;
    for(int i=0; i!=num; ++i)
        sum_gpa+=st[i].gpa;

    return sum_gpa/float(num);
}

void bestscore(student*& st, int num)
{
    float max=0;
    char* name;
    for(int i=0; i!=num; i++)
        if(st[i].gpa > max)
        {
            max=st[i].gpa;
            name=st[i].name;
        }

    cout<<"Student with the best score: ";
    for(int i=0; i!=strlen(name); i++)
        cout<<name[i];
    cout<<endl;
}

void worstscore(student*& st, int num)
{
    char* name;
    float min=st[0].gpa;
    for(int i=0; i!=num; i++)
        if(st[i].gpa <= min)
        {
            min=st[i].gpa;
            name=st[i].name;
        }
    cout<<"Student with the worst score: ";
    for(int i=0; i!=strlen(name); i++)
        cout<<name[i];
    cout<<endl;
}

void older_50(student*& st, int num)
{
    cout<<"Students with the supervisor older than 50 yrs old:"<<endl;
    bool exist=false;
    for(int i=0; i!=num; i++)
        if(st[i].supervisor->age > 50)
        {
            cout<<st[i].name<<endl;
            exist=true;
        }
    if(exist==false)
        cout<<"No such students."<<endl;
}

int main()
{
    //=============================================Task18===========================================
    cout<<"Professors: "<<endl;
    professor *professors=new professor[3];
    prof_init(professors, 3);
    cout<<"Enter the number of students: ";
    int Num;
    cin>>Num;
    student *stud=new student[Num];
    struct_init(stud, professors, Num);
    cout<<"-----------------------------"<<endl;
    average_gpa(stud, Num);
    cout<<"Average gpa: "<<average_gpa(stud,Num)<<endl;
    cout<<"-----------------------------"<<endl;
    bestscore(stud, Num);
    cout<<"-----------------------------"<<endl;
    worstscore(stud,Num);
    cout<<"-----------------------------"<<endl;
    older_50(stud,Num);
    cout<<"-----------------------------"<<endl;
    delete[] professors;
    delete[] stud;
    return 0;
}

