//Bibliotecas
#include <stdio.h>
#include<string.h>
//Constantes Globais
#define MAX 5
//Tipos Globais
typedef struct{
    char modelo[MAX];
    int matriz[MAX][MAX];
    int ano;
    char marca;
    char dono;
    double preco;
    int comprado;
}carro;
//Protótipos
void altera_modelo(carro *carr01);
void altera_ano(carro *carro01);
int altera_anoCOPIA(carro carr01);
void ler_matriz(carro *_carr01, int _linha, int _coluna);
void ler_matriz1(int matriz[][MAX], int _linha, int _coluna);
//char altera modelo1(carro *carr01);
//Programa Principal
int main(){
    carro carr01;
    int matriz1[MAX][MAX];
    
    int tamanho;
    /*int a;
    altera_modelo(&carr01);
    printf("%s\n", carr01.modelo);
   // altera_ano(&carr01);
   // printf("%d\n", carr01.ano);
    a = altera_anoCOPIA(carr01);
    printf("%d\n", a);
    */
   int linha;
   int coluna;
    printf("Digite a quantidade de linhas da sua matriz\n");
    scanf("%d", &linha);
    printf("Digite a quantidade de colunas da sua matriz\n");
    scanf("%d", &colunas);
        
   ler_matriz1(matriz1, linha, coluna);
   //VERIFICAÇão
   int i , j;
    for(i = 0; i < linha; i++){
        for(j = 0; j < coluna; j++){
            printf("%d ",  matriz1[i][j]);
        }
        printf("\n");
    }    
    
    return 0;
}
/*
void altera_modelo(carro *carr01){
    char modelo1[MAX];
    printf("Digite o modelo do carro:\n");
    scanf("%s", modelo1);
    strcpy(carr01->modelo, modelo1);
   // _carr01->modelo = _modelo; SUB15D+
}
void altera_ano(carro *carr01){
    int _ano;
    printf("Digite o ano do carro\n");
    scanf("%d", &_ano);
    carr01->ano = _ano;
}

*/
void ler_matriz1(int matriz[][MAX], int _linha, int _coluna){
    int i,j;
    for(i = 0; i < _linha; i++){
        printf("Digite o elemento da linha #%d\n", i+1);
        for(j = 0; j < _coluna; j++){
            printf("\tDa coluna #%d :", j+1);
            scanf("%d", &matriz[i][j]);
        }
    } 
}
void ler_matriz(carro *_carr01, int _linha, int _coluna){
    for(_linha = 0; _linha < MAX; _linha++){
        printf("Digite o elemento da _linha #%d\n", _linha+1);
        for(_coluna = 0; _coluna < MAX; _coluna++){
            printf("\tDa coluna #%d :", _coluna+1);
            scanf("%d", &_carr01->matriz[_linha][_coluna]);
        }
     
    }    
}

/*
char altera modelo1(carro *carr01){
    char modelo1[MAX];
    printf("Digite o modelo do carro:\n");
    scanf("%s", modelo1);
    strcpy(carr01->modelo, modelo1);
    return carr01->modelo;
}
*/
/*


Deverás então implementar as seguintes funções, seguindo as instruções nas descrições.
 Mudar Modelo
Recebe o carro, e o novo nome do modelo do carro e o altera no carro. Implemente a
função por referência e por cópia.
 Mudar Ano
Recebe o carro, e o novo ano do carro e o altera no carro. Implemente a função por
referência e por cópia.
 Mudar Marca
Recebe o carro, e o novo nome da marca do carro e o altera no carro. Implemente a
função por referência e por cópia.
 Mudar Dono
Recebe o carro, e o novo nome do dono do carro e o altera no carro. Implemente a
função por referência e por cópia.
 Mudar Preço
Recebe o carro, e o novo preço do carro e o altera no carro. Implemente a função por
referência e por cópia.
 Mudar Comprado
Recebe o carro, altera o estado de compra do carro.
 Adicionar Similar
Recebe o carro, um carro similar e adiciona na lista de similares do carro, alterando
também sua quantidade de similares.
 Imprimir Carro
Recebe o carro, e imprime as sua informações.
 Média de Preço
Recebe uma lista de carros e retorna a média de seus preços.
 Comprar Similares
Recebe um carro, e retorna a soma do preço de todos os seu similares.
1
*/