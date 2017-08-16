//FunctionClass2.h
#ifndef FUNCTIONCLASS2_H
#define FUNCTIONCLASS2_H

class FunctionClass2{
public: 
virtual double Value(double x) =0;
virtual double Derivative(double x)=0; 
}; 

class MyFun : public FunctionClass2{
private: 
      double d;    
public: 
      MyFun(double dd);        
      virtual double Value(double x); 
      virtual double Derivative(double x); 
};       

    


#endif
