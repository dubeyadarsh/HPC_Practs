//**Aim: Hello World program using MPI**

//The message passing interface (MPI) is a standardized means of exchanging messages between multiple computers running a parallel program across distributed memory.

#include <mpi.h>
#include <stdio.h>
int main(int argc, char** argv)
{
// Initialize the MPI environment
MPI_Init(NULL, NULL);
// Get the number of processes
int world_size;
MPI_Comm_size(MPI_COMM_WORLD, &world_size);
// Get the rank of the process
int world_rank;
MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
// Get the name of the processor
char processor_name[MPI_MAX_PROCESSOR_NAME];
int name_len;
MPI_Get_processor_name(processor_name, &name_len);
// Print off a hello world message
printf("Hello world from processor %s, rank %d out of %d processors\n",
processor_name, world_rank, world_size);
// Finalize the MPI environment.
MPI_Finalize();
}



//**Output:**

//ubuntu@ubuntu-HP-Elite-Tower-600-G9-Desktop-PC:~$ mpicc mpi_hello_world.c -o hello-world
//ubuntu@ubuntu-HP-Elite-Tower-600-G9-Desktop-PC:~$ mpirun -np 5 ./hello-world
//Hello world from processor ubuntu-HP-Elite-Tower-600-G9-Desktop-PC, rank 0 out of 5 processors
//Hello world from processor ubuntu-HP-Elite-Tower-600-G9-Desktop-PC, rank 1 out of 5 processors
//Hello world from processor ubuntu-HP-Elite-Tower-600-G9-Desktop-PC, rank 3 out of 5 processors
//Hello world from processor ubuntu-HP-Elite-Tower-600-G9-Desktop-PC, rank 2 out of 5 processors
//Hello world from processor ubuntu-HP-Elite-Tower-600-G9-Desktop-PC, rank 4 out of 5 processors
//ubuntu@ubuntu-HP-Elite-Tower-600-G9-Desktop-PC:~$
