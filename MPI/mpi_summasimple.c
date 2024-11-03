#include <stdio.h>
#include <mpi.h>

int main(int argc, char** argv)
{
    int num, count, sum = 0;
    int rank, size;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    if (rank == 0)
    {
        printf("Enter a positive integer: ");
        scanf("%d", &num);
    }

    MPI_Bcast(&num, 1, MPI_INT, 0, MPI_COMM_WORLD);

    int start = rank * (num / size) + 1;
    int end = (rank + 1) * (num / size);

    if (rank == size - 1)
    {
        end = num;
    }

    for (count = start; count <= end; ++count)
    {
        sum += count;
    }

    int totalSum = 0;
    MPI_Reduce(&sum, &totalSum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if (rank == 0)
    {
        printf("\nSum = %d\n", totalSum);
    }


    MPI_Finalize();

    return 0;
}

/*In this version, we have added the necessary MPI calls to initialize the MPI environment, obtain the rank and size of the communicator, and synchronize the value of num across all processes using MPI_Bcast.

Then, we calculate the range of values to sum based on the process rank and the total size. Each process adds up its assigned range.

Finally, we use MPI_Reduce to sum all the partial sum values and obtain the final result in process 0. The final result is printed only in process 0 after the reduction.

Please note that to compile and execute this code, you need to have a compatible MPI library installed and use the appropriate compilation commands.
