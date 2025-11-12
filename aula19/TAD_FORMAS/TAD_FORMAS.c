#include <stdio.h>
#include <stdlib.h>
#include "TAD_FORMAS.h"

float area(Listahet* l){
    float a;
    switch(l->geometria){
        case RET:   {
            Retangulo* r = (Retangulo*)l->info;
            a = r->b * r->h;
            break;
        }
        case TRI:   {
            Triangulo* t = (Triangulo*)l->info;
            a = (t->b * t->h) / 2;
            break;
        }
        case CIR:   {
            Circulo* c = (Circulo*)l->info;
            a = PI*c->r*c->r;
            break;
        }
        default:
            printf("Tipo invalido...\n");
    }
    return a;
}

Listahet* cria_ret(float b, float h){
    Retangulo* r = (Retangulo*)malloc(sizeof(Retangulo));
    if(!r) exit(1);
    r->b = b;
    r->h = h;

    Listahet* l = (Listahet*)malloc(sizeof(Listahet));
    if(!l) exit(1);
    l->geometria = RET;
    l->info = r;
    l->prox = NULL;
    
    return l;
}

Listahet* cria_tri(float b, float h){
    Triangulo* t = (Triangulo*)malloc(sizeof(Triangulo));
    if(!t) exit(1);
    t->b = b;
    t->h = h;

    Listahet* l = (Listahet*)malloc(sizeof(Listahet));
    if(!l) exit(1);
    l->geometria = TRI;
    l->info = t;
    l->prox = NULL;
    
    return l;
}

Listahet* cria_cir(float r){
    Circulo* c = (Circulo*)malloc(sizeof(Circulo));
    if(!c) exit(1);
    c->r = r;

    Listahet* l = (Listahet*)malloc(sizeof(Listahet));
    if(!l) exit(1);
    l->geometria = CIR;
    l->info = c;
    l->prox = NULL;
    
    return l;
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
            free(p->info);

            if(ant == NULL)
                l = p->prox;
            else    
                ant->prox = p->prox;
            
            p = p->prox;
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
            a = (t->b * t->h) / 2;
        break;
        case CIR:
            Circulo* c = (Circulo*)info;
            a = PI * c->r * c->r;
        break;
        default:
            printf("Geometria invalida...\n");
            return 0.0;
        }
    return a;
}

float lsthet_area_total(Listahet* l){
    float areaTotal = 0.0;
    for(l; l != NULL; l = l->prox){
        float temp = lsthet_calc_area(l->info, l->geometria);
        areaTotal += temp;
    }
    return areaTotal;
}

int lsthet_conta_tipo(Listahet* l, Tipo geometria){
    int cont = 0;
    for(; l != NULL; l = l->prox)
        if(l->geometria == geometria)
            cont++;
    
    return cont;
}

Listahet* lsthet_insere(Listahet* l, Tipo geometria){
    Listahet* novo = NULL;
    float b = 0.0;
    float h = 0.0;
    float r = 0.0;

    switch(geometria){
        case RET:   {
            printf("RETANGULO\n");
            printf("Digite base e altura: \n");
            scanf("%f %f", &b, &h);
            novo = cria_ret(b, h);
            break;
        }
        case TRI:   {
            printf("TRIANGULO\n");
            printf("Digite base e altura: \n");
            scanf("%f %f", &b, &h);
            novo = cria_tri(b, h);
            break;
        }
        case CIR:   {
            printf("CIRCULO\n");
            printf("Digite o raio: \n");
            scanf("%f", &r);
            novo = cria_cir(r);
            break;
        }
        default:
            printf("Tipo invalido!\n");
    }
    if(!novo)
        printf("Nao possivel inserir novo elemento...\n");
    else{
        if(l == NULL)
            l = novo;
        else{
            novo->prox = l;
            l = novo;
        }
    }    
    return l;
}


void lsthet_imprime(Listahet* l){
    for(l; l != NULL; l = l->prox){
        switch(l->geometria){
            case RET:   {
                Retangulo* r = (Retangulo*)l->info;
                printf("RETANGULO\n");
                printf("Base = %f\nAltura = %f\n", r->b, r->h);
                printf("Area = %f\n", area(l));
                break;
            }
            case TRI:   {
                Triangulo* t = (Triangulo*)l->info;
                printf("TRIANGULO\n");
                printf("Base = %f\nAltura = %f\n", t->b, t->h);
                printf("Area = %f\n", area(l));
                break;
            }
            case CIR:   {
                Circulo* c = (Circulo*)l->info;
                printf("CIRCULO\n");
                printf("Raio = %f\n", c->r);
                printf("Area = %f\n", area(l));
                break;
            }
            default:
                printf("Tipo invalido!\n");
        }
    }
}

void lsthet_imprime_tipo(Listahet* l, Tipo geometria){
    for(l; l != NULL; l = l->prox){
        if(l->geometria == geometria)
            lsthet_imprime(l)
    }
}