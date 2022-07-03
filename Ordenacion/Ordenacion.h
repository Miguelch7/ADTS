#include <stdio.h>

void Seleccion(int A[], int n);
void Insercion(int A[], int n);
void Intercambio(int A[], int n);

void Seleccion(int A[], int n) {

  for (int i = 1; i < n-1; i++) {

    int menor = A[i];
    int kMenor = i;

    for (int j = i+1; j < n; j++) {

      if (A[j] < menor) {
        kMenor = j;
        menor = A[j];
      };

      A[kMenor] = A[i];
      A[i] = menor;
    };
  };
};

void Insercion(int A[], int n) {
  
  for (int i = 2; i < n; i++) {
    int proximo = A[i];
    int j = i;

    while (j > 1 && proximo < A[j-1]) {
      A[j] = A[j-1];
      j = j-1;
    };

    A[j] = proximo;
  };
};

void Intercambio(int A[], int n) {
  for (int i = 0; i < n; i++) {
    for (int j = n; j > i; j--) {
      if (A[j-1] > A[j]) {
        int aux = A[j-1];
        A[j-1] = A[j];
        A[j] = aux;
      };
    };
  };
};