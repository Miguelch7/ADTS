#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FilaArbol.h"
#include "ArbolBinario.h"

int main() {

  AB J = ArmarAB(ABVacio(), 'J', ABVacio());
  AB I = ArmarAB(ABVacio(), 'I', ABVacio());
  AB H = ArmarAB(ABVacio(), 'H', J);
  AB G = ArmarAB(ABVacio(), 'G', ABVacio());
  AB F = ArmarAB(ABVacio(), 'F', G);
  AB E = ArmarAB(H, 'E', I);
  AB D = ArmarAB(ABVacio(), 'D', ABVacio());
  AB C = ArmarAB(F, 'C', ABVacio());
  AB B = ArmarAB(D, 'B', E);
  AB A = ArmarAB(B, 'A', C);

  printf("Implementacion ARBOL BINARIO\n");

  AB Z = ABVacio();

  printf("Es vacio el arbol \"Z\"?: %d\n", EsABVacio(Z));
  printf("Es vacio el arbol \"A\"?: %d\n", EsABVacio(A));

  printf("La raiz del arbol A es: %c\n", Raiz(A));
  printf("La izquierda del arbol A es: %c\n", Izquierdo(A)->raiz);
  printf("La derecha del arbol A es: %c\n", Derecho(A)->raiz);

  printf("Pertenece \"J\" al arbol A?: %d\n", ABPertenece(A, 'J'));
  printf("Pertenece \"W\" al arbol A?: %d\n", ABPertenece(A, 'W'));

  printf("\nPreOrden: ");
  MostrarOrdenPrevio(A);

  printf("\nOrden Simetrico: ");
  MostrarOrdenSimetrico(A);

  printf("\nPostOrden: ");
  MostrarOrdenPosterior(A);

  printf("\nLa altura del arbol A es: %d", Altura(A));

  printf("\n\nListado de nodos por nivel:\n");
  Fila miFila = Niveles(A);

  return 0;
};