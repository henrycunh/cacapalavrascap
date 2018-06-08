#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//Variaveis Globais

#define NOME_MAX 60
#define NOTA_MAX 5
#define AMIGO_MAX
//Estrutura

typedef struct aluno
{
    char nome[NOME_MAX];
    int idade;
    double notas[NOTA_MAX];
    int status;
    int quantidade_de_amigos;
    struct aluno *amigos[AMIGO_MAX];
} Aluno;

// Prototipos

void alterar_nome(Aluno *a1, char *alterar_nome);
void alterar_idade(Aluno *a1);
void alterar_notas(Aluno *a1);
void alterar_status(Aluno *a1, int _media);
//Programa principal

int main()
{
    Aluno a1; //Estrutura do tipo aluno
    //Variaveis Locais
    int i; // controlador de laço
    //int _notas[NOTA_MAX];
    char nomeee[NOME_MAX];

    //Questão 1
    alterar_nome(&a1, nomeee);
    printf("Nome do aluno e: %s\n", a1.nome);

    //Questão 2
    alterar_idade(&a1);

    //Questão 3
    printf("A idade do aluno e: %d\n", a1.idade);

    //Questão 4

    alterar_notas(&a1);
    for (i = 0; i < NOTA_MAX; i++)
        printf("%.2lf\n", a1.notas[i]);

    // Questão 5
    double soma = 0;
    double media;
    for (i = 0; i < NOTA_MAX; i++)
    {
        soma += a1.notas[i];
    }
    //printf("%d", soma);

    media = soma / NOTA_MAX;
    printf("A media do aluno e: %.2lf\n", media);
    alterar_status(&a1, media);
    printf("Status do aluno e: %d\n", a1.status);
    printf("Se status zero, Aluno com nota irregular\n");
    printf("Se status um, aluno com nota regular\n");
    return 0;
}

void alterar_nome(Aluno *a1, char _nome[])
{
    printf("Digite o nome do aluno\n");
    scanf("%s", _nome);
    strcpy(a1->nome, _nome);
}

void alterar_idade(Aluno *a1)
{
    int _idade;
    printf("Digite a idade do aluno :\n");
    scanf("%d", &_idade);
    a1->idade = _idade;
}
// Leitura dentro da função
void alterar_notas(Aluno *a1)
{
    int i;
    double _notas[NOTA_MAX];
    for (i = 0; i < NOTA_MAX; i++)
    {
        printf("\tDigite a #%d nota do aluno: ", i + 1);
        //printf("\n");
        scanf("%lf", &_notas[i]);
        a1->notas[i] = _notas[i];
    }
}

void alterar_status(Aluno *a1, int _media)
{
    if (_media >= 6)
        a1->status = 1;
    else
        a1->status = 0;
}

void altera_amigos(Aluno *a1, Aluno *_aluno)
{
}