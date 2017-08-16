//MainDiscreteSample.cpp
#include<cstdlib>
#include<iostream>
#include<cmath>

using namespace std;

double myrandomnumber(double *probs, double *values, int n)
{       
       double myuniform, result; 
       myuniform=rand()/static_cast<double>(RAND_MAX); 
       //cout << "myuniform=" << myuniform << "\n"; 
       double *qs=new double [n+1]; 
       qs[0]=0.0; 
       //cout << "qs[0]=" << qs[0]<< "\n"; 
       
       int i=1; 
       bool found=false; 
       while ((i <=n) && (found==false))
       {
              qs[i]=qs[i-1] + probs[i-1]; 
              if ((myuniform > qs[i-1]) && (myuniform <= qs[i]))
              {
                 found=true; 
                 result=values[i-1];                
              }
              //cout << "qs[" << i << "]=" << qs[i] << "\n";  
              i++;        
       }
       
       delete []qs; 
       return result;             
}

int main()
{   
    srand((unsigned)time(0)); 
    double cs[]={1, 3, 7, 10}; 
    double probs[] = {0.1, 0.3, 0.5, 0.1}; 
    
    double expectation=0.0; 
    for (int i=0; i < 4; i++) expectation=expectation+cs[i]*probs[i]; 
    
    cout << "expectation= " << expectation << "\n"; 
    
    double test=0.0; 
    int N=10000; 
    
    for(int i=0; i<N; i++)
    {
            test=test+myrandomnumber(probs, cs, 4); 
    }
    
    cout << "test=" << test/static_cast<double>(N) << "\n"; 
    
    cout << "Random number = "  << myrandomnumber(probs, cs, 4) << "\n"; 
     
    
  
 system("PAUSE");
 return 0; 

}
