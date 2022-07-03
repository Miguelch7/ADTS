/*
 * SOLUCION TP N� 8 - CURSADO 2021
 * IMPLEMENTACION AB
 */
#include <stdlib.h>

typedef char itemAB;
const itemAB INDEFINIDO='$';

struct nodoAB{
			  itemAB Raiz;
			  struct nodoAB *Der;
			  struct nodoAB *Izq;
		   };
typedef struct nodoAB *AB;

AB ABvacio(){
	return NULL;
}

bool esABvacio(AB ab){
	   return(ab==NULL);
}

AB armarAB(AB ab_i,itemAB raiz,AB ab_d){
	struct nodoAB *ab;
	ab=new (struct nodoAB);
	ab->Izq=ab_i;
	ab->Der=ab_d;
	ab->Raiz=raiz;
	return(ab);
}
itemAB Raiz(AB ab){
	if(!(esABvacio(ab)))
		return(ab->Raiz);
	else
		return(INDEFINIDO);
}

AB Izquierdo(AB ab){
	   if(!(esABvacio(ab)))
		 return(ab->Izq);
	   else
		 return(NULL);
}

AB Derecho(AB  ab){
	if(!(esABvacio(ab)))
		 return(ab->Der);
	   else
		 return(NULL);
}

int esHoja(AB a){
	return(a->Izq==NULL && a->Der==NULL);
}

int Pertenece(AB arbol, itemAB x){
  if(esABvacio(arbol)){
    return 0;
  }else if(x == arbol->Raiz){
    return 1;
  }else{
    return (Pertenece(arbol->Izq, x) || Pertenece(arbol->Der, x));
  }
