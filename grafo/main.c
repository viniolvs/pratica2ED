#include "modulo.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    Graph G;
    initGraph(&G);
    insertVertex(&G, 0);
    insertVertex(&G, 1);
    insertVertex(&G, 8);
    insertAresta(&G, 0, 2, 8);
    insertAresta(&G, 0, 1, 7);
    printGraph(&G);

    return 0;
}
