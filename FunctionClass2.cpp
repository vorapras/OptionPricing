//FunctionClass2.cpp
#include "FunctionClass2.h"


//Definitions of member functions of class MyFun
MyFun::MyFun(double dd){
d=dd;
}
       
double MyFun::Value(double x)
{
       return (x-d)*(x-d)*(x-d); 
}
 
double MyFun::Derivative(double x)
{
       return 3.0*(x-d)*(x-d); 
}
