//MonteCarloFun.cpp
#include "MonteCarloFun.h"
#include "Normal.h"
#include "Sampler.h"
#include <cmath>
#include <iostream>
#include <algorithm> //For function max


///Function returns the Monte Carlo price for a European Call option in the BS modell
double MC1(double S0,double K,double T,double r,double sigma, int NumOfPaths)
{
//Normal Random Variable
 NormalSampler norm(0.0, 1.0);
 double mysum = 0.0;
 double MCprice = 0.0;

 for(int i=0; i < NumOfPaths; i++)
	{
		double Wt = norm.getnumber();
		double tmppayoff = std::max(S0*exp(-0.5*sigma*sigma*T + sigma*sqrt(T)*Wt) - K*exp(-r*T), 0.0);
		mysum += tmppayoff;
     }

    MCprice = mysum/NumOfPaths;
	return MCprice;
}

///Function returns the Monte Carlo price for a European Call option in the BS modell
//and stores the sample standard deviation in SampleStdev (call by reference!).
//With this we can compute a confidence interval.
double MC2(double &SampleStdv,double S0,double K,double T,double r,double sigma, int NumOfPaths)
{
    //Normal Random Variable
 NormalSampler norm(0.0, 1.0);
 double *myvector;
 myvector =  new double[NumOfPaths];
 double mysum = 0.0;
 double MCprice = 0.0;

 for(int i=0; i < NumOfPaths; i++)
 {
		double Wt = norm.getnumber();
		double tmppayoff = std::max(S0*exp(-0.5*sigma*sigma*T + sigma*sqrt(T)*Wt) - K*exp(-r*T), 0.0);
		myvector[i] = tmppayoff;
		mysum += tmppayoff;
 }

    MCprice = mysum/NumOfPaths;

SampleStdv=0.0;
double tmp = 0.0;

 for(int i=0;i < NumOfPaths;i++)
 {
     tmp += pow(myvector[i]-MCprice,2.0);
 }
 SampleStdv = sqrt(tmp/(NumOfPaths-1.0));
 delete [] myvector;
 return MCprice;

}

//Function returns MC price using Antithetic variates
double MCAntiVariate(double S0,double K,double T,double r,double sigma, int NumOfPaths)
{
    //Normal Random Variable
 NormalSampler norm(0.0, 1.0);
 double mysum = 0.0;
 double MCprice = 0.0;

 for(int i=0; i < NumOfPaths; i++)
	{
		double Wt = norm.getnumber();
		double tmppayoff1 = std::max(S0*exp(-0.5*sigma*sigma*T + sigma*sqrt(T)*Wt) - K*exp(-r*T), 0.0);
        double tmppayoff2 = std::max(S0*exp(-0.5*sigma*sigma*T + sigma*sqrt(T)*(-Wt)) - K*exp(-r*T), 0.0);
		mysum += tmppayoff1+tmppayoff2;
     }

    MCprice = mysum/(2*NumOfPaths);
	return MCprice;
}

//Function returns MC price using control variates
double MCControlVariate(double S0,double K,double T,double r,double sigma, int NumOfPaths)
{

    NormalSampler norm(0.0, 1.0);
    double mysumX, mysumY;
    double MCprice =  0.0;
    double cov, varX, varY, bhat;
    double *myYvector;
    myYvector =  new double[NumOfPaths];
    double *myXvector;
    myXvector =  new double[NumOfPaths];

    mysumX=0.0;
    mysumY=0.0;

	for (int i=0; i < NumOfPaths; i++)
	{
		double Wt = norm.getnumber();
        double Disstock= S0*exp(-0.5*sigma*sigma*T + sigma*sqrt(T)*Wt);
		double tmppayoff = std::max(Disstock - K*exp(-r*T), 0.0);
		myXvector[i] = Disstock;
		myYvector[i] = tmppayoff;
		mysumX += myXvector[i];
		mysumY += myYvector[i];
     }


    bhat = 0.0;
    cov  = 0.0;
    varX = 0.0;
    varY = 0.0;

    for (int i=0; i < NumOfPaths; i++)
	{
        cov += (myXvector[i] - mysumX/NumOfPaths)*(myYvector[i] - mysumY/NumOfPaths);
        varX += (myXvector[i] - mysumX/NumOfPaths)*(myXvector[i] - mysumX/NumOfPaths);
        varY += (myYvector[i] - mysumY/NumOfPaths)*(myYvector[i] - mysumY/NumOfPaths);

    }

    //Note that cov & var ar not the sample covariance/variance since one still needs to divide by NumberOfPaths.
    //In the computation of bhat this cancels.
    //Note, that this computation does introduce bias in the estimator since the same X, Y are used for computing bhat.
    //This could be avoided by using a new sample for the estimation, see Glasserman.

    bhat=cov/varX;
    std::cout << "bhat =  " << bhat << " and corr(X, Y)^2 = " << (cov*cov)/(varX*varY) << "\n";
    for (int i=0; i < NumOfPaths; i++)
	{
        MCprice+=myYvector[i]- bhat*(myXvector[i]-S0);
     }

    delete [] myXvector;
    delete [] myYvector;

    MCprice=MCprice/NumOfPaths;
	return MCprice;

}










