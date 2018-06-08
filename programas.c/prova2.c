//Bibliotecas 
#include <stdio.h>
#include <string.h>
//Constantes Globais
#define MAX_NOME 60
#define MAX_NOTAS 5
//Tipos Globais
typedef struct {
    char nome[MAX_NOME];
    int idade;
    double notas[MAX_NOTAS];
    int status;
}Aluno;

//Protótipos
void altera_nome(Aluno *_aluno1, char _nome[]);
void altera_idade(Aluno *_aluno1, int _idade1);
void altera_notas(Aluno *_aluno1, double _notass[]);
//Programa Principal

int main (){
//Declarações Locais
    Aluno _aluno1; //Estrutura aluno1
    char _nome[MAX_NOME];
    int _idade;
    printf("Digite o nome do aluno\n");
    scanf("%s", _nome);
    //ANTES DA ALTERAÇÃO
    //printf("ANTES%s\n", _aluno1.nome);
    altera_nome(&_aluno1, _nome);
    //POS ALTERAÇÃO
    printf("%s\n", _aluno1.nome);

    //Idade antes
    //printf("IDADE ANTES DE CHAMAR A FUNCAO %d\n", _aluno1.idade);
    printf("Digite a idade do aluno\n");
    scanf("%d", &_idade);
    altera_idade(&_aluno1, _idade);
    //idade depois
    printf("%d\n", _aluno1.idade);
    
    //Antes de alterar 
    printf("NOTAS ANTES DE ALTERAR %lf\n", _aluno1.notas);
    //depois de alterar
    int i;
    double _notas1[MAX_NOTAS];
    printf("Digite as notas do aluno\n");
    for (i = 0; i < MAX_NOTAS; i++){
        printf("Nota #%d: ", i+1);
        scanf("%lf", &_notas1[i]);
        
    }    
    altera_notas(&_aluno1, _notas1);
    //DEPOIS DA ALTERAÇão
    for (i = 0 ; i < MAX_NOTAS; i++){
        printf("%.2lf\n", _aluno1.notas[i]);
    }
    



    return 0;
}

void altera_nome(Aluno *_aluno1, char _nome[]){ 
    strcpy(_aluno1->nome,_nome);
}
void altera_idade(Aluno *_aluno1, int _idade1){
    _aluno1->idade = _idade1;
}
void altera_notas(Aluno *_aluno1, double _notass[]){
    int i;
    for(i = 0; i < MAX_NOTAS; i++){
        _aluno1->notas[i] = _notass[i];
    }
}