**How to run MPI code?**

1. First write code and save hello.c
2. Sudo apt install mpich
3. mpicc hello.c -o hello
4. mpirun -np 5 ./hello

**How to run omp code?? **

1. First write code and save area.c

Terminal (sudo apt install gcc)
2. gcc area.c -o area.out
3. export OMP_NUM_THREADS=4
4. gcc -fopenmp area.c -o area.out
5.   ./area.out
