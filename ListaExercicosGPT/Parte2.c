#include <stdio.h>
#include <stdlib.h>

int* vetOrigal_vetPar(int n);
int soma_intervalo(int* v, int n, int inicio, int fim);

int main(){
    
    return 0;
}

// Ler n números inteiros e armazena em um vetor dinâmico e em outro vetor, apenas os numeros pares.
int* vetOrigal_vetPar(int n, int* qtdPar){
    int* vetOriginal = (int*)malloc(n * sizeof(int));
    if(!vetOriginal) exit(1);

    printf("## Digite os numeros ##\n");
    for(int i = 0; i < n; i++)          // Armazena os números no vetor.
        scanf(" %d", &vetOriginal[i]);

    *qtdPar = 0;
    for(int i = 0; i < n; i++)
        if(vetOriginal[i] % 2 == 0)
            (*qtdPar)++;
    
    int* vetPar = (int*)malloc(*qtdPar * sizeof(int));
    if(!vetPar) exit(1);

    int j = 0;
    for(int i = 0; i < n; i++)
        if(vetOriginal[i] % 2 == 0){
            vetPar[j] = vetOriginal[i];
            j++;
        }
}

// Soma o intervalo dos elementos entre A e B.
int soma_intervalo(int* v, int n, int inicio, int fim){
    int contador = 0;
    for(int i = 0; i < n; i++)
        if(v[i] >= inicio && fim >= v[i])
            contador++;
    return contador;
}