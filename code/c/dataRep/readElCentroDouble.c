#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
  FILE *fpIN, *fpOUT;
  fpIN = fopen("elCentro.dat","r");
  fpOUT = fopen("elCentro.bin","w");

  double data;
  char *dataC = (char *)&data;
  while (fscanf(fpIN,"%lf",&data) != EOF) {
    //    fprintf(stderr,"%f",data);
    fprintf(fpOUT,"%c%c%c%c%c%c%c%c",dataC[0],dataC[1],dataC[2],dataC[3],dataC[4],dataC[5],dataC[6],dataC[7]);
  }
  fclose(fpIN);
  fclose(fpOUT);

  fpOUT = fopen("elCentro.txt","w");
  fpIN = fopen("elCentro.bin","r");
  while (fscanf(fpIN,"%c%c%c%c%c%c%c%c",&dataC[0],&dataC[1],&dataC[2],&dataC[3],&dataC[4],&dataC[5],&dataC[6],&dataC[7]) != EOF) {
    // fprintf(stderr,"%f",data);
    fprintf(fpOUT,"%f\n",data);
  }
  fclose(fpIN);
  fclose(fpOUT);
}  


