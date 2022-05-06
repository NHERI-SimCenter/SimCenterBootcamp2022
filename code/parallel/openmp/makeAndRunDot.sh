gcc -fopenmp dot1.c -lm -o dot1
gcc -fopenmp dot2.c -lm -o dot2
gcc -fopenmp dot3.c -lm -o dot3
gcc -fopenmp dot4.c -lm -o dot4
sbatch submitDot.sh
