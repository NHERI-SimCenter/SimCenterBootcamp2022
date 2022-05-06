#!/bin/bash

#--------------------------------------------------------------------
# Generic SLURM script -- MPI Hello World
#
# This script requests 1 node and 8 cores/node (out of total 64 avail)
# for a total of 8 MPI tasks.
#---------------------------------------------------------------------
#SBATCH -J myjob          # Job name
#SBATCH -o myjob.%j.out   # stdout; %j expands to jobid
#SBATCH -e myjob.%j.err   # stderr; skip to combine stdout and stderr
#SBATCH -p development    # queue
#SBATCH -N 1              # Number of nodes, not cores (64 cores/node)
#SBATCH -n 8              # Total number of MPI tasks (if omitted, n=N)
#SBATCH -t 00:00:10       # max time

module petsc    # load any needed modules, these just examples
moduele load list

ibrun ./a.out