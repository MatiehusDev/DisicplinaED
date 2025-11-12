#include "TAD_ALUNOS_JIFS.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Lista* lst_cria(){
    return NULL;
}

Lista* lst_insere(Lista* l, char nome[], char telefone[], char modalidade[]){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if(!novo) exit(1);

    strcpy(novo->info.nome, nome);
    strcpy(novo->info.telefone, telefone);
    strcpy(novo->info.modalidade, modalidade);
    novo->prox = l;

    return novo;
}

Lista* lst_buscar_aluno(Lista* l, char nome[]){
    Lista* p = l;

    while(p != NULL){
        if(strcmp(p->info.nome, nome) != 0)
            return p;
        p = p->prox;
    }

    return NULL;
}

Lista* lst_remove(Lista* l, char nome[]){
    Lista* ant = NULL;
    Lista* p = l;

    while(p != NULL && strcmp(p->info.nome, nome) != 0){
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

Lista* lst_insere_final(Lista *l, char nome[], char telefone[], char modalidade[]){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if(!novo) exit(1);

    strcpy(novo->info.nome, nome);
    strcpy(novo->info.telefone, telefone);
    strcpy(novo->info.modalidade, modalidade);
    novo->prox = NULL;
    
    if(l == NULL)
        return novo;
    
    Lista* p = l;
    while(p->prox != NULL)
        p = p->prox;

    p->prox = novo;
    return l;
}

Lista* lst_insere_ordenado(Lista *l, char nome[], char telefone[], char modalidade[]){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    if(!novo) exit(1);

    strcpy(novo->info.nome, nome);
    strcpy(novo->info.telefone, telefone);
    strcpy(novo->info.modalidade, modalidade);

    if(l == NULL){
        novo->prox = NULL;
        return novo;
    }
    
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

Lista* lst_buscar_aluno(Lista* l, char nome[]){
    Lista* p = l;
    while(p != NULL){
        if(strcmp(p->info.nome, nome) == 0)
            return p;
        p = p->prox;
    }
    return p;
}

Lista* lst_remove_inicio(Lista *l){
    if(l == NULL)
        return NULL;
    
    Lista* p = l;
    l = p->prox;

    free(p);
    return l;
}

Lista* lst_remove_final(Lista *l){
    if(l == NULL) return NULL;

    if(l->prox == NULL){
        free(l);
        return NULL;
    }
    
    Lista* ant = NULL;
    Lista* p = l;

    while(p->prox != NULL){
        ant = p;
        p = p->prox;
    }
    
    ant->prox = NULL;
    free(p);
    
    return l;
}

void lst_imprime(Lista *l){
    for(Lista* p = l; p != NULL; p = p->prox){
        printf("Aluno = %s\n", p->info.nome);
        printf("Telefone = %s\n", p->info.telefone);
        printf("Modalidade = %s\n", p->info.modalidade);
    }
}

void lst_imprime_por_modalidade(Lista *l, char modalidade[]){
    Lista* p = l;

    while(p != NULL){
        if(strcmp(p->info.modalidade, modalidade) == 0){
            lst_imprime(p);
        }
        p = p->prox;
    }
}