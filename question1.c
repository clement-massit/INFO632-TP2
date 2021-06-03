#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>

int n = 5;


int func(int n) {
    
    if (n == 0)
    { 
        return 0;
    }
    int pid = fork(); 
    if (pid == -1) {
        exit(0);
    }
    if (pid==0) { 
        printf("VALUE : %d ", n);
        printf("PID: %d ", getpid());
        printf("PPID: %d\n", getppid());
        n--;
        func(n);
        exit(0);
    }
    else {
       wait(NULL);
    }
    
    return 0;   
}


int main() {
    func(n); 
    return 0;
}