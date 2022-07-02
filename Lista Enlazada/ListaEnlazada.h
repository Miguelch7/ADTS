#include <stdio.h>
#include <stdlib.h>

// Definición de Lista como una Lista enlazada
typedef int item;
struct Nodo {
    item dato;
    struct Nodo* siguiente;
};
typedef struct Nodo* Lista;

// Declaración funciones básicas de lista enlazada
Lista CrearLista();
int EsListaVacia(Lista L);
void MostrarLista(Lista L);
item PrimerElemento(Lista L);
Lista Insertar(Lista L, item x);
Lista BorrarUltimo(Lista L);
int Longitud(Lista L);
int Pertenece(Lista L, item x);
Lista BorrarK(Lista L, item k);

// Definición funciones basicas de lista enlazada
Lista CrearLista() {
    return NULL;
};

int EsListaVacia(Lista L) {
    return (L == NULL);
};

void MostrarLista(Lista L) {
    while ( !EsListaVacia(L) ) {
        printf("%d\n", L->dato);
        L = L->siguiente;
    };
};

item PrimerElemento(Lista L) {
    return L->dato;
};

Lista Insertar(Lista L, item x) {

    struct Nodo* nuevoNodo;
    nuevoNodo = (Lista) malloc( sizeof(struct Nodo) );

    nuevoNodo->dato = x;
    nuevoNodo->siguiente = L;

    L = nuevoNodo;

    return L;
};

Lista BorrarUltimo(Lista L) {
    if ( !EsListaVacia(L) ) {

        struct Nodo* auxNodo = L;
        
        L = L->siguiente;

        free(auxNodo);
    };

    return L;
};

int Longitud(Lista L) {
    int longitud = 0;

    while ( !EsListaVacia(L) ) {
        longitud++;
        L = L->siguiente;
    };

    return longitud;
};

int Pertenece(Lista L, item x) {
    while ( !EsListaVacia(L) ) {
        if (L->dato == x) {
            return 1;
        };

        L = L->siguiente;
    };

    return 0;
};

Lista BorrarK(Lista L, item k) {

};

int Iguales(Lista L1, Lista L2) {
	
    int sonIguales = 1;
	
    while( !EsListaVacia(L1) && !EsListaVacia(L2) && sonIguales ){
		
        if(PrimerElemento(L1) != PrimerElemento(L2)) {
			sonIguales = 0;
        };

		L1 = BorrarUltimo(L1);
		L2 = BorrarUltimo(L2);
	};

	return EsListaVacia(L1) && EsListaVacia(L2);
};