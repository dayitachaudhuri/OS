#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// Runs in the background rather than under direct control of a user.

int main(){
    int pid;
    pid=fork();
    if (pid>0){
        printf("To Parent Process \n");
        step(5);
        printf("Again to Parent Process \n");
    }
    else if (pid==0)
        printf("To Child Process \n");
    return 0;
}