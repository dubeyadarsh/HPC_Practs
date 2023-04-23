//**Aim :: Area of circle using omp**
#include <stdio.h>
#include <omp.h>
Int main(int argc, char *argv[])
{ Double radius = 5.0;
    Double area = 0.0;
    Double pi = 3.14159;
    Int num_threads = 4;
#pragma omp parallel num_threads(num_threads)
    {
        Int tid = omp_get_thread_num();
        Double local_area = 0.0;
 #pragma omp for
        For (int I = 0; I < 10000000; i++) {
            Double x = (double)rand() / RAND_MAX;
            Double y = (double)rand() / RAND_MAX;
            If (x*x + y*y <= radius*radius) {
                Local_area += 1.0;
            }
        }
#pragma omp critical
        {
            Area += local_area;
        }
    }
  Area = 4.0 * radius * radius * (area / 10000000.0) / num_threads;
    Printf(“Area of circle with radius %f is %f\n”, radius, area);
Return 0;
}

//OUTPUT- 
//Area of circle with radius 5.000000 is 78.539200

