#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TAD_PILHA_LINKS.h"

Pilha* pilha_cria(void){
    Pilha* p = (Pilha*)malloc(sizeof(Pilha));
    p->topo = NULL;
    return p;
}

void pilha_push(Pilha* p, char* link){
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->link = (char*)malloc((strlen(link) + 1) * sizeof(char));
    strcpy(novo->link, link);

    novo->prox = p->topo;
    p->topo = novo;
}

char* pilha_pop(Pilha* p){
    if(pilha_vazia(p))
        return NULL;
    Lista* topo_atual = p->topo;
    char* link_pop = topo_atual->link;

    p->topo = topo_atual->prox;
    free(topo_atual);

    return link_pop;
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
        Lista* aux = i->prox;
        free(i->link);
        free(i);
        i = aux;
    }
}

void pilha_imprime(Pilha* p){
    if(pilha_vazia(p)){
        printf("Pilha vazia...\n");
        exit(1);
    }

    Lista* i = p->topo;
    while(i != NULL){
        printf("https://%s\n", i->link);
        i = i->prox;    
    }
}

int pilha_conta_links(Pilha* p, char* link){
    if(pilha_vazia(p))
        return 0;
    
    int qtd_ocorrencias = 0;
    Lista* i = p->topo;
    while(i != NULL){
        if(strcmp(i->link, link) == 0)
            qtd_ocorrencias++;
        i = i->prox;
    }
    return qtd_ocorrencias;
}

Pilha* pilha_filtra_dominio(Pilha* p, char* dominio){
    if(p == NULL|| dominio == NULL || pilha_vazia(p)) // Verificação mais robusta
        return NULL;
    
    Lista* i = p->topo; // Recebe o topo da pilha para percorrer
    Pilha* filtrados = pilha_cria(); // Cria uma pilha inicialmente vazia para guardar os links filtrados

    while(i != NULL){
        // Verifica se o nó atual não é vazio e verifica se há substring (domínio) na string atual
        if(i->link == NULL && strstr(i->link, dominio) != NULL)
            pilha_push(filtrados, i->link);
        i = i->prox;
    }

    if(pilha_vazia(filtrados)){ // Verifica se pilha filtrados está vazia (não filtrou nenhum link)
        pilha_libera(filtrados); // Caso não tenha filtrado nenhum link, libera memória da pilha
        return NULL;
    }

    return filtrados;
}

int pilha_contem_link(Pilha* p, char* link){
    if(p == NULL || link == NULL || pilha_vazia(p))
        return NULL;

    Lista* i = p->topo;
    while(i != NULL){
        if(strcmp(i->link, link) == 0)
            return 1;
        i = i->prox;
    }
    return 0;
}

Pilha* pilha_inverter(Pilha* p){
    Pilha* invertida = pilha_cria();
    Lista* i = p->topo;

    while(i != NULL){
        pilha_push(invertida, i->link);
        i = i->prox;
    }
    return invertida;
}

Pilha* pilha_concatenar(Pilha* p1, Pilha* p2){
    if(pilha_vazia(p1))
        return p2;
    
    Pilha* temp = pilha_cria();
    Pilha* concatenado = pilha_cria();

    Lista* i = p2->topo;
    while(i != NULL){
        pilha_push(temp, i->link);
        i = i->prox;
    }
    
    while(i != NULL){
        pilha_push(temp, i->link);
        i = i->prox;
    }

    while(!pilha_vazia(temp)){
        char* link = pilha_pop(temp);
        pilha_push(concatenado, link);
        free(link);
    }

    pilha_libera(temp);
    return concatenado;
}