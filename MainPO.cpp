//MainPO.cpp
#include<iostream>

#include "BinomialModel.h"
#include "Payoff.h"
#include "FunPO.h"

using namespace std;

int main()
{   
    
    double S0=100.0, u=1.5, d=0.66, R=1.02; 
    
    BinomialModel TestCase(S0, u, d, R); 
    
    double K=100.0; 
    int N=2; 
    
    CallPayoff x(K); 
    PutPayoff y(K); 
        
    double priceput, pricecall; 
    
    pricecall=Pricing(&x, &TestCase, N); 
    priceput=Pricing(&y, &TestCase, N); 
    
   
    cout<<"Binomial tree model with "<< N << " steps: call price is " << pricecall <<"\n"; 
    cout<<"Binomial tree model with "<< N << " steps: put price is  " << priceput << "\n"; 
   
   //Check Put-Call-Parity
    cout << "Checking Put-Call-Parity: \n"; 
    cout << "Call - Put = " << pricecall-priceput << "\n"; 
    cout << "S0 - K/R^N = " << S0 - K/pow(R,N) << "\n"; 
    cout << "-------------------------\n";    
    
    double k1=100.0, k2=110.0;  
    double pricebull; 
    BullSpreadPayoff Bull(k1, k2); 
    
    pricebull=Pricing(&Bull, &TestCase, N); 
       
    cout << "Price of bull spread with K1 = "<< k1 << " and K2 = " << k2 << " is " << pricebull <<" \n"; 
    
    CallPayoff B1(k1);
    CallPayoff B2(k2); 
    
    double C1, C2; 
    
    C1=Pricing(&B1, &TestCase, N); 
    C2=Pricing(&B2, &TestCase, N); 
    
    cout << "Constructing the bull spread from call options: \n"; 
    cout << "Buy one call with lower strike price K1 and sell one call with higher strike price K2.  \n"; 
    
    cout << "Price of Call with strike K1 is " << C1<< "\n";
    cout << "Price of Call with strike K2 is " << C2<< "\n";
    cout << "(Price of Call with strike K1) - (Price of Call with strike K2) is " << C1-C2<< "\n"; 
    
    //In this example we buy one at-the-money call K1=S0 and sell one out-of-the-money call with K2>K1.  
    
 system("PAUSE");
 return 0; 

}
