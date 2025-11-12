#include <stdio.h>
#include <stdlib.h>

float** matriz_clone(float** mat, int linhas, int colunas);

int main(){
    
    return 0;
}

// Cria uma cópia de uma matriz.
float** matriz_clone(float** mat, int linhas, int colunas){
    float** copiaMat = (float**)malloc(linhas  * sizeof(float*));
    if(!copiaMat) exit(1);

    for(int i = 0; i < linhas; i++){
        copiaMat[i] = (float*)malloc(colunas * sizeof(float));
        if(!copiaMat[i]) exit(1);
    }

    for(int i = 0; i < linhas; i ++)
        for(int j = 0; j < colunas; j++)
            copiaMat[i][j] = mat[i][j];
    return copiaMat;
}