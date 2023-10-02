#include <iostream>
#include <vector>
#include <iomanip>


using namespace std;

int main()
{
double x1=0;
double x2=0;
double x3=0;
vector<double> str1{2.75,1.78,1.11,15.71};
vector<double> str2{3.28,0.71,1.15,43.78};
vector<double> str3{1.15,2.70,3.58,37.11};
vector<vector<double>> matr{str1,str2,str3};
double max=matr[0][0];

cout<<setw(6);
for (size_t i = 0; i < 3;i++)
{
    for (size_t j = 0; j < 4; j++)
    {
        cout<<matr[i][j]<<setw(6);
    }
    cout<<endl;
}
//iter1
int index=0;
for (size_t i = 1; i < 3; i++)
{
       if (matr[i][0]>max)
       {
        max=matr[i][0];
        index=i;
       }
}
swap(matr[0],matr[index]);
// cout<<"1 iteraziya"<<endl;
// cout<<setw(6);

// for (size_t i = 0; i < 3;i++)
// {
//     for (size_t j = 0; j < 4; j++)
//     {
//         cout<<matr[i][j]<<setw(6);
//     }
//     cout<<endl;
// }

//iter2
double perviy=matr[0][0];
for (size_t j = 0; j < 4; j++)
{
    matr[0][j]=matr[0][j]/perviy;
}


// cout<<"2 iteraziya"<<endl;
// cout<<setw(10);
// for (size_t i = 0; i < 3;i++)
// {
//     for (size_t j = 0; j < 4; j++)
//     {
//         cout<<matr[i][j]<<setw(10);
//     }
//     cout<<endl;
// }

//3 iter

for (size_t i = 1; i < 2; i++)
{
    double elem=matr[1][0];
    for (size_t j = 0; j < 4; j++)
    {
        matr[i][j]=matr[0][j]*elem*(-1)+matr[i][j];
    }
}
for (size_t i = 2; i < 3; i++)
{
    double elem=matr[2][0];
    for (size_t j = 0; j < 4; j++)
    {
        matr[i][j]=matr[0][j]*elem*(-1)+matr[i][j];
    }
}

double max1=matr[1][1];
cout<<"1 iteraziya"<<endl;
cout<<setw(10);
for (size_t i = 0; i < 3;i++)
{
    for (size_t j = 0; j < 4; j++)
    {
        cout<<matr[i][j]<<setw(10);
    }
    cout<<endl;
}

//iter 4
int index1=1;
for (size_t i = 1; i < 3; i++)
{  
       if (matr[i][1]>max1)
       {
        max1=matr[i][1];
        index1=i;
       }
}
swap(matr[1],matr[index1]);

double vtoroy=matr[1][1];
for (size_t j = 0; j < 4; j++)
{
    matr[1][j]=matr[1][j]/vtoroy;
}

for (size_t i = 2; i < 3; i++)
{
    double elem1=matr[2][1];
    for (size_t j = 0; j < 4; j++)
    {
        matr[i][j]=matr[1][j]*elem1*(-1)+matr[i][j];
    }
}

cout<<"2 iteraziya"<<endl;
cout<<setw(10);
for (size_t i = 0; i < 3;i++)
{
    for (size_t j = 0; j < 4; j++)
    {
        cout<<matr[i][j]<<setw(10);
    }
    cout<<endl;
}
x3=matr[2][3]/matr[2][2];
x2=matr[1][3]-x3*matr[1][2];
x1=matr[0][3]-x2*matr[0][1]-x3*matr[0][2];
cout<<"x1="<<x1<<endl;
cout<<"x2="<<x2<<endl;
cout<<"x3="<<x3<<endl;
return 0;
}