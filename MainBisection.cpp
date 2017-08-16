//MainBisection.cpp
#include<iostream>
#include<cmath>
#include "BiSec1.h"
#include "BiSec2.h"
#include "BSFun.h"
#include "FunctionClass.h"

using namespace std;

double testf(double x)
{
       return exp(x); 
}

int main()
{   
    
    cout << "Solution to e^x=1 is " << Bisection1(testf,  -3.0, 5.0, 1.0, 0.00001) << "\n";
    cout << "Solution to e^x=1 is " << Bisection1(testf,  -2.0, 2.0, 1.0, 0.00001) << "\n"; 
    //You can also do the following:
    //cout << "Solution to e^x=1 is " << Bisection1(&testf,  -3.0, 5.0, 1.0, 0.00001) << "\n";
    //cout << "Solution to e^x=1 is " << Bisection1(exp,  -3.0, 5.0, 1.0, 0.00001) << "\n"; 
    //cout << "Solution to e^x=1 is " << Bisection1(&exp,  -3.0, 5.0, 1.0, 0.00001) << "\n"; 

    cout << "---------------------------\n"; 
    
    cout << "Testing the FunctionClass: \n"; 
    F1 TestFun(3.0); 
    //cout << TestFun.Value(2.5) << "\n"; 
    //cout << TestFun.Value(3.7) << "\n"; 
    
    cout << "Solution to (x-3.0)^3=0 is " << Bisection2(&TestFun, 2.5, 3.7, 0.0, 0.00001) << "\n"; 
    
    
    double K=100.0, S0=100.0; 
    double T=1.0, sigma=0.2, r=0.01; 
    double priceBS; 
    
    priceBS = BSCall(S0, K, r, sigma, T); 
    cout<<"Call price in Black Scholes model: " << priceBS << "\n"; 
    
    FunClassBS A(S0, K, r, T); 
    double pmarket=9.0; 
    cout << "Call price in Black Scholes model (using class FunClassBS): " << A.Value(sigma) << "\n"; 
    cout << "Implied volatility for market price " << pmarket << " is "<< Bisection2(&A,  0.001, 1.0, pmarket, 0.00001) << "\n"; 
     
 system("PAUSE");
 return 0; 

}
