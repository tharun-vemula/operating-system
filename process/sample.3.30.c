#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int value = 5;
/**
 * The fork function creates a copy of the calling process. 
 * The only distinction between the two processes is that the value returned to one of them, 
 * referred to as the parent process, will be the process ID of the copy.
 * The copy is usually referred to as the child process. The value returned to the child process will be zero.
 * child receives copy of the parent (code & data)
*/
int main(){
    pid_t pid;
    pid = fork();
    if(pid == 0){
        value += 15;
        printf("CHILD: value = %d\n", value);
        return 0;
    }

    else if(pid > 0){
        wait(NULL);
        printf("PARENT: value = %d\n", value);
        return 0;
    }

}