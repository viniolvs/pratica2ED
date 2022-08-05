#ifndef GRAPH_H
#define GRAPH_H

#include "list.h"
#include "data.h"
#include <stdbool.h>

// Define o máximo de vértices que o grafo pode conter
#define MAX_VERTICES 100

// Estrutura do grafo
typedef struct Graph
{
    List *array; // array de listas encadeads
    int num_vertices; // numero de vértices no grafo
    int num_arestas;  // numero de arestas no grafo
}Graph;

// Métodos utilizados para o grafo

// Printa um grafo
void printGraph(Graph *G);

// Inicializa um grafo
void initGraph(Graph *G);

// Destrói um grafo
void freeGraph(Graph *G);

// Insere um vértice em um grafo
void insertVertex(Graph *G);

// Insere uma aresta em um grafo do vértice v1 para o vértice v2 com peso weight
void insertAresta(Graph *G ,int v1, int v2, int weight);

// Remove a aresta do vértive v1 para o vértice v2
bool removeAresta(Graph *G, int v1, int v2);

// Verifica se existe uma aresta do vértice v1 para o vértice v2
bool existsAresta(Graph *G, int v1, int v2);

#endif