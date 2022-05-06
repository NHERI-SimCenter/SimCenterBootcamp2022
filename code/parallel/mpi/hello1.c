#include <mpi.h>
#include <stdio.h>

int main( int argc, char **argv )
{
  int procID, numP;

  MPI_Init( &argc, &argv);
  MPI_Comm_size( MPI_COMM_WORLD, &numP );
  MPI_Comm_rank( MPI_COMM_WORLD, &procID );

  printf("Hello World, I am %d of %d\n", procID, numP);
  MPI_Finalize();
  return 0;
}
