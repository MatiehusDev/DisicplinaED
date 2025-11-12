#ifndef __TAD_MATRIZ__
    #define __TAD_MATRIZ__

    typedef struct matriz{
        int lin;
        int col;
        float** v;
    } Matriz;

    /* Cria uma matriz m por n
    *  usando alocação dinâmica.
    */
    Matriz* mat_cria(int m, int n);

    /* Libera memória
    *  de uma matriz.
    */
    void mat_libera(Matriz* mat);

    /* Acessa o elemento
    *  da linha i e coluna j.
    */
    float mat_acessa(Matriz* mat, int i, int j);

    /* Atribui novos valores
    *  a linha i e coluna j.
    */
    void mat_atribui(Matriz* mat, int i, int j, float v);

    /* Retorna a quantidade
    *  de linhas da matriz.
    */
    int mat_linhas(Matriz* mat);

    /* Retorna a quantidade
    *  de colunas da matriz.
    */
    int mat_colunas(Matriz* mat);    

    #include "TAD_MATRIZ.c"
#endif