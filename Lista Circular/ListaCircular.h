#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int item;
const item indefinido = -9999;

struct nodo {
  item dato;
  struct nodo* siguiente;
};
typedef struct nodo* Nodo;

typedef struct {
  struct nodo* cabecera;
  int longitud;
} LC;

LC LCVacia();
LC LCInsertar(LC L, item x);
bool EsLCVacia(LC L);
item LCValor(LC L);
LC LCBorrar(LC L);
LC LCRotar(LC L);
LC LCBorrarK(LC L, int k);
int LCLongitud(LC L);
void mostrarLC(LC L);

LC LCVacia() {

  LC L;

  L.cabecera = NULL;
  L.longitud = 0;

  return L;
};

LC LCInsertar(LC L, item x) {
  
  Nodo nuevo = (Nodo) malloc(sizeof(struct nodo));

  nuevo->dato = x;

  if (EsLCVacia(L)) {
    nuevo->siguiente = nuevo;
    L.cabecera = nuevo;
  } else {
    nuevo->siguiente = L.cabecera->siguiente;
  };  

  L.cabecera->siguiente = nuevo;
  L.longitud++;

  return L;
};

bool EsLCVacia(LC L) {
  return L.cabecera == NULL;
};

item LCValor(LC L) {
  if (EsLCVacia(L)) {
    return indefinido;
  } else {
    return L.cabecera->siguiente->dato;
  };
};

LC LCBorrar(LC L) {

  if (!EsLCVacia(L)) {
    
    Nodo aux = L.cabecera->siguiente;

    L.cabecera->siguiente = aux->siguiente;
    L.longitud--;

    free(aux);
  };

  return L;
};

LC LCRotar(LC L) {
  
  L.cabecera = L.cabecera->siguiente;

  return L;
};

LC LCBorrarK(LC L, int k) {
  
  if (!EsLCVacia(L)) {

    if (LCValor(L) == k) {

      return LCBorrarK(LCBorrar(L), k);
    } else {

      return LCInsertar(LCBorrarK(LCBorrar(L), k), LCValor(L));
    };
  };

  return L;
};

int LCLongitud(LC L) {
  return L.longitud;
};

void mostrarLC(LC L) {
  
  Nodo cabecera = L.cabecera->siguiente;
  int longitud = LCLongitud(L);

  while (longitud > 0) {
    printf("%d -> ", cabecera->dato);
    cabecera = cabecera->siguiente;

    longitud--;
  };
};