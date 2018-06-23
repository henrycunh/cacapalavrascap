/**
 * Contém definições de bibliotecas, definições
 * globais e o arranjo geral do programa junto
 * a seu runtime principal
 * 
 * @author  Henrique Cunha  
 * @info    RA  759023
*/

// Importação de Bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Definição de constantes
#define MAX_LINHAS          100
#define MAX_COLUNAS         100
#define MAX_PALAVRAS        100
#define MAX_COMP_PALAVRA    100
#define MIN_COMP_PALAVRA    3
#define CHAR_PREENCHIMENTO  ' '
// Inclusão de módulos
#include "tipos.c"
#include "aleatorio.c"
#include "matriz.c"
#include "palavras.c"
#include "interface.c"

// Execução do runtime
int main(int argc, char * argv[]){
    // Inicializando matriz de caracteres
    char matriz[MAX_LINHAS][MAX_COLUNAS];
    // Inicializando matriz com as palavras da lista
    char matriz_palavras[MAX_LINHAS][MAX_COLUNAS];
    // Inicializando matriz de 0
    char matriz_zero[MAX_LINHAS][MAX_COLUNAS];
    // Inicializando matriz com palavras destacadas
    char matriz_destacada[MAX_LINHAS][MAX_COLUNAS];
    // Inicializando lista de palavras
    Palavra palavras[MAX_PALAVRAS];
    // Inicializando configurações
    Config conf = NOVA_CONFIG;
    // Inicializar aleatoriedade
    inicializar_aleatoriedade();
    // Verificando se está no modo de debug
    conf.debug = argc >= 2 && !strcmp("debug", argv[1]);
    // Verifica predefinições
    if(argc >= 3){
        conf.def = 1;
        strcpy(conf.matrizDef  , argv[1 + conf.debug]);
        strcpy(conf.palavrasDef, argv[2 + conf.debug]);
    } else {
        // Receber opções 
        alterar_opcoes( &conf );
    }
    // Leitura da Matriz
    ler_matriz( matriz, &conf );
    // Leitura das Palavras
    ler_palavras( palavras, matriz, &conf );
    // Resolução 
    verificar_palavras( matriz, palavras, conf );
    // Exibir resultado
    exibir_encontradas( palavras, conf, matriz, matriz_palavras, matriz_destacada, matriz_zero);

    return 0;
}