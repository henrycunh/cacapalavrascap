/**
 * Interage com o usuário para extrair as formas
 * de entrada e as configurações respectivas 
 * 
 * @param   conf    Estrutura de configuração a ser inscrita
*/
void alterar_opcoes(Config * conf){
    printf("$ Configuracoes Gerais\n|\n");
    // Entrada da Matriz
    printf("|\tForma de entrada da Matriz:\n");
    printf("|\t   [1]> A partir do teclado\n");
    printf("|\t   [2]> A partir de um arquivo\n");
    printf("|\t   [3]> Gerado aleatoriamente\n");
    printf("|\t   > ");
    scanf("%d", &conf->entradaMatriz);
    // Receber dimensões
    if(conf->entradaMatriz == 1 || conf->entradaMatriz == 3){
        printf("|\tDimensoes da Matriz:\n");
        printf("|\t    Linhas: ");
        scanf("%d", &conf->linhas);
        printf("|\t   Colunas: ");
        scanf("%d", &conf->colunas);
    }
    // Entrada das Palavras
    printf("|\n|\tForma de entrada das Palavras:\n");
    printf("|\t   [1]> A partir do teclado\n");
    printf("|\t   [2]> A partir de um arquivo\n");
    printf("|\t   [3]> Gerado aleatoriamente\n");
    printf("|\n|\t   > ");
    scanf("%d", &conf->entradaPalavras);
    // Receber quantidade de palavras
    if(conf->entradaPalavras == 1 || conf->entradaPalavras == 3){
        printf("|\tQuantidade de palavras:\n");
        printf("|\n$\t  > ");
        scanf("%d", &conf->numPalavras);
    } else 
        printf("$\n");
}

/**
 * Recebe a matriz através de entrada por teclado
 * 
 * @param   matriz  Matriz de caracteres a ser inscrita
 * @param   conf    Estrutura de configurações
*/
void ler_matriz_teclado(char matriz[MAX_LINHAS][MAX_COLUNAS], Config conf){
    int linha, coluna;
    printf("|\tDigite a Matriz de Caracteres:\n");
    // Recebe do teclado de forma iterativa
    for(linha = 0; linha < conf.linhas; linha++){
        printf("|\t   # ");
        for(coluna = 0; coluna < conf.colunas;){
            char atual;
            scanf("%c", &atual);
            if(atual != ' '){
                matriz[linha][coluna] = atual;
                coluna++;
            }
        }
    }
}

/**
 * Recebe a matriz através do método de entrada informado
 * 
 * @param   matriz      Matriz de caracteres a ser inscrita
 * @param   conf        Estrutura de configurações
*/
void ler_matriz(char matriz[MAX_LINHAS][MAX_COLUNAS], Config conf){
    char * nomeArquivo;
    printf("$ Entrada da Matriz\n");
    // Verifica a forma de entrada
    switch(conf.entradaMatriz){
        // Teclado
        case 1:
            ler_matriz_teclado( matriz, conf );
        break;
        // Arquivo
        case 2:
            printf("|\t   Digite o nome do arquivo:\n");
            printf("|\n|\t   > ");
            scanf("%s", &nomeArquivo);
            ler_matriz_arquivo( matriz, nomeArquivo, conf );
        break;
        // Aleatoriamente
        case 3:
            gerar_matriz_aleatoria( matriz, conf );
            imprimir_matriz( matriz, conf );
        break;
    }
}

/**
 * Recebe a lista de palavras através do método de entrada informado
 * 
 * @param   palavras    Lista de palavras a ser inscrita
 * @param   conf        Estrutura de configurações
*/
void ler_palavras(Palavra palavras[MAX_PALAVRAS], Config conf){
    // Verifica a forma de entrada
    switch(conf.entradaPalavras){
        // Teclado
        case 1:
        break;
        // Arquivo
        case 2:
        break;
        // Aleatoriamente
        case 3:
        break;
    }
}

/**
 * Exibe quais das palavras possuem o status de encontrado
 * 
 * @param   palavras    Lista de palavras
 * @param   conf        Estrutura de configurações
*/
void exibir_encontradas(Palavra palavras[MAX_PALAVRAS], Config conf){
    int i;
    printf("$ Palavras encontradas:\n");
    for(i = 0; i < conf.numPalavras; i++)
        if(palavras[i].encontrada)
            printf("\t   %s\n", palavras[i].valor);

    printf("$ Palavras nao encontradas:\n");
    for(i = 0; i < conf.numPalavras; i++)
        if(!palavras[i].encontrada)
            printf("\t   %s\n", palavras[i].valor);
}