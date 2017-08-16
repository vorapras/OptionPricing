//TestingConst_Main.cpp
#include<iostream>

using namespace std;


class Payoff_A
{
      public: 
              Payoff_A(){}   //constructor   
              virtual double computepayoff(double spot) const=0; //function computes the payoff for a given spot price
      private:    
};

//Call-----------------------------------------------
class CallPayoff_A : public Payoff_A
{
      public:
              CallPayoff_A(double k){Strike=k;}   //constructor   
              virtual double computepayoff(double spot)const 
              {
                      if (spot > Strike) return spot-Strike; 
                      else return 0.0;
              }             
      private:    
      double Strike;
};


class Payoff_B
{
      public: 
              Payoff_B(){}   //constructor   
              virtual double computepayoff(double spot)=0; //function computes the payoff for a given spot price
      private:    
};

//Call-----------------------------------------------
class CallPayoff_B : public Payoff_B
{
      public:
              CallPayoff_B(double k){Strike=k;}   //constructor   
              virtual double computepayoff(double spot) 
              {
                      if (spot > Strike) return spot-Strike; 
                      else return 0.0;
              }             
      private:    
      double Strike;
};


int main()
{   
  cout<<"Testing the meaning of const after a function: \n"; 
  CallPayoff_A test1(5); 
  cout << "Payoff is " << test1.computepayoff(20) << "\n"; 
  
  const CallPayoff_A test2(5); 
  cout << "Payoff is " << test2.computepayoff(20) << "\n";  
  
  CallPayoff_B test3(5); 
  cout << "Payoff is " << test3.computepayoff(20) << "\n"; 
  
  const CallPayoff_B test4(5);
  //This will not compile:  
 // cout << "Payoff is " << test4.computepayoff(20) << "\n"; 
  
 //The reason for that is that test4 is constant and hence cannot be changed. 
 //From the definition of the member function in Payoff_B it is not clear that 
 //computepayoff() does not attempt to modify the object test4. 
 //In general, one can include the const specifier at the end of the function declaration
 //for any member function that does not modify any data member.      
 //You can read more details about this in Capper (2001), Section 8.14,  p. 229-231.    
    
 system("PAUSE");

}
