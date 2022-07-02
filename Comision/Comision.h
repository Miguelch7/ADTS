#include <stdio.h>
#include <stdlib.h>

typedef char item;
const item indefinido = '*';
struct Nodo {
    item apellidoAlumno;
    struct Nodo* siguiente;
} typedef Nodo;
typedef struct Nodo* Comision;

Comision ComisionVacia();  // Constructora
Comision AltaAlumno(Comision C, item x); // Constructora
int EstaVacia(Comision C); // Test
int Cantidad(Comision C); // Operacion
Comision BajaAlumno(Comision C, item x); // Operacion
Comision BajaUltimo(Comision C); // Operacion
item UltimoInscripto(Comision C); // Selectora
int Esta(Comision C, item x); // Test
int HayComunes(Comision C1, Comision C2); // Test
void Mostrar(Comision C);

Comision ComisionVacia() {
    return NULL;
};

Comision AltaAlumno(Comision C, item x) {

    Comision nuevoAlumno;
    nuevoAlumno = (Comision) malloc( sizeof(Nodo) );

    nuevoAlumno->apellidoAlumno = x;
    nuevoAlumno->siguiente = C;

    C = nuevoAlumno;

    return C;
};

int EstaVacia(Comision C) {
    return (C == NULL);
};

int Cantidad(Comision C) {
    
    if ( EstaVacia(C) ) {
        return 0;
    } else {
        return 1 + Cantidad( C->siguiente );
    };
};

Comision BajaUltimo(Comision C) {

    if ( !EstaVacia(C) ) {
        Comision aux = C;

        C = C->siguiente;
        
        free(aux);
    };

    return C;
};

Comision BajaAlumno(Comision C, item x) {
    while(!EstaVacia(C) && C->apellidoAlumno == x) {
        C = BajaUltimo(C);
    };

    Comision auxActual = C;
    Comision auxAnterior = C;

    while (!EstaVacia(C)) {
        if (auxActual->apellidoAlumno == x) {
            auxAnterior->siguiente = auxActual->siguiente;
            free(auxActual);
            auxActual = auxAnterior->siguiente;
        } else {
            auxAnterior = auxActual;
            auxActual = auxActual->siguiente;
        };
    };

    return C;
};

item UltimoInscripto(Comision C) {
    if (EstaVacia(C)) {
        return indefinido;
    } else {
        return C->apellidoAlumno;
    };
};

int Esta(Comision C, item x) {
    while (!EstaVacia(C) && C->apellidoAlumno != x) {
        C = C->siguiente;
    };
    
    return (C != NULL);
};

int HayComunes(Comision C1, Comision C2) {

    while ( !EstaVacia(C1) ) {
        if (Esta(C2, UltimoInscripto(C1))) {
            return 1;
        } else {
            C1 = BajaUltimo(C1);
        };
    };

    return 0;  
};

void Mostrar(Comision C) {
    if (!EstaVacia(C)) {

        while (!EstaVacia(C)) {
            printf("Apellido del alumno: %c\n", C->apellidoAlumno);
            C = C->siguiente;
        }
          
    } else {
        printf("La comision no tiene alumnos inscriptos\n");
    };
};
