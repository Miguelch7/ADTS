#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "FilaArbol.h"

// typedef char itemAB;
// struct nodoAB {
//   itemAB raiz;
//   struct nodoAB* izq;
//   struct nodoAB* der;
// };
// typedef struct nodoAB* AB;

int max(int a, int b);

// Operaciones básicas Arból Binario
AB ABVacio();
AB ArmarAB(AB I, itemAB r, AB D);
bool EsABVacio(AB T);
bool ABPertenece(AB T, itemAB x);
itemAB Raiz(AB T);
AB Izquierdo(AB T);
AB Derecho(AB T);

// Más operaciones
bool EsHoja(AB T);
int NumeroHojas(AB T);
int Cuenta(AB T, itemAB x);
int Altura(AB T);

// Orden
void Escribir(itemAB x);
void MostrarOrdenSimetrico(AB T);
void MostrarOrdenPrevio(AB T);
void MostrarOrdenPosterior(AB T);

// Listar arbol por nivel
Fila Niveles(AB T);

int max(int a, int b) {
  if (a > b) {
    return a;
  };
  
  return b;
};

// Operaciones básicas Arból Binario
AB ABVacio() {
  return NULL;
};

AB ArmarAB(AB I, itemAB r, AB D) {
  
  AB T = (AB) malloc(sizeof(struct nodoAB));

  T->raiz = r;
  T->izq = I;
  T->der = D;

  return T;
};

bool EsABVacio(AB T) {
  return T == NULL;
};

bool ABPertenece(AB T, itemAB x) {

  if (EsABVacio(T)) {
    return false;
  };
  
  return T->raiz == x || ABPertenece(T->izq, x) || ABPertenece(T->der, x);
};

itemAB Raiz(AB T) {
  return T->raiz;
};

AB Izquierdo(AB T) {
  return T->izq;
};

AB Derecho(AB T) {
  return T->der;
};

// Más operaciones
bool EsHoja(AB T) {
  return EsABVacio(T->izq) && EsABVacio(T->der);
};

int NumeroHojas(AB T) {
  if (EsABVacio(T)) {
    return 0;
  } else if (EsHoja(T)) {
    return 1;
  } else {
    return NumeroHojas(Izquierdo(T)) + NumeroHojas(Derecho(T));
  };
};

int Cuenta(AB T, itemAB x) {
  if (EsABVacio(T)) {
    return 0;
  } else if (Raiz(T) == x) {
    return 1 + Cuenta(Izquierdo(T), x) + Cuenta(Derecho(T), x);
  } else {
    return Cuenta(Izquierdo(T), x) + Cuenta(Derecho(T), x);
  };
};

int Altura(AB T) {
  if (EsABVacio(T) || EsHoja(T)) {
    return 0;
  } else {
    return 1 + max(Altura(Izquierdo(T)), Altura(Derecho(T)));
  };
};

// Orden
void Escribir(itemAB x) {
  printf("%c -> ", x);
};

void MostrarOrdenSimetrico(AB T) {
  if (!EsABVacio(T)) {
    MostrarOrdenSimetrico(Izquierdo(T));
    Escribir(Raiz(T));
    MostrarOrdenSimetrico(Derecho(T));
  };
};

void MostrarOrdenPrevio(AB T) {
  if (!EsABVacio(T)) {
    Escribir(Raiz(T));
    MostrarOrdenPrevio(Izquierdo(T));
    MostrarOrdenPrevio(Derecho(T));
  };
};

void MostrarOrdenPosterior(AB T) {
  if (!EsABVacio(T)) {
    MostrarOrdenPosterior(Izquierdo(T));
    MostrarOrdenPosterior(Derecho(T));
    Escribir(Raiz(T));
  };
};

Fila Niveles(AB T) {
  
  Fila F = FilaVacia();
  
  if (!EsABVacio(T)) {

    F = Enfila(F, T);

    while (F.frente != NULL) {

      AB TAux = Frente(F);
      F = Defila(F);
      
      Escribir(Raiz(TAux));
      
      if (!EsABVacio(Izquierdo(TAux))) {
        F = Enfila(F, Izquierdo(TAux));
      };
      
      if (!EsABVacio(Derecho(TAux))) {
        F = Enfila(F, Derecho(TAux));
      };
    };
  };

  return F;
};
