#include <mpi.h>
#include <stdio.h>

int main(int argc, char* argv[]) {
    MPI_Init(&argc, &argv);

    int rank, size;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Get current process rank
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Get total number of processes

    int send_data = rank;  // Send rank as data
    int recv_data;

    // Define left and right neighbors
    int left = (rank - 1 + size) % size;
    int right = (rank + 1) % size;

    // Send to right neighbor, receive from left neighbor
    MPI_Send(&send_data, 1, MPI_INT, right, 0, MPI_COMM_WORLD);
    MPI_Recv(&recv_data, 1, MPI_INT, left, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    printf("Process %d received data %d from process %d\n", rank, recv_data, left);

    MPI_Finalize();
    return 0;
}
