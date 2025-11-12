#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    printf("Digite a quantidade de elementos:\n");
    scanf("%d", &n);

    int* elementos = (int*)malloc(n * sizeof(int));
    if(!elementos){
        printf("Memoria insuficiente...\n");
        exit(1);
    }

    for(int i = 0; i < n; i++){
        printf("Digite o (%d) elemento:\n", i+1);
        scanf("%d", &elementos[i]);
    }

    int maior = 0;
    for(int i = 0; i < n; i++)
        if(maior < elementos[i])
            maior = elementos[i];
    printf("Maior elemento: %d\n", maior);   

    int menor = 0;
    for(int i = 0; i < n; i++)
        if(menor > elementos[i])
            menor = elementos[i];
    printf("Maior elemento: %d\n", menor);

    return 0;
}