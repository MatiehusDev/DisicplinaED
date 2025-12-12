#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int info;
    struct no* sae;
    struct no* sad;
} No;

No* arv_cria_vazia();
No* arv_cria(int info, No* sae, No* sad);
void arv_imprime(No* arvore);
No* arv_deleta(No* arvore);
int arv_conta_nos(No* arvore);
int arv_conta_folhas(No* arvore);
int arv_altura(No* arvore);
int arv_busca(No* arvore, int valor);
void arv_imprime_pre(No* arvore);
void arv_imprime_pos(No* arvore);
int arv_soma(No* arvore);
int arv_e_cheia(No* arvore);
No* arv_clona(No* arvore);
int arv_min(No* arvore);

int conta_maiores(No* arvore, int x);
int todos_pares(No* arvore);
int produto_valores(No* arvore);

int conta_negativos(No* arvore);
int eh_bst(No* arvore);

int main(){
    
    return 0;
}

No* arv_cria_vazia(){
    return NULL;
}

No* arv_cria(int info, No* sae, No* sad){
    No* novo = (No*)malloc(sizeof(No));
    if(!novo) exit(1);

    novo->info = info;
    novo->sae = sae;
    novo->sad = sad;

    return novo;
}

void arv_imprime(No* arvore){
    if(arvore != NULL){
        arv_imprime(arvore->sae);
        printf("%d\n", arvore->info);
        arv_imprime(arvore->sad);
    }
}

No* arv_deleta(No* arvore){
    if(arvore != NULL){
        arv_deleta(arvore->sae);
        arv_deleta(arvore->sad);
        free(arvore);
    }

    return NULL;
}

int arv_conta_nos(No* arvore){
    if(arvore == NULL)    
        return 0;

    return arv_conta_nos(arvore->sae) + 1 + arv_conta_nos(arvore->sad);
}

int arv_conta_folhas(No* arvore){
    if(arvore == NULL)
        return 0;

    if(arvore->sae == NULL || arvore->sad == NULL)
        return 1;

    return arv_conta_folhas(arvore->sae) + arv_conta_folhas(arvore->sad);
}

int arv_altura(No* arvore){
    if(arvore == NULL)
        return -1;

    int arv_esquerda = arv_altura(arvore->sae);
    int arv_direita = arv_altura(arvore->sad);

    if(arv_esquerda > arv_direita)
        return arv_esquerda + 1;
    else
        return arv_direita + 1;
}

int arv_busca(No* arvore, int valor){
    if(arvore == NULL)
        return 0;

    if(arvore->info == valor)
        return 1;

    if(arv_busca(arvore->sae, valor))
        return 1;

    return arv_busca(arvore->sad, valor);
}

void arv_imprime_pre(No* arvore){
    if(arvore != NULL){
        printf("%d\n", arvore->info);
        arv_imprime_pre(arvore->sae);
        arv_imprime_pre(arvore->sad);
    }
}

void arv_imprime_pos(No* arvore){
    if(arvore != NULL){
        arv_imprime_pre(arvore->sae);
        arv_imprime_pre(arvore->sad);
        printf("%d\n", arvore->info);
    }
}

int arv_soma(No* arvore){
    if(arvore == NULL)
        return 0;
    
    return arv_soma(arvore->sae) + arvore->info + arv_soma(arvore->sad);
}

int arv_e_cheia(No* arvore){
    if(arvore == NULL)
        return 1;

    if((arvore->sae == NULL && arvore->sad != NULL) || (arvore->sae != NULL && arvore->sad == NULL))
        return 0;

    return arv_e_cheia(arvore->sae) && arv_e_cheia(arvore->sad);
}

No* arv_clona(No* arvore){
    if(arvore == NULL)
        return NULL;
    No* clona_sae = arv_clona(arvore->sae);
    No* clona_sad = arv_clona(arvore->sad);
    
    return arv_cria(arvore->info, clona_sae, clona_sad);
}

int arv_min(No* arvore){
    if(arvore == NULL){
        printf("Arvore vazia...\n");
        exit(1);
    }
    
    int min = arvore->info; // Assume que a raiz é o menor valor
    
    if(arvore->sae != NULL){ // Enquanto sae não for NULL
        int minEsquerda = arv_min(arvore->sae); // minEsquerda recebe info da esquerda
        if(minEsquerda < min) // Compara se minEsquerda é menor que a raiz
            min = minEsquerda; // Se sim, troca
    }

    if(arvore->sad != NULL){ // Enquanto sad não for NULL
        int minDireita = arv_min(arvore->sad); // minDireita recebe info da direita
        if(minDireita < min) // Compara se minDireita é menor que min
            min = minDireita; // Se sim, troca
    }

    return min; // Retorna menor valor
}

int conta_maiores(No* arvore, int x){
    if(arvore == NULL)
        return 0;

    if(arvore->info > x)
        return 1;

    return conta_maiores(arvore->sae, x) + conta_maiores(arvore->sad, x);
}

// Verifica se todos os nós são pares
// Retorna 1 se sim, 0 se não
int todos_pares(No* arvore){
    if(arvore == NULL) return 1;

    if(arvore->info % 2 != 0) 
        return 0;

    return todos_pares(arvore->sae) && todos_pares(arvore->sad);
}

// Calcula o produto de todos os nós
int produto_valores(No* arvore){
    if(arvore == NULL) return 1;

    return arvore->info * produto_valores(arvore->sae) * produto_valores(arvore->sad);
}

int conta_negativos(No* arvore){
    if(arvore == NULL) return 0;

    return (arvore->info < 0) + conta_negativos(arvore->sae) + conta_negativos(arvore->sad);
}

// Verifica se todos da esquerda são menores
// do que a raiz e se da direita são maiores
int todos_menores(No* arvore, int limite){
    if(arvore == NULL) return 1;

    return arvore->info < limite && todos_menores(arvore->sae, limite) && todos_menores(arvore->sad, limite);
}

int todos_maiores(No* arvore, int limite){
    if(arvore == NULL) return 1;

    return arvore->info > limite && todos_maiores(arvore->sae, limite) && todos_maiores(arvore->sad, limite);
}

int eh_bst(No* arvore){
    if(arvore == NULL) return 1;

    return todos_menores(arvore->sae, arvore->info) && todos_maiores(arvore->sad, arvore->info) && eh_bst(arvore->sae) && eh_bst(arvore->sad);
}           