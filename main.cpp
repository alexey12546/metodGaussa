#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
void print(vector<vector<double>> matr);
void iter1(vector<vector<double>> matr,vector<vector<double>> matr1,double*vectornev1);
void iter2(vector<vector<double>> matr);
void gaus(vector<vector<double>> matr,double  * result);

double normA=0;

int main()
{
vector<double> str1{2.75,1.78,1.11,15.71};
vector<double> str2{3.28,0.71,1.15,43.78};
vector<double> str3{1.15,2.70,3.58,37.11};
vector<vector<double>> matr{str1,str2,str3};
vector<vector<double>> matr1{str1,str2,str3};
double vectornev[3]={0,0,0};
print(matr);
iter1(matr,matr1,vectornev);
vector<double> str4{2.75,1.78,1.11,vectornev[0]};
vector<double> str5{3.28,0.71,1.15,vectornev[1]};
vector<double> str6{1.15,2.70,3.58,vectornev[2]};
vector<vector<double>> matr2{str4,str5,str6};
iter2(matr2);
return 0;
}

void iter1(vector<vector<double>> matr,vector<vector<double>> matr1,double*vectornev1){
const int N=3;
double * massX = new double[3];
double * massVectNev = new double[3];
gaus(matr,massX);
double maxX=abs(massX[0]);
for (size_t i = 1; i < 3; i++)
{
    if (abs(massX[i])>maxX)
    {
        maxX=abs(massX[i]);
    }
    
}
cout<<"VECTOR NEVYAZKI:"<<endl;
for (size_t i = 0; i < 3; i++)
{
    vectornev1[i]=(matr1[i][0]*massX[0]+matr1[i][1]*massX[1]+matr1[i][2]*massX[2])-matr1[i][3];
    cout<<vectornev1[i];
    cout<<endl;
}
for (int i = 0; i < 3; i++)
{
    massVectNev[i]=vectornev1[i];
}
cout<<"NORMA:"<<endl;
double norma=vectornev1[0];
for (size_t i = 1; i < 3; i++)
{
    if(abs(vectornev1[i])>norma){
    norma=vectornev1[i];
    }
}
normA=norma;
cout<<norma<<endl;
delete[] massVectNev;
delete[] massX;
}

void gaus(vector<vector<double>> matr,double * result){
double x1=0;
double x2=0;
double x3=0;
double max=matr[0][0];
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
double perviy=matr[0][0];
double elem=matr[1][0];
for (size_t j = 0; j < 4; j++)
{
    matr[0][j]=matr[0][j]/perviy;
    matr[1][j]=matr[0][j]*elem*(-1)+matr[1][j];
}
elem=matr[2][0];
for (size_t j = 0; j < 4; j++)
{
    matr[2][j]=matr[0][j]*elem*(-1)+matr[2][j];
}
double max1=matr[1][1];
cout<<"1 iteraziya"<<endl;
print(matr);
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
double elem1=matr[2][1];
for (size_t j = 0; j < 4; j++)
{
    matr[1][j]=matr[1][j]/vtoroy;
    matr[2][j]=matr[1][j]*elem1*(-1)+matr[2][j];
}
cout<<"2 iteraziya"<<endl;
print(matr);
x3=matr[2][3]/matr[2][2];
x2=matr[1][3]-x3*matr[1][2];
x1=matr[0][3]-x2*matr[0][1]-x3*matr[0][2];
cout<<"x1="<<x1<<endl;
cout<<"x2="<<x2<<endl;
cout<<"x3="<<x3<<endl;
result[0] = x1;
result[1] = x2;
result[2] =x3;
}

void iter2(vector<vector<double>> matr){
double * massX1 = new double[3];
print(matr);
gaus(matr,massX1);
double mas1[3]={massX1[0],massX1[1],massX1[2]};
double Eabsol=abs(massX1[0]);
for (size_t i = 1; i < 3; i++)
{
    if(abs(mas1[i])>Eabsol){
        Eabsol=abs(mas1[i]);
    }
}
double ocenkOtnPogr=abs(Eabsol-normA)/normA;
cout<<"Ocenka otnositelnoy pogreshnosti:"<<ocenkOtnPogr<<"%";
delete[]massX1;
}

void print(vector<vector<double>> matr)
{
    cout<<setw(14);
    for (size_t i = 0; i < 3;i++)
{
    for (size_t j = 0; j < 4; j++)
    {
        if (i<2)
        {
            cout<<matr[i][j]<<setw(14);
        }
        else if(i==2 && j==3)
        cout<<matr[i][j];
        else
        cout<<matr[i][j]<<setw(14);
    }
    cout<<endl;
}
}