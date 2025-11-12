#ifndef __TAD_ALUNOS_JIFS__
    #define __TAD_ALUNOS_JIFS__

    typedef struct alunos{
        char nome[81];
        char telefone[12];
        char modalidade[20];
    } Alunos;

    typedef struct lista{
        Alunos info;
        struct lista* prox;
    } Lista;
    
    Lista* lst_cria();

    Lista* lst_insere(Lista* l, char nome[], char telefone[], char modalidade[]);
    Lista* lst_insere_final(Lista *l, char nome[], char telefone[], char modalidade[]);
    Lista* lst_insere_ordenado(Lista *l, char nome[], char telefone[], char modalidade[]);

    Lista* lst_buscar_aluno(Lista* l, char nome[]);

    Lista* lst_remove(Lista* l, char nome[]);
    Lista* lst_remove_inicio(Lista *l);
    Lista* lst_remove_final(Lista *l);

    void lst_imprime(Lista *l);
    void lst_imprime_por_modalidade(Lista *l, char modalidade[]);
    void lst_imprime_aluno(Alunos *aluno);

    int lst_atualiza_aluno(Lista *l, char nome_antigo[], char novo_nome[], char novo_telefone[], char nova_modalidade[]);
    
    #include "TAD_ALUNOS_JIFS.c"
#endif