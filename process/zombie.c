#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
/**
 * Program that forks a child process that ultimately becomes zombie process
 * A process that has terminated, but whose parent has not yet called wait(), is known as zombie process
 * If parent instead terminated, then child processes are orphans
*/
int main()
{
    
    pid_t pid = fork();
  
    if (pid > 0){ /* Parent Process */
        sleep(50);
    }else{ 
        exit(0);
    }        
        
  
    return 0;
}