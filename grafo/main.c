#include "graph.h"
#include "list.h"
#include "data.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int i;
    printf("Testando a implementação de grafo através de lista de adjacências:\n\n");
    printf("Inicializando um grafo...\n");
    Graph G;
    initGraph(&G);
    if(G.array != NULL)
        printf("Grafo inicializado!\n");
    
    printf("\nRepresentação do grafo: \n");
    printf("v = vértice | p = peso\n");

    printf("\nInserindo 4 vértices no grafo...\n");
    for (i = 0; i < 4; i++)
    {
        printf("Inserindo vértice %d...\n", i);
        insertVertex(&G);
    }

    printf("\nInserindo arestas para testes e exibindo o grafo...\n");
    insertAresta(&G, 0, 2, 8);
    insertAresta(&G, 0, 1, 7);
    insertAresta(&G, 0, 3, 5);
    insertAresta(&G, 1, 2, 1);
    insertAresta(&G, 1, 3, 3);
    insertAresta(&G, 2, 0, 5);
    printGraph(&G);

    printf("\nVerificando se existe uma aresta do vértice 0 para o vértice 2:\n");
    if(existsAresta(&G, 0, 2))
        printf("Aresta existe!\n");
    else
        printf("Aresta não existe!\n");
    printf("Verificando se existe uma aresta do vértice 3 para o vértice 0:\n");
    if(existsAresta(&G, 3, 0))
        printf("Aresta existe!\n");
    else
        printf("Aresta não existe!\n");
    printf("\nRemovendo aresta do vértice 2 para o vértice 0:\n");
    if(removeAresta(&G, 2, 0))
        printf("Aresta removida!\n");
    else
        printf("Falha ao remover aresta!\n");
    printGraph(&G);
    printf("Removendo aresta do vértice 0 para o vértice 1:\n");
    if(removeAresta(&G, 0, 1))
        printf("Aresta removida!\n");
    else
        printf("Falha ao remover aresta!\n");
    printGraph(&G);
    printf("Removendo aresta do vértice 2 para o vértice 1:\n");
    if(removeAresta(&G, 2, 1))
        printf("Aresta removida!\n");
    else
        printf("Falha ao remover aresta!\n");
    printGraph(&G);
    
    printf("\nDeletando grafo...\n");
    freeGraph(&G);
    printf("Grafo deletado!\n");
    
    return 0;
}
