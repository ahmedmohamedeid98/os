#include <omp.h>
#include <stdio.h>


int main(int argc, char *argv[])
{

    /* sequentail code */

    /* 
       identifies parallel regions 
       blocks of code that can run
       in parallel
    */
    #pragma omp parallel
    {
        /* move this block of code to run in one of previously created*/
        printf("I am a parallel region.\n");
    }
    
    /* another parallel region */
    #pragma omp parallel
    {
        int i;
        for( i = 0 ; i < 10 ; i++)
        {
            printf("%d\n",i);
        }
    }
    
    /* sequentail code */
    
    return 0;
}

/*
OpenMP: slightly faster to service a request with an existing threas
        than create new thread.

*/


