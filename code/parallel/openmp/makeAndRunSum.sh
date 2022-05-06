gcc -fopenmp sum1.c -lm -o sum1
gcc -fopenmp sum2.c -lm -o sum2
gcc -fopenmp sum3.c -lm -o sum3
sbatch submitSum.sh
