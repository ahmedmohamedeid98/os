#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


int sum;

void *runner(void *params)
{
    int i, upper = atoi(params);
    sum = 0;
    for(i = 1; i <= upper; i++)
    {
        sum += i;
    }
    pthread_exit(0);
}

int main(int argc, char *argv[])
{
    pthread_t tid; /* thread identifier */
    pthread_attr_t attr; /* set of thread attributes */
    
    if(argc != 2)
    {
        fprintf(stderr, "usage: a.out <int value>\n");
        return -1;
    }
    if(atoi(argv[1]) < 0)
    {
        fprintf(stderr, "%d must be >= 0", atoi(argv[1]));
        return -1;
    }
    
    /* get default attr */
    pthread_attr_init(&attr);
    /* create the thread */
    pthread_create(&tid, &attr, runner, argv[1]);
    /* wait for thread to exit */
    pthread_join(tid, NULL);
    /* print result */
    printf("sum = %d\n", sum);

}
