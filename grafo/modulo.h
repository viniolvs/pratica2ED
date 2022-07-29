#define MAX_VERTICES 100
#include <stdbool.h>

typedef struct Data
{
    int vertex; //número do vértice
    int weight; //peso do vértice
}Data;

typedef struct Node
{
    Data item; // dado armazenado no nó
	struct Node *next;	// ponteiro para o próximo nó
}Node;

typedef struct List
{
    Node *first;
    Node *last;
    int length;
}List;

typedef struct Graph
{
    List *array; // vetor de Listas
    int num_vertices; // tamanho do array de listas
    int num_arestas;
}Graph;

void initList(List *L);

void deleteList(List *L);

bool emptyList(List L);

void printList(List L);

short insertLeft(Data x, List *L);

short insertRight(Data x, List *L);

void removeFirst(List *L);

void removeLast(List *L);

// ==========================================================

void printGraph(Graph *G);

void initGraph(Graph *G);

void insertVertex(Graph *G);

void insertAresta(Graph *G ,int v1, int v2, int weight);