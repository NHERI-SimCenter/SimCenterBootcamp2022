#ifndef STRESSTRANSFORM_H
#define STRESSTRANSFORM_H

typedef struct {
	double sigx;
	double sigy;
	double tau;
} STRESS ;

void StressTransform(STRESS s, STRESS *sp, double theta);

#endif

