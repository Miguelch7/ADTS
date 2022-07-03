/*
 * SOLUCION TP N� 8 - CURSADO 2021
 */
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include "Funciones.h"

int esOperando(char car){
	if((car>='a'&& car<='z')||(car>='A'&& car<='Z'))
		return 1;
	else
		return 0;
}

AB Construir(char posfija[]){
	AB der, izq;
	Pila P;
	P = pilaVacia();
	int i=0;
	while(posfija[i]!='=')
	{
		if(esOperando(posfija[i]))
			P = push(P,armarAB(ABvacio(),posfija[i],ABvacio()));
		else
		{
			der=top(P);
			P = pop(P);
			izq=top(P);
			P = pop(P);
			P = push(P, armarAB(izq,posfija[i], der));
		}
		i++;
	}
	return top(P);
}

// IMPLEMENTACION LISTADOS

void posOrden(AB A){
	if(!esABvacio(A)) 	{
		posOrden(Izquierdo(A));
		posOrden(Derecho(A));
		printf("%c",Raiz(A));
	}
}

void enOrden(AB A){
	if(!esABvacio(A)) 	{
		printf("(");
		enOrden(Izquierdo(A));
		printf("%c",Raiz(A));
		enOrden(Derecho(A));
		printf(")");
	}
}

void preOrden(AB A){
	if(!esABvacio(A)) 	{
		printf("%c",Raiz(A));
		preOrden(Izquierdo(A));
		preOrden(Derecho(A));
	}
}

