#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;
const item indefinido = -9999;
struct nodo {
  item dato;
  struct nodo* sig;
};
typedef struct nodo* Nodo;

typedef struct {
  struct nodo* cabecera;
  int altura;
} Pila;

// Operaciones básicas del ADT PILA(item)
Pila PilaVacia();
bool EsPilaVacia(Pila P);
Pila Push(Pila P, item x);
Pila Pop(Pila P);
item Top(Pila P);

// Más operaciones
item Fondo(Pila P);
bool EsCreciente(Pila P);
bool Incluida(Pila P1, Pila P2);

void Escribir(Pila P);

Pila PilaVacia() {

  Pila P;

  P.cabecera = NULL;
  P.altura = 0;

  return P;
};

bool EsPilaVacia(Pila P) {
  return P.cabecera == NULL;
};

Pila Push(Pila P, item x) {

  Nodo nuevoNodo = (Nodo) malloc(sizeof(struct nodo));

  nuevoNodo->dato = x;
  nuevoNodo->sig = P.cabecera;

  P.cabecera = nuevoNodo;
  P.altura++;

  return P;
};

Pila Pop(Pila P) {
  
  if (!EsPilaVacia(P)) {
    
    Nodo aux = P.cabecera;
    P.cabecera = aux->sig;
    P.altura--;

    free(aux);
  };

  return P;
};

item Top(Pila P) {

  if (EsPilaVacia(P)) {

    return indefinido;
  } else {

    return P.cabecera->dato;
  };
};

item Fondo(Pila P) {
  if (EsPilaVacia(P)) {
    return indefinido;
  } else {
    if (P.cabecera->sig == NULL) {
      return Top(P);
    } else {
      P.cabecera = P.cabecera->sig;
      return Fondo(P);
    };
  };
};

bool EsCreciente(Pila P) {
  if (EsPilaVacia(P)) {
    return false;
  } else {
    if (P.cabecera->sig == NULL) {
      return true;
    } else {
      if (P.cabecera->dato >= P.cabecera->sig->dato) {
        P.cabecera = P.cabecera->sig;
        return EsCreciente(P);
      } else {
        return false;
      };
    };
  };
};

bool Incluida(Pila P1, Pila P2) {
  if (EsPilaVacia(P1)) {
    return true;
  } else if (EsPilaVacia(P2)) {
    return false;
  } else {
    if (P1.cabecera->dato == P2.cabecera->dato) {
      P1.cabecera = P1.cabecera->sig;
      P2.cabecera = P2.cabecera->sig;
      Incluida(P1, P2);
    } else {
      P2.cabecera = P2.cabecera->sig;
      Incluida(P1, P2);
    };
  };
};

void Escribir(Pila P) {
  printf("PILA: \n");
  while (!EsPilaVacia(P)) {
    printf("%d\n", P.cabecera->dato);
    P.cabecera = P.cabecera->sig;
  };
};