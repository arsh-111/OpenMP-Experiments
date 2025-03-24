#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);  // Start MPI

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Get process rank

    int a = 0;
    int b;

    if (rank == 0) {
        a = 100;        // Set some value to send
        
       
//	printf("Rank 0: Sending value %d to Rank 1\n", b);
        MPI_Ssend(&a, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
	 printf("Rank 0: Sending value %d to Rank 1\n", a);
//	MPI_Send(&b, 1, MPI_INT, 2, 2, MPI_COMM_WORLD);
	 MPI_Recv(&b, 1, MPI_INT, 1, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
    }
    else if (rank == 1) {
        
	 MPI_Ssend(&a, 1, MPI_INT, 0, 1, MPI_COMM_WORLD);
	 MPI_Recv(&b, 1, MPI_INT, 0, 1, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Rank 1: Received value %d from Rank 0\n", b);
//	printf("Rank 1: Received value %d from Rank 0\n", b);
    }

    MPI_Finalize();  // End MPI
    return 0;
}
