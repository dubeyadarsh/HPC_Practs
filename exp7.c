//**Aim: EXP7 Cube of N number using cuda**
//CUDA® is a parallel computing platform and programming model developed by NVIDIA for general computing on graphical processing units (GPUs).

#include <stdio.h>
#include <stdlib.h>
#include <cuda_runtime.h>
#define N 5
_global_ void cube(float *d_in, float *d_out) {
int i = blockIdx.x * blockDim.x + threadIdx.x;
if (i < N) {
float f = d_in[i];
d_out[i] = f * f * f;
}
}
int main() {
float *h_in, *h_out;
float *d_in, *d_out;
int size = N * sizeof(float);
// Allocate memory on host and device
h_in = (float *) malloc(size);
h_out = (float *) malloc(size);
cudaMalloc((void **) &d_in, size);
cudaMalloc((void **) &d_out, size);
// Initialize input array on host
for (int i = 0; i < N; i++) {
h_in[i] = i;
}
// Copy input array from host to device
cudaMemcpy(d_in, h_in, size, cudaMemcpyHostToDevice);
// Launch kernel on device
dim3 threadsPerBlock(256);
dim3 numBlocks((N + threadsPerBlock.x - 1) / threadsPerBlock.x);
cube<<<numBlocks, threadsPerBlock>>>(d_in, d_out);
// Copy output array from device to host
cudaMemcpy(h_out, d_out, size, cudaMemcpyDeviceToHost);
// Print output array
for (int i = 0; i < N; i++) {
printf("%f ", h_out[i]);
}
printf("\n");
// Free memory on host and device
free(h_in);
free(h_out);
cudaFree(d_in);
cudaFree(d_out);
return 0;
}

//Output:
//1.000000 8.000000 27.000000 64.000000
