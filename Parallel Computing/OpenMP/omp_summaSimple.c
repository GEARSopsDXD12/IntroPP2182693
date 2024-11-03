// From https://www.programiz.com/c-programming/c-for-loop 
// Modified by C. Barrios for training purposes 2023
// Simple Program to calculate the sum of first n natural numbers
// Positive integers 1,2,3...n are known as natural numbers
/*
 * Tomado de: https://github.com/carlosjaimebh/SomeExamples/blob/main/summaSimple.c
 * */
//EXAMPLE:
// 24 de abril de 2023 

#include <stdio.h>
#include <omp.h>

int main()
{
    int num, count, sum = 0;

    printf("Enter a positive integer: ");
    scanf("%d", &num);

    #pragma omp parallel for reduction(+:sum)
    for(count = 1; count <= num; ++count)
    {
        sum += count;
    }

    printf("\nSum = %d\n", sum);

    return 0;
}
/*In this code block, the pragma omp directive is used to create a team of threads and distribute the work of the for loop in parallel.
The parallel clause indicates that the following code block will be executed in parallel. The for clause indicates that the work of the for loop should be distributed among the created threads. 
The reduction clause indicates that the variable sum should be shared among the threads, and each thread should maintain a private copy of the variable.
At the end of the loop, the values of all private copies are added together and stored in the variable sum/*
