//BSFun2.cpp
//BSCall uses the CDF of the standard normal distribution from "RandomVariable.h".  
#include "BSFun2.h"
#include "RandomVariable.h"
#include <cmath>
double BSCall2(double S0, double K, double r, double sigma, double T)
{
    double d1 =(log(S0/K) + (r + sigma*sigma*0.5)*T)/(sigma*sqrt(T));
    double d2 = d1 - sigma*sqrt(T); 
    NormalRV N; 
    
    return S0* N.cdf(d1) - K*exp(-r*T)*N.cdf(d2);
}

