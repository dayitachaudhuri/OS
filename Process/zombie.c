#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// When a child terminates, an association of it with the parent survives until the parent either terminates or calls wait.

int main(){
    pid_t pid;
    pid=fork();
    if (pid>0){
        printf("Parent PID \n");
        step(5);
    }
    else{
        printf("Child PID \n");
        exit(0);
    }
    return 0;
}