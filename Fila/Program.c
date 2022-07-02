#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Fila.h"

int main() {

  Fila F = FilaVacia();
  F = Enfila(F, 1);
  F = Enfila(F, 2);
  F = Enfila(F, 3);
  F = Enfila(F, 4);
  F = Enfila(F, 5);

  mostrarFila(F);


  printf("\nEl frente de la fila es: %d\n", Frente(F));
  printf("\nEl final de la fila es: %d\n", Final(F));

  F = Enfilan(F, 10, 3);

  F = Defila(F);
  F = Defila(F);

  printf("El 5 pertenece a la fila: %d\n", Pertenece(F, 5));
  printf("El 10 pertenece a la fila: %d\n", Pertenece(F, 10));

  printf("\n");
  mostrarFila(F);

  return 0;
};