#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);  // Start MPI

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Get process rank

    int a = 0;
    int b = 0;

    if (rank == 0) {
        a = 100;	// Set some value to send
	b = 101;		// 
        printf("Rank 0: Sending value %d to Rank 1\n", a);
        MPI_Send(&a, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
//MPI_Send(&b, 1, MPI_INT, 1, 1, MPI_COMM_WORLD);
    }
    else if (rank == 1) {
        MPI_Recv(&a, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Rank 1: Received value %d from Rank 0\n", a);
    }

    MPI_Finalize();  // End MPI
    return 0;
}
