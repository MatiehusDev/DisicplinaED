#include <stdio.h>

int main(){
    int quantidade;

    do{
    printf("Informe a quantidade:\n");
    scanf("%d", &quantidade);
    }while(quantidade < 0);

    int cont = 0;
    for(int i = 1; i < quantidade; i++)
        if(i % 3 == 0)
            cont++;
    
    printf("Quantidade de numeros inteiros positivos e multiplos de tres: %d", cont);

    return 0;   
}