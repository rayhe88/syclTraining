#include "func.hpp"
#include <iostream>
#include <CL/sycl.hpp>
#include "mkl.h"
#include "oneapi/mkl/blas.hpp"

namespace sycl = cl::sycl;

class VectorAddKernel;

void sum(int nele, double *inp1, double *inp2, double *res){

    sycl::queue q(sycl::default_selector{});


    std::cout << " Running on " << q.get_device().get_info <sycl::info::device::name>()
              << "\n\n";

    // Create the buffers
    size_t n = nele;
    sycl::buffer<double, 1> a_buf(inp1, sycl::range<1>(n));
    sycl::buffer<double, 1> b_buf(inp2, sycl::range<1>(n));
    sycl::buffer<double, 1> c_buf(res, sycl::range<1>(n));

    // Submit the command to the queue

    oneapi::mkl::blas::column_major::axpy(q, nele, 1.0, a_buf, 1, b_buf,1);
    oneapi::mkl::blas::column_major::axpy(q, nele, 1.0, b_buf, 1, c_buf,1);

    q.submit([&](sycl::handler &h){
        auto b = b_buf.get_access<sycl::access::mode::read>(h);
        auto c = c_buf.get_access<sycl::access::mode::write>(h);

        // Define the kernel
        h.parallel_for<class VectorAddKernel> (sycl::range<1>(n), [=](sycl::id<1> idx){
            if(idx[0] < n)
                c[idx] = b[idx];
        });
    });

    q.wait_and_throw();

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
