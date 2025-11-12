#include <stdio.h>
#include <stdlib.h>
#include "TAD_FORMAS/TAD_FORMAS.h"

int main() {
    printf("=== TESTE DA LISTA HETEROGENEA ===\n\n");
    
    // Criando lista vazia
    Listahet* lista = lsthet_cria_vazia();
    printf("Lista criada (vazia): %s\n", (lista == NULL) ? "SIM" : "NAO");
    
    // Criando e inserindo formas manualmente
    printf("\n--- Criando formas manualmente ---\n");
    
    // Criando um retângulo
    Listahet* retangulo = cria_ret(5.0, 3.0);
    printf("Retangulo criado: base=%.2f, altura=%.2f\n", 
           ((Retangulo*)retangulo->info)->b, 
           ((Retangulo*)retangulo->info)->h);
    
    // Criando um triângulo  
    Listahet* triangulo = cria_tri(4.0, 6.0);
    printf("Triangulo criado: base=%.2f, altura=%.2f\n",
           ((Triangulo*)triangulo->info)->b,
           ((Triangulo*)triangulo->info)->h);
    
    // Criando um círculo
    Listahet* circulo = cria_cir(2.5);
    printf("Circulo criado: raio=%.2f\n",
           ((Circulo*)circulo->info)->r);
    
    // Montando a lista manualmente
    printf("\n--- Montando a lista ---\n");
    circulo->prox = triangulo;
    triangulo->prox = retangulo;
    lista = circulo;  // lista agora aponta para o círculo
    
    printf("Lista montada com 3 elementos\n");
    
    // Testando a função de impressão (que já usa a função area internamente)
    printf("\n--- Imprimindo todas as formas ---\n");
    lsthet_imprime(lista);
    
    // Testando inserção (comentado pois precisa de input do usuário)
    /*
    printf("\n--- Testando insercao interativa ---\n");
    printf("Inserindo novo retangulo:\n");
    lista = lsthet_insere(lista, RET);
    printf("\nLista apos insercao:\n");
    lsthet_imprime(lista);
    */
    
    printf("\n=== FIM DO TESTE ===\n");
    
    return 0;
}