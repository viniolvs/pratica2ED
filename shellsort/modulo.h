#ifndef MODULO_H
#define MODULO_H

#include <stdbool.h>

// Aloca um vetor de tamanho len
int* newVector(int len);

//Destrói um vetor
void freeVector(int *V);

// Preenche um vetor com valores aleatórios
// seed é utilizado para gerar aleatoriedade entre as execuções
void fillVector(int *V, int len, bool seed);

// copia o vetor V1 para o vetor V2
// V2 não pode ser menor do que V1
void copyVector(int *V1, int *V2, int len);

// Printa um vetor de tamanho len
void printVector(int *V, int len);

// Ordena um vetor utilizando insertion sort
void insertionSort(int *V, int len);

// Ordena um vetor utilizando shell sort
void shellSort(int *V, int len);

#endif