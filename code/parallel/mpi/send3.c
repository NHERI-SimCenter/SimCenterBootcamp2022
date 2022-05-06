#include <mpi.h>
#include <stdio.h>
int main(int argc, char **argv) {
  int procID, numP;
  MPI_Status status;

  MPI_Init( &argc, &argv );
  MPI_Comm_size( MPI_COMM_WORLD, &numP );
  MPI_Comm_rank( MPI_COMM_WORLD, &procID );

  if (procID == 0) {
    int bufS[2] = {12345, 67890};
    int bufR[2];
    MPI_Send(&bufS, 2, MPI_INT, 1, 0, MPI_COMM_WORLD);
    MPI_Recv(&bufR, 2, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
    printf("%d Received %d %d\n", procID, bufR[0], bufR[1]);
  } else if (procID == 1) {
    int bufS[2] = {67890, 12345};
    int bufR[2];
    MPI_Recv(&bufR, 2, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    MPI_Send(&bufS, 2, MPI_INT, 0, 0, MPI_COMM_WORLD);
    printf("%d Received %d %d\n", procID, bufR[0], bufR[1]);
  }


  MPI_Finalize();
  return 0;

}
