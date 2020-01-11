#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

#define MSGSIZE 16

int main(){

    char intbuff[MSGSIZE];
    int pfd[2];
    
    //Something wrong, like failed to create Virusl file
    if ( pipe(pfd) < 0 )   exit(0);
    
    // write to pipe    
    write( pfd[1], "hello", MSGSIZE);
    
    // read from pipe
    read( pfd[0], intbuff, MSGSIZE);
    
    printf("%s\n",intbuff);

}

/*

Note:
    pipe: 
        - is System Call used to share info between two process, such that the standard output from one process becomes the standard input of the other process
        - is one-way can use a pipe such that one process can write to the pipe, and onther process read from the pipe, it opens a pipe which is an erea of main memory which called "Virsual File" 
        - if a process tries to read be read before something is written to the pipe, the process is suspended until something is written.
        - Any pipe process contain from two PFD (process file descriptor)
        - pfd[0] will be the fd(file descriptor) for the read from pipe.
        - pfd[1] will be the fd(file descriptor) for the write  to pipe.
        - Pipes behave FIFO(first in first out) --> "queue"
        
        
     ------------------                     -------------------
    |  parent process  |                   |   child process   |
    |   fd[0]  fd[1]   |                   |   fd[0]  fd[1]    |
     -----------------                      -------------------
        |       |                                |      | 
        |       |                                |      |
        |       |                                |      |
        |       |                                |      |
        |        --------------------------------|------|----
        |                                        |      |    |
        |     -----------------------------------       |    |  
        |    |                                          |    |
        |    |                 kernal                   |    |   
        |    |         -----------------------          |    |
        |    |       |                       |          |    |
        |    |       |      ------------     |          |    |
        |     ---<<--|     |    pipe    |    |<---------     |
        |            |     |            |    |               |
         -----<<-----|      ------------     |<--------------
                     |                       |
                      ----------------------



*/
