//Bibliotecas


#include <stdio.h>
#include <stdlib.h>// rand, srand
#include <time.h> //time

//Variaveis Globais


#define MAX 100

//Protótipos


void gerar_matriz_aleatoria(int _linha, int _coluna, char _matriz[][MAX]);
void dimensao(int *_linha, int *_coluna);
int aleatorio(int min, int max);
void matriz_zerada (char _matriz2[][MAX]);
//Programa Principal


int main(){
    srand(time(NULL));
    int linha, coluna;
    char matriz[MAX][MAX];
    char matriz_zero[MAX][MAX];
    dimensao(&linha, &coluna);
    gerar_matriz_aleatoria(linha, coluna, matriz);
    matriz_zerada(matriz_zero);

    return 0;
}


//Obejetivo
//Parametros
//retorno
int aleatorio(int min, int max){
    //srand( time (NULL) );
    return min + (rand() % (max - min + 1));
}
//Obejetivo
//Parametros
//retorno
void dimensao(int *_linha, int *_coluna){
    printf("Digite o número de linhas:");
    scanf("%d", _linha);
    printf("\n");
    printf("Digite o número de colunas:");
    scanf("%d", _coluna);
    printf("\n");
}
//Obejetivo
//Parametros
//retorno
void gerar_matriz_aleatoria(int _linha, int _coluna, char _matriz[][MAX]){
    int i, j;
    for (i = 0; i < _linha; i++){
        for (j = 0; j < _coluna; j++){
            _matriz[i][j] = 'A' + aleatorio(0, 25);
            printf("%3c", _matriz[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void matriz_zerada(char _matriz2[][MAX]){
    int i,j;
    int a = aleatorio(10,MAX-50);
    int b = aleatorio(10,MAX-50);
    for (i = 0; i < a; i++){
        for (j = 0; j < b; j++){
            _matriz2[i][j] = 0;
            printf("%d ", _matriz2[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}
void acoplamento_de_posicao
