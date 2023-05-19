#include "func.hpp"
#include <CL/sycl.hpp>

using namespace sycl;

void sum(int nele, double *inp1, double *inp2, double *res){

    queue q;

    // Create the buffers
    size_t n = nele;
    buffer<double, 1> a_buf(inp1, range<1>{n});
    buffer<double, 1> b_buf(inp2, range<1>{n});
    buffer<double, 1> c_buf(res, range<1>{n});

    // Submit the command to the queue

    q.submit([&](handler &h)
             {
                 auto a = a_buf.get_access<access::mode::read>(h);
                 auto b = b_buf.get_access<access::mode::read>(h);
                 auto c = c_buf.get_access<access::mode::write>(h);

                 // Define the kernel
                 h.parallel_for(range<1>{n}, [=](id<1> i)
                                { c[i] = a[i] + b[i]; }); });
}


void check_sum(int n, double *res){

    for(int i = 0; i < n; i++)
        if(fabs(res[i] - 3.0) > 1.E-15){
            printf(" There is an error in the addition of vectors\n");
            exit(EXIT_FAILURE);
        }

    printf(" No errors in the addition of vectors\n");

}
