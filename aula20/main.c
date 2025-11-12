#include <stdio.h>
#include "TAD_PILHA_LINKS/TAD_PILHA_LINKS.h"

int main(){
    Pilha* p = pilha_cria();

    // Da push com três links e imprime
    pilha_push(p, "google.com.br"); 
    pilha_push(p, "youtube.com.br");
    pilha_push(p, "github.com");
    pilha_imprime(p);

    // Mostra qual o topo da pilha (último push dado)
    printf("\n");
    printf("Topo da pilha: %s\n", pilha_topo(p));

    // Da pop na pilha e imprime novamente
    pilha_pop(p);
    printf("\n");
    pilha_imprime(p);
    
    // Libera pilha
    pilha_libera(p);

    return 0;
}