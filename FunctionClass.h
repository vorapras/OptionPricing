//FunctionClass.h
#ifndef FUNCTIONCLASS_H
#define FUNCTIONCLASS_H

class FunctionClass{
public: 
virtual double Value(double x) =0; 
}; 

class F1 : public FunctionClass{
private: 
      double d;    
public: 
      F1(double dd);        
      virtual double Value(double x); 
};       


class FunClassBS : public FunctionClass{
private: 
         double S0, r; 
         double K, T;       
public:
       FunClassBS(double tmpS0, double tmpK, double tmpr, double tmpT); 
       virtual double Value(double x);  
      
};       


#endif
