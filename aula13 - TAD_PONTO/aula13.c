#include "TAD_PONTO/TAD_PONTO.h"

int main(){
    Ponto* p = pto_cria(2, 3);                          // Uso da função pto_cria.
    printf("Ponto original: %.1f, %.1f\n", p->x, p->y);

    float x, y;             // Uso da função pto_acessa, passando
    pto_acessa(p, &x, &y);  // os valores de ponto para as variaveis.

    printf("\nValores copiados do ponto para as variaveis:\n"); // Mostrando o uso da função pto_acessa.
    printf("Valor de x = %.1f\n", x);
    printf("Valor de y = %.1f\n", y);

    pto_atribui(p, 4, 5);                                                   // Usando pto_atribui atribuindo
    printf("\nNovos valores do ponto:\nx = %.1f\ny = %.1f\n", p->x, p->y);  // novos valores para ponto.

    Ponto* q = pto_cria(8, 9); // Criando novo ponto.

    // Usando função pto_distancia para calcular distância entre p e q.
    printf("\nDistancia entre os pontos (%1.f, %1.f) e (%.1f, %.1f): %.1f\n", p->x, p->y, q->x, q->y, pto_distancia(p, q));

    pto_libera(p);
    pto_libera(q);
}