#include "list.h"
#include "data.h"
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
		printData(p->item);
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