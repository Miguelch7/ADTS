#include <stdio.h>
#include <stdlib.h>
#include "ListaEnlazada.h"

int main() {
    Lista L = CrearLista();

    L = Insertar(L, 0);
    L = Insertar(L, 1);
    L = Insertar(L, 2);
    L = Insertar(L, 2);
    L = Insertar(L, 3);
    L = Insertar(L, 2);
    L = Insertar(L, 4);
    L = Insertar(L, 2);
    L = Insertar(L, 5);
    L = Insertar(L, 55555555);

    L = BorrarUltimo(L);

    printf("El primer elemento es: %d\n", PrimerElemento(L));
    printf("Es lista vacía: %d\n", EsListaVacia(L));
    printf("Longitud de la lista: %d\n", Longitud(L));
    printf("El 1 pertenece a la lista: %d\n", Pertenece(L, 1));

    MostrarLista(L);

    return 0;
};