//  StochProc.h

#ifndef StochProc_h
#define StochProc_h

class StochProcess
{
    public :
    double get_terminalvalue(double T,int numberofsteps, double X0);
    void get_samplepath(double T,int numberofsteps, double X0, double *p);
    
    private:
    virtual double step(double currentX,double h) = 0;
};

//Derived class for Brownian motion with drift X_t=X_0 + mu t + sigma W_t and initial value X0
//Default parameters are mu=0, sigma=1.

class BM : public StochProcess
{
    public :
    BM(double mymu = 0.0 ,double mysigma = 1.0): mu(mymu),sigma(mysigma){};
    
private:
    virtual double step(double currentX,double h);
    double mu;
    double sigma;
};

//Derived class for Geometric Brownian motion  X_t=X0*exp((mu-0.5*sigma^2) t + \sigma W_t) and initial value X0
//Default parameters are mu=0, sigma=1.

class GBM : public StochProcess
{
    public :
    GBM(double mymu = 0.0 ,double mysigma = 1.0): mu(mymu),sigma(mysigma){};
    
private:
    virtual double step(double currentX,double h);
    double mu;
    double sigma;
};



#endif /* StochProc_h */
