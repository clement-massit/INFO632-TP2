#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int n = 2;

int func(int n) {
    if (n == 0)
    { 
        return 0;
    }

    // PID 1
    int pid1 = fork(); 
    if (pid1 == -1) {
        exit(0);
    }

    if (pid1 ==0) { 
        printf("VALUE : %d ", n);
        printf("PID: %d ", getpid());
        printf("PPID: %d\n", getppid());
        n--;
        func(n);
        sleep(10);
        exit(0);
    }

    // PID 2
    int pid2 = fork(); 
    if (pid2 == -1) {
        exit(0);
    }

    if (pid2 ==0) { 
        printf("VALUE : %d ", n);
        printf("PID: %d ", getpid());
        printf("PPID: %d\n", getppid());
        n--;
        func(n);
        sleep(10);
        exit(0);   
    }
    
    else {
       wait(NULL);
    } 
    return 0;   
}


int main(){
    func(n); 
    return 0;
}

