#include <stdio.h>
#include <stdlib.h>
#include "TAD_MATRIZ.h"

Matriz* mat_cria(int m, int n){
    Matriz* novo = (Matriz*)malloc(sizeof(Matriz)); // Aloca memória para
    if(!novo) exit(1);                              // a struct.

    novo->lin = m; // Struct recebe as
    novo->col = n; // Dimensões da matriz.

    novo->v = (float**)malloc(m * sizeof(float*)); // Aloca as linhas
    if(!novo->v) exit(1);                          // da matriz em novo->v.

    for(int i = 0; i < m; i++){
        novo->v[i] = (float*)malloc(n * sizeof(float*)); // Aloca as colunas
        if(!novo->v[i]) exit(1);                         // da matriz em novo->v[i].
    }
}

void mat_libera(Matriz* mat){
    for(int i = 0; i < mat->lin; i++) // Libera memória
        free(mat->v[i]);              // de cada linha.
    free(mat->v); // Libera memória da matriz.
    free(mat); // Libera memória da struct.
}

float mat_acessa(Matriz* mat, int i, int j){
    return mat->v[i][j];
}

void mat_atribui(Matriz* mat, int i, int j, float v){
    mat->v[i][j] = v;
}

int mat_linhas(Matriz* mat){
    return mat->lin;
}

int mat_colunas(Matriz* mat){
    return mat->col;
}