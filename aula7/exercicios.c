#include <stdio.h>
#include <stdlib.h>

float** matriz_cria(int linhas, int colunas);
void matriz_imprime(float** mat, int linhas, int colunas);
void matriz_inicializa(float** mat, int linhas, int colunas);
void matriz_libera(float** mat, int linhas);
float** matriz_soma(float** matA, int linhas_a, int colunas_a, float** matB, int linhas_b, int colunas_b);
float** matriz_subtrai(float** matA, int linhas_a, int colunas_a, float** matB, int linhas_b, int colunas_b);
float** matriz_duplica(float** matriz, int linhas, int colunas);
float** matriz_transposta(float** mat, int linhas, int colunas);

int main(){
    /*Cria, inicializa e imprime uma matrizA*/
    float** matrizA = matriz_cria(3,3);
    matriz_inicializa(matrizA, 3, 3);
    matriz_imprime(matrizA, 3, 3);

    /*Cria, inicializa e imprime uma matrizB*/
    float** matrizB = matriz_cria(3, 3);
    matriz_inicializa(matrizB, 3, 3);
    matriz_imprime(matrizB, 3, 3);

    /*Apresenta a soma entre duas matrizes*/
    float** soma = matriz_soma(matrizA, 3, 3, matrizB, 3, 3);
    printf("\nSoma das matrizes:");
    matriz_imprime(soma, 3, 3);
    
    /*Apresenta a subtração entre duas matrizes*/
    float** subtracao = matriz_subtrai(matrizA, 3, 3, matrizB, 3, 3);
    printf("\nSubtracao das matrizes:");
    matriz_imprime(subtracao, 3, 3);

    /*Imprime a transposta de uma matriz*/
    float** transposta = matriz_transposta(matrizA, 3, 3);
    printf("\nMatrizA transposta:");
    matriz_imprime(transposta, 3, 3);

    return 0;
}

//Função vai criar uma matriz NULA
float** matriz_cria(int linhas, int colunas){
    float** mat = (float**)malloc(linhas* sizeof(float*));
    if(!mat) exit(1);

    for(int i = 0; i < linhas; i ++){
        mat[i] = (float*)malloc(colunas * sizeof(float));
        if(!mat[i]) exit(1);
    }

    return mat;
}

//Vai imprimir uma matriz
void matriz_imprime(float** mat, int linhas, int colunas){
    printf("\n");
    for(int i = 0; i < linhas; i++){
        for(int j = 0; j < colunas; j++)
            printf("%.1f ", mat[i][j]);
        printf("\n");
    }
}

//Inicializa uma matriz com valores aleatorios 
void matriz_inicializa(float** mat, int linhas, int colunas){
    for(int i = 0; i < linhas; i++)
        for(int j = 0; j < colunas; j++)
            mat[i][j] = (i+1)*(j+1);
}

//Libera memória de uma matriz
void matriz_libera(float** mat, int linhas){
    printf("\nLiberando matriz...\n");
    for(int i = 0; i < linhas; i++)
        free(mat[i]);
    free(mat);
}

//Soma duas matrizes
float** matriz_soma(float** matA, int linhas_a, int colunas_a, float** matB, int linhas_b, int colunas_b){
    if((linhas_a != linhas_b) || (colunas_a != colunas_b)){
        printf("\nMatrizes de tamanhos diferentes!\n");
        exit(1);
    }

    float** soma = matriz_cria(linhas_a, colunas_a);

    for(int i = 0; i < linhas_a; i++)
        for(int j = 0; j <colunas_a; j++)
            soma[i][j] = matA[i][j] + matB[i][j];
    return soma;
}

//Subtrai duas matrizes
float** matriz_subtrai(float** matA, int linhas_a, int colunas_a, float** matB, int linhas_b, int colunas_b){
    if((linhas_a != linhas_b) || (colunas_a != colunas_b)){
        printf("\nMatrizes de tamanhos diferentes!\n");
        exit(1);
    }

    float** subtracao = matriz_cria(linhas_a, colunas_a);

    for(int i = 0; i < linhas_a; i++)
        for(int j = 0; j <colunas_a; j++)
            subtracao[i][j] = matA[i][j] - matB[i][j];
    return subtracao;
}

//Duplica uma matriz sem alterar a original
float** matriz_duplica(float** matriz, int linhas, int colunas){
    float** duplicada = matriz_cria(linhas, colunas);

    for(int i = 0; i < linhas; i++)
        for(int j = 0; j < colunas; j++)
            duplicada[i][j] = matriz[i][j];
    return duplicada;
}

//Retorna uma matriz na sua forma transposta
float** matriz_transposta(float** mat, int linhas, int colunas){
    float** transposta = matriz_cria(colunas, linhas);

    for(int i = 0; i < linhas; i++)
        for(int j = 0; j < colunas; j++)
            transposta[j][i] = mat[i][j];
    return transposta;
}