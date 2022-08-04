#include "list.hpp"

#ifndef QUEUE_HPP
#define QUEUE_HPP

// Definição da classe e métodos da Fila com herança da lista encadeada
class Queue : protected List
{
public:
    // Construtor
    Queue();
    // Destrutor
    ~Queue();
    // Retorna o tamanho da fila
    int size();
    // Insere um elemento na fila
    bool insert(Data data);
    // Remove um elemento da fila
    bool remove();
    // Verifica se a fila está vazia
    bool emptyQueue();
    // Printa a fila
    void printQueue();
    // Retorna o primeiro elemento da fila
    Data getFirst();
    // Retorna o último elemento da fila
    Data getLast();
};

#endif