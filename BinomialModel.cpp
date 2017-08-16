//BinomialModel.cpp
#include "BinomialModel.h"

BinomialModel::BinomialModel(double initial, double up, double down, double interest)
{
 S0=initial; 
 u=up; 
 d=down; 
 R=interest; 
 
 if ((d >=R)||(u<=R))
 {
        cout << "No-arbitrage condition violated for d="<< d << ", R=" << R << ", u=" << u << "\n"; 
        u=1.5; 
        d=0.66; 
        R=1.02; 
        cout << "Default parameters chosen: d="<< d << ", R=" << R << ", u=" << u << "\n";
 }                                   
}

double BinomialModel::GetR(void)
{
       return R;       
}

double BinomialModel::Stock(int n, int i)
{
       if ((n<0)||(i>n)||(i<0))
       { cout << "Wrong input in Stock!\n"; } 
       return S0*pow(u, i)*pow(d, n-i);       
}

double BinomialModel::RiskNeutralProb(void)
{
       return (R-d)/(u-d);       
}
