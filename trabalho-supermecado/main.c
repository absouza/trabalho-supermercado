/* 
 * File:   main.c
 * Author: Alana
 *
 * Created on 17 de Novembro de 2014, 23:42
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct spilha{
    struct spilha *proximo;
    int chave;
    int prioridade;
} noPilhaInt, *PilhaInt;

void inicializa (PilhaInt *p){
    *p = NULL;
}

_Bool top(PilhaInt *p, int *y){
    if (!*p){
        return false;
    }
    else{
        *y = (*p)->chave;
        return true;
    }
}

_Bool push(PilhaInt *z, int x){
    noPilhaInt *p;
    if (!(p = (noPilhaInt*) malloc(sizeof (noPilhaInt))))
        return false;
    p->proximo = !(*z) ? NULL : *z;
    *z = p;
    return true;
}

_Bool pop(PilhaInt *p, int *x){
    if (p->qtd == 0){
        return false;
    }
    *x = p->pilha[-- p->qtd];
    return true;
}

int main(){
    int x = 0;
    PilhaInt p;
    inicializa(&p);
    printf("%d\n" , push(&p, 100));
    printf("%d\n" , push(&p , 5000));
    printf("%d\n" , push(&p , 10412));
    printf("%d\n" , pop(&p, &x));
    printf("%d\n" , top(&p));
    return 0;
}
