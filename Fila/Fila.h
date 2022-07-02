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

struct Fila {
  struct nodo* frente;
  struct nodo* final;
} typedef Fila;

Fila FilaVacia();
bool EsFilaVacida();
Fila Enfila(Fila F, item x);
Fila Defila(Fila F);
item Frente(Fila F);
item Final(Fila F);
Fila Enfilan(Fila F, item x, int n);
bool Pertenece(Fila F, item x);
void mostrarFila(Fila F);

Fila FilaVacia() {
  Fila F;

  F.frente = NULL;
  F.final = NULL;

  return F;
};

bool EsFilaVacia(Fila F) {
  return F.frente == NULL;
};

Fila Enfila(Fila F, item x) {

  Nodo nuevo = (Nodo) malloc(sizeof( struct nodo ));

  nuevo->dato = x;
  nuevo->sig = NULL;

  if (EsFilaVacia(F)) {
    F.frente = nuevo;
  } else {
    F.final->sig = nuevo;
  };

  F.final = nuevo;

  return F;
};

Fila Defila(Fila F) {
  Nodo aux = F.frente;

  F.frente = aux->sig;

  free(aux);

  return F;
};

item Frente(Fila F) {

  if (EsFilaVacia(F)) {
    return indefinido;
  };

  return F.frente->dato;
};

item Final(Fila F) {

  if (EsFilaVacia(F)) {
    return indefinido;
  };

  return F.final->dato;
};

Fila Enfilan(Fila F, item x, int n) {
  
  if (n == 0) {
    return F;
  } else {
    return Enfila(Enfilan(F, x, n-1), x);
  };
};

bool Pertenece(Fila F, item x) {

  if (EsFilaVacia(F)) {
    return false;
  } else {
    return F.frente->dato == x || Pertenece(Defila(F), x);
  };
};

void mostrarFila(Fila F) {
  Nodo aux = F.frente;

  while (aux != NULL) {
    
    printf("%d - ", aux->dato);
    aux = aux->sig;
  };
};
