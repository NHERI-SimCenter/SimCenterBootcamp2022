#include <mpi.h>
#include <stdio.h>
#define DATA_SIZE 10000
int main(int argc, char **argv) {
  int procID, numP;
  MPI_Status status;

  MPI_Init( &argc, &argv );
  MPI_Comm_size( MPI_COMM_WORLD, &numP );
  MPI_Comm_rank( MPI_COMM_WORLD, &procID );

  int buf[DATA_SIZE];
  if (procID == 0) {
    printf("Buffer Size: %d\n",DATA_SIZE);
    for (int i=0; i<DATA_SIZE; i++) buf[i]=1+i;
    MPI_Send(&buf, DATA_SIZE, MPI_INT, 1, 0, MPI_COMM_WORLD);
    MPI_Recv(&buf, DATA_SIZE, MPI_INT, 1, 0, MPI_COMM_WORLD, &status);
    printf("%d Received %d %d\n", procID, buf[0], buf[DATA_SIZE-1]);
  } else if (procID == 1) {
    for (int i=0; i<DATA_SIZE; i++) buf[i]=DATA_SIZE-i;
    MPI_Send(&buf, DATA_SIZE, MPI_INT, 0, 0, MPI_COMM_WORLD);
    MPI_Recv(&buf, DATA_SIZE, MPI_INT, 0, 0, MPI_COMM_WORLD, &status);
    printf("%d Received %d %d\n", procID, buf[0], buf[DATA_SIZE-1]);
  }

  MPI_Finalize();
  return 0;

}
