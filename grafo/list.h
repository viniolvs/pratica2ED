#ifndef LIST_H
#define LIST_H

#include "data.h"
#include <stdbool.h>

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

#endif