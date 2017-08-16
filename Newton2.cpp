//Newton2.cpp
#include "Newton2.h"
#include <cmath>
#include <iostream>


double Newton2(FunctionClass2 *FCptr, double c, double x0, double epsilon, int MaxIter)
{       
       double xn, xnplus1, funxn, derivxn, testaccuracy;  
       
       xn=x0; 
       testaccuracy=epsilon+10.0; 
       int i=0; 
       while ((i < MaxIter)&&(testaccuracy > epsilon))
       {
             funxn=FCptr->Value(xn);
             derivxn=FCptr->Derivative(xn); 
             xnplus1=xn-(funxn-c)/derivxn;  
             std::cout<<"New xnplus1 = " << xnplus1 << "\n";     
             
             testaccuracy = fabs(xnplus1-xn); 
             xn=xnplus1; 
             i++;       
       }
       std::cout<<"Newton method stopped after i=" << i << " iterations \n"; 
       return xn;      
       
       
}
