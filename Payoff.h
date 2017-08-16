//Payoff.h
#ifndef PAYOFF_H
#define PAYOFF_H

//Note that the class Payoff is an abstract class since it contains a pure virtual function computepayoff. 
//You can see this from the "=0" part. 
class Payoff
{
      public: 
              Payoff(void);    //constructor   
              virtual double computepayoff(double spot) const=0; //function computes the payoff for a given spot price
};

//Call-----------------------------------------------
class CallPayoff : public Payoff
{
      public:
              CallPayoff(double k);   //constructor   
              virtual double computepayoff(double spot)const; //function computes the payoff for a given spot price              
      private:    
      double Strike;
};

//Put-------------------------------------------------------
class PutPayoff : public Payoff
{
      public:
              PutPayoff(double k);   //constructor   
              virtual double computepayoff(double spot)const; //function computes the payoff for a given spot price
      private:    
      double Strike;
};

//Bull spread
class BullSpreadPayoff : public Payoff
{
      public:
              BullSpreadPayoff(double k1, double k2);   //constructor   
              virtual double computepayoff(double spot)const; //function computes the payoff for a given spot price
      private:    
      double K1, K2;
}; 
#endif
