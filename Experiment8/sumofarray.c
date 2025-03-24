#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    int rank, num_procs;
    int A[] = {1, 2, 3, 4, 5, 6, 7, 8}; // Example array (size = 8)
    int local_sum = 0, total_sum = 0;
    int n = 8; // Size of the array

    MPI_Init(&argc, &argv);  
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &num_procs);

    // Each process sums half of the array
    for (int i = rank * (n / 2); i < (rank + 1) * (n / 2); i++) {
        local_sum += A[i];
    }

    // Process 1 sends its sum to Process 0
    if (rank == 0) {
        int other_sum;
        MPI_Recv(&other_sum, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        total_sum = local_sum + other_sum;
        printf("Total sum = %d\n", total_sum);
    } else {
        MPI_Send(&local_sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    return 0;
}

