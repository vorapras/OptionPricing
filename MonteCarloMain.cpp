//MonteCarloMain.cpp
#include <cmath>
#include <ctime>
#include <iostream>
#include "BSFun.h"
#include "MonteCarloFun.h"
#include "Normal.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////////////////
int main()
{
cout << "Welcome to the Monte Carlo Calculator! \n";

   // Set the seed of the random number generator using time
 srand((unsigned)time(0));
 //cout << "time(0)=" << time(0) <<"\n";
 //srand(1.0);  //Could also use such a seed. This is useful if you would like to reproduce your results;

 // Initialise option parameters
 double T = 1.0;
 double K = 50.0;
 double S0 = 50.0;
 double sigma = 0.3;
 double r = 0.05;
 int NumOfPaths=1000000;
 double mystdev = 0.0;
 double myepsilon = 0.05;

 double price1, price2, price3, price4;
 double leftside, rightside;

 cout << "//..................................//" << "\n";
 //Calculate Call Price
 price1 = BSCall(S0,K,r,sigma,T);
 cout << "The Black- Scholes price is " << price1 << "\n";

 cout << "//..................................//" << "\n";
 price2 = MC2(mystdev,S0,K,T,r,sigma,NumOfPaths);

 double quantile=InverseCumulativeNormal(1.0-myepsilon*0.5);
 cout << "Recall that Phi^{-1}(" <<1.0-myepsilon*0.5 <<") = " << quantile << "\n";
 cout << "//..................................//" << "\n";

 leftside  = price2-(quantile*mystdev/sqrt(NumOfPaths));
 rightside = price2+(quantile*mystdev/sqrt(NumOfPaths));

 cout << "MC price is " << price2 << "\n";
 cout << "MC confidence interval for epsilon ="<<myepsilon <<"  and n=" << NumOfPaths << " is (" << leftside << " , " << rightside << ") \n";

 cout << "//..................................//" << "\n";
 //Note that MCAntithetic uses effectively 2*NumberofPaths numbers to compute the expectation
 //For a fair comparison to standard MC estimator you could consider
 //price3=MCAntithetic(T, K, S0, sig, r, NumberOfPaths/2);
 //assuming that  NumberofPaths is an even integer.
 price3 = MCAntiVariate(S0,K,T,r,sigma,NumOfPaths);
 cout << "MC price using antithetic variates is " << price3 << "\n";
 cout << "//..................................//" << "\n";

 price4 = MCControlVariate(S0,K,T,r,sigma,NumOfPaths);
 cout << "MC price using control variates is " << price4 << "\n";
 cout << "//..................................//" << "\n";
 

system("PAUSE");
return 0; 
}


