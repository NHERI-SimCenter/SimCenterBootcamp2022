#include <mpi.h>
#include <stdio.h>
int main(int argc, char **argv) {
  int procID, numP;
  MPI_Status status;

  MPI_Init( &argc, &argv );
  MPI_Comm_size( MPI_COMM_WORLD, &numP );
  MPI_Comm_rank( MPI_COMM_WORLD, &procID );

  if (procID == 0) {
    int buf[2] = {12345, 67890};
    MPI_Send(&buf, 2, MPI_INT, 1, 0, MPI_COMM_WORLD);
  } else if (procID == 1) {
    int data[2];
    MPI_Recv(&data, 2, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    printf("Received %d %d\n", data[0], data[1]);
  }
  MPI_Finalize();
  return 0;

}
