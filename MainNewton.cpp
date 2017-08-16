//MainNewton.cpp
#include<iostream>
#include<cmath>
#include "Newton1.h"
#include "Newton2.h"
#include "FunctionClass2.h"

using namespace std;

double testf(double x)
{
       return exp(x); 
}

double derivtestf(double x)
{
       return exp(x);       
}

int main()
{   
    cout << "Solution to e^x=1 is " << Newton1(testf, 1.0,  derivtestf, 0.5, 0.00001, 100000) << "\n"; 
    //cout << "Solution to e^x=1 is " << Newton1(&testf, 1.0,  &derivtestf, 0.5, 0.00001, 100000) << "\n"; 
    //You can also do the following:
    //cout << "Solution to e^x=1 is " << Newton1(exp, 1.0,  exp, 0.5, 0.00001, 1000000) << "\n"; 
    //cout << "Solution to e^x=1 is " << Newton1(&exp, 1.0,  exp, 0.5, 0.00001, 1000000) << "\n"; 

    cout << "---------------------------\n"; 
    
    cout << "Testing the FunctionClass: \n"; 
    MyFun TestFun(3.0); 
    //cout << TestFun.Value(2.5) << "\n"; 
    //cout << TestFun.Value(3.7) << "\n"; 
    
    cout << "Solution to (x-3.0)^3=0 is " << Newton2(&TestFun, 0.0, 2.0, 0.00001, 1000) << "\n"; 
    
  
 system("PAUSE");
 return 0; 

}
