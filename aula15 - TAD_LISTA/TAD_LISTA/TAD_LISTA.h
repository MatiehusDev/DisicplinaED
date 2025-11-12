#ifndef __TAD_LISTA__
    #define __TAD_LISTA__
    
    typedef struct lista{
        int info;
        struct lista* prox;
    } Lista;

    Lista* lst_cria();
    Lista* lst_insere(Lista* l, int info);
    void lst_imprime(Lista* l);
    Lista* lst_busca(Lista* l, int v);
    int lst_vazia(Lista* l);
    void lst_libera(Lista* l);
    Lista* lst_insere_fim(Lista* l, int v);
    int lst_tamanho(Lista* l);
    Lista* lst_insere_ordenado(Lista* l, int v);
    Lista* lst_retira(Lista* l, int v);
    int lst_maior(Lista* l);
    Lista* lst_inverte(Lista* l);
    
    #include "TAD_LISTA.c"
#endif