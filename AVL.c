#include "AVL.h"
#include <stdio.h>
#include <stdlib.h>

avl* aloca_novo(int info){
    avl* novo = (avl*) malloc(sizeof(avl));
    novo->pai = NULL;
    novo->dir = NULL;
    novo->esq = NULL;
    novo->info = info;
    return novo;
}

raiz* starta_arvore(int info){
    avl* novo = aloca_novo(info);
    raiz* nova = (raiz*) malloc(sizeof(raiz));
    nova->arvore = novo;
    return nova;
}

void add(raiz* inicio, avl* raiz, avl* novo){
    int existe = busca_no(raiz, novo->info);
    if(existe == 0){
        return;
    } else{
        if(raiz->info > novo->info){
            if(raiz->esq != NULL){
                add(inicio, raiz->esq, novo);
            } else {
                novo->pai = raiz;
                raiz->esq = novo;
            }
            } else {
                if(raiz->dir != NULL){
                add(inicio, raiz->dir, novo);
            } else {
                novo->pai = raiz;
                raiz->dir = novo;
            }
        }
    }
    fazer_rotacoes(raiz);
    atualizar_raiz(inicio, inicio->arvore);
}

void imprimir(avl* arvore){
    if(arvore->esq != NULL){
        imprimir(arvore->esq);
    }
    printf("%d  ", arvore->info);
    printf("%d\n", retorna_balanceamento(arvore));
    if(arvore->dir != NULL){
        imprimir(arvore->dir);
    }
}

int busca_no(avl* raiz, int numero){
    if (raiz == NULL){
        return 1;
    } else {
        if(raiz->info == numero){
            return 0;
        } else{
        if(raiz->info > numero){
            return busca_no(raiz->esq, numero);
        } else{
            return busca_no(raiz->dir, numero);
            }
        }
    }
}

int altura_no(avl* raiz){
    if (raiz == NULL){
            return 0;
    }  else {
            int esq, dir;
            esq = altura_no(raiz->esq);
            dir = altura_no(raiz->dir);
            return maior(esq, dir) + 1;
        }

}

int retorna_balanceamento(avl* raiz){
    int esquerdo = altura_no(raiz->esq);
    int direito = altura_no(raiz->dir);
    return (esquerdo - direito);
}


void rotacionar_sd(avl* raiz){
    raiz->pai->esq = raiz->dir;
    raiz->dir = raiz->pai;
    raiz->pai = raiz->pai->pai;
    if (raiz->pai != NULL){
        if(raiz->pai->dir == raiz->dir){
            raiz->pai->dir = raiz;
        } else if(raiz->pai->esq == raiz->dir){
            raiz->pai->esq = raiz;
        }
    }
    raiz->dir->pai = raiz;



}

void rotacionar_se(avl* raiz){
    raiz->pai->dir = raiz->esq;
    raiz->esq = raiz->pai;
    raiz->pai = raiz->pai->pai;
    if (raiz->pai != NULL){
        if(raiz->pai->dir == raiz->esq){
            raiz->pai->dir = raiz;
        } else if(raiz->pai->esq == raiz->esq){
            raiz->pai->esq = raiz;
        }
    }
    raiz->esq->pai = raiz;


}

void rotacionar_dd(avl* raiz){
    rotacionar_sd(raiz->esq);
    rotacionar_se(raiz->pai);
}

void rotacionar_de(avl* raiz){
    rotacionar_se(raiz->dir);
    rotacionar_sd(raiz->pai);
}

void fazer_rotacoes(avl* raiz){
    if (raiz != NULL){
        fazer_rotacoes(raiz->esq);
        fazer_rotacoes(raiz->dir);
        int fatorb = retorna_balanceamento(raiz);
        if (fatorb > 1){
           int fatorFilho = retorna_balanceamento(raiz->esq);
           if(fatorFilho == 1){
            rotacionar_sd(raiz->esq);
           } else{
               if(fatorFilho == -1){
                rotacionar_de(raiz->esq);
               }
           }
        } else {
            if (fatorb < -1){
                int fatorFilho = retorna_balanceamento(raiz->dir);
                if(fatorFilho == -1){
                    rotacionar_se(raiz->dir);
                } else{
                    if(fatorFilho == 1){
                        rotacionar_dd(raiz->dir);
                    }
                }
            }
        }
    }
}
void atualizar_raiz(raiz* raiz, avl* arvore){
    if (arvore->pai == 0){
        raiz->arvore = arvore;
    } else{
        atualizar_raiz(raiz, arvore->pai);
    }
}

int maior(int valor1, int valor2){
    if (valor1 > valor2){
        return valor1;
    }else{
        return valor2;
    }
}


