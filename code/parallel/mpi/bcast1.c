#include <mpi.h>
#include <stdio.h>
int main(int argc, char **argv) {
  int procID, buf[2];
  MPI_Status status;

  MPI_Init( &argc, &argv );
  MPI_Comm_rank( MPI_COMM_WORLD, &procID );

  if (procID == 0) {
    buf[0] = 12345;
    buf[1] = 67890;
  } 

  MPI_Bcast(&buf, 2, MPI_INT, 0, MPI_COMM_WORLD);
  printf("Process %d data %d %d\n", procID, buf[0], buf[1]);

  MPI_Finalize();
  return 0;

}
