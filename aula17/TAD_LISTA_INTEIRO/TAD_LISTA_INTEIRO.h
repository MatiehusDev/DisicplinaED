#ifndef __TAD_LISTA_INTEIROS_H__
    #define __TAD_LISTA_INTEIROS_H__
    
    typedef struct lista{
        int info;
        struct lista* prox;
    }Lista;

    Lista* lst_cria();
    Lista* lst_insere(Lista* l, int info);
    void lst_imprime(Lista* l);
    Lista* lst_busca(Lista* l, int v);
    int lst_vazia(Lista* l);
    void lst_libera(Lista* l);
    Lista* lst_retira(Lista* l, int v);
    Lista* lst_insere_ordenado(Lista* l, int v);
    int lst_igual(Lista* l1, Lista* l2);
 
    #include "TAD_LISTA_INTEIRO.c"
#endif