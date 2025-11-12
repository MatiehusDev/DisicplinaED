#include "TAD_FILA_BANCO/TAD_FILA_BANCO.h"

int main(){
    Fila* fila_banco = fila_cria(); // Cria uma fila vazia
    
    // Enfileira pessoas na fila e imprime
    fila_enqueue(fila_banco, 1, "Matheus Lima Costa");
    fila_enqueue(fila_banco, 2, "Pedro Lucas Lima Costa");
    fila_enqueue(fila_banco, 4, "Jose Airton da Costa");
    fila_enqueue(fila_banco, 3, "Antonielle Lima Braga");
    fila_enqueue(fila_banco, 3, "Maria de Lourdes Lima Braga");
    fila_imprime(fila_banco);
    printf("Quantidade de pessoas coma prioridade [%d]: %d\n", 3, fila_contar_prioridade(fila_banco, 3));

    // Desenfileira a pessoa de maior prioridade primeiro
    fila_dequeue(fila_banco);
    printf("\n");
    fila_imprime(fila_banco);

    // Desenfileira a pessoa de maior prioridade primeiro, como tem
    // duas pessoas de prioridade iguais, desenfileira o que chegou primeiro
    fila_dequeue(fila_banco);
    printf("\n");
    fila_imprime(fila_banco);

    printf("\n");
    printf("Tamanho da fila %d\n", fila_tamanho(fila_banco));
    fila_free(fila_banco);
    return 0;
}