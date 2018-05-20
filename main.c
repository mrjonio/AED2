#include <stdio.h>
#include <stdlib.h>
#include "AVL.h"

int main()
{
    raiz* arvore = starta_arvore(10);
    avl* a = aloca_novo(4);
    avl* b = aloca_novo(12);
    avl* c = aloca_novo(2);
    avl* d = aloca_novo(3);
    avl* e = aloca_novo(-2);
    avl* f = aloca_novo(1);
    add(arvore, arvore->arvore, a);
    add(arvore, arvore->arvore, b);
    add(arvore, arvore->arvore, c);
    add(arvore, arvore->arvore, d);
    add(arvore, arvore->arvore, e);
    add(arvore, arvore->arvore, f);
    imprimir(arvore->arvore);
    return 0;
}
