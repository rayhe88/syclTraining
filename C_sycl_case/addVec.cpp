#include <iostream>
#include <cassert>
#include <vector>
#include <new>
#include "func.hpp"
#include <CL/sycl.hpp>

using namespace std;

int main(int argc, char *argv[])
{

    double *a, *b, *c;
    int i, nelements;

    if (argc == 2)
    {
        nelements = atoi(argv[1]);
    }
    else
    {
        nelements = 1000;
    }

    printf(" Sum of two vectors:\n");
    printf("    c[i] = a[i] + b[i]\n");
    printf("    Test for %6d elements\n\n", nelements);

    // Allocate memory

    a = new double[nelements];
    b = new double[nelements];
    c = new double[nelements];

    assert(a);
    assert(b);
    assert(c);

    // Fill the vector
    for (i = 0; i < nelements; i++)
    {
        a[i] = 1.;
        b[i] = 2.;
        c[i] = 0.;
    }

    // Call the sum function
    sum2(nelements, a, b, c);

    // Check the sum
    check_sum(nelements, c);

    delete[] a;
    delete[] b;
    delete[] c;
    exit(EXIT_SUCCESS);
}
