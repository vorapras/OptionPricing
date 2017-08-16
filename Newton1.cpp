//Newton1.cpp
#include "Newton1.h"
#include <cmath>
#include <iostream>

double Newton1(double (*Fptr) (double x), double c, double (*FptrDeriv) (double xx), double x0, double epsilon, int MaxIter)
{
       double xn, xnplus1, funxn, derivxn, testaccuracy;  
       
       xn=x0; 
       testaccuracy=epsilon+10.0; 
       int i=0; 
       while ((i < MaxIter)&&(testaccuracy > epsilon))
       {
             funxn=Fptr(xn);
             //This would be equivalent: 
             //funxn=(*Fptr)(xn); 
             derivxn=FptrDeriv(xn); 
             xnplus1=xn-(funxn-c)/derivxn;  
             std::cout<<"New xnplus1 = " << xnplus1 << "\n";     
             
             testaccuracy = fabs(xnplus1-xn); 
             xn=xnplus1; 
             i++;       
       }
       std::cout<<"Newton method stopped after i=" << i << " iterations \n"; 
       return xn;       
       
}

