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
    strcpy(novo->link, link);

    novo->prox = p->topo;
    p->topo = novo;
}
char* pilha_pop(Pilha* p){
    if(pilha_vazia(p)) return NULL;
    
    Lista* i = p->topo;
    char* pop = i->link;    

    p->topo = i->prox;
    free(i);
    
    return pop;
}
char* pilha_topo(Pilha* p);
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
int pilha_conta_links(Pilha* p, char* link);
// Filtra todos os links de um determinado domínio
Pilha* pilha_filtra_dominio(Pilha* p, char* dominio){
    if(pilha_vazia(p)) return NULL;
    
    Lista* i = p->topo;
    Pilha* filtrados = pilha_cria();

    while(i != NULL){
        if(strstr(i->link, dominio) != NULL)
            pilha_push(filtrados, i->link);
        i = i->prox;
    }
        if(pilha_vazia(filtrados)){
            pilha_libera(filtrados);
            return NULL;
        }
        
    return filtrados;
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