/**
 * Contém estruturas que facilitam o
 * manuseio das informações por entre as
 * demais funções da aplicação
 * 
 * @author  Henrique Cunha
 * @info    RA  759023
*/

#define NOVA_CONFIG {0, 0, 0, 0, 0}

typedef struct {
    int linhas,
        colunas,
        entradaMatriz,
        entradaPalavras,
        numPalavras,
        debug,
        def;
    char matrizDef  [256],
         palavrasDef[256];
} Config;

typedef struct {
    char valor[MAX_COMP_PALAVRA];
    int encontrada;
} Palavra;