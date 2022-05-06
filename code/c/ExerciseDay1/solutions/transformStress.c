// program to transform stress:
//
// sigmaX' = sigmaX * cos^2(theta) + sigmaY * sin^2(theta) + 2 * tauXY Sin(theta)Cos(theta)
// sigmaY' = sigmaX * sin^2(theta) + sigmaY * cos^2(theta) - 2 * tauXY Sin(theta)Cos(theta)
// tauXY' = (sigmaY-sigmaX) * sin(theta)cos(theta) + tauXY(cos^2(theta) - sin^2(theta))
//
// write a program to take 4 inputs: sigmaX, sigmaY, tauXY, theta
// output transformed stresses: sigmaX', sigmaY', tauXY'
//
// NOTE: perform the transformation inside a function that cannot be named main
//
// Extend to possibly include all outputs for a Mohr circle, were the theta now provided is a deltaTheta

#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void transformStress(float *stressIN, float theta, float *stressTransformed);

int main(int argc, char **argv) {

  // NOTE: if 5 args are provided, the program will output data for a Mohr Circle
  if (argc != 5 && argc != 6) {
    printf("Usage: appName sigX sigY tauXY theta <anything>\n");
    exit(-1);
  }

  float vectorIN[3], vectorTransformed[3];
  vectorIN[0] = atof(argv[1]);
  vectorIN[1] = atof(argv[2]);
  vectorIN[2] = atof(argv[3]);
  float theta = atof(argv[4]);  


  if (argc == 5) {

    // 4 args: Compute single transformed stress for theta provided
    
    transformStress(vectorIN, theta, vectorTransformed);
    printf("%f, %f, %f\n", vectorTransformed[0], vectorTransformed[1], vectorTransformed[2]);
    
  } else {

    // 5 args provided: compute Mohr circle using deltaTheta
    
    // print current
    printf("%f, %f, %f, %f\n", 0.0, vectorIN[0], vectorIN[1], vectorIN[2]);    

    // compute for all angles until we reach 360 (don't compute for 360)
    float currentTheta = theta;
    while (currentTheta < 360.) {
      transformStress(vectorIN, currentTheta, vectorTransformed);
      printf("%f, %f, %f, %f\n", currentTheta, vectorTransformed[0],
	     vectorTransformed[1], vectorTransformed[2]);      
      currentTheta += theta;
    }
  }
  
  return 0;
}

void transformStress(float *stressIN, float theta, float *stressTransformed) {

  float sigX  = stressIN[0];
  float sigY  = stressIN[1];
  float tauXY = stressIN[2];    

  // convert theta to radians & compute sin and cos of the angle
  
  float thetaRadians = theta*180.0/M_PI; // M_PI is PI as a double from the math.h file
  float cosX = cos(thetaRadians);
  float sinX = sin(thetaRadians);

  stressTransformed[0] = sigX*cosX*cosX + sigY*sinX*sinX + 2*tauXY * sinX*cosX;
  stressTransformed[1] = sigX*sinX*sinX + sigY*cosX*cosX - 2*tauXY * sinX*cosX;
  stressTransformed[2] = (sigY-sigX)*sinX*cosX + tauXY * (cosX*cosX - sinX*sinX);
}
