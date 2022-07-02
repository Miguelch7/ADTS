#include <stdio.h>
#include <stdlib.h>
#include "Comision.h"

int main() {
    
    Comision C = ComisionVacia();

    C = AltaAlumno(C, 'a');
    C = AltaAlumno(C, 'b');
    C = AltaAlumno(C, 'c');
    C = AltaAlumno(C, 'd');
    C = AltaAlumno(C, 'e');
    C = AltaAlumno(C, 'f');
    C = AltaAlumno(C, 'g');
    C = AltaAlumno(C, 'h');
    C = AltaAlumno(C, 'i');
    C = AltaAlumno(C, 'j');

    C = BajaUltimo(C);

    Mostrar(C);

    printf("Cantidad de alumnos: %d", Cantidad(C));
    printf("Esta vacia?: %d", EstaVacia(C));
    printf("Esta el apellido \'d\'?: %d", Esta(C, 'd'));
    printf("Ultimo inscripto: %c", UltimoInscripto(C));

    return 0;
};