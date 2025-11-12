#ifndef __TAD_PONTO__
    #define __TAD_PONTO__
    
    #define PI 3.14159

    typedef struct ponto{
        float x;
        float y;
    } Ponto;

    /* Cria um ponto
    *  que recebe x, y.
    */
    Ponto* pto_cria(float x, float y);
    
    /* Libera memória
    *  de um ponto.
    */
    void pto_libera(Ponto* p);

    /* Acessa os valores de um
    *  ponto por referêcia.
    */
    void pto_acessa(Ponto* p, float* x, float* y);

    /* Atribui valores a
    *  ponto x e y.
    */
    void pto_atribui(Ponto* p, float x, float y);

    /* Retorna a distância
    *  entre dois pontos.
    */
    float pto_distancia(Ponto* p1, Ponto* p2);

   #include "TAD_PONTO.c"
#endif