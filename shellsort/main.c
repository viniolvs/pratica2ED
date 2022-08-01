#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "modulo.h"

int main(int argc, char const *argv[])
{
    int len = 10000;

    int *Vi = newVector(len);
    int *Vs = newVector(len);
    fillVector(Vi, len, true);
    copyVector(Vi, Vs, len);

    printf("Tamanho do vetor = %d\n", len);

    clock_t begin, end;
    double time_insertion = 0.0, time_shell = 0.0;
    begin = clock();
    insertionSort(Vi,len);
    end = clock();
    time_insertion = (float)(((end - begin) + 0.0) / CLOCKS_PER_SEC);
    printf("Tempo para ordenar insertion sort = %6.6lf\n", time_insertion);

    begin = clock();
    shellSort(Vs,len);
    end = clock();
    time_shell = (float)(((end - begin) + 0.0) / CLOCKS_PER_SEC);
    printf("Tempo para ordenar shell sort = %6.6lf\n", time_shell);

    printf("Shell sort utilizou %c%.2lf do tempo que insertion sort utilizou!\n", '%', (time_shell/time_insertion)*100);
    return 0;
}

