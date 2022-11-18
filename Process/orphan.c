#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

// Process whose parent has terminated though it itself is running. Detached to the users session.

int main(){
    int pid;
    pid=fork();
    if (pid>0){
        printf("In Parent Process \n");
    }
    else if (pid==0){
        sleep(5);
        printf("In Child Process \n");
    }
    return 0;
}