#include <iostream>
#include "queue.hpp"

int main(int argc, char const *argv[])
{
    cout << "Testando implementação fila com herança de lista encadeada:" << endl;
    cout << "Os métodos da classe mão são utilizados de acordo com as regras de uma fila, ou seja, inserção no começo e remoção pelo fim." << endl;
    // Instancia um objeto da classe fila
    // O construtor da classe mãe é chamado
    // "Por baixo dos panos", uma lista encadeada é incializada
    Queue queue;
    cout << endl << "Inserção no final da fila utilizando o método herdado da classe mãe(List):" << endl;
    cout << "Inserindo 10 elementos(int) na fila: " << endl;
    for (int i = 0; i < 10; i++)
    {
        cout << "Inserindo " << i << " na fila..." << endl;
        queue.insert(i);
        queue.printQueue();
    }
    cout << endl;
    cout << "Remoção no começo da fila utilizando o método herdado da classe mãe(List):" << endl;
    cout << "Removendo metade dos elementos da fila: " << endl;
    for (int i = queue.size()/2; i > 0; i--)
    {
        cout << "Removendo... " << endl;
        queue.remove();
        queue.printQueue();
    }
    
    cout << endl << "Primeiro elemento da fila: " << queue.getFirst() << endl;
    cout << "Ultimo elemento da fila: " << queue.getLast() << endl;

    cout << endl << "Removendo todos os elementos da fila: " << endl;
    while (true)
    {
        if (queue.emptyQueue())
        {
            cout << "Fila vazia!" << endl;
            break;
        }
        cout << "Removendo... " << endl;
        queue.remove();
        queue.printQueue();
    }
    cout << "Destruindo a fila utilizando o destrutor da classe mãe..." << endl;
    queue.~Queue();
    cout << "Fila destruída!" << endl;
    return 0;
}
