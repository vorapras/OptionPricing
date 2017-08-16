//MainBlackScholes.cpp
#include<iostream>

#include "BinomialModel.h"
#include "Payoff.h"
#include "FunPO.h"

#include "Normals.h"
#include "BSFun.h"
#include "BSFun2.h"
#include "RandomVariable.h"

using namespace std;

int main()
{   
    cout << "Testing the class RandomVariable: \n"; 
    
    NormalRV normal1(4.0, 3.0); 
    NormalRV normal2; 
    
    cout << "PDF of N(4.0, (3.0)^2) random variable at 4.0 is " << normal1.pdf(4.0) << "\n"; 
    cout << "PDF of N(4.0, (3.0)^2) random variable at 2.0 is " << normal1.pdf(2.0) << "\n";
    cout << "PDF of N(4.0, (3.0)^2) random variable at 6.0 is " << normal1.pdf(6.0) << "\n"; 
     
    cout << "PDF of N(0.0, 1.0) random variable at 0.0 is " << normal2.pdf(0.0) << "\n";
    
    cout << "CDF of N(4.0, (3.0)^2) random variable at 4.0 is " << normal1.cdf(4.0) << "\n";
    cout << "CDF of N(0.0, 1.0) random variable at 0.0 is " << normal2.cdf(0.0) << "\n";
    cout << "------------------------------------------------\n"; 
    
    cout << "Pricing: Black-Scholes versus Binomial Tree: \n"; 
    //Pricing: 
    double K=100.0, S0=100.0; 
    double T=1, sigma=0.2, r=0.01; 
    double DeltaN, uN, dN, RN;
    int N=10000; 
    
    DeltaN=T/N; 
    uN=exp(sigma*sqrt(DeltaN)); 
    dN=exp(-sigma*sqrt(DeltaN)); 
    RN=exp(r*DeltaN);  
    BinomialModel TestCase(S0, uN, dN, RN); 
    
    CallPayoff x(K); 
        
    double priceBinomial, priceBS, priceBS2; 
    
    priceBinomial=Pricing(&x, &TestCase, N); 
    priceBS = BSCall(S0, K, r, sigma, T); 
    priceBS2 = BSCall2(S0, K, r, sigma, T); 
       
    cout<<"Call price in the binomial tree model with "<< N << " steps: " << priceBinomial <<"\n";  
    cout<<"Call price in Black Scholes model: " << priceBS << "\n"; 
    cout<<"Call price in Black Scholes model (using the class RandomVariable): " << priceBS2 << "\n"; 
     
 system("PAUSE");
 return 0; 

}
