//FunBM.h
#ifndef FUNBM_H
#define FUNBM_H

#include "BinomialModel.h"

double pricingCall(BinomialModel *B, double strike, int N); 

double mymax(double a, double b); 

#endif
