#include "modulo.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// FUNCOES PARA LISTA ENCADEADA

// Inicialização da lista
void initList(List *L)
{
	L->first = NULL;
	L->last = NULL;
	L->length = 0;
	return;
}

// destruição da lista
void deleteList(List *L)
{
	Node *p = L->first;
	while (p)
	{
		L->first = L->first->next;
		free(p);
		L->length--;
		p = L->first;
	}
	L->last = NULL;
}

// verifica lista vazia
bool emptyList(List L)
{
	return (L.length == 0);
}

// escreve a lista;
void printList(List L)
{
	Node *p = L.first;
	
	printf("[");
	while (p)
	{
		printf("v:%d p:%d", p->item.vertex, p->item.weight);
		if (p->next)
			printf(" | ");
		p = p->next;
	}
	printf("]");
}

// inserção pela esquerda
short insertLeft(Data x, List *L)
{
	Node *aux;
	aux = (Node*)malloc(sizeof(Node));
	if (aux == NULL)	
		return 1;	
	else
	{ 
		aux->item = x;					
		aux->next = L->first;		
		L->first = aux;					
		if (L->last == NULL)		
			L->last = aux;				
		L->length++;						
		return 0;								
	}
}

// Inserção pela direita
short insertRight(Data x, List *L)
{
	Node *aux = (Node*)malloc(sizeof(Node));
	if (aux ==NULL)
		return 1;
	else
	{
		aux->item = x;
		aux->next = NULL;
	
		if (L->last == NULL)		
			L->first = L->last = aux; 
		else                            
		{
			L->last->next = aux;
			L->last = aux;
		}
		L->length++;
		return 0;
	}
}

// remoção pela esquerda
void removeFirst(List *L)
{
	Node *aux = L->first;	
	L->first = L->first->next;	
	free(aux)	;									
	if (L->first == NULL)		
		L->last = NULL;			
	L->length--;						
}

// remoção pela direita
void removeLast(List *L)
{
	Node *aux = L->first;
	
	if (L->first == L->last)		
	{
		free(L->first);					
		L->last = L->first =NULL;	
	}
	else
	{	
		while (aux->next->next != NULL)		
			aux = aux->next;
		L->last = aux;								
		free(aux->next);							
		L->last->next = NULL;			
	}
	L->length--;
}

// ===========================================================================

// FUNCOES PARA GRAFO

void printGraph(Graph *G){
	int i;
	for (i = 0; i < G->num_vertices; i++)
	{
		if (&G->array[i] != NULL)
		{
			printf("Vertice %d = ",i);
			printList(G->array[i]);
			printf("\n");
		}
	}
}

// inicializa um grafo
void initGraph(Graph *G){
	G->num_arestas = 0;
	G->num_vertices = 0;
	G->array = (List*)malloc(sizeof(List)*MAX_VERTICES);
}

// insere um vértice no grafo
void insertVertex(Graph *G){
	if(G->num_vertices+1 == MAX_VERTICES){
		printf("Número máximo de vértices atingido\n!");
		return;	
	}
	initList(&G->array[G->num_vertices]);
	G->num_vertices++;
}

// insere uma aresta no grafo do vertice v1 para o vertice v2
void insertAresta(Graph *G, int v1, int v2, int weight){
	if(v1 >= G->num_vertices){
		printf("Erro ao inserir aresta: ");
		printf("Vertice origem da aresta não existe\n");
		return;
	}
	else if (v2 >= G->num_vertices){
		printf("Erro ao inserir aresta: ");
		printf("Vertice destino da aresta não existe\n");
		return;
	}
	Data *item = (Data*)malloc(sizeof(Data));
	item->vertex = v2;
	item->weight = weight;
	insertRight(*item, &G->array[v1]);
	G->num_arestas++;
}
