set -x
WRAPPERDIR=$( cd "$( dirname "$0" )" && pwd )

${AGAVE_JOB_CALLBACK_RUNNING}

module load intel

cd "${inputDirectory}"

mpicc ${programFile}
ibrun ./a.out

if [ ! $? ]; then
        echo "program exited with an error status. $?" >&2
        ${AGAVE_JOB_CALLBACK_FAILURE}
        exit
fi
