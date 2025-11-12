#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comprimento_string(char* v);
void imprime_strings(char* v[], int n);
int maior_comprimento(char* v[], int n);
void ler_imprime_nomes(int n);
void libera_strings(char* v[], int n);
int busca_string(char* v[], int n, char* alvo);
void imprime_primeiro_nome();
void concatena_strings(char* destino, char* v[], int n);
void ordena_strings(char* v[], int n);

int main(){
    // Declara um vetor de ponteiros com 5 nomes fixos e imprime.
    char* nomes[5] = {"Matheus", "Lucas", "Geovane", "Ingrid", "Maria"};
    imprime_strings(nomes, 5);
    
    printf("\nMaior elemento da string: %d\n", maior_comprimento(nomes, 5));
    ler_imprime_nomes(3);
    
    printf("\n");
    imprime_primeiro_nome();

    return 0;
}

// Retorna o comprimento de uma string.
int comprimento_string(char* v){
    int cont = 0;
    for(int i = 0; v[i] != '\0'; i++)
        cont++;
    return cont;
}

// Imprime as strings de um vetor
void imprime_strings(char* v[], int n){
    for(int i = 0; i < n; i++)
        printf("%s\n", v[i]);
}   

// Retorna o comprimento da maior string de um vetor.
int maior_comprimento(char* v[], int n){
    int maior = 0;
    for(int i = 0; i < n; i++){
        int tamanho = comprimento_string(v[i]);
        if(tamanho > maior)
            maior = tamanho;
    }
    return maior;
}


// Ler n nomes do teclado, armazena memória para cada um e imprime.
void ler_imprime_nomes(int n){
    char buffer[100]; // Temporário
    char* nomes[n];

    printf("\n");
    for(int i = 0; i < n; i++){
        printf("Digite o [%d] nome: ", i+1);
        scanf("%s", &buffer);

        nomes[i] = (char*)malloc((comprimento_string(buffer)+1) * sizeof(char));
        if(!nomes[i]) exit(1);

        strcpy(nomes[i], buffer);
    }

    printf("\nNomes digitados:\n");
    imprime_strings(nomes, n);
}

// Libera memória de um vetor de strings.
void libera_strings(char* v[], int n){
    for(int i = 0; i < n; i++){
        free(v[i]);
        v[i] = NULL;
    }
}

// Retorna a posição de uma string no vetor, retorna -1 se não encontrar.
int busca_string(char* v[], int n, char* alvo){
    for(int i = 0; i < n; i++)
        if(strcmp(v[i], alvo) == 0)
            return i;
    return -1;
}

// Recebe nome inteiro de uma pessoa, mas imprime apenas o primeiro nome.
void imprime_primeiro_nome(){
    int qtd;
    printf("Digite quantos nomes vai querer digitar:");
    scanf("%d", &qtd);

    char nome[qtd][100];

    for(int i = 0; i < qtd; i++){
        printf("Digite o [%d] nome:", i+1);
        scanf(" %99[^\n]", &nome[i]);
    }

    for(int i = 0; i < qtd; i++){

        int j = 0;
        while(nome[i][j] != ' ' && nome[i][j] != '\0'){
            putchar(nome[i][j]);
            j++;
        }
        printf("\n");
    }
}

// Concatena todas strings de um vetor em uma string de destino.
void concatena_strings(char* destino, char* v[], int n){
    int pos = 0;
    for(int i = 0; i< n; i++){
        int j = 0;
        while(v[i][j] != '\0'){
            destino[pos++] = v[i][j];
            j++;
        }
    }
    destino[pos] = '\0';
}

// Ordena strings em ordem alfabética.
void ordena_strings(char* v[], int n){
    char* temp;
    for(int i = 0; i < n - 1; i++)
        for(int j = i  + 1; j < n; j++)
            if(strcmp(v[i], v[j]) > 0){
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
}