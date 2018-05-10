/* Inclusão dos bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

/* Definição de constantes */
#define MAX_PALAVRAS 50
#define MAX_W 1000
#define MAX_H 1000

/* Definição de tipos globais */
typedef struct word {
    int encontrado, // se a palavra foi encontrada
        orientacao; // orientação da palavra
    char val[64];   // palavra em si
} Palavra;

/* Definição de váriaveis globais */
int W = 20;                     // Largura da matriz
int H = 30;                     // Altura da matriz
int matriz_opt = 0;             // Opção de obtenção da matriz de caracteres
int lista_opt  = 0;             // Opção de obtenção da lista de palavras
char matriz[MAX_W][MAX_H];      // Matriz de caracteres
int quantidade_palavras = 0;
Palavra palavras[MAX_PALAVRAS]; // Lista de palavras

/* Inclusão dos módulos */
#include "random.c"     // Aleatorização das informações 
#include "matriz.c"     // Controle da matriz 
#include "palavras.c"   // Controle das palavras 
#include "ui.c"         // Interface de usuário 

/* Main Runtime */
int main(){
    // Obtenção das opções
    definir_opcoes();
    // Processamento das opções da matriz
    if(matriz_opt == 1)
        receber_matriz_teclado();
    else if(matriz_opt == 2)
        receber_matriz_arquivo();
    // else
    //     gerar_matriz_aleatoria();
    // Processamento das opções da lista de palavras
    if(lista_opt == 1)
        receber_lista_teclado();
    else if(lista_opt == 2)
        receber_lista_arquivo();
    // else
    //     receber_lista_aleatoria();
    // Verificar quais palavras estão na matriz
    verificar_palavras();
    // Expor o resultado
    dispor_resultado();    
    // imprimir_matriz();
}
