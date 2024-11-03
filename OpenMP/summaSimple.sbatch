bash summa
#!/bin/bash
#SBATCH --job-name=summaSimple       # nombre del trabajo
#SBATCH --output=summaSimple.out     # archivo de salida
#SBATCH --error=summaSimple.err      # archivo de error
#SBATCH --ntasks=1                   # número de tareas
#SBATCH --cpus-per-task=4            # número de hilos por tarea
#SBATCH --time=00:10:00              # tiempo máximo de ejecución (hh:mm:ss)

# carga el módulo OpenMPI
module load gcc/9.3.0

# establece el número de hilos
export OMP_NUM_THREADS=4

# ejecuta el programa
./omp_summaSimple
