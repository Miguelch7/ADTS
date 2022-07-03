/*
 * SOLUCION TP N� 8 - CURSADO 2021
 * IMPLEMENTACION PILAAB
 */

#include <stdio.h>
#include"AB.h"


typedef AB item;
const item indefinido=NULL;
struct nodo{
			item dato;
			struct nodo *sig;
		   };

typedef struct nodo* Pila;

Pila pilaVacia();
bool esPilaVacia(Pila P);
Pila push(Pila P, item x);
void escribir(Pila l);
Pila pop(Pila P);
item top(Pila P);

Pila pilaVacia(){
	return NULL;
}

bool esPilaVacia(Pila P){
	return P==NULL;
}

Pila push(Pila P, item x){
	struct nodo *aux;
	aux=new struct nodo;
	aux->dato=x;
	aux->sig=P;
    P=aux;
    return P;
}

item top(Pila P){
	if(!esPilaVacia(P))
		return P->dato;
	else
		return indefinido;
}

void escribir(Pila P){
	printf("\nPILA ->");
	while(!esPilaVacia(P)){
		printf(" %c ->",Raiz((P->dato)));
        P=P->sig;
	}
	printf(" FIN\n");
}

Pila pop(Pila P){
	if(!esPilaVacia(P)){
		struct nodo *aux=P;
		P=aux->sig;
		delete aux;
	}
	return P;
}

