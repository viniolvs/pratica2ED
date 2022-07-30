#ifndef MODULO_H
#define MODULO_H 

#include <stdbool.h>

// Estrutura que cada nó armazena
typedef struct Data
{
    int vertex; //número do vértice
    int weight; //peso do vértice
}Data;

// Estrutura do nó da lista encadeada
typedef struct Node
{
    Data item; // dado armazenado no nó
	struct Node *next;	// ponteiro para o próximo nó
}Node;

// Estrutura da lista encadeada
typedef struct List
{
    Node *first;
    Node *last;
    int length;
}List;

// Métodos utilizados para a lista encadeada

// Inicializa uma lista
void initList(List *L);

// Destrói uma lista
void freeList(List *L);

// Verifica se uma lista está vazia
bool emptyList(List L);

// Printa uma lista
void printList(List L);

// Insere um elemento no começo de uma lista
short insertLeft(List *L, Data x);

// Insere um elemento no fim de uma lista
short insertRight(List *L, Data x);

// Remove um elemento do começo de uma lista
void removeFirst(List *L);

// Remove um elemento do fim de uma lista
void removeLast(List *L);

// Remove um elemento na posição pos
void removeAt(List *L, int pos);

// ======================= GRAFO ===================================

// Define o máximo de vértices que o grafo pode conter
#define MAX_VERTICES 100
// Define o máximo de arestas que o grafo pode conter
#define MAX_ARESTAS -1

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