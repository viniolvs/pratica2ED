#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "modulo.h"

int main(int argc, char const *argv[])
{
    printf("Ordenando um vetor de 20 posições com shell sort: \n");
    int len = 20;
    int *V = newVector(len);
    fillVector(V, len, true);
    printf("Vetor a ser ordenado: ");
    printVector(V, len);
    printf("Ordenando vetor...\n");
    shellSort(V, len);
    printf("Vetor ordenado: ");
    printVector(V, len);
    freeVector(V);

    printf("\nComparando tempo de execução insertion sort e shell sort: \n");
    printf("Para comparar o tempo de execução, dois vetores idênticos serão ordenados, um vetor para cada algoritmo.\n");
    printf("Um vetor aleatório de 10000 posições é gerado e copiado para outro vetor para realizar este teste.\n");
    len = 10000;
    int *Vi = newVector(len);
    int *Vs = newVector(len);
    printf("\nGerando vetores...\n");
    fillVector(Vi, len, true);
    copyVector(Vi, Vs, len);
    
    clock_t begin, end;

    printf("Ordenando vetor com insertion sort...\n");
    double time_insertion = 0.0;
    begin = clock();
    insertionSort(Vi,len);
    end = clock();
    time_insertion = (float)(((end - begin) + 0.0) / CLOCKS_PER_SEC);
    printf("Tempo para ordenar utilizando insertion sort = %6.6lf\n", time_insertion);

    printf("Ordenando vetor com shell sort...\n");
    double time_shell = 0.0;
    begin = clock();
    shellSort(Vs,len);
    end = clock();
    time_shell = (float)(((end - begin) + 0.0) / CLOCKS_PER_SEC);
    printf("Tempo para ordenar utilizando shell sort = %6.6lf\n", time_shell);

    printf("Shell sort utilizou %c%.2lf do tempo que insertion sort utilizou!\n", '%', (time_shell/time_insertion)*100);
    freeVector(Vi);
    freeVector(Vs);
    return 0;
}

