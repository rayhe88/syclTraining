#include "func.hpp"
#include <iostream>
#include <cuda.h>


__global__ void sum_kernel(int n, double* vecA, double* vecB, double *vecRes){
    int index = blockIdx.x * blockDim.x + threadIdx.x;
    if( index < n )
        vecRes[i] = vecA[i] + vecB[i];
}

void sum(int nele, double *inp1, double *inp2, double *res){

    double *dev_inp1, *dev_inp2, *dev_res;

    // Memory allocation
    cudaMalloc((void**) &dev_inp1, nele*sizeof(double));
    cudaMalloc((void**) &dev_inp2, nele*sizeof(double));
    cudaMalloc((void**) &dev_res, nele*sizeof(double));

    // Data copy
    cudaMemcpy(dev_inp1, inp1, nele*sizeof(double), cudaMemcpyHostToDevice);
    cudaMemcpy(dev_inp1, inp1, nele*sizeof(double), cudaMemcpyHostToDevice);


    sum_kernel <<<4096, 256>>> (nele, dev_inp1, dev_inp2, dev_res);

    cudaMemcpy(res, dev_res, nele*sizeof(double), cudaMemcpyDeviceToHost);


    cudaFree(dev_res)
    cudaFree(dev_inp2)
    cudaFree(dev_inp1)

    return;
}


void check_sum(int n, double *res){

    for(int i = 0; i < n; i++)
        if(fabs(res[i] - 3.0) > 1.E-15){
            printf(" There is an error in the addition of vectors\n");
            exit(EXIT_FAILURE);
        }

    printf(" No errors in the addition of vectors\n");

}
