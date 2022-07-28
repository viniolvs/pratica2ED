#include <stdbool.h>

// aloca um vetor
int* newVector(int len);

// preenche um vetor com valores aleatórios
void fillVector(int *V, int len, bool seed);

// copia o vetor V1 para o vetor V2
void copyVector(int *V1, int *V2, int len);

// printa um vetor
void printVector(int *V, int len);

// ordena um vetor utilizando insertion sort
void insertionSort(int *V, int len);

// ordena um vetor utilizando shell sort
void shellSort(int *V, int len);