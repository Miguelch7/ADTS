#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "ListaCircular.h"

int main() {

  LC L = LCVacia();

  L = LCInsertar(L, 1);
  L = LCInsertar(L, 2);
  L = LCInsertar(L, 3);
  L = LCInsertar(L, 4);
  L = LCInsertar(L, 5);

  mostrarLC(L);

  L = LCBorrar(L);

  printf("\n");
  mostrarLC(L);

  L = LCRotar(L);

  printf("\n");
  mostrarLC(L);

  printf("\nEl valor de la Lista es: %d\n", LCValor(L));
  printf("La longitud de la lista es: %d\n", LCLongitud(L));

  return 0;
};