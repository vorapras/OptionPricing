//Payoff.cpp

#include "Payoff.h"

//Definition of the constructor for Payoff
Payoff::Payoff(void)
{                   
}


//Definition of the constructor for CallPayoff
CallPayoff::CallPayoff(double k)
{ 
  Strike=k;
}

double CallPayoff::computepayoff(double spot)const
{
 if (spot > Strike) return spot-Strike; 
 else return 0.0; 
}


//Definition of the constructor for PutPayoff
PutPayoff::PutPayoff(double k)
{
 Strike=k;
}



double PutPayoff::computepayoff(double spot)const
{
 if (Strike > spot) return Strike-spot; 
 else return 0.0; 
}


BullSpreadPayoff::BullSpreadPayoff(double k1, double k2)
{
 if (k1 < k2)
 {
  K1=k1; 
  K2=k2;        
 }       
 else
 {
  K1=k2;    
  K2=k1; 
 }                                                                                                                 
}

double BullSpreadPayoff::computepayoff(double spot)const
{
 if (K1 >= spot) return 0; 
 else if (K2 <= spot) return K2-K1; 
 else return spot-K1;        
}

//You could define these functions as inline if you want to (but then they should be in the .h file).  
