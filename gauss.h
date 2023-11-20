
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;

double normA=0;
double massXFirst[3];

void print(vector<vector<double>>& matr);
void iter1(vector<vector<double>>& matr,const vector<vector<double>>& matr1,double*vectornev1);
void iter2(vector<vector<double>>& matr);
void gaus(vector<vector<double>>& matr,double  * result);