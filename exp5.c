//**Aim :: Area of circle using mpi**
#include <stdio.h>
#include <mpi.h>

#define PI 3.14159265358979323846

int main(int argc, char** argv) {
    int rank, size;
    double radius = 5.0;
    double area, local_area;
    int tag = 0;
    MPI_Status status;
    
    MPI_Init(&argc, &argv);
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    
    local_area = (radius * radius * PI) / size; // Divide the work equally among processes
    
    MPI_Reduce(&local_area, &area, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD); // Sum the areas from all processes
    
    if (rank == 0) {
        printf("Area of circle with radius %f is %f\n", radius, area);
    }
    
    MPI_Finalize();
    
    return 0;
}
