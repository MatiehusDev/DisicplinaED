#include <stdio.h>
#include <stdlib.h>
#include "TAD_PONTO.h"

Ponto* pto_cria(float x, float y){
    Ponto* novo = (Ponto*)malloc(sizeof(Ponto));
    if(!novo) exit(1);

    novo->x = x;
    novo->y = y;

    return novo;
}

void pto_libera(Ponto* p){
    printf("Liberando memoria...\n");
    free(p);
}

void pto_acessa(Ponto* p, float* x, float* y){
    *x = p->x;
    *y = p->y;
}

void pto_atribui(Ponto* p, float x, float y){
    p->x = x;
    p->y = y;
}

float pto_distancia(Ponto* p1, Ponto* p2){
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}