#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char **argv){

  int k = atoi(argv[1]);

  while(k > 0) {
    k --;
    int fork = fork();
    printf("PID : %d",fork);
    if(fork){
      wait();
    }else{
      sleep(10);
    }
  }
  sleep(10);
  return 0;
}

