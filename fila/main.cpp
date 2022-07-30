#include <iostream>
#include "modulo.hpp"

int main(int argc, char const *argv[])
{
    Queue queue;
    List list;
    for (int i = 0; i < 5; i++)
    {
        list.pushFront(i);
        queue.insert(i);
    }
    queue.printQueue();
    cout << "Tamanho da fila = " << queue.size() << endl;
    cout << "Primeiro da fila = " << queue.getFirst() << endl;
    cout << "Ultimo da fila = " << queue.getLast() << endl;
    queue.remove();
    queue.printQueue();

    return 0;
}
