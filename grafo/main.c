#include "modulo.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    Graph G;
    
    initGraph(&G);
    insertVertex(&G);
    insertVertex(&G);
    insertVertex(&G);
    insertVertex(&G);
    insertAresta(&G, 0, 2, 8);
    insertAresta(&G, 0, 1, 7);
    insertAresta(&G, 1, 2, 1);
    insertAresta(&G, 2, 0, 5);
    printGraph(&G);
    if(existsAresta(&G, 0, 2))
        printf("Aresta existe!\n");
    printf("Removendo aresta:\n");
    removeAresta(&G, 2, 0);
    printGraph(&G);
    printf("Deletando grafo\n");
    freeGraph(&G);
    printGraph(&G);
    return 0;
}
