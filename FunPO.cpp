//FunPO.cpp
#include "FunPO.h"

double Pricing(Payoff *PO, BinomialModel * B, int N) 
{
   double time0price=0.0; 
   //cout<<"Pricing of European option with N="<< N << ": \n";     
   int sizeoftree=N+1;     
      
   //Creating the array for saving the prices: 
   double *prices=new double[sizeoftree]; 
   
   //Computing time-T price of the option (start of backward recursion):
   //cout<<"-------------time step n=" << N << "-----------\n";  
   for(int i=0; i<sizeoftree; i++)
   {
    prices[i]=PO->computepayoff(B->Stock(N, i));
    //cout << "stock price["<< i <<"]= " << B->Stock(N, i) << ", option prices[" << i << "]="<<prices[i]<< "\n"; 
    }
    //cout << "\n";    
       
   //Compute risk-neutral probability and interest: 
   double qtmp=B->RiskNeutralProb(); 
   double Rtmp=B->GetR();            
   
   //Backward recursion: 
   for(int n=N-1; n>=0; n--)
   {
     //cout<<"-------------time step n=" << n << "-----------\n"; 
     for(int i=0; i<n+1; i++)
     {
      prices[i]=(qtmp*prices[i+1]+(1-qtmp)*prices[i])/Rtmp;
      //cout << "option prices[" << i << "]="<<prices[i]<< "  "; 
     }  
     //cout << "\n";     
   }
   //cout<<"-------------------------------------\n"; 
   time0price=prices[0]; 
   delete [] prices; 
   return time0price;     
} 
