#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int value = 5;

/*
* getpid() returns the pid of the calling process
*/
int main(){
    pid_t pid, pid1;
    pid = fork();
    printf("%d\n", pid);
    if(pid < 0){
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if(pid == 0){ /* Child Process*/
        pid1 = getpid(); /** Get the Process ID of the calling process*/
        printf("child: pid = %d\n", pid);
        printf("child: pid1 = %d\n", pid1);
        return 0;
    }

    else if(pid > 0){ /* Parent Process */
        pid1 = getpid();
        printf("parent: pid = %d\n", pid);
        printf("parent: pid1 = %d\n", pid1);
        wait(NULL);
        return 0;
    }

}