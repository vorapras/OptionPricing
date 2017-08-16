//  StochProc.cpp

#include "StochProc.h"
#include "Sampler.h"

#include<cstdlib>
#include<cmath>
#include<iostream>

//Stochastic Process
double StochProcess::get_terminalvalue(double T, int numberofsteps, double X0)
{
    std::cout << "X0="<< X0 << "\n"; 
    double h = T/numberofsteps;
    double currentX = X0;
    
    for(int i = 0 ;i < numberofsteps;i++)
    {
        
        currentX = step(currentX,h);
    }
    return currentX;
};


void StochProcess::get_samplepath(double T,int numberofsteps, double X0, double *p)
{
    std::cout << "X0="<< X0 << "\n";
    double h = T/numberofsteps;
    *p = X0;
    
    for(int i = 0 ;i < numberofsteps;i++)
    {
        *(++p)= step(*p,h);
    }
    
    return;
};


//Brownian Motion
double BM::step(double currentX,double h)
{
    double nextvalue;
    NormalSampler n(0.0,1.0);
    double normalrand = n.getnumber();
    nextvalue = currentX+mu*h+sqrt(h)*sigma*normalrand;
    //std::cout<< "in BM::takestep:  h=" << h << " stdnormal = "<< normalrand << " nextvalue = " << nextvalue << "\n";
    return nextvalue;
}

//Geometric Brownian Motion
double GBM::step(double currentX,double h)
{
    double nextvalue;
    NormalSampler n(0.0,1.0);
    double normalrand = n.getnumber();
    nextvalue = currentX*exp((mu-0.5*sigma*sigma)*h+sqrt(h)*sigma*normalrand);
    //std::cout<< "in GBM::takestep:  h=" << h << " stdnormal = "<< normalrand << " nextvalue = " << nextvalue << "\n";
    return nextvalue;
}













