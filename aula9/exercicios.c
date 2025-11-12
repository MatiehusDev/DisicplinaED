#include <stdio.h>
#include <stdlib.h>

int compara(char* s1, char* s2);
void concatena(char* destino, char* origem);
char* duplica(char* s);
int comprimento(char string);
int conta_caractere(char* s, char c);
void inverte(char* s);
void para_maiusculas(char* s);
int main(){

    return 0;
}

//Função da o comprimento de uma string.
int comprimento(char string){
    int n = 0;
    for(int i = 0; string != '\0'; i++)
    n++;
    return n;
}

//Função compara duas strings, retorna 1 se forem iguais e 0 se forem diferentes.
int compara(char* s1, char* s2){

    for(int i = 0; s1[i] != '\0' && s2[i] != '\0'; i++)
        if(s1[i] != s2[i])
            return 0;

    return (s1[i] == '\0' && s2[i] == '\0');
}


//Função concatena uma string em uma string de destino.
void concatena(char* destino, char* origem){
    int i = 0;
    while(destino[i] != '\0')
        i++;
    
    int j = 0;
    while(origem[j] != '\0'){
        destino[i] = origem[j];
        i++;
        j++;
    }

    destino[i] = '\0';
}

//Função faz uma cópia de uma string sem alterar a original.
char* duplica(char* s){
    char* novaS = (char*)malloc((comprimento(s)+1) * sizeof(char));
    if(!novaS) exit(1);

    int i = 0;
    while(s[i] != '\0'){
        novaS[i] = s[i];
        i++;
    }
    novaS[i] = '\0';
    return novaS;
}

//Função conta quantas vezes um caracter X foi encontrado na string.
int conta_caractere(char* s, char c){
    int n = 0;
    for(int i = 0; s[i] != '\0'; i++)
        if(s[i] == c)
            n++;
    return n;
}

//Função inverte uma string no próprio vetor.
void inverte(char* s){
    char temp;
    int comp = comprimento(s);

    for(int i = 0; s[i] != '\0'; i++){
        
    }
}

void para_maiusculas(char* s){
    for(int i = 0; s[i] != '\0'; i++)
        if(s[i] >= 'a' && 'z' >= s[i])
            s[i] = s[i] - 'a' + 'A';
}