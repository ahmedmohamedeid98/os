#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){

    pid_t pid = fork();
    
    if(pid == 0){
       printf("\t##Child##\n");
       printf("current pid: %d - child pid: %d\n", getpid(), pid); 
    }else{
        //wait(NULL);
        printf("\t##Parent##\n");
       printf("current pid: %d - child pid: %d\n", getpid(), pid); 
    }


    return 0;
}
/*
Note:-
    getpid: get the acually id for the process that the os exist in.
    fork_pid: 0 mean that the os is exist in the child process.
    fork_pid: > 0 mean the the os finich the child process.
    fork_pid: -1 mean that the os failure in creating child process. 
    
    
-------------------------------------------------------
output: (if we inforce the os to execute the child process first using "wait")
    ##Child##
current pid: 2218 - child pid: 0
    ##Parent##
current pid: 2217 - child pid: 2218

        ---------------------
output: (if we delete wait and let the choice for os)
	##Parent##
current pid: 2259 - child pid: 2260
	##Child##
current pid: 2260 - child pid: 0

----------------------------------------------------
what happen(first case)? 
    - during os in the child process fork_pid = 0(which mean that the os exist in child process), while getpid = 2218 which is the acually id for the child process.
    - during os in the parent process fork_pid = 2218 (which is the child id, and mean that os finich the child and ready for execute the parent process or it decide to execute the parent process in the first then child process), while getpid = 2217 which is the acually id for the parent process.


*/
