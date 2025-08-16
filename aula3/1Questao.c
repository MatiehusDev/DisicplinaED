#include <stdio.h>

int main(){
    int a = 2;
    int b = 3;
    int c = 4;

    printf("%s\n", ((a < b && b < c) || (c < b && b < a )) ? "Sim" : "Nao");

    return 0;
}