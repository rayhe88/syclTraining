#include "func.hpp"

#include <CL/sycl.hpp>

namespace sycl = cl::sycl;

void sum(int nele, double *inp1, double *inp2, double *res)
{
    for (int i = 0; i < nele; i++)
        res[i] = inp1[i] + inp2[i];
}

void sum2(int nele, double *inp1, double *inp2, double *res)
{
    //default_selector device_selector;

    //queue q(device_selector);
    sycl::queue q(sycl::default_selector{});

    std::cout << " Running on " << q.get_device().get_info <sycl::info::device::name>()
              << "\n\n";

    // Create the buffers
    const size_t n = nele;
    sycl::buffer<double, 1> a_buf(inp1, sycl::range<1>(n));
    sycl::buffer<double, 1> b_buf(inp2, sycl::range<1>(n));
    sycl::buffer<double, 1> c_buf(res,  sycl::range<1>(n));

    // Submit the command to the queue
    q.submit([&](sycl::handler& h)
             {
                 auto a = a_buf.get_access<sycl::access::mode::read>(h);
                 auto b = b_buf.get_access<sycl::access::mode::read>(h);
                 auto c = c_buf.get_access<sycl::access::mode::write>(h);

                 // Define the kernel
                 h.parallel_for<class VectorAddKernel>(sycl::range<1>(n), [=](sycl::id<1> idx)
                                { c[idx] = a[idx] + b[idx];
                                   });
                                });
    q.wait();
}

void check_sum(int n, double *res)
{

    for (int i = 0; i < n; i++)
        if (fabs(res[i] - 3.0) > 1.E-15)
        {
            std::cout << " There is an error in the addition of vectors" << std::endl;
            exit(EXIT_FAILURE);
        }

    std::cout << " No errors in the addition of vectors" << std::endl;
}
