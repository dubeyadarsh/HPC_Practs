//**Aim : Write a program in C to multiply two matrices of size 10000 x 10000 each and find its execution-
//time using "time" command.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
int r1 = 1000, c1 = 1000, r2 = 1000, c2 = 1000, i, j, k;

double(*a)[r1][c1] = malloc(sizeof *a);
double(*b)[r2][c2] = malloc(sizeof *b);
double(*result)[r1][c2] = malloc(sizeof *result);

for (i = 0; i < r1; ++i)
{
for (j = 0; j < c1; ++j)
{
(*a)[i][j] = rand() / RAND_MAX;
}
}

for (i = 0; i < r2; ++i)
{
for (j = 0; j < c2; ++j)
{
(*b)[i][j] = rand() / RAND_MAX;
}
}

for (i = 0; i < r1; ++i)
{
for (j = 0; j < c2; ++j)
{
(*result)[i][j] = 0;
}
}

clock_t begin1 = clock();

for (i = 0; i < r1; ++i)
for (j = 0; j < c2; ++j)
for (k = 0; k < c1; ++k)
{
(*result)[i][j] += (*a)[i][k] * (*b)[k][j];
}

clock_t end1 = clock();
double time_taken = (double)(end1 - begin1) / CLOCKS_PER_SEC;
printf("\n \nfunction took %f seconds to execute \n",
time_taken);
free(a);
free(b);
free(result);

r1 = 10000, c1 = 10000, r2 = 10000, c2 = 10000;
printf("\n run second one for %d \n",r1);

for (i = 0; i < r1; ++i)
{
for (j = 0; j < c1; ++j)
{
(*a)[i][j] = rand() / RAND_MAX;
}

}

for (i = 0; i < r2; ++i)
{
for (j = 0; j < c2; ++j)
{
(*b)[i][j] = rand() / RAND_MAX;
}
}

for (i = 0; i < r1; ++i)
{
for (j = 0; j < c2; ++j)
{
(*result)[i][j] = 0;
}
}

begin1 = clock();

for (i = 0; i < r1; ++i)
for (j = 0; j < c2; ++j)
for (k = 0; k < c1; ++k)
{
(*result)[i][j] += (*a)[i][k] * (*b)[k][j];
}

end1 = clock();
time_taken = (double)(end1 - begin1) / CLOCKS_PER_SEC;
printf("\n second function took %f seconds to execute \n",
time_taken);
free(a);

free(b);
free(result);

return 0;
}

//Output

//function took 8.466246 seconds to execute
//run second one for 10000
