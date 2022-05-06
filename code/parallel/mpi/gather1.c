#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#define LUMP 5

int main(int argc, char **argv) {
  
  int numP, procID;

  // the usual mpi initialization
  MPI_Init(&argc, &argv);
  MPI_Comm_size(MPI_COMM_WORLD, &numP);
  MPI_Comm_rank(MPI_COMM_WORLD, &procID);

  int *globalData=NULL;
  int localData[LUMP];

  // process 0 is only 1 that needs global data
  if (procID == 0) {
    globalData = malloc(LUMP * numP * sizeof(int) );
    for (int i=0; i<LUMP*numP; i++)
      globalData[i] = 0;
  }

  for (int i=0; i<LUMP; i++)
    localData[i] = procID*10+i;
  
  MPI_Gather(localData, LUMP, MPI_INT, globalData, LUMP, MPI_INT, 0, MPI_COMM_WORLD);

  if (procID == 0) {
    for (int i=0; i<numP*LUMP; i++)
      printf("%d ", globalData[i]);
    printf("\n");
  }

  if (procID == 0)
    free(globalData);

  MPI_Finalize();
}
