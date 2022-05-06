
set -x
WRAPPERDIR=$( cd "$( dirname "$0" )" && pwd )

${AGAVE_JOB_CALLBACK_RUNNING}

# compile the program
module load intel
mpicc ${programFile}

# run it
ibrun ./a.out

# clean up
rm ./a.out

if [ ! $? ]; then
        echo "program exited with an error status. $?" >&2
        ${AGAVE_JOB_CALLBACK_FAILURE}
        exit
fi
