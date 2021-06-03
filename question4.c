#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int max_count = 20;


int main(int argc, char **argv){
  
    int status;
    pid_t pid;
    pid = fork();

    if (pid == 0){
        int i;
        for (i = 1; i <= max_count; i++){
            printf("   The child :%d , value = %d\n",getpid(), i);
        }
    }else{
       
        waitpid(pid, &status, 0);
        printf("The parent :%d, value = %d\n",getpid(), WEXITSTATUS(status));
        
    }
    sleep(3);
    return 0;

}


