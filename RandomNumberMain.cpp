//RandomNumberMain.cpp
#include<iostream>
#include<cmath>
#include "Sampler.h"
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////              
int main()
{   

  
 cout << "Welcome to the random number generation session! \n";  
 
 // Set the seed of the random number generator using time
 //void srand ( unsigned int seed );
 srand((unsigned)time(0));
 //cout << "time(0)=" << time(0) <<"\n";  
 //srand(1.0);  //Could also use such a seed. This is useful if you would like to reproduce your results; 
 
 UniformSampler u1; 
 ExponentialSampler e1(2.0); 
 NormalSampler n1(5.0, 1.0); 
 DoubleExpSampler de1; 
 
 ////////////////////////////////////////////////////
 //Some examples using pointers. 
 //Sampler *myrandomnum[2]; 
 //myrandomnum[0]=new UniformSampler(5.0, 6.0); 
 //myrandomnum[1]=new NormalSampler(3.0, 1.0); 
 
 //cout << "A little practice with pointers: \n"; 
 ////Two equivalent ways for accessing the elements
 //cout << "Uniform example is " << myrandomnum[0]->getnumber() << "\n"; 
 //cout << "Normal example is " << (*myrandomnum[1]).getnumber() << "\n"; 
 ////////////////////////////////////////////////
 
 
 
 ///////////////////////////////
 //Compute the sample means 
 int N=100000; 
 double mysum1; 
 
 
 mysum1=0.0; 
 for(int i=0; i < N; i++){mysum1=mysum1+u1.getnumber(); }
 cout << "Uniform: sample mean=" << mysum1/N << "\n"; 
  
 
 mysum1=0.0; 
 for(int i=0; i < N; i++){mysum1=mysum1+e1.getnumber(); }
 cout << "Exponential: sample mean=" << mysum1/N << "\n"; 
  
  
 mysum1=0.0; 
 for(int i=0; i < N; i++){mysum1=mysum1+n1.getnumber(); }
 cout << "Normal sample mean=" << mysum1/N << "\n"; 
 
 mysum1=0.0; 
 for(int i=0; i < N; i++){mysum1=mysum1+de1.getnumber(); }
 cout << "Double exponential has expectation 0 and sample mean=" << mysum1/N << "\n"; 
 
 ////////////////////////////////////////
 //Example acceptance-rejection sampling
 int rejnumber=0; 
 double myc=sqrt(2.0*exp(1)/PI);
 double myrandom; 
  
 myrandom = specialRejectionSampling(rejnumber, myc); 
 //cout << "Acceptance-Rejection Sampling: c=" << myc << " random number =" << myrandom <<" number of rections=" << rejnumber << "\n";
 
 //Check the proportion of rejections: 
 int totalrej=0; 
 mysum1=0.0; 
 for(int i=0; i < N; i++){mysum1=mysum1+specialRejectionSampling(rejnumber, myc); totalrej=totalrej+rejnumber;} 
 
 //Note that N +totalrej random numbers were computed to obtain N random numbers of the double exp;  
 cout << "Acceptance-Rejection sampling for standard normal dstr. using the double exponential distr.  and c=" << myc << "\n"; 
 cout << "1-1/c = " << 1.0-1.0/myc << "   Sample rejection rate = " << totalrej/static_cast<double>(N+totalrej) << "\n";   
 cout << "sample mean for N= " <<N << " random numbers is " << mysum1/N << "\n"; 
 
 system("PAUSE");

 return 0; 
}

