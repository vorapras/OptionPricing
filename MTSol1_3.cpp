//MTSol1_3.cpp
#include<iostream>
#include<cstdlib>

using namespace std;

void generate_rv(double *pt_rv, int n, double min=0.0, double max=1.0);
double array_mean(double *p, int n);
double array_variance(double *p, int n);
double tvar(double min, double max);


int main()
{

  srand((unsigned)time(0)); // random seed for the generator

  int n=100000;
  // OR we could ask the user:
  // cout << "Enter the number of variates to generate> ";
  // cin >> n;

  double *pt_variates, min=0.0, max=2.0;

  pt_variates=new double[n]; 

  generate_rv(pt_variates, n, min, max);

  double sample_mean = array_mean(pt_variates,n);
  double sample_variance = array_variance(pt_variates,n);


  cout << "The mean of " << n << " uniform random variates in U[";
  cout << min << "," << max << "] generated is " << sample_mean;
  cout << ", where the theoretical value is " << (min+max)/2 << '.' << endl;

  cout << "The variance of " << n << " uniform random variates in U[";
  cout << min << "," << max << "] generated is " << sample_variance;
  cout << ", where the theoretical value is " << tvar(min,max) << '.' << endl;
  system("PAUSE"); 
  return 0; 
}

void generate_rv(double *pt_rv, int n, double min, double max)
{
  for(int i=0; i<n; ++i)
    pt_rv[i] = min + rand() * (max-min) / RAND_MAX;
}

double array_mean(double *p, int n)
{
  double sum = 0.0;
  for(int i=0; i<n; ++i)
    sum += p[i];
  return (sum/n);
}


double array_variance(double *p, int n)
{
  double mean = array_mean(p,n);
  double sum =0.0;

  for(int i=0; i<n; ++i)
    sum += (p[i]-mean)*(p[i]-mean);

  return (sum/(n-1));
}


double tvar(double min, double max)
{
 return (max - min)*(max-min)/12; 
}
  
