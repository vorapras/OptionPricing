//Newton1.h
#ifndef NEWTON1_H
#define NEWTON1_H


double Newton1(double (*Fptr) (double x), double c, double (*FptrDeriv) (double xx), double x0, double epsilon, int MaxIter); 



#endif
