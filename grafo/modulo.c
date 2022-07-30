#include "modulo.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// MÉTODOS PARA LISTA ENCADEADA

void initList(List *L)
{
	L->first = NULL;
	L->last = NULL;
	L->length = 0;
	return;
}

void freeList(List *L)
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

bool emptyList(List L)
{
	return (L.length == 0);
}

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

short insertLeft(List *L, Data x)
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

short insertRight(List *L, Data x)
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

void removeFirst(List *L)
{
	Node *aux = L->first;	
	L->first = L->first->next;	
	free(aux)	;									
	if (L->first == NULL)		
		L->last = NULL;			
	L->length--;						
}

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

void removeAt(List *L, int pos){
	if(pos >= L->length){
		printf("Invalid position\n");
		return;
	}
	if(pos == 0){
		removeFirst(L);
		return;
	}
	if(pos == L->length-1){
		removeLast(L);
		return;
	}
	Node *aux = L->first->next;
	Node *aux_prev = L->first;
	int i;
	for(i = 1 ; i < pos ; i++){
		aux = aux->next;
		aux_prev = aux_prev->next;
	}
	aux_prev->next = aux->next;
	free(aux);
}

// ===========================================================================

// MÉTODOS PARA GRAFO

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

void initGraph(Graph *G){
	G->num_arestas = 0;
	G->num_vertices = 0;
	G->array = (List*)malloc(sizeof(List)*MAX_VERTICES);
}

void freeGraph(Graph *G){
	int i;
	for (i = 0; i < G->num_vertices; i++)
		freeList(&G->array[i]);
	free(G->array);
}

void insertVertex(Graph *G){
	if(G->num_vertices+1 == MAX_VERTICES){
		printf("Número máximo de vértices atingido\n!");
		return;	
	}
	initList(&G->array[G->num_vertices]);
	G->num_vertices++;
}

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
	insertRight(&G->array[v1], *item);
	G->num_arestas++;
}

bool removeAresta(Graph *G, int v1, int v2){
	Node *aux = G->array[v1].first;
	bool flag = false;
	int i;
	for ( i = 0; (aux!=NULL) && (flag == false); i++){
		if(v2 == aux->item.vertex){
			flag = true;
			G->num_arestas--;
			removeAt(&G->array[v1], i);
		}
	}
	return flag;
}

bool existsAresta(Graph *G, int v1, int v2){
	bool flag = false;
	Node *aux = G->array[v1].first;
	while ((aux != NULL) && (flag == false))
	{
		if(v2 == aux->item.vertex)
			flag = true;
		aux = aux->next;	
	}
	return flag;
}