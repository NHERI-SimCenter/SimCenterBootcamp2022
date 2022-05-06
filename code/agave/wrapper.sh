
set -x
WRAPPERDIR=$( cd "$( dirname "$0" )" && pwd )

${AGAVE_JOB_CALLBACK_RUNNING}

module load intel

echo "program file is ${programFile}"
pwd
ls -sal
cd "${inputDirectory}"
echo "currentDIR"
pwd
echo "directory listing"
ls -sal

mpicc ${programFile}
ibrun ./a.out

if [ ! $? ]; then
        echo "program exited with an error status. $?" >&2
        ${AGAVE_JOB_CALLBACK_FAILURE}
        exit
fi
