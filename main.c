/* Inclusão dos bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ncurses.h>

/* Definição de constantes */
#define MAX_PALAVRAS 50
#define MAX_W 1000
#define MAX_H 1000

/* Definição de tipos globais */
#include "tipos.c"

/* Definição de váriaveis globais */
int W = 20;                     // Largura da matriz
int H = 30;                     // Altura da matriz

/* Inclusão dos módulos */
#include "random.c"         // Aleatorização das informações 
#include "matriz.c"         // Controle da matriz 
#include "palavras.c"       // Controle das palavras 
#include "gui/graphic.c"    // Interface gráfica de usuário 
#include "gui/cli.c"        // Interface por CLI 

/* Main Runtime */
int main(int argc, char * argv[]){
    // Checa se deve executar o programa no modo gráfico ou CLI
    if(argc == 2)
        if(!strcmp(argv[1], "grafico"))
            modo_grafico();
        else if(!strcmp(argv[1], "cli"))
            modo_cli();
        else
            printf("Erro:\nArgumento invalido.\n");
    // Checa por erros
    else if(argc > 2)
        printf("Erro:\nMuitos argumentos.\n");
    else
        printf("Erro:\nInforme o modo de execucao (grafico ou cli).\n");
}
