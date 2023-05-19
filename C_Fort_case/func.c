#include "func.h"

void sum(int n, double *inp1, double *inp2, double *res){

    for(int i = 0; i < n; i++)
        res[i] = inp1[i] + inp2[i];
}


void check_sum(int n, double *res){

    for(int i = 0; i < n; i++)
        if(fabs(res[i] - 3.0) > 1.E-15){
            printf(" There is an error in the addition of vectors\n");
            exit(EXIT_FAILURE);
        }

    printf(" No errors in the addition of vectors\n");

}
