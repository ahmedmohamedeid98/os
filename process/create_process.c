#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){

    // p0: Parent child
    pid_t d1 = fork(); // create first chid p1
    pid_t d2 = fork(); // create second child p2 and third child p3
    
    //parent process
    if( d1 > 0 && d2 > 0 )
    {
        wait(NULL); //wait for execute child1 (p1)
        wait(NULL); //wait for execute child2 (p2)
        printf("Parent terminated\n");
    }
    
    //child 1
    else if( d1 == 0 && d2 > 0 )
    {
        
        sleep(2); // sleep for allowing execute p3 then execute p2
        wait(NULL); // wait for execute child3 (p3) 
        printf("first child terminated\n");
    }
    
    // child 2
    else if( d2 == 0 && d1 > 0)
    {
        sleep(1); // sleep for allowing execute p3
        printf("Second Child terminated\n");
    }
    
    // child 3
    else
    {
        printf("Third Child terminated\n");

    }
    
    return 0;
}


/**
>>>>> Bottom-Up <<<<<<
first fork()
        p0
       / 
      p1  

second fork()

        p0
       /  \
      p1  p2
     /
    p3
    
Note: number of process = num_fork ^ 2
     
------------------------------------------
System call:-

fork(): create child process from parent process
wait(): 
        - move parent process to wait_state to release resouces for execute child process
        - return id for the child process
        - return -1 if there is no child process created
        - can terminated by using exit(0)
        
sleep(): 
        - move process to Inactive_state 
        - not release resources just frezing the process
        
        
exec(): 
        - replace code in a process with another code...
        - return value in one case if it failure
        
execv(path, array of pointer terminated by null):
        - import compiled code from anther file and execute it and terminate
 
SIGCHIID: notified child's terminated.

pid_t: data type for process id it may by act as int datatype

getpid: get process id either parent or child

getppid: get process_id for parent process

**/
