#include <stdio.h>
#include <stdlib.h>
#include "TAD_FORMAS.h"

Listahet* cria_ret(float b, float h){
    Retangulo* r = (Retangulo*)malloc(sizeof(Retangulo));
    r->b = b;
    r->h = h;

    Listahet* novo = (Listahet*)malloc(sizeof(Listahet));
    novo->geometria = RET;
    novo->info = r;
    novo->prox = NULL;

    return novo;
}
Listahet* cria_tri(float b, float h){
    Triangulo* t = (Triangulo*)malloc(sizeof(Triangulo));
    t->b = b;
    t->h = h;

    Listahet* novo = (Listahet*)malloc(sizeof(Listahet));
    novo->geometria = TRI;
    novo->info = t;
    novo->prox = NULL;

    return novo;
}
Listahet* cria_cir(float r){
    Circulo* c = (Circulo*)malloc(sizeof(Circulo));
    c->r = r;

    Listahet* novo = (Listahet*)malloc(sizeof(Listahet));
    novo->geometria = CIR;
    novo->info = c;
    novo->prox = NULL;

    return novo;
}

Listahet* lsthet_cria_vazia(){
    return NULL;
}
Listahet* lsthet_deleta_formas(Listahet* l, Tipo geometria){
    Listahet* p = l;
    Listahet* ant = NULL;

    while(p != NULL){
        if(p->geometria == geometria){
            Listahet* temp = p;
            
            if(ant == NULL)
                l = p->prox;
            else    
                ant->prox = p->prox;

            p = p->prox;
            free(temp->info);
            free(temp);
        }
        else{
            ant = p;
            p = p->prox;
        }
    }
    return l;
}
Listahet* lsthet_libera(Listahet* l){
    Listahet* p = l;
    while(p != NULL){
        Listahet* temp = p;
        p = p->prox;
        
        free(temp->info);
        free(temp);
    }
    return NULL;
}
Listahet* lsthet_busca_forma(Listahet* l, Tipo geometria);

float lsthet_calc_area(void* info, Tipo geometria){
    float a;
    switch(geometria){
        case RET:
            Retangulo* r = (Retangulo*)info;
            a = r->b * r->h;
        break;
        case TRI:
            Triangulo* t = (Triangulo*)info;
            a = (t->b * t->h) /2;
        break;
        case CIR:
            Circulo* c = (Circulo*)info;
            a = PI*c->r*c->r;
        break;
        default:
            a = 0.0;
    }
    return a;
}
float lsthet_area_total(Listahet* l){
    float areaTotal = 0.0;
    while(l != NULL){
        areaTotal += lsthet_calc_area(l->info, l->geometria);
        l = l->prox;
    }
    return areaTotal;
}
int lsthet_conta_tipo(Listahet* l, Tipo geometria);

Listahet* lsthet_insere(Listahet* l, Tipo geometria){
    Listahet* novo = NULL;
    float b = 0.0;
    float h = 0.0;
    float r = 0.0;
    switch(geometria){
        case RET:
            scanf("%f %f", &b, &h);
            novo = cria_ret(b, h);
        break;
        case TRI:
            scanf("%f %f", &b, &h);
            novo = cria_tri(b, h);
        break;
        case CIR:
            scanf("%f", &r);
            novo = cria_cir(r);
        break;
        default: 
            printf("Invalido...\n");
    }

    if(l == null)
        l = novo;
    else{
        novo->prox = l;
        l = novo;
    }
    return l;
}
void lsthet_imprime(Listahet* l);
void lsthet_imprime_tipo(Listahet* l, Tipo geometria);