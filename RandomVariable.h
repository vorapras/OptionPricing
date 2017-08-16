//RandomVariable.h
#ifndef RANDOMVARIABLE_H
#define RANDOMVARIABLE_H

class RandomVariable{
public: 
virtual double pdf(double x) = 0; 
virtual double cdf(double x) = 0; 
}; 


class NormalRV : public RandomVariable{
private: 
         double mu, sigma; 
public: 
        NormalRV(double tmpmu=0.0, double tmpsigma=1.0); 
        virtual double pdf(double x); 
        virtual double cdf(double x); 
}; 


#endif
