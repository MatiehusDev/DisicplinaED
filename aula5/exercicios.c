#include <stdio.h>

//Macros
#define MAX(a, b) (((a) >  (b)) ? (a) : (b))
#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define QUADRADO(a) (a*a)
#define CUBO(a) (a*a*a)
//Globais
int ContaUmQuandoChama = 0;

void teste();
void imprime();
int fat_recursivo(int n);
int soma_recursivo(int n);

int main(){
    teste();
    teste();
    teste();
    teste();
    teste();
    teste();
    imprime();
    imprime();
    imprime();
    imprime();
    int r = fat_recursivo(10);
    printf("Fatorial recursivo: %d\n", r);
    printf("Maior: %d\n", MAX(9, 8));
    printf("Menor: %d\n", MIN(8, 7));
    printf("Quadrado: %d\n", QUADRADO(3));
    printf("Quadrado: %d\n", QUADRADO(4));
    printf("Quadrado: %d\n", QUADRADO(5));
    printf("Cubo: %d\n", CUBO(2));
    printf("Cubo: %d\n", CUBO(3));
    printf("Cubo: %d\n", CUBO(4));
    int r1 = soma_recursivo(5);
    printf("Soma recursiva: %d\n", r1);

    return 0;
}

void teste(){
    ContaUmQuandoChama++;
    printf("Chamada: %d\n", ContaUmQuandoChama);
}

void imprime(){
    static int a = 1;
    printf("Chamada (%d) vezes!\n", a);
    a++;
}

int fat_recursivo(int n){
    if(n == 0)
        return 1;
    else
        return n * fat_recursivo(n-1);
}

int soma_recursivo(int n){
    if(n == 1)
        return 1;
    else
        return n + soma_recursivo(n - 1);
}