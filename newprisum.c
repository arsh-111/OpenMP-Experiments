#include <stdio.h>
#include <omp.h>

int main() {
    int sum = 0;
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    #pragma omp parallel
    {
        int local_sum = 0;  // Local sum for each thread

        #pragma omp for ordered
        for (int i = 0; i < n; i++) {
            local_sum += arr[i];  // Each thread accumulates its own local sum

            #pragma ordered
            {
                printf("Thread id = %d, sum = %d\n", omp_get_thread_num(), local_sum);
            }
        }

        // Synchronizing the global sum update
        #pragma omp critical
        sum += local_sum;
    }

    printf("Total Sum = %d\n", sum);  // Final accumulated sum
    return 0;
}

