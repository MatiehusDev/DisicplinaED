#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Inclua apenas o header, NÃO inclua o .c no header
#include "TAD_ALUNOS_JIFS/TAD_ALUNOS_JIFS.h"

int main() {
    Lista* lista = NULL;
    Lista* resultado = NULL;
    
    printf("=== TESTE DA LISTA DE ALUNOS JIFs ===\n\n");
    
    // 1. Teste criar lista
    printf("1. Criando lista...\n");
    lista = lst_cria();
    
    // 2. Teste inserir no início
    printf("2. Inserindo alunos no início:\n");
    lista = lst_insere(lista, "João Silva", "8599991111", "Futebol");
    lista = lst_insere(lista, "Maria Santos", "8599992222", "Vôlei");
    lst_imprime(lista);
    
    // 3. Teste buscar aluno (PRECISA CORRIGIR A FUNÇÃO!)
    printf("3. Buscando aluno 'Maria Santos':\n");
    resultado = lst_buscar_aluno(lista, "Maria Santos");
    if(resultado != NULL) {
        printf("Encontrado: ");
        lst_imprime_aluno(&resultado->info);
    } else {
        printf("NÃO encontrado! (ERRO na função buscar)\n");
    }
    
    // 4. Teste inserir no final
    printf("4. Inserindo no final:\n");
    lista = lst_insere_final(lista, "Carlos Lima", "8599993333", "Natação");
    lst_imprime(lista);
    
    // 5. Teste remover
    printf("5. Removendo 'João Silva':\n");
    lista = lst_remove(lista, "João Silva");
    lst_imprime(lista);
    
    // 6. Teste remover do início
    printf("6. Removendo do início:\n");
    lista = lst_remove_inicio(lista);
    lst_imprime(lista);
    
    // 7. Teste atualizar aluno
    printf("7. Atualizando dados do Carlos:\n");
    if(lst_atualiza_aluno(lista, "Carlos Lima", "Carlos Souza", "8599994444", "Basquete")) {
        printf("Atualizado com sucesso!\n");
    } else {
        printf("Erro na atualização!\n");
    }
    lst_imprime(lista);
    
    // 8. Teste filtrar por modalidade
    printf("8. Filtrando por modalidade:\n");
    lista = lst_insere(lista, "Ana Costa", "8599995555", "Vôlei");
    lista = lst_insere(lista, "Pedro Santos", "8599996666", "Futebol");
    lst_imprime_por_modalidade(lista, "Vôlei");
    
    // 9. Teste remover do final
    printf("9. Removendo do final:\n");
    lista = lst_remove_final(lista);
    lst_imprime(lista);
    
    // 10. Limpar lista
    printf("10. Limpando lista...\n");
    while(lista != NULL) {
        lista = lst_remove_inicio(lista);
    }
    printf("Lista vazia: ");
    lst_imprime(lista);
    
    printf("\n=== FIM DOS TESTES ===\n");
    return 0;
}