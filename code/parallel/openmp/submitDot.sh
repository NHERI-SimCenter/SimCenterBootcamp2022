#!/bin/bash
#--------------------------------------------------------------------
# Generic SLURM script – MPI Hello World
#
# This script requests 1 node and 8 cores/node (out of total 64 avail)
# for a total of 1*8 = 8 MPI tasks.
#---------------------------------------------------------------------
#SBATCH -J myjob
#SBATCH -o myjob.%j.out 
#SBATCH -e myjob.%j.err 
#SBATCH -p development
#SBATCH -N 1
#SBATCH -n 1
#SBATCH -t 00:02:00
#SBATCH -A DesignSafe-SimCenter

echo "DOT1"
export OMP_NUM_THREADS=1
./dot1
export OMP_NUM_THREADS=2
./dot1
export OMP_NUM_THREADS=4
./dot1
export OMP_NUM_THREADS=8
./dot1

echo "DOT2"
export OMP_NUM_THREADS=1
./dot2
export OMP_NUM_THREADS=2
./dot2
export OMP_NUM_THREADS=4
./dot2
export OMP_NUM_THREADS=8
./dot2

echo "DOT3"
export OMP_NUM_THREADS=1
./dot3
export OMP_NUM_THREADS=2
./dot3
export OMP_NUM_THREADS=4
./dot3
export OMP_NUM_THREADS=8
./dot3

echo "DOT4"
export OMP_NUM_THREADS=1
./dot4
export OMP_NUM_THREADS=2
./dot4
export OMP_NUM_THREADS=4
./dot4
export OMP_NUM_THREADS=8
./dot4

