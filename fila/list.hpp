#ifndef LIST_HPP
#define LIST_HPP

using namespace std;

// Tipo armazenado na estrutura de dados
typedef int Data;

// Estrutura do nó utilizado na lista encadeada
typedef struct Node
{
	Data info; // dado armazenado no nó
	struct Node *next;	// ponteiro para o próximo nó
} Node;

// Definição da classe e métodos da lista encadeada
class List
{
private:
    Node *first;
    Node *last;
    int length;
public:
    // Construtor
    List();
    // Destrutor
    ~List();
    // Retorna o tamanho da lista
    int len();
    // Verifica se a lista está vazia
    bool empty();
    // Printa a lista
    void print();
    // Insere um elemento no começo da lista (inserção a esquerda)
    bool pushFront(Data data);
    // Insere um elemente no final da lista (inserção a direita)
    bool pushBack(Data data);
    // Remove um elemento do começo da lista
    bool popFront();
    // Remove um elemento do final da lista
    bool popBack();
    // Verifica se um elemento existe na lista
    bool search(Data data);
    // Retorna o elemento na posição pos da lista
    Data at(int pos);
};

#endif