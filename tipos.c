#define NOVA_CONFIG {0, 0, 0, 0}

typedef struct {
    int linhas,
        colunas,
        entradaMatriz,
        entradaPalavras,
        numPalavras;
} Config;

typedef struct {
    char valor[MAX_COMP_PALAVRA];
    int encontrada;
} Palavra;