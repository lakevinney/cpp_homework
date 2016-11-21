#include <iostream>

using namespace std;

//============================Task15=====================================
void rotate_clockwise(double** arr, int n, int m)
{
    double rot[m][n];
    for(int i=0; i!=n; i++)
        for(int j=0; j!=m; j++)
            rot[j][n-1-i]=arr[i][j];
    cout<<"Rotated:"<<endl;
    for(int i=0; i!=m; i++)
    {
        for(int j=0; j!=n; j++)
            cout<<rot[i][j]<<" ";
        cout<<endl;
    }
}

int main()
{
    //============================Task15=====================================
    int n,m;
    cout<<"Enter the numbers of rows and columns of the matrix (n,m): ";
    cin>>n>>m;
    if(n>=100 || m>=100)
    {
        cout<<"The numbers must be less than 100. Exiting..."<<endl;
        return 0;
    }

    double** a=new double*[n];

    for(int i=0; i!=n; i++)
    {
        cout<<"line "<<i<<endl;
        a[i]=new double[m];
        for(int j=0; j!=m; j++)
        {
            cout<<"a["<<i<<"]["<<j<<"]= ";
            cin>>a[i][j];
        }
    }
    cout<<endl;
    cout<<"Matrix:"<<endl;
    for(int i=0; i!=n; i++)
    {
        for(int j=0; j!=m; j++)
            cout<<a[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
    rotate_clockwise(a,n,m);
    for(int i = 0; i < n; i++) delete[] a[i];
        delete[] a;
    cout<<"==================================================================="<<endl;
    return 0;
}

