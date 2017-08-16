//BSFun.cpp
//BSCall uses the CDF of the standard normal distribution from "Normals.h".
#include "BSFun.h"
#include "Normal.h"
#include <cmath>

double BSCall(double S0, double K, double r, double sigma, double T)
{
    double d1 =(log(S0/K) + (r + sigma*sigma*0.5)*T)/(sigma*sqrt(T));
    double d2 = d1 - sigma*sqrt(T);
    return S0* CumulativeNormal(d1) - K*exp(-r*T)*CumulativeNormal(d2);
}


