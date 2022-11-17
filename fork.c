#include <stdio.h>
#include <sys/types.h>

int childProcess(){
    printf("From Child.\n");
    return 0;
}

int parentProcess(){
    printf("From Parent.\n");
    return 0;
}

int main(){
    pid_t pid;
    pid=fork();
    if (pid==0)
        childProcess();
    else
        parentProcess();
    return 0;
}