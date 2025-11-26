#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main() {
  char *addr = sbrk(0); // Dirección actual del heap
  sbrk(4096); // Reservar una página
  addr[0] = 'Z'; // Escribir valor inicial
  
  printf("Valor inicial: %c\n", addr[0]);
  
  // Proteger contra lectura
  if (mrdprotect(addr, 1) < 0) {
    printf("mrdprotect falló\n");
    exit(1);
  }
  
  printf("Página protegida contra lectura\n");
  
  // Escritura aún permitida
  addr[0] = 'A';
  printf("Escritura exitosa\n");
  
  // Intento de lectura debería provocar fallo
  printf("Intentando leer...\n");
  char c = addr[0];
  printf("Valor leído: %c (esto NO debería imprimirse)\n", c);
  
  // Revertir protección
  if (munrdprotect(addr, 1) < 0) {
    printf("munrdprotect falló\n");
    exit(1);
  }
  
  printf("Protección revertida correctamente.\n");
  printf("Valor leído después de revertir: %c\n", addr[0]);
  
  exit(0);
}