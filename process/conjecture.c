#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>
#include <stdlib.h>
/*
* Collatz Conjecture Sequence
*/


int main(int argc, char *argv){
    pid_t pid;
    int n=0;
    do{
			printf("Enter a number greater than 0 to run the Collatz Conjecture.\n"); 
  			scanf("%d", &n);	
	}while (n <= 0);

    
    pid = fork();
    printf("%d\n", pid);
    if(pid < 0){
        fprintf(stderr, "Fork Failed");
        return 1;
    }
    else if(pid == 0){ /* Child Process*/
        printf("%d ", n);
        while(n != 1){
            
            if(n % 2 == 0){
                n /= 2;
            }else{
                n = 3*n + 1;
            }
            printf("%d ", n);
        }
        return 0;
    }

    else if(pid > 0){ /* Parent Process */
        wait(NULL);
        printf("\nCollatz Conjecture Sequence is generated.\n");
        return 0;
    }

}