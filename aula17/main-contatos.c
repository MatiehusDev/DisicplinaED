#include <stdio.h>
#include "TAD_LISTA_CONTATOS/TAD_LISTA_CONTATOS.h"

int main(){
    Lista* contatos = lst_cria();
    contatos = lst_insere(contatos, "Matheus Lima", "88982170091");
    contatos = lst_insere(contatos, "Pedro Lucas", "88981536271");
    contatos = lst_insere(contatos, "Jose Airton", "88962781388");
    contatos = lst_insere(contatos, "Tielle Braga", "88998634553");
    
    lst_imprime(contatos);

    return 0;
}