#include <stdio.h>
#define PI 3.14159

float converte_celsius_fahrenheit(float n);
int dobro_numero(int n);
int maior_entre_dois(int n, int m);
long long numero_fatorial(int n);
float area_circulo(float r);
void troca_valores(int m, int n);
int conta_digitos(int n);
int eh_primo(int n);
int potenciacao(int b, int e);
float velocidade_media(float k, float h);

int main(){

    //Testa função de converter celsius em fahrenheit
    float c = converte_celsius_fahrenheit(32.3);
    printf("Graus celsius convertido em fahrenhei: %f\n", c);

    //Testa função que dobra valor
    int d = dobro_numero(34);
    printf("Valor dobrado: %d\n", d);

    //Testa função que retorno o maior valor entre dois elementos
    int m = maior_entre_dois(37, 34);
    printf("Maior: %d\n", m);

    //Testa função que fatora um número
    long long f = numero_fatorial(10);
    printf("Numero fatorado: %lld\n", f);

    //Testa função que calcula área de um círculo
    float a = area_circulo(3.4);
    printf("Area do circulo: %f\n", a);

    //Testa função que prova que a troca dos valores entre dois elementos sem ponteiro não altera os valores originais
    int num1 = 5, num2 = 7;
    troca_valores(num1, num2);
    printf("Valores originais: %d - %d\n", num1, num2);

    //Testa função que conta quantos digitos um valor tem
    int cd = conta_digitos(123456789);
    printf("O valor tem (%d) digitos!\n", cd);

    //Testa função que diz se valor é primo ou não
    int valor = 8;
    int p = eh_primo(valor);
    if(p == 1) printf("Valor (%d) e primo!\n", valor);
    else printf("Valor (%d) nao e primo!\n", valor);

    //Testa função que faz potencialização (recebe base e expoente)
    int po = potenciacao(2, 10);
    printf("Resultado da potenciacao: %d\n", po);

    //Testa função que calcula velocida media
    float tempo = velocidade_media(6.3, 0.5);
    printf("Velocidade media: %.2f\n", tempo);

    return 0;
}

float converte_celsius_fahrenheit(float n){
    return n*1.8+32;
}

int dobro_numero(int n){
    return n*2;
}

int maior_entre_dois(int n, int m){
    return n > m ? n : m;
}

long long numero_fatorial(int n){
    long long a = 1;

    for(int i = 1; i <= n; i++)
        a *= i;
    return a;
}

float area_circulo(float r){
    return PI*r*r;
}

void troca_valores(int m, int n){
    int temp = m;
    m = n;
    n = temp;

    printf("Valores trocados: %d - %d\n", m, n);
}

int conta_digitos(int n){
    if(n < 10)
        return 1;
    if(n < 0)
        n = -n;
    
    int cont = 0;
    while(n > 0){
        n /= 10;
        cont++;
    }
    return cont;
}

int eh_primo(int n){
    for(int i = 2; i <= n/2; i++)
        if(n % i == 0)
            return 0;
    return 1;
}

int potenciacao(int b, int e){
    int resultado = 1;
    for(int i = 0; i < e; i++)
        resultado *= b;
    return resultado;
}

float velocidade_media(float k, float h){
    float vMedia = k/h;
    return vMedia;
}