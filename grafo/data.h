#ifndef DATA_H
#define DATA_H

// Estrutura que cada nó da lista de adjacência armazena
typedef struct Data
{
    int vertex; //número do vértice
    int weight; //peso do vértice
}Data;

void printData(Data data);

#endif