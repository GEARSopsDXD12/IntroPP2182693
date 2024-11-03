# Comparative Performance Analysis of Sequential and Parallel Approaches on a Shared Resource System

To determine which approach has better performance in terms of acceleration and execution time, you can conduct a comparative experiment on a shared resource system (e.g., a computer with multiple CPU cores).

In the experiment, you can execute each approach multiple times and measure the execution time. Then, you can compare the execution times and calculate the acceleration obtained using the formula:

Acceleration = Sequential Execution Time / Parallel Execution Time

If the acceleration is greater than 1, it means that the parallel approach is faster than the sequential approach. Additionally, you can observe how the execution time changes as the problem size increases (e.g., the value of num in the given code) to evaluate how the performance scales.

It is important to note that performance may vary depending on the hardware, problem size, and specific implementation. Therefore, it is recommended to perform experiments in the specific execution environment and analyze the obtained results to determine which approach offers better performance in the particular case.

# How it runs on GUANE-1
1. First we are going to open a terminal in mobaxterm and then start the session using the ssh command user@toctoc.sc3.uis.edu.co
2. in a second moment we are going to place the password of our user
3. guane's server is now accessed using guane's ssh
4. then we are going to use a command to assign us a worker node within the server
5. Once we have our work node we are going to access nano to be able to place our MPI code using nano mpi_summaSimple.c
6. Then we use the command mpicc mpi summaSimple.c -o mpi_summaSimple.c
7. mpirun -np 12./mpi_summaSimple.c
8. Finally we are going to calculate the execution time of the code using time ./summaSimple and we will be able to make the respective comparison of the work.
