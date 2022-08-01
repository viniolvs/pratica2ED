#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "modulo.h"

int* newVector(int len)
{
    int *V;
    int i;
    V = (int*)malloc(sizeof (int) * len);
   return V;
}

void freeVector(int *V)
{
    if (V != NULL)
        free(V);
}

void fillVector(int *V, int len, bool seed)
{
    int i;
    clock_t clk = clock();
    if (seed)
        srand(clk);
    for (i = 0; i < len; i++)
            V[i] = ((int)(rand() % 1000));
}

void copyVector(int *V1, int *V2, int len){
    int i = 0;
    for (i = 0; i < len; i++)
        V2[i] = V1[i];
}

void printVector(int *V, int len){
    int i;
    printf("[ ");
    for (i = 0 ; i < len ; i++)
        printf("%d ", V[i]);
    printf("]\n");
}

void insertionSort(int *V, int len){
    int i, j, key;
    for (j = 0; j < len; j++)
    {
        key = V[j];
        i = j-1;
        while (i >= 0 && V[i] > key)
        {
            V[i+1] = V[i];
            i--;
        }
        V[i+1] = key;
    }
}

void shellSort(int *V, int len){
    int i, h, aux;
    for (h = (len/2); h > 1 ; h/=2)
    {
        for (i = 0 ; i + h < len ; i++)
        {
            if(V[i] > V[i+h]){
                aux = V[i];
                V[i] = V[h+i];
                V[h+i] = aux;
            }
        }
    }  
    // h == 1 corresponde ao insertion sort 
    insertionSort(V, len);
}