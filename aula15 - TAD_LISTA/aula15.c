#include <stdio.h>
#include "TAD_LISTA/TAD_LISTA.h"

int main(){
    Lista* minha_lista = lst_cria();
    minha_lista = lst_insere(minha_lista, 1);
    minha_lista = lst_insere(minha_lista, 2);
    minha_lista = lst_insere(minha_lista, 3);
    
    printf("Lista inicialmente:\n");
    lst_imprime(minha_lista);
    
    lst_insere_fim(minha_lista, 4);
    lst_insere_fim(minha_lista, 5);
    printf("\nNova lista usando [lst_insere_fim]:\n");
    lst_imprime(minha_lista);

    printf("\nTamanho da sua lista: %d\n", lst_tamanho(minha_lista));

    lst_insere_ordenado(minha_lista, 4);
    printf("\nAdiciona nome elemento na lista de forma ordenada:\n");
    lst_imprime(minha_lista);
    printf("\nTamanho da sua lista atualizada: %d\n", lst_tamanho(minha_lista));

    
    return 0;
}