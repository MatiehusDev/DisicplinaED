#ifndef __TAD_LISTA_CONTATOS_H__
    #define __TAD_LISTA_CONTATOS_H__

    typedef struct contatos{
        char nome[81];
        char tel[12];
    } Contatos;
    
    typedef struct lista{
        Contatos info;
        struct lista* prox;
    } Lista;

    Lista* lst_cria();
    Lista* lst_insere(Lista* l, char* nome, char* tel);
    void lst_imprime(Lista* l);
    Lista* lst_busca(Lista* l, char* nome);
    int lst_vazia(Lista* l);
    void lst_libera(Lista* l);
    Lista* lst_retira(Lista* l, char* nome);
    Lista* lst_insere_ordenado(Lista* l, char* nome, char* tel);
    int lst_igual(Lista* l1, Lista* l2);
 
    #include "TAD_LISTA_CONTATOS.c"
#endif