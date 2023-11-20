#include <gauss.h>

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