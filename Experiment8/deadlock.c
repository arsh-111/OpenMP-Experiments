#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    int rank;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    int message = rank; // Each process sends its rank

    if (rank == 0) {
    printf("Process 0: Sending to Process 1...\n");
    MPI_Ssend(&message, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);  // Forces blocking
    printf("Process 0: Waiting to receive from Process 1...\n");
    MPI_Recv(&message, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
}
else if (rank == 1) {
    printf("Process 1: Sending to Process 0...\n");
    MPI_Ssend(&message, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);  // Forces blocking
    printf("Process 1: Waiting to receive from Process 0...\n");
    MPI_Recv(&message, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

}

    MPI_Finalize();
    return 0;
}
