#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define N 10

void
trabajo(int id, int tickets)
{
  settickets(tickets);
  
  int count = 0;
  for(int i = 0; i < 50000000; i++) {
    count++;
    if(i % 1000000 == 0) {
      count = count * 1;  // evitar optimizacion del compilador
    }
  }
  
  exit(0);
}

int
main(int argc, char *argv[])
{
  int pid;
  int tickets;
  int pids[N];
  int ticks[N];
  
  printf("\nTest Lottery Scheduler\n");
  printf("----------------------\n");
  
  for(int i = 0; i < N; i++) {
    tickets = 50 * (i + 1);
    ticks[i] = tickets;
    
    pid = fork();
    
    if(pid < 0) {
      printf("fork error\n");
      exit(1);
    }
    else if(pid == 0) {
      trabajo(i, tickets);
      exit(0);
    }
    else {
      pids[i] = pid;
    }
  }
  
  printf("%d procesos creados\n\n", N);
  
  for(int i = 0; i < N; i++) {
    int status;
    pid = wait(&status);
    
    for(int j = 0; j < N; j++) {
      if(pids[j] == pid) {
        printf("P%d (tickets=%d) termino\n", j, ticks[j]);
        break;
      }
    }
  }
  
  printf("\nListo. Los procesos con mas tickets\n");
  printf("deberian terminar primero.\n");
  
  exit(0);
}