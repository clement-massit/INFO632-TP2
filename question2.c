#include <stdio.h>
#include <stdlib.h>




int foo(const char *whoami) {
    printf("I am a %s.  My pid is:%d  my ppid is %d\n", whoami, getpid(), getppid() );
    return 1;
}

int func(int n) 
{
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
        foo("child");
        n = n-1;
        func(n);
        sleep(20);
        exit(0);
        
    }

    // PID 2
    int pid2 = fork(); 
    if (pid2 == -1) {
        exit(0);
    }

    if (pid2 ==0) { 
        foo("child");
        n = n-1;
        func(n);
        sleep(20);
        exit(0);   
    }
    
    else {
       wait(NULL);
    } 
    return 0;   
}


int main(int argc, char *argv[])
{
    func(atoi(argv[1])); 
    return 0;
    
}
