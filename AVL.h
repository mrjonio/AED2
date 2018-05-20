#ifndef __AVL_H__
#define __AVL_H__

#include <stdlib.h>
#include <stdio.h>

typedef struct avl avl;
typedef struct raiz raiz;


struct avl
{
    int info;
    avl* pai;
    avl* esq;
    avl* dir;
};

struct raiz
{
    avl* arvore;
};




void add(raiz* inicio, avl* raiz, avl* novo);
void imprimir(avl* raiz);
avl* aloca_novo(int info);
int busca_no(avl* raiz, int info);
int altura_no(avl* raiz);
int retorna_balanceamento(avl* raiz);
void rotacionar_sd(avl* raiz);
void rotacionar_se(avl* raiz);
void rotacionar_dd(avl* raiz);
void rotacionar_de(avl* raiz);
void fazer_rotacoes(avl* raiz);
raiz* starta_arvore(int info);
void atualizar_raiz(raiz* raiz, avl* arvore);
int maior(int valor1, int valor2);

#endif // __AVL_H__
