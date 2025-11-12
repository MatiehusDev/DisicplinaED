#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_FILA_BANCO.h"

int fila_vazia(Fila* f){
    return f->ini == NULL || f->fim == NULL;
}

Fila* fila_cria(){
    Fila* f = (Fila*)malloc(sizeof(Fila));
    f->ini = f->fim = NULL;
    return f;
}

void fila_enqueue(Fila* f, int prioridade, char* nome){
    Lista* enqueue = (Lista*)malloc(sizeof(Lista));
    enqueue->prio = prioridade;
    strcpy(enqueue->nome, nome);
    enqueue->prox = NULL;

    if(fila_vazia(f))
        f->fim = f->ini = enqueue;
    else{
        f->fim->prox = enqueue;
        f->fim = enqueue;
    }
}

Lista* fila_dequeue(Fila* f){
    Lista* p = f->ini;
    Lista* maior_prioridade = p;

    while(p != NULL){
        if(p->prio > maior_prioridade->prio)
            maior_prioridade = p;
        p = p->prox;
    }

    p = f->ini;
    Lista* ant = NULL;

    if(maior_prioridade == f->ini)
        f->ini = p->prox;
    else{
        while(p != maior_prioridade){
            ant = p;
            p = p->prox;
        }
        ant->prox = p->prox;
    }
    return maior_prioridade;
}

void fila_free(Fila* f){
    printf("\nLiberando fila...\n");
    Lista* p = f->ini;
    while(p != NULL){
        Lista* temp = p;
        p = p->prox;
        free(temp);
    }
    free(f);
}

void fila_imprime(Fila* f){
    Lista* p = f->ini;
    while(p != NULL){
        printf("Nome: %s\n", p->nome);
        printf("Prioridade: %d\n", p->prio);
        p = p->prox;
    }
}

int fila_tamanho(Fila* f){
    if(fila_vazia(f))
        return 0;

    int tam = 0;
    for(Lista* p = f->ini; p != NULL; p = p->prox)
        tam++;

    return tam;
}

int fila_contar_prioridade(Fila* f, int prioridade){
    if(fila_vazia(f))
        return 0;
    
    int qtd_prio = 0;
    for(Lista* p = f->ini; p != NULL; p = p->prox)
        if(p->prio == prioridade)
            qtd_prio++;

    return qtd_prio;
}

Lista* fila_remover_por_nome(Fila* f, char* nome){
    if(fila_vazia(f)) return NULL;
    
    Lista* p = f->ini;
    Lista* ant = NULL;

    while(p != NULL && strcmp(p->nome, nome) != 0){
        ant = p;
        p = p->prox;
    }

    if(p == NULL) return NULL;

    Lista* removido = p;
    if(ant == NULL)
        f->ini = removido->prox;
    else    
        ant->prox = removido->prox;

    if(removido == f->fim)
        f->fim = ant;

    removido->prox = NULL;
    return removido;
}

void fila_enqueue_ordenado(Fila* f, int prioridade, char* nome){
    Lista* enqueue = (Lista*)malloc(sizeof(Lista));
    enqueue->prio = prioridade;
    strcpy(enqueue->nome, nome);

    Lista* p = f->ini;
    Lista* ant = NULL;
    while(p != NULL && p->prio > prioridade){
        ant = p;
        p = p->prox;
    }    
    
    if(ant == NULL){
        enqueue->prox = f->ini;
        f->ini = enqueue;
    }
    else if(p != NULL){
        enqueue->prox = p;
        ant->prox = enqueue;
    }
    else{
        enqueue->prox = NULL;
        ant->prox = enqueue;
        f->fim = enqueue;
    }
}