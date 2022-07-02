#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Pila.h"

int main() {
  
  Pila P = PilaVacia();

  printf("Es pila vacia?: %d\n", EsPilaVacia(P));

  printf("Agregar 1, 2, 3, 4, 5\n");
  P = Push(P, 1);
  P = Push(P, 2);
  P = Push(P, 3);
  P = Push(P, 4);
  P = Push(P, 5);
  Escribir(P);
  
  printf("Altura de la pila: %d\n", P.altura);

  printf("Es creciente?: %d\n", EsCreciente(P));

  printf("Hacer Pop() dos veces\n");
  P = Pop(P);
  P = Pop(P);
  Escribir(P);

  printf("Altura de la pila: %d\n", P.altura);
  printf("Top: %d\n", Top(P));
  printf("Fondo: %d\n", Fondo(P));

  return 0;
};