#!/bin/bash
#--------------------------------------------------------------------
# Generic SLURM script – MPI Hello World
#
# This script requests 1 node and 1 cores/node (out of total 64 avail)
# you can run in parallel by setting OMP_NUM_THREADS
#---------------------------------------------------------------------
#SBATCH -J myjob
#SBATCH -o myjob.%j.out 
#SBATCH -e myjob.%j.err 
#SBATCH -p development
#SBATCH -N 1
#SBATCH -n 1
#SBATCH -t 00:02:00
#SBATCH -A DesignSafe-SimCenter

echo "PI1"
export OMP_NUM_THREADS=1
./pi
export OMP_NUM_THREADS=2
./pi
export OMP_NUM_THREADS=4
./pi
export OMP_NUM_THREADS=8
./pi


