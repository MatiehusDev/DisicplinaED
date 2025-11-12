#ifndef __TAD_PILHA_LINKS_H__
    #define __TAD_PILHA_LINKS_H__

    typedef struct lista{
        char* link;
        struct lista* prox;
    } Lista;

    typedef struct pilha{
        Lista* topo;
    } Pilha;

    Pilha* pilha_cria(void);
    void pilha_push(Pilha* p, char* link);
    char* pilha_pop(Pilha* p);
    char* pilha_topo(Pilha* p);
    int pilha_vazia(Pilha* p);
    void pilha_libera(Pilha* p);
    void pilha_imprime(Pilha* p);

    // Conta ocorrências de um link
    int pilha_conta_links(Pilha* p, char* link);
    // Filtra todos os links de um determinado domínio
    Pilha* pilha_filtra_dominio(Pilha* p, char* dominio);

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
    
    #include "TAD_PILHA_LINKS.c"
#endif