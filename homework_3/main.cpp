#include <iostream>
#include <iomanip>

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

//============================Task16=====================================
double determinant(double** arr)
{
    double det = arr[0][0] * arr[1][1] * arr[2][2] + arr[0][1] * arr[1][2] * arr[2][0] + \
            arr[0][2] * arr[1][0] * arr[2][1] - arr[0][2] * arr[1][1] * arr[2][0] - \
            arr[0][1] * arr[1][0] * arr[2][2] - arr[0][0] * arr[1][2] * arr[2][1];
    return det;
}

//============================Task17=====================================
double** multiply(double** arr1, int n1, int m1, double** arr2, int n2, int m2)
{
    double** res=new double*[n1];
    for(int i=0; i!=n1; i++)
    {
        res[i]=new double[m2];
        for(int j=0; j!=m2; j++)
        {
            res[i][j]=0;
            for(int k=0; k!=n2; k++)
                res[i][j]+=arr1[i][k]*arr2[k][j];
        }
    }

    return res;
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

    //============================Task16=====================================
    cout<<"Enter 3x3 matrix:"<<endl;
    double** matr=new double*[3];
    for(int i=0; i!=3; i++)
    {
        cout<<"line "<<i<<endl;
        matr[i]=new double[m];
        for(int j=0; j!=3; j++)
        {
            cout<<"matr["<<i<<"]["<<j<<"]= ";
            cin>>matr[i][j];
        }
    }
    cout<<endl;
    cout<<"Matrix:"<<endl;
    for(int i=0; i!=3; i++)
    {
        for(int j=0; j!=3; j++)
            cout<<matr[i][j]<<" ";
        cout<<endl;
    }
    cout<<"Determinant: "<<determinant(matr)<<endl;
    for(int i = 0; i < 3; i++) delete[] matr[i];
        delete[] matr;
     cout<<"==================================================================="<<endl;

     //============================Task17=====================================
    int row_A, col_A;
    cout<<"Enter the numbers of rows and columns of the matrix A: ";
    cin>>row_A>>col_A;

    int row_B, col_B;
    cout<<"Enter the numbers of rows and columns of the matrix B: ";
    cin>>row_B>>col_B;
    cout<<endl;
    if(col_A!=row_B)
    {
        cout<<"Number of columns in matrix A must be equal to number of rows in matrix B. Exiting..."<<endl;
        return 0;
    }
    double** A=new double*[row_A];
    cout<<"Matrix A:"<<endl;
    for(int i=0; i!=row_A; i++)
    {
        cout<<"line "<<i<<endl;
        A[i]=new double[col_A];
        for(int j=0; j!=col_A; j++)
        {
            cout<<"A["<<i<<"]["<<j<<"]= ";
            cin>>A[i][j];
        }
    }
    double** B=new double*[row_B];
    cout<<"Matrix B:"<<endl;
    for(int i=0; i!=row_B; i++)
    {
        cout<<"line "<<i<<endl;
        B[i]=new double[col_B];
        for(int j=0; j!=col_B; j++)
        {
            cout<<"B["<<i<<"]["<<j<<"]= ";
            cin>>B[i][j];
        }
    }
    cout<<endl;
    cout<<"A:"<<endl;
    for(int i=0; i!=row_A; i++)
    {
        for(int j=0; j!=col_A; j++)
            cout<<A[i][j]<<" ";
        cout<<endl;
    }
    cout<<"B:"<<endl;
    for(int i=0; i!=row_B; i++)
    {
        for(int j=0; j!=col_B; j++)
            cout<<B[i][j]<<" ";
        cout<<endl;
    }
    double** C=multiply(A, row_A, col_A, B, row_B, col_B);
    cout<<"C=AxB:"<<endl;
    for(int i=0; i!=row_A; i++)
    {
        for(int j=0; j!=col_B; j++)
            cout<<setw(2)<<C[i][j]<<" ";
        cout<<endl;
    }
    return 0;
}

