//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Variáveis globais

#define MAX 1000

//Protótipos

void dimensao(int *, int *);
int aleatorio(int, int);
void sorteio_inicio_fim(int, int *, int *);



//Programa principal

int main() {
  char matriz[MAX][MAX]; // Maior matriz possível
  int i, j; // Contadores
  int linha, coluna;
  int opcao;

  srand(time(NULL)); //Semente aleatória da função rand

  //Leitura da matriz
  printf("Ler uma matriz:\n");
  printf("1) a partir do teclado\n");
  printf("2) de um arquivo\n");
  printf("3) gerar uma matriz aleatória\n");
  printf("\nOpção:");
  scanf("%d", &opcao);
  printf("\n");

  if(opcao == 1) {}

  else if(opcao == 2) {}

  else if(opcao == 3) {
        //Dimensão da matriz
        dimensao(&linha, &coluna);

        //Gerador de matriz aleatória
        for(i = 0; i < linha; i++) {
            for(j = 0; j < coluna; j++) {
                matriz[i][j] = 'A' + aleatorio(0 , 25);
                printf("%3c", matriz[i][j]);
            }
            printf("\n");
        }
        printf("\n");
    }

  //Gerador de lista aleatória
  char listaAleatoria[MAX][MAX];
  int sorteio;
  int posicaoInicial, posicaoFinal;
  int lcAleatoria; // Linha ou coluna aleatória 
  int temp; //Variável auxiliar
  int x = 0, y = 0, z;
  int nPalavras; // Número de palavras na lista

  printf("Digite o número de palavras da lista:");
  scanf("%d", &nPalavras);
  printf("\n");

  for(z = 0; z < nPalavras; z++) {
        sorteio = aleatorio(0, 1); // Escolhe orientção aleatória

        //PALAVRA NA LINHA
        if(sorteio == 0) { 
            lcAleatoria = aleatorio(0, linha - 1);
            sorteio_inicio_fim(coluna, &posicaoInicial, &posicaoFinal);
            for(i = posicaoInicial; i <= posicaoFinal; i++) {
                listaAleatoria[x][y] = matriz[lcAleatoria][i];
                y++; 
            }
            listaAleatoria[x][y] = '\0';
            printf("%s ", listaAleatoria[x]);
            printf("%d e %d\n", posicaoInicial, posicaoFinal);
        }

        //PALAVRA NA COLUNA 
        else if(sorteio == 1) {
            lcAleatoria = aleatorio(0, coluna - 1);
            sorteio_inicio_fim(linha, &posicaoInicial, &posicaoFinal);
            for(i = posicaoInicial; i <= posicaoFinal; i++) {
                 listaAleatoria[x][y] = matriz[i][lcAleatoria];
                 y++; 
                }
                listaAleatoria[x][y] = '\0';
                printf("%s ", listaAleatoria[x]);
                printf("%d e %d\n", posicaoInicial, posicaoFinal);
        }
        y = 0;
        x++;
    }

  return 0;
}

//Objetivo: determinar as dimensões da matriz
//Parâmetros formais:
//  - l: número de linhas
//  - c: número de colunas
void dimensao(int *l, int *c) {
  printf("Digite o número de linhas:");
  scanf("%d", l);
  printf("\n");
  printf("Digite o número de colunas:");
  scanf("%d", c);
  printf("\n");
}

//Objetivo: Gerar um número aleatório em um dado intervalo
//Parâmetros formais: 
//  - min : início do intervalo 
//  - max: fim do intervalo
//Valor de retorno: número dentro do intervalo
int aleatorio(int min, int max) {
  //srand( time (NULL) );
  return min + (rand() % (max - min + 1));
}

//Objetivo: determinar posições inicial e final
//Parâmetros formais: 
//  - y: tamanho da linha ou da coluna
//  - inicio: posição da primeira letra da palavra
//  - fim: posição da última letra da palavra
void sorteio_inicio_fim(int y, int *inicio, int *fim) {
  //Variáveis locais 
  int temp; //Variável auxiliar
    *inicio = aleatorio(0, y - 1); // Escolhe posição inicial
    *fim = aleatorio(0 , y - 1); // Escolhe posição final
    if(*inicio > *fim) {
        temp = *fim;
        *fim = *inicio;
        *inicio = temp;
    }
}

/* 
//Objetivo: determinar posições inicial e final
//Parâmetros formais: 
//  - 
//  -
void geraPalavra(int lcAleatoria, int x, int y, int posicaoInicial, int posicaoFinal, char listaAleatoria[][MAX], char matriz[][coluna]) {
  int i;
  for(i = posicaoInicial; i <= posicaoFinal; i++) {
    listaAleatoria[x][y] = matriz[lcAleatoria][i];
    y++; 
  }
  listaAleatoria[x][y] = '\0';
}*/