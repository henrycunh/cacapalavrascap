// Importação de Bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Definição de constantes
#define MAX_LINHAS          999
#define MAX_COLUNAS         999
#define MAX_PALAVRAS        999
#define MAX_COMP_PALAVRA    999
// Inclusão de módulos
#include "tipos.c"
#include "aleatorio.c"
#include "matriz.c"
#include "interface.c"
#include "palavras.c"

// Execução do runtime
int main(int argc, char * argv[]){

    // Inicializando matriz de caracteres
    char matriz[MAX_LINHAS][MAX_COLUNAS];
    
    // Inicializando lista de palavras
    Palavra palavras[MAX_PALAVRAS];

    // Inicializando configurações
    Config conf = NOVA_CONFIG;
    
    // Inicializar aleatoriedade
    inicializar_aleatoriedade();

    // Receber opções 
    alterar_opcoes( &conf );

    // Leitura da Matriz
    ler_matriz( matriz, conf );
    
    // Leitura das Palavras
    // ler_palavras( &palavras, conf );

    // // Resolução 
    // verificar_palavras( matriz, &palavras, conf );

    gerar_palavras_aleatorias(palavras, matriz, conf );
    // Exibir resultado
    exibir_encontradas( palavras, conf );
    
    return 0;
}