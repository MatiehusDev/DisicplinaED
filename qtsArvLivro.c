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
No* arv_insere(No* arvore, int info);

int pares(No* arvore);
int folhas(No* arvore);
int um_filho(No* arvore);
No* igual(No* arv1, No* arv2);
No* copia(No* arvore);

int altura(No* arvore);
int quantidade(No* arvore);
int cheia(No* arvore);
No* busca(No* arvore, int valor);
int iguais_estrutura(No* a, No* b);
int soma_nivel(No* arvore, int nivel);
int eh_BST(No* arvore);

int maiores_que(No* arvore, int x);
int maior_valor(No* arvore);
int menor_valor(No* arvore);
int impares(No* arvore);
int estritamente_binaria(No* arvore);
int soma_todos(No* arvore);
int nos_acima_nivel(No* arvore, int nivel);
int nos_completos(No* arvore);
int existe(No* arvore, int x);

int main(){
    No* minha_arvore = arv_cria(4, arv_cria_vazia(), arv_cria_vazia()); // Criei a árvore vazia

    minha_arvore = arv_insere(minha_arvore, 2);
    minha_arvore = arv_insere(minha_arvore, 6);
    minha_arvore = arv_insere(minha_arvore, 3);
    minha_arvore = arv_insere(minha_arvore, 1);
    minha_arvore = arv_insere(minha_arvore, 5);
    minha_arvore = arv_insere(minha_arvore, 7);

    arv_imprime(minha_arvore);
    printf("\nQuantidade de pares: %d\n", pares(minha_arvore));
    printf("\nQuantidade de folhas: %d\n", folhas(minha_arvore));
    printf("\nQuantos nos tem somente um filho: %d\n", um_filho(minha_arvore));
    printf("\nAltura da arvore: %d\n", altura(minha_arvore));
    printf("\nQuantida de nos: %d\n", quantidade(minha_arvore));
    printf("\nEh cheia? %d\n", cheia(minha_arvore));
    printf("\nSoma de nivel 2: %d\n", soma_nivel(minha_arvore, 2));

    No* copiado = copia(minha_arvore);
    arv_imprime (copiado);

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
No* arv_insere(No* arvore, int info){
    if(arvore == NULL)
        return arvore = arv_cria(info, arv_cria_vazia(), arv_cria_vazia());

    if(info < arvore->info)
        arvore->sae = arv_insere(arvore->sae, info);
    else
        arvore->sad = arv_insere(arvore->sad, info);

    return arvore;
}

int pares(No* arvore){
    if(arvore == NULL) return 0;

    int cont = 0;
    if(arvore->info % 2 == 0)
        cont = 1;

    return cont + pares(arvore->sae) + pares(arvore->sad);
}

int folhas(No* arvore){
    if(arvore == NULL) return 0;

    int cont = 0;
    if(arvore->sae == NULL && arvore->sad == NULL)
        cont = 1;

    return cont + folhas(arvore->sae) + folhas(arvore->sad);
}

int um_filho(No* arvore){
    if(arvore == NULL) return 0;

    int cont = 0;
    if((arvore->sae == NULL && arvore->sad != NULL) || (arvore->sae != NULL && arvore->sad == NULL))
        cont = 1;
    
    return cont + um_filho(arvore->sae) + um_filho(arvore->sad);
}

No* igual(No* arv1, No* arv2){
    if(arv1 == NULL && arv2 == NULL) return arv1;

    if(arv1 == NULL || arv2 == NULL) return NULL;

    if(arv1->info != arv2->info) return NULL;

    No* esq = igual(arv1->sae, arv2->sae);
    if(esq == NULL) return NULL;

    No* dir = igual(arv1->sad, arv2->sad);
    if(dir == NULL) return NULL;

    return arv1;
}

No* copia(No* arvore){
    if(arvore == NULL) return NULL;

    No* copiaEsq = copia(arvore->sae);
    No* copiaDir = copia(arvore->sad);

    return arv_cria(arvore->info, copiaEsq, copiaDir);
}

int altura(No* arvore){
    if(arvore == NULL) return -1;

    int esquerda = altura(arvore->sae); 
    int direita = altura(arvore->sad);

    if(esquerda > direita)
        return esquerda + 1;
    else
        return direita +1;
}

int quantidade(No* arvore){
    if(arvore == NULL) return 0;

    return 1 + quantidade(arvore->sae) + quantidade(arvore->sad);
}

int cheia(No* arvore){
    if(arvore == NULL) return 1;

    if((arvore->sae == NULL && arvore->sad != NULL) || (arvore->sae != NULL && arvore->sad == NULL))
        return 0;

    return cheia(arvore->sae) && cheia(arvore->sad);
}

No* busca(No* arvore, int valor){
    if(arvore == NULL) return NULL;

    if(arvore->info == valor)
        return arvore;

    if(valor < arvore->info)
        return busca(arvore->sae, valor);
    else
        return busca(arvore->sad, valor);
}

int iguais_estrutura(No* a, No* b){
    if(a == NULL && b == NULL) return 1;

    if(a == NULL || b == NULL)
        return 0;

    return iguais_estrutura(a->sae, b->sae) && iguais_estrutura(a->sad, b->sad);
}

int soma_nivel(No* arvore, int nivel){
    if(arvore == NULL) return 0;

    if(nivel == 0)
        return arvore->info;

    return soma_nivel(arvore->sae, nivel-1) + soma_nivel(arvore->sad, nivel-1);
}

int eh_BST_aux(No* arvore, int min, int max){
    if(arvore == NULL) return 1;

    if(arvore->info <= min || arvore->info >= max)
        return 0;

    return eh_BST_aux(arvore->sae, min, arv->info) && eh_BST_aux(arvore->sad, arvore->info, max); 
}

int eh_BST(No* arvore){
    return eh_BST_aux(arvore, -999999, 999999);
}

int maiores_que(No* arvore, int x){
    if(arvore == NULL) return 0;

    return (arvore->info > x) + maiores_que(arvore->sae, x) + maiores_que(arvore->sad, x);
}

int maior_valor(No* arvore){
    if(arvore == NULL) exit(1);

    int maior = arvore->info;
    if(arvore->sae != NULL){
        int maiorEsq = maior_valor(arvore->sae);
        if(maiorEsq > maior)
            maior = maiorEsq;
    }

    if(arvore->sad != NULL){
        int maiorDir = maior_valor(arvore->sad);
        if(maiorDir > maior)
            maior = maiorDir;
    }

    return maior;
}

int menor_valor(No* arvore){
    if(arvore == NULL) exit(1);

    int menor = arvore->info;

    if(arvore->sae != NULL){
        int menorEsq = menor_valor(arvore->sae);
        if(menorEsq < menor)
            menor = menorEsq;
    }

    if(arvore->sad != NULL){
        int menorDir = menor_valor(arvore->sad);
        if(menorDir < menor)
            menor = menorDir;
    }

    return menor;
}

int impares(No* arvore){
    if(arvore == NULL) return 0;

    return (arvore->info % 2 != 0) + impares(arvore->sae) + impares(arvore->sad);    
}

int estritamente_binaria(No* arvore){
    if(arvore == NULL) return 1;

    if((arvore->sae == NULL && arvore->sad != NULL) || (arvore->sae != NULL && arvore->sad == NULL))
        return 0;

    return estritamente_binaria(arvore->sae) && estritamente_binaria(arvore->sad);
}

int soma_todos(No* arvore){
    if(arvore == NULL) return 0;

    return arvore->info + soma_todos(arvore->sae) + soma_todos(arvore->sad);
}

int nos_acima_nivel(No* arvore, int nivel){
    if(arvore == NULL) return 0;

    if(nivel == 0) return 0;

    return 1 + nos_acima_nivel(arvore->sae, nivel-1) + nos_acima_nivel(arvore->sad, nivel-1);
}

int nos_completos(No* arvore){
    if(arvore == NULL) return 0;

    int cont = 0;
    if(arvore->sae != NULL && arvore->sad != NULL)
        cont = 1;

    return cont + nos_completos(arvore->sae) + nos_completos(arvore->sad);
}

int existe(No* arvore, int x){
    if(arvore == NULL) return 0;
    
    if(arvore->info == x)
        return 1;
    
    return existe(arvore->sae, x) && existe(arvore->sad, x);
}