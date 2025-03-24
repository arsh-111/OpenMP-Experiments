#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int rank, num_procs;

    MPI_Init(&argc, &argv);  // Initialize MPI
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Get process rank
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);  // Get total number of processes

    printf("Hello World from process %d out of %d\n", rank, num_procs);

    MPI_Finalize();  // Finalize MPI
    return 0;
}


