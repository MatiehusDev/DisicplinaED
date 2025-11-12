#include <stdio.h>

int eh_substring(char* texto, char* padrao);
int eh_igual(char* s1, char* s2);

int main(){
    
    return 0;
}

// Retorna 1 se padrão ocorre dentro do texto
int eh_substring(char* texto, char* padrao){
    if(*padrao == NULL) exit(1);
    
    for(int i = 0; texto[i] != '\0'; i++){
        int j = 0;
        while(texto[i + j] != '\0' && padrao[j] != '\0' && texto[i + j] == padrao[j])
            j++;
        if(padrao[j] == '\0')
            return 1;
    }
    return 0;
}

// Compara se duas strigs são iguais.
int eh_igual(char* s1, char* s2){
    int i = 0;
    for(i; s1[i] != '\0' && s2[i] != '\0'; i++){
        if(s1[i] != s2[i])
            return 0;
    }

    if(s1 == s2)
        return 0;
    if(s1[i] == '\0')
        return 1;
    if(s2[i] == '\0')
        return -1;
}