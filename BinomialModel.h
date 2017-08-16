//BinomialModel.h
#ifndef BINOMIALMODEL_H
#define BINOMIALMODEL_H

#include<iostream>
#include<cmath>
using std::cout; 

class BinomialModel{
private: 
	double S0; 
	double u; 
	double d; 
	double R; 
		
public: 
	//Constructor
	BinomialModel(double initial, double up, double down, double interest); 
	
	//Returns the private variable R
	double GetR(void); 
	
	//Computes stock price at time n
	double Stock(int n, int i); 
	
	//Computes risk neutral probability
	double RiskNeutralProb(void); 
}; 

#endif
