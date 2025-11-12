#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* lexico_maior(char* v[], int n);
int conta_vogais(char* s);
char* remove_char(char* s, char c);
void substitui_char(char* s, char antigo, char novo);
void imprime_reverso(char* v[], int n);
int ocorrencias_string(char* v[], int n, char* alvo);
char* junta_strings(char* s1, char* s2);

int main(){
    char* nomes[] = {"Matheus", "Lima", "Costa", "Pedro", "Airton", "Tielle"};

    printf("Maior lexicograma: %s\n", lexico_maior(nomes, 6));

    char* nome = "Matheus";
    printf("Quantidade de vogais em [%s]: %d\n", nome, conta_vogais(nome));

    return 0;
}

// Retorna qual palavra é lexocograficamente maior em uma string.
char* lexico_maior(char* v[], int n){
    char* maior = v[0];
    for(int i = 0; i < n; i++)
        if(strcmp(v[i], maior) > 0)
            maior = v[i];
    return maior;
}

// Conta quantas vogais há em uma string.
int conta_vogais(char* s){
    int cont = 0;
    char vogais[10] = {'a', 'A', 'e', 'E', 'i', 'I', 'o', 'O', 'u', 'U'};
    for(int i = 0; s[i] != '\0'; i++)
        for(int j = 0; j < 10; j++)
            if(s[i] == vogais[j])
                cont++;
    return cont;
}

// Remove todas as ocorrências de uma caracter c e retorna uma nova string sem esse caracter.
char* remove_char(char* s, char c){
    int cont = 0;
    for(int i = 0; s[i] != '\0'; i++) // Descobre a quantidade de ocorrências de c.
        if(s[i] == c)
            cont++;
    
    int tamanhoS = strlen(s);
    char* novaS = (char*)malloc((tamanhoS+1-cont) * sizeof(char)); // Cria uma nova string com tamanho menor (sem contar as ocorrências de c).
    if(!novaS) exit(1);

    int j = 0;
    for(int i = 0; i < tamanhoS; i++) // Preenche a nova string sem ocorrências de c.
        if(s[i] != c){
            novaS[j] = s[i];
            j++;
        }

    novaS[j] = '\0';
    return novaS;
}

// Substitui todas as ocorrências de antigo por novo.
void substitui_char(char* s, char antigo, char novo){
    for(int i = 0; s[i] != '\0'; i++)
        if(s[i] == antigo)
            s[i] = novo;
}

// Imprime uma string reversa.
void imprime_reverso(char* v[], int n){
    for(int i = n - 1; i >= 0; i--)
        printf(" %s ", v[i]);
}

// Retorna quantas vezes alvo aparece no vetor.
int ocorrencias_string(char* v[], int n, char* alvo){
    int cont = 0;
    for(int i = 0; i < n; i++){
        if(strcmp(v[i], alvo) == 0)
            cont++;
    }
    return cont;
}

// Concatena, só mudou o nome.
char* junta_strings(char* s1, char* s2){
    int cont = 0;
    for(int i = 0; s1[i] != '\0'; i++)
        cont++;
    for(int i = 0; s2[i] != '\0'; i++)
        cont++;

    char* novaS = (char*)malloc((cont + 1) * sizeof(char));
    if(!novaS) exit(1);

    int i = 0;
    for(i; s1[i] != '\0'; i++)
        novaS[i] = s1[i];

    for(int j = 0; s2[j] != '\0'; j++){
        novaS[i] = s2[j];
        i++;
    }
    novaS[i] = '\0';
    return novaS;
}