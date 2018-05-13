/* Inclusão dos bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
// #include <curses.h>

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
// #include "gui/graphic.c"    // Interface gráfica de usuário 
#include "gui/cli.c"        // Interface por CLI 

/* Main Runtime */
int main(int argc, char * argv[]){
    modo_cli();
    gerar_matriz_aleatoria();
}
