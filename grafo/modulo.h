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

void initList(List *L);

void deleteList(List *L);

bool emptyList(List L);

void printList(List L);

short insertLeft(Data x, List *L);

short insertRight(Data x, List *L);

void removeFirst(List *L);

void removeLast(List *L);

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

void printGraph(Graph *G);

void initGraph(Graph *G);

void insertVertex(Graph *G);

void insertAresta(Graph *G ,int v1, int v2, int weight);