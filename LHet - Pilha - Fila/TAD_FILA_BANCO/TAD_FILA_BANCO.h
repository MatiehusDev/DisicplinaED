#ifndef __TAD_FILA_BANCO_H__
    #define __TAD_FILA_BANCO_H__

    typedef struct lista{
        int prio;
        char nome[51];
        struct lista* prox;
    } Lista;

    typedef struct fila{
        Lista* ini;
        Lista* fim;
    } Fila;

    int fila_vazia(Fila* f);
    Fila* fila_cria();
    void fila_enqueue(Fila* f, int prioridade, char* nome);
    Lista* fila_dequeue(Fila* f);
    void fila_free(Fila* f);
    void fila_imprime(Fila* f);
    int fila_tamanho(Fila* f);
    int fila_contar_prioridade(Fila* f, int prioridade);
    Lista* fila_remover_por_nome(Fila* f, char* nome);
    void fila_enqueue_ordenado(Fila* f, int prioridade, char* nome);

    #include "TAD_FILA_BANCO.c"
#endif