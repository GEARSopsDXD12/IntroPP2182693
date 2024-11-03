
#!/bin/bash
#SBATCH --job-name=MPI
#SBATCH --nodes=2
#SBATCH --ntasks=2
#SBATCH --cpus-per-task=8

#SBATCH --output=output_summaSimple.txt%j.out
#SBATCH --error=error_summaSimple.err%j.err

Load GCC and MPI modules
module load devtools/gcc/6.2.0
module load devtools/mpi/openmpi/3.1.4

Compile the "summaSimple.c", "mpi_summaSimple.c", and "omp_summaSimple.c" files
gcc -O3 summaSimple.c -o summaSimple
gcc -fopenmp -O3 omp_summaSimple.c -o omp_summaSimple
mpicc -O3 mpi_summaSimple.c -o mpi_summaSimple

Run the programs with input 10 and export the output to a text file
echo "Input: 10" >> output_summaSimple.txt
echo -e "\nSequential version:" >> output_summaSimple.txt
./summaSimple 10 >> output_summaSimple.txt

echo -e "\nOpenMP version:" >> output_summaSimple.txt
./omp_summaSimple 10 >> output_summaSimple.txt

echo -e "\nMPI version:" >> output_summaSimple.txt
mpiexec -n 2 ./mpi_summaSimple 10 >> output_summaSimple.txt

echo "Execution completed."
