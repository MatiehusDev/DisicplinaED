#include "TAD_LISTA_CONTATOS.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Lista* lst_cria(){
    return NULL;
}

Lista* lst_insere(Lista* l, char* nome, char* tel){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if(!novo) exit(1);

    strcpy(novo->info.nome, nome);
    strcpy(novo->info.tel, tel);

    novo->prox = l;

    return novo;
}


void lst_imprime(Lista* l){
    for(Lista* p = l; p != NULL; p = p->prox){
        printf("Nome = %s\n", p->info.nome);
        printf("Telefone = %s\n", p->info.tel);
        printf(">------------=------------<\n");

    }
}

Lista* lst_busca(Lista* l, char* nome){
    Lista* p = l;
    while(p != NULL){
        if(strcmp(p->info.nome, nome) == 0)
            return p;
    }

    return NULL;
}

int lst_vazia(Lista* l){
    return l == NULL;
}

void lst_libera(Lista* l){
    Lista* p = l;
    while(p != NULL){
        Lista* t = p;
        free(p);
        p = t;
    }
}


Lista* lst_retira(Lista* l, char* nome){
    Lista* ant = NULL;
    Lista* p = l;
    
    while(p != NULL && strcmp(p->info.nome, nome) != 0){
        ant = p;
        p = p->prox;
    }

    if(p == NULL)
        return l;
    if(ant == NULL)
        l = ant->prox;
    else
        ant->prox = p->prox;
    free(p);
    return l;
}


Lista* lst_insere_ordenado(Lista* l, char* nome, char* tel){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if(!novo) exit(1);
    strcpy(novo->info.nome, nome);
    strcpy(novo->info.tel, tel);

    Lista* ant = NULL;
    Lista* p = l;

    while(p != NULL && strcmp(p->info.nome, nome) < 0){
        ant = p;
        p = p->prox;
    }

    if(ant == NULL){
        novo->prox = l;
        l = novo;
    }
    else{
        novo->prox = p;
        ant->prox = novo;
    }
    return l;
}


int lst_igual(Lista* l1, Lista* l2){
    Lista* p1 = l1;
    Lista* p2 = l2;

    while(p1 != NULL && p2 != NULL){
        if(strcmp((p1->info.nome, p2->info.nome) != 0) || (strcmp(p1->info.tel, p2->info.tel) != 0))
            return 0;

        p1 = p1->prox;
        p2 = p2->prox;
    }
    return (p1 == NULL && p2 == NULL);
}