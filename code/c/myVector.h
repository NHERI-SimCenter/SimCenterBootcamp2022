
#ifndef _MY_VECTOR_H
#define _MY_VECTOR_H

#include <stdio.h>

double *createMyVector(int size);
double normMyVector(double *data, int size);
double dotMyVector(double *data1, double *data2, int size);
void dotSumMyVector(double *data1, double *data2, double *result, int size);
void printMyVector(double *data, int size, char *name);

#endif
