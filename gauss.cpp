#include "gauss.h"

void iter1(vector<vector<double>>& matr,const vector<vector<double>>& matr1,double*vectornev1){
double * massX = new double[3];
double * massVectNev = new double[3];
gaus(matr,massX);
massXFirst[0]=massX[0];
massXFirst[1]=massX[1];
massXFirst[2]=massX[2];
cout<<"VECTOR NEVYAZKI:"<<endl;
for (size_t i = 0; i < 3; i++)
{
    vectornev1[i]=(matr1[i][0]*massX[2]+matr1[i][1]*massX[1]+matr1[i][2]*massX[0])-matr1[i][3];
    massVectNev[i]=vectornev1[i];
    cout<<vectornev1[i];
    cout<<endl;
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

void gaus(vector<vector<double>>& matr,double * result){
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
result[0] = matr[2][3]/matr[2][2];
result[1] = matr[1][3]-matr[2][3]/matr[2][2]*matr[1][2];
result[2] = matr[0][3]-(matr[1][3]-matr[2][3]/matr[2][2]*matr[1][2])*matr[0][1]-matr[2][3]/matr[2][2]*matr[0][2];
cout<<"x1="<<result[2]<<endl;
cout<<"x2="<<result[1]<<endl;
cout<<"x3="<<result[0]<<endl;
}

void iter2(vector<vector<double>>& matr){
double* massX1 = new double[3];
print(matr);
gaus(matr,massX1);
double slsh_max,asnw_max;
double answer[3];
answer[0] = massXFirst[0];
answer[1] = massXFirst[1];
answer[2] = massXFirst[2];
asnw_max=abs(answer[0]);
slsh_max=abs(massXFirst[0]-massX1[0]);
for (size_t i = 1; i < 3; i++)
{
    if (abs(answer[i])>asnw_max)
    {
        asnw_max=answer[i];
    }

    if (abs(massXFirst[i]-massX1[i])>slsh_max)
    {
        slsh_max=abs(massXFirst[i]-massX1[i]);
    }
    
}
double mas1[3]={massX1[0],massX1[1],massX1[2]};
double Eabsol=abs(massX1[0]);
for (size_t i = 1; i < 3; i++)
{
    if(abs(mas1[i])>Eabsol){
        Eabsol=abs(mas1[i]);
    }
}
// double ocenkOtnPogr=slsh_max/asnw_max;
// cout<<"Ocenka otnositelnoy pogreshnosti:"<<ocenkOtnPogr<<"%"<<endl;

// cout<<"norma:"<<endl;
// double ocenkOtnPogr=abs(Eabsol-normA)/normA;
// cout<<"Ocenka otnositelnoy pogreshnosti:"<<ocenkOtnPogr<<"%";
delete[]massX1;
}

void print(vector<vector<double>>& matr)
{
    cout<<setw(14);
    for (size_t i = 0; i < 3;i++)
{
    for (size_t j = 0; j < 4; j++)
    {
        cout<<matr[i][j]<<setw(14);
    }
    cout<<endl;
}
}