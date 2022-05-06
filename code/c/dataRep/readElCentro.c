#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv) {
  FILE *fpIN, *fpOUT;
  fpIN = fopen("elCentro.dat","r");
  fpOUT = fopen("elCentro.bin","w");

  float data;
  char *dataC = (char *)&data;
  while (fscanf(fpIN,"%f",&data) != EOF) {
    //    fprintf(stderr,"%f",data);
    fprintf(fpOUT,"%c%c%c%c",dataC[0],dataC[1],dataC[2],dataC[3]);
  }
  fclose(fpIN);
  fclose(fpOUT);

  fpOUT = fopen("elCentro.txt","w");
  fpIN = fopen("elCentro.bin","r");
  while (fscanf(fpIN,"%c%c%c%c",&dataC[0],&dataC[1],&dataC[2],&dataC[3]) != EOF) {
    // fprintf(stderr,"%f",data);
    fprintf(fpOUT,"%f\n",data);
  }
  fclose(fpIN);
  fclose(fpOUT);
}  


