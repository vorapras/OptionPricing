//BiSec1.cpp
#include "BiSec1.h"
#include <cmath>
#include <iostream>

double Bisection1(double (*Fptr) (double x), double a, double b, double c, double epsilon)
{
       double left=a, right=b, middle=0.5*(left+right); 
       double fleft, fright, fmiddle; 
       fleft=Fptr(left)-c;
       //This would be equivalent: 
       //fleft=(*Fptr)(left)-c; 
       fright=Fptr(right)-c; 
       fmiddle=Fptr(middle)-c; 
       //std::cout<< "fleft=" << fleft << "  fright=" << fright << "  fmiddle="<< fmiddle << "\n"; 
       if (fleft*fright > 0.0){exit(1);}
       
       while ((right-left)>epsilon)
       {
            if (fleft*fmiddle <= 0.0){right=middle; fright=fmiddle; } 
            else {left = middle; fleft=fmiddle;}
            middle=0.5*(left+right); 
            fmiddle=Fptr(middle)-c; 
       }      
       
       return middle;       
       
}
