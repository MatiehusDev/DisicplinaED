#include <stdio.h>
#include <stdlib.h>
#include "TAD_LISTA.h"

Lista* lst_cria(){
    return NULL;
}

Lista* lst_insere(Lista* l, int info){
    Lista* novo = (Lista*)malloc(sizeof(Lista)); // Aloca nova lista.
    if(!novo) exit(1);

    novo->info = info; // novo->info recebe info.
    novo->prox = l; //novo->prox recebe

    return novo;
}

void lst_imprime(Lista* l){
    Lista* p = l;
    while(p != NULL){
        printf("Info = %d\n", p->info);
        p = p->prox;
    }
}

Lista* lst_busca(Lista* l, int v){
    Lista* p = l;
    while(p != NULL && p->info != v){
        p = p->prox;
    }

    return p; // Se encontrar, retorna o valor, se não, retorna NULL.
}

int lst_vazia(Lista* l){
    return l == NULL;    
}

void lst_libera(Lista* l){
    Lista* p = l;
    while(p != NULL){
        Lista* t = p->prox; // t guarda referência para próximo valor de p.
        free(p); // Libera o elemento atual.
        p = t; // p recebe o próximo elemento que agora é o atual.
    }
}

Lista* lst_insere_fim(Lista* l, int v){
    Lista* aux = (Lista*)malloc(sizeof(Lista));
    if(!aux) exit(1);

    aux->info = v;
    aux->prox = NULL;
    
    if(l == NULL) return aux;

    Lista* p = l;
    while(p->prox != NULL)
        p = p->prox;

    p->prox = aux;
    return l;
}

int lst_tamanho(Lista* l){
    int tam = 0;

    while(l != NULL){
        tam++;
        l = l->prox;
    }

    return tam;
}

Lista* lst_insere_ordenado(Lista* l, int v){
    Lista* novo;
    Lista* ant = NULL;
    Lista* p = l;

    while(p != NULL && p->info < v){
        ant = p;
        p = p->prox;
    }

    novo = (Lista*)malloc(sizeof(Lista));
    if(!novo) exit(1);
    novo->info = v;

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
    else{
        ant->prox = p->prox;
    
    free(p);
    return l;
}

int lst_maior(Lista* l){
    int maior = l->info;
    Lista* p = l->prox;

    while(p != NULL){
        if(maior < p->info)
            maior = p->info
        p = p->prox;
    }
    return maior;
}

Lista* lst_inverte(Lista* l){
    Lista* novo = NULL;
    Lista* p = l;

    while(p != NULL){
        Lista* aux = (Lista*)malloc(sizeof(Lista));
        aux->info = p->info;
        aux->prox = novo;
        novo = aux;
        p = p->prox;
    }
    return nova;
}