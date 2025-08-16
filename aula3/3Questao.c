#include <stdio.h>

int main(){
    int num;

    do{
        printf("Digite um numero inteiro positivo par:\n");
        scanf("%d", &num);

    }while(num % 2 != 0);

    return 0;
}