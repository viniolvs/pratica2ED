#include "graph.h"
#include "list.h"
#include "data.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

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
	G->num_arestas = 0;
	G->num_vertices = 0;
	G = NULL;
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
		aux = aux->next;
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