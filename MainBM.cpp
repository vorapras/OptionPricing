//MainBM.cpp
#include<iostream>
#include "BinomialModel.h"
#include "FunBM.h"

using std::cout;

int main()
{
 cout << "Applications of the Binomial Model: \n";

 BinomialModel A(100.0, 1.5, 0.66, 1.02);

 cout<< "Risk neutral probability is: " << A.RiskNeutralProb() << "\n";
 cout<< "R is: " << A.GetR() << "\n";

 cout<< "Stock price at time 0 is: " << A.Stock(0, 0) << "\n";
 cout<< "Stock price at time 1 after one upwardsstep is: " << A.Stock(1, 1) << "\n";
 cout<< "Stock price at time 1 after one downwardsstep is: " << A.Stock(1, 0) << "\n";
 BinomialModel B(100.0, 0.66, 1.55, 1.02);


 //BinomialModel TestCase(100.0, 1.5,0.66, 1.02);

 //double res=pricingCall(&TestCase, 100.0, 2);
 //cout<<"Price of Call is " <<  res << "\n";

 system("PAUSE");
 return 0;
}
