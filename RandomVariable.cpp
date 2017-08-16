//RandomVariable.cpp
#include "RandomVariable.h"
#include "Normals.h"
#include <cmath>


NormalRV::NormalRV(double tmpmu, double tmpsigma)
{
 mu=tmpmu; 
 sigma=tmpsigma;                          
}


double NormalRV::pdf(double x)
{
 double tmp = (x-mu)/sigma; 
 return NormalDensity(tmp)/sigma; 
}

double NormalRV::cdf(double x)
{
  double tmp=(x-mu)/sigma;       
  return  CumulativeNormal(tmp);      
}
