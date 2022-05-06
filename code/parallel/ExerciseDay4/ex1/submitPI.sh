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

ibrun ./pi 


