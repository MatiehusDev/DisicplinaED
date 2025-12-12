#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "TAD_PILHA_LINKS.h"

Pilha* pilha_cria(void){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}
void pilha_push(Pilha* p, char* link){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->link = (char*)malloc((strlen(link)+1) * sizeof(char));
    strcpy(novo->link, link);

    novo->prox = p->topo;
    p->topo = novo;
}
char* pilha_pop(Pilha* p){
    if(pilha_vazia(p)) return NULL;

    Lista* topoAtual = p->topo;
    char* linkPop = topoAtual->link;

    p->topo = topoAtual->prox;
    free(topoAtual);
    return linkPop;
}
char* pilha_topo(Pilha* p){
    if(pilha_vazia(p))
        return NULL;
    return p->topo->link;
}
int pilha_vazia(Pilha* p){
    return p->topo == NULL;
}
void pilha_libera(Pilha* p){
    Lista* i = p->topo;
    while(i != NULL){
        Lista* temp = i;
        i = i->prox;
        free(temp->link);
        free(temp);
    }
}
void pilha_imprime(Pilha* p);

// Conta ocorrências de um link
int pilha_conta_links(Pilha* p, char* link){
    int qtdLink = 0;
    Lista* i = p->topo;

    while(i != NULL){
        if(strcmp(i->link, link) == 0)
            qtdLink++;
        i = i->prox;
    }
    return qtdLink;
}
// Filtra todos os links de um determinado domínio
Pilha* pilha_filtra_dominio(Pilha* p, char* dominio){
    if(p->topo == NULL || dominio == NULL) return NULL;
    
    Pilha* novo = pilha_cria();
    Lista* i = p->topo;

    while(i != NULL){
        if(strstr(i->link, dominio) != NULL)
            pilha_push(novo, i->link);
        i = i->prox;
    }

    if(pilha_vazia(novo)){
        pilha_libera(novo);
        return NULL;
    }
    
    return novo;
}

// Função: Verifica se um link existe na pilha
int pilha_contem_link(Pilha* p, char* link);
// Função: Inverte a ordem dos elementos na pilha
Pilha* pilha_inverter(Pilha* p);
// Função: Concatena duas pilhas (p2 no topo de p1)
Pilha* pilha_concatenar(Pilha* p1, Pilha* p2);  
// Função: Retorna estatísticas dos links (domínios mais frequentes)
typedef struct {
    char dominio[100];
    int frequencia;
} EstatisticaDominio;
void pilha_estatisticas_dominios(Pilha* p);
// Função: Remove links duplicados mantendo apenas a primeira ocorrência
Pilha* pilha_remover_duplicados(Pilha* p);