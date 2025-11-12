#include <stdio.h>
#include <stdlib.h>
#include "TAD_LISTA_INTEIRO.h"

Lista* lst_cria(){
    return NULL;
}

Lista* lst_insere(Lista* l, int info){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if(!novo) exit(1);

    novo->info = info;
    novo->prox = l;

    return novo;
}

void lst_imprime(Lista* l){
    while(l != NULL){
        printf("Info =  %d\n", l->info);
        l = l->prox;
    }
}

Lista* lst_busca(Lista* l, int v){
    Lista* p = l;
    while(p != NULL && p->info != v)
        p = p->prox;
    
    return p;
}

int lst_vazia(Lista* l){
    return l == NULL;
}

void lst_libera(Lista* l){
    Lista* p = l;
    while(p != NULL){
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}

Lista* lst_retira(Lista* l, int v){
    Lista* ant = NULL;
    Lista* p = l;

    while(p != NULL && p->info != v){
        ant = p;
        p = p->prox;
    }

    if(p == NULL)
        return l;
    if(ant == NULL)
        l = p->prox;
    else
        ant->prox = p->prox;

    free(p);
    return l;
}

Lista* lst_insere_ordenado(Lista* l, int v){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if(!novo) exit(1);
    novo->info = v;

    Lista* ant = NULL;
    Lista* p = l;

    while(p != NULL && p->info < v){
        ant = p;
        p = p->prox;
    }

    if(ant == NULL){
        novo->prox = l;
        l = novo;
    }
    else{
        novo->prox = ant->prox;
        ant->prox = novo;
    }

    return l;
}

int lst_igual(Lista* l1, Lista* l2){
    Lista* p1 = l1;
    Lista* p2 = l2;

    while(p1 != NULL && p2 != NULL){
        if(p1->info != p2->info)
            return 0;
        p1 = p1->prox;
        p2 = p2->prox;
    }

    return (p1 == NULL && p2 == NULL);
}