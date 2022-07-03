#include <stdio.h>
#include "Ordenacion.h"

void mostrarArray(int A[], int longitud);

int main() {

  int A[] = { 1, 8, 3, 4, 6, 9, 7, 5, 2, 10 };
  int longitud = (int) (sizeof(A) / sizeof(int));

  printf("Array original: ");
  mostrarArray(A, longitud);

  // printf("\nOrdenacion por seleccion: ");
  // Seleccion(A, longitud);
  // mostrarArray(A, longitud);

  // printf("\nOrdenacion por insercion: ");
  // Insercion(A, longitud);
  // mostrarArray(A, longitud);

  // printf("\nOrdenacion de intercambio: ");
  // Intercambio(A, longitud);
  // mostrarArray(A, longitud);

  return 0;
};

void mostrarArray(int A[], int longitud) {
  for (int i = 0; i < longitud; i++) {
    printf("%d, ", A[i]);
  };
};