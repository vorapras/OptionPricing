//FunctionClass.cpp
#include "FunctionClass.h"
#include "BSFun.h"


//Definitions of member functions of class F1
F1::F1(double dd){
d=dd;
}
       
double F1::Value(double x)
{
       return (x-d)*(x-d)*(x-d); 
}

//Definitions of member functions of class FunClassBS

FunClassBS::FunClassBS(double tmpS0, double tmpK, double tmpr, double tmpT)
{
  S0=tmpS0; K=tmpK; r=tmpr; T=tmpT;                             
} 

double FunClassBS::Value(double x){
return BSCall(S0, K, r, x, T);                                                   
}  
