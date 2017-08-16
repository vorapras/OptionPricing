//BiSec2.cpp
#include "BiSec2.h"
#include <cmath>
#include <iostream>


double Bisection2(FunctionClass *FCptr, double a, double b, double c, double epsilon)
{
       double left=a, right=b, middle=0.5*(left+right); 
       double fleft, fright, fmiddle; 
       fleft=FCptr->Value(left)-c; 
       fright=FCptr->Value(right)-c; 
       fmiddle=FCptr->Value(middle)-c; 
       //std::cout<< "fleft=" << fleft << "  fright=" << fright << "  fmiddle="<< fmiddle << "\n"; 
       if (fleft*fright > 0.0){exit(1);}
       
       while ((right-left)>epsilon)
       {
            if (fleft*fmiddle <= 0.0){right=middle; fright=fmiddle; } 
            else {left = middle; fleft=fmiddle;}
            middle=0.5*(left+right); 
            fmiddle=FCptr->Value(middle)-c; 
       }      
       
       return middle;       
       
}
