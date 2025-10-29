#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

#define NCHILDREN 10
#define ITERATIONS 100000

int
main(int argc, char *argv[])
{
  int i, pid;
  
  printf("Starting Lottery Scheduler Demo with %d processes\n", NCHILDREN);
  
  for(i = 0; i < NCHILDREN; i++) {
    pid = fork();
    
    if(pid < 0) {
      printf("Fork failed\n");
      exit(1);
    }
    
    if(pid == 0) {
      // Proceso hijo
      int tickets = 50 * (i + 1);  // 50, 100, 150, 200...
      settickets(tickets);
      
      printf("Process %d started with %d tickets\n", getpid(), tickets);
      
      // Trabajo intensivo en CPU
      int j, k = 0;
      for(j = 0; j < ITERATIONS; j++) {
        k = k + j * 2;  // Operación simple para consumir CPU
        if(j % 10000 == 0) {
          // Yield ocasionalmente para permitir scheduling
          sleep(0);
        }
      }
      
      printf("Process %d (tickets=%d) finished\n", getpid(), tickets);
      exit(0);
    }
  }
  
  // Proceso padre espera a todos los hijos
  for(i = 0; i < NCHILDREN; i++) {
    wait(0);
  }
  
  printf("All children finished. Demo completed.\n");
  exit(0);
}