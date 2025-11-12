#include <stdio.h>
#include <stdlib.h>

#define RET 0
#define TRI 1
#define CIR 2
#define PI 3.14159

typedef struct retangulo{
    float b;
    float h;
} Retangulo;

typedef struct triangulo{
    float b;
    float h;
} Triangulo;

typedef struct circulo{
    float r;
} Circulo;

typedef struct listahet{
    int tipo;
    void* info;
    struct listahet* prox;
} Listahet;

float area(Listahet* l){
    float a;

    switch(l->tipo){
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
            printf("Tipo invalido!\n");
    }

    return a;
}

Listahet* cria_ret(float b, float h);
Listahet* cria_tri(float b, float h);
Listahet* cria_cir(float r);

Listahet* lsthet_insere(Listahet* l, int tipo);
void lsthet_imprime(Listahet* l);
void lsthet_libera(Listahet* l);

int main(){
    Listahet* lista = NULL;
    
    // Insere algumas figuras
    lista = lsthet_insere(lista, RET);
    lista = lsthet_insere(lista, TRI);
    lista = lsthet_insere(lista, CIR);
    
    // Imprime todas
    lsthet_imprime(lista);
    
    // Libera memória
    // lsthet_libera(lista);
    
    return 0;
}

Listahet* cria_ret(float b, float h){
    Retangulo* r = (Retangulo*)malloc(sizeof(Retangulo));
    if(!r) exit(1);
    r->b = b;
    r->h = h;

    Listahet* l = (Listahet*)malloc(sizeof(Listahet));
    if(!l) exit(1);
    l->tipo = RET;
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
    l->tipo = TRI;
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
    l->tipo = CIR;
    l->info = c;
    l->prox = NULL;

    return l;
}

Listahet* lsthet_insere(Listahet* l, int tipo){
    Listahet* novo = NULL;
    float b = 0.0;
    float h = 0.0;
    float r = 0.0;

    switch(tipo){
        case RET:   {
            printf("--==+RETANGULO+==--\n");
            printf("Digite a base e a altura, respectivamente: \n");
            scanf("%f  %f", &b, &h);

            novo = cria_ret(b, h);
            break;
        }
        case TRI:   {
            printf("--==+TRIANGULO+==--\n");
            printf("Digite a base e a altura, respectivamente: \n");
            scanf("%f %f", &b, &h);

            novo = cria_tri(b, h);
            break;
        }
        case CIR:   {
            printf("--==+CIRCULO+==--\n");
            printf("Digite o raio do circulo: \n");
            scanf("%f", &r);

            novo = cria_cir(r);
            break;
        }

        default:
            printf("Tipo invalido!\n");
    }
    if(!novo){
        printf("Novo elemento nao inserido na listta...\n");
        return l;
    }
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
    for(Listahet* p = l; p != NULL; p = p->prox){
        switch(p->tipo){
            case RET:   {
                Retangulo* r = (Retangulo*)p->info;
                printf("--==+RETANGULO+==--\n");
                printf("Base: %.1f\n", r->b);
                printf("Altura: %.1f\n", r->h);
                printf("Area: %.1f\n", area(p));

                break;
            }
            case TRI:   {
                Triangulo* t = (Triangulo*)p->info;
                printf("--==+TRIANGULO+==--\n");
                printf("Base: %.1f\n", t->b);
                printf("Altura: %.1f\n", t->h);
                printf("Area: %.1f\n", area(p));

                break;
            }
            case CIR:   {
                Circulo* c = (Circulo*)p->info;
                printf("--==+CIRCULO+==--\n");
                printf("Raio: %.1f\n", c->r);
                printf("Area: %.1f\n", area(p));

                break;
            }

            default:
                printf("Tipo invalido!\n");
        }
    }
}

void lsthet_libera(Listahet* l){
    
}