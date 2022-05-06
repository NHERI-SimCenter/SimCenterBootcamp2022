#!/bin/bash
#--------------------------------------------------------------------
# Generic SLURM script – MPI Hello World
#
# This script requests 1 node and 8 cores/node (out of total 64 avail)
# for a total of 1*8 = 8 MPI tasks.
#---------------------------------------------------------------------
#SBATCH -J myjob
#SBATCH -o myjob.out 
#SBATCH -e myjob.err 
#SBATCH -p development
#SBATCH -N 1
#SBATCH -n 1
#SBATCH -t 00:02:00
#SBATCH -A DesignSafe-SimCenter

echo "SUM1"
export OMP_NUM_THREADS=1
./sum1
export OMP_NUM_THREADS=2
./sum1
export OMP_NUM_THREADS=4
./sum1
export OMP_NUM_THREADS=8
./sum1

echo "SUM2"
export OMP_NUM_THREADS=1
./sum2
export OMP_NUM_THREADS=2
./sum2
export OMP_NUM_THREADS=4
./sum2
export OMP_NUM_THREADS=8
./sum2

echo "SUM3"
export OMP_NUM_THREADS=1
./sum3
export OMP_NUM_THREADS=2
./sum3
export OMP_NUM_THREADS=4
./sum3
export OMP_NUM_THREADS=8
./sum3


