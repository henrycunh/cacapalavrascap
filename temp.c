//Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//Variáveis globais

#define MAX 1000

//Protótipos

void dimensao(int *, int *);
int aleatorio(int, int);
void sorteio_inicio_fim(int, int *, int *);
void gerar_matriz_aleatoria(char matriz[MAX][MAX], int linhas, int colunas);
void imprimir_matriz(char matriz[MAX][MAX], int linhas, int colunas);

//Programa principal

int main()
{
    char matriz[MAX][MAX]; // Maior matriz possível
    char lista[MAX][MAX];  // Maior lista de palavras possível
    int nPalavras;         // Número de palavras na lista
    int i, j, k, l;        // Contadores
    int linha, coluna;
    int opcao;
    int achou;
    int valida = 0;
    int resultado;

    srand(time(NULL)); //Semente aleatória da função rand

    //Leitura da matriz
    printf("Ler uma matriz:\n");
    printf("1) a partir do teclado\n");
    printf("2) de um arquivo\n");
    printf("3) gerar uma matriz aleatória\n");
    printf("\nOpção:");
    scanf("%d", &opcao);
    printf("\n");

    if (opcao == 1)
    {
        //Dimensão da matriz
        dimensao(&linha, &coluna);

        //Entrada de dados
        printf("Digite as letras da matriz:\n");
        for (i = 0; i < linha; i++)
        {
            for (j = 0; j < coluna; j++)
            {
                scanf(" %c", &matriz[i][j]);
                if (matriz[i][j] >= 97)
                    matriz[i][j] -= 32;
            }
        }
        printf("\nMatriz:\n\n");
        for (i = 0; i < linha; i++)
        {
            for (j = 0; j < coluna; j++)
                printf("%3c", matriz[i][j]);
            printf("\n");
        }
        printf("\n");
    }

    else if (opcao == 2)
    {
    }

    else if (opcao == 3)
    {
        // Dimensão da matriz
        dimensao(&linha, &coluna);
        gerar_matriz_aleatoria( matriz, linha, coluna );
        imprimir_matriz( matriz, linha, coluna );
    }

    //Leitura da lista
    printf("Ler uma lista:\n");
    printf("1) a partir do teclado\n");
    printf("2) de um arquivo\n");
    printf("3) gerar uma lista aleatória\n");
    printf("\nOpção:");
    scanf("%d", &opcao);
    printf("\n");

    if (opcao == 1)
    {
        printf("Digite o número de palavras da lista:");
        scanf("%d", &nPalavras);
        printf("\n");
        printf("Digite as palavras da lista:\n\n");
        for (i = 0; i < nPalavras; i++)
            scanf("%s", lista[i]);
        for (i = 0; i < nPalavras; i++)
        {
            j = 0;
            while (lista[i][j] != '\0')
            {
                if (lista[i][j] >= 97)
                    lista[i][j] -= 32;
                j++;
            }
        }
        for (i = 0; i < nPalavras; i++)
            printf("%s\n", lista[i]);
        printf("\n");
    }

    else if (opcao == 2)
    {
    }

    else if (opcao == 3)
    {
        //Gerador de lista aleatória
        int sorteio;
        int posicaoInicial, posicaoFinal;
        int lcAleatoria; // Linha ou coluna aleatória
        int temp;        //Variável auxiliar
        int x = 0, y = 0, z;

        printf("Digite o número de palavras da lista:");
        scanf("%d", &nPalavras);
        printf("\n");

        for (z = 0; z < nPalavras; z++)
        {
            sorteio = aleatorio(0, 1); // Escolhe orientção aleatória

            //PALAVRA NA LINHA
            if (sorteio == 0)
            {
                lcAleatoria = aleatorio(0, linha - 1);
                sorteio_inicio_fim(coluna, &posicaoInicial, &posicaoFinal);
                for (i = posicaoInicial; i <= posicaoFinal; i++)
                {
                    lista[x][y] = matriz[lcAleatoria][i];
                    y++;
                }
                lista[x][y] = '\0';
                printf("%s ", lista[x]);
                printf("%d e %d\n", posicaoInicial, posicaoFinal);
            }

            //PALAVRA NA COLUNA
            else if (sorteio == 1)
            {
                lcAleatoria = aleatorio(0, coluna - 1);
                sorteio_inicio_fim(linha, &posicaoInicial, &posicaoFinal);
                for (i = posicaoInicial; i <= posicaoFinal; i++)
                {
                    lista[x][y] = matriz[i][lcAleatoria];
                    y++;
                }
                lista[x][y] = '\0';
                printf("%s ", lista[x]);
                printf("%d e %d\n", posicaoInicial, posicaoFinal);
            }
            y = 0;
            x++;
        }
        printf("\n");
    }

    //Encontrar as palavras
    for (i = 0; i < nPalavras; i++)
    {
        achou = 0;
        resultado = 0;
        for (j = 0; j < linha; j++)
        {
            for (k = 0; k < coluna; k++)
            {
                if (lista[i][0] == matriz[j][k])
                {
                    if (lista[i][1] == matriz[j][k + 1])
                    { //Palavra na linha
                        achou = 1;
                        for (l = 0; l < strlen(lista[i]); l++)
                        {
                            if (lista[i][l] != matriz[j][k + l])
                                achou = 0;
                        }
                    }
                    if (achou == 0)
                    {
                        if (lista[i][1] == matriz[j + 1][k])
                        { //Palavra na coluna
                            achou = 1;
                            for (l = 0; l < strlen(lista[i]); l++)
                            {
                                if (lista[i][l] != matriz[j + l][k])
                                    achou = 0;
                            }
                        }
                    }
                }
                resultado += achou;
            }
        }
        if (resultado == 0)
            printf("Palavra não encontrada: %s\n", lista[i]);
        else
            valida += 1;
    }

    if (valida == nPalavras)
        printf("O caça palavras é válido!");
    else
        printf("O caça palavras não é válido.");
    


    return 0;
}

void gerar_matriz_aleatoria(char matriz[MAX][MAX], int linhas, int colunas){
    int i, j;
    //Gerador de matriz aleatória
    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; j++)
            matriz[i][j] = 'A' + aleatorio(0, 25);
}

// Imprime matriz
void imprimir_matriz(char matriz[MAX][MAX], int linhas, int colunas){
    int i, j;
    for (i = 0; i < linhas; i++)
        for (j = 0; j < colunas; j++)
            // Imprime caracter a caracter junto a uma quebra de linha no último
            printf("%3c%c", matriz[i][j], (j == colunas - 1 ? '\n' : ' ') );
}


//Objetivo: determinar as dimensões da matriz
//Parâmetros formais:
//  - l: número de linhas
//  - c: número de colunas
void dimensao(int *l, int *c)
{
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
int aleatorio(int min, int max)
{
    //srand( time (NULL) );
    return min + (rand() % (max - min + 1));
}

//Objetivo: determinar posições inicial e final
//Parâmetros formais:
//  - y: tamanho da linha ou da coluna
//  - inicio: posição da primeira letra da palavra
//  - fim: posição da última letra da palavra
void sorteio_inicio_fim(int y, int *inicio, int *fim)
{

    //Variáveis locais
    int temp; //Variável auxiliar
    do
    {
        *inicio = aleatorio(0, y - 1); // Escolhe posição inicial
        *fim = aleatorio(0, y - 1);    // Escolhe posição final
    } while (*inicio == *fim);
    if (*inicio > *fim)
    {
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