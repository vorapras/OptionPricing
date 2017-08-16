//MonteCarloFun.h

#ifndef MONTECARLOFUN_H
#define MONTECARLOFUN_H


///Function returns the Monte Carlo price for a European Call option in the BS model
double MC1(double S0,double K,double T,double rf,double sigma, int NumOfPaths);

///Function returns the Monte Carlo price for a European Call option in the BS modell
//and stores the sample standard deviation in SampleStdev (call by reference!).
//With this we can compute a confidence interval
double MC2(double &SampleStdv,double S0,double K,double T,double rf,double sigma, int NumOfPaths);

//Function returns MC price using Antithetic variates
double MCAntiVariate(double S0,double K,double T,double rf,double sigma, int NumOfPaths);


//Function returns MC price using control variates
double MCControlVariate(double S0,double K,double T,double rf,double sigma, int NumOfPaths);


#endif
