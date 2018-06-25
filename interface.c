/**
 * Contém funções usadas na interação
 * programa-usuário, provendo uma interface gráfica
 * entre as operações do programa e a entrada de 
 * dados fornecida pelo usuário
 * 
 * @author  Henrique Cunha
 * @info    RA  759023 
*/

/**
 * Interage com o usuário para extrair as formas
 * de entrada e as configurações respectivas 
 * 
 * @param   conf    Estrutura de configuração a ser inscrita
*/
void alterar_opcoes(Config * conf){
    printf("*\tCONFIGURACOES GERAIS\n|\n");
    // Entrada da Matriz
    printf("|\tForma de entrada da Matriz:\n");
    printf("|\t   [1] A partir do teclado\n");
    printf("|\t   [2] A partir de um arquivo\n");
    printf("|\t   [3] Gerado aleatoriamente\n");
    printf("|\n|\t   > ");
    scanf("%d", &conf->entradaMatriz);
    printf("|\n");
    // Receber dimensões
    if(conf->entradaMatriz == 1 || conf->entradaMatriz == 3){
        printf("|\tDimensoes da Matriz:\n");
        printf("|\t    Linhas: ");
        scanf("%d", &conf->linhas);
        printf("|\t   Colunas: ");
        scanf("%d", &conf->colunas);
    }
    if(conf->debug)
        printf("Ent. Matriz: %d, Linhas: %d, Colunas: %d\n", conf->entradaMatriz, conf->linhas, conf->colunas);
    // Entrada das Palavras
    printf("|\n|\tForma de entrada das Palavras:\n");
    printf("|\t   [1] A partir do teclado\n");
    printf("|\t   [2] A partir de um arquivo\n");
    printf("|\t   [3] Gerado aleatoriamente\n|\n");
    printf("|\t   > ");
    scanf("%d", &conf->entradaPalavras);
    printf("|\n");
    // Receber quantidade de palavras
    if(conf->entradaPalavras == 1 || conf->entradaPalavras == 3){
        printf("|\tQuantidade de palavras:\n");
        printf("|\t  > ");
        scanf("%d", &conf->numPalavras);
    } else 
        printf("\n");
    if(conf->debug)
        printf("Ent. Palavras: %d, Qtd: %d\n", conf->entradaPalavras, conf->numPalavras);
    printf("*\n\n");
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
            if(atual != ' ' && atual != '\n'){
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
void ler_matriz(char matriz[MAX_LINHAS][MAX_COLUNAS], Config * conf){
    char nomeArquivo[256];
    if(!conf->def){
        printf("*\tENTRADA DA MATRIZ\n");
        // Verifica a forma de entrada
        switch(conf->entradaMatriz){
            // Teclado
            case 1:
                ler_matriz_teclado( matriz, *conf );
            break;
            // Arquivo
            case 2:
                printf("|\n|\t   Digite o nome do arquivo:\n");
                printf("|\t   > ");
                scanf("%s", &nomeArquivo);
                ler_matriz_arquivo( matriz, nomeArquivo, conf );
            break;
            // Aleatoriamente
            case 3:
                gerar_matriz_aleatoria( matriz, *conf );
                imprimir_matriz( matriz, *conf );
            break;
        }
        printf("*\n\n");
    }
    else 
        ler_matriz_arquivo( matriz, conf->matrizDef, conf );
}

/**
 * Recebe a lista de palavras a partir de entrada do teclado
 * 
 * @param   palavras    Lista de palavras
 * @param   conf        Estrutura de configurações
*/
void ler_palavras_teclado(Palavra palavras[MAX_PALAVRAS], Config conf){
    int i;
    printf("|\tDigite as palavras da lista:\n");
    for(i = 0; i < conf.numPalavras; i++){
        printf("|\t   > ");
        scanf("%s", &palavras[i].valor);
    }
}

/**
 * Recebe a lista de palavras através do método de entrada informado
 * 
 * @param   palavras    Lista de palavras a ser inscrita
 * @param   conf        Estrutura de configurações
*/
void ler_palavras(Palavra palavras[MAX_PALAVRAS], char matriz[MAX_LINHAS][MAX_COLUNAS], Config * conf){
    char nomeArquivo[256];
    if(!conf->def){
        printf("*\tENTRADA DA LISTA DE PALAVRAS\n");
        // Verifica a forma de entrada
        switch(conf->entradaPalavras){
            // Teclado
            case 1:
                ler_palavras_teclado( palavras, *conf );
            break;
            // Arquivo
            case 2:
                printf("|\n|\t   Digite o nome do arquivo:\n");
                printf("|\t   > ");
                scanf("%s", &nomeArquivo);
                ler_palavras_arquivo( palavras, nomeArquivo, conf );
                if(conf->debug){
                    imprimir_palavras( palavras, *conf );
                    printf("%d\n", conf->numPalavras );
                }
            break;
            // Aleatoriamente
            case 3:
                gerar_palavras_aleatorias( palavras, matriz, *conf );
                imprimir_palavras( palavras, *conf );
            break;
        }
        printf("*\n\n");
    }
    else
        ler_palavras_arquivo( palavras, conf->palavrasDef, conf );
}

/**
 * Exibe quais das palavras possuem o status de encontrado
 * 
 * @param   palavras    Lista de palavras
 * @param   conf        Estrutura de configurações
*/
void exibir_encontradas(Palavra palavras[MAX_PALAVRAS], Config conf, char matriz[][MAX_COLUNAS], char matriz_palavras[][MAX_COLUNAS], char matriz_destacada[][MAX_COLUNAS], char matriz_zero[][MAX_COLUNAS]){
    int i,
        validas = 0,
        numNaoEncontradas = 0,
        opcao,
        qtdPalavras;
    double palavrasEncontradas;
    char naoEncontradas[MAX_PALAVRAS][MAX_COMP_PALAVRA],
         palavrasExtras[MAX_PALAVRAS][MAX_COMP_PALAVRA];

    // Itera pelas palavras encontradas
    printf("*\tPALAVRAS ENCONTRADAS\n");
    for(i = 0; i < conf.numPalavras; i++)
        if(palavras[i].encontrada) {
            printf("|\t   %s\n", palavras[i].valor);
            validas++;
        }
    printf("*\n\n");

    // Itera pelas palavras não encontradas
    printf("*\tPALAVRAS NAO ENCONTRADAS\n");
    for(i = 0; i < conf.numPalavras; i++)
        if(!palavras[i].encontrada){
            printf("|\t   %s\n", palavras[i].valor);
            strcpy(naoEncontradas[numNaoEncontradas++], palavras[i].valor);
        }
    printf("*\n\n");
    
    // Estatísticas
    palavrasEncontradas = ((double) validas / (double) conf.numPalavras) * 100.0;
    printf("*\tESTATISTICAS\n");
    printf("|\t   %.2lf%% das palavras foram encontradas.\n*\n", palavrasEncontradas);
    matriz_de_palavras(matriz_palavras, palavras, conf);

    printf("*\tDESTACAR MATRIZ\n");
    printf("|\t   Deseja destacar as palavras encontradas?\n");
    printf("|\t      [1] Sim\n");
    printf("|\t      [2] Nao\n");
    printf("|\t   > ");
    scanf("%d", &opcao);
    if(opcao == 1)
        destaca_palavra(matriz, matriz_zero, matriz_palavras, conf);
    printf("*\n\n");
    
    printf("*\tCOMPLETAR MATRIZ\n");
    printf("|\t   Inserir as palavras nao encontradas na matriz?\n");
    printf("|\t      [1] Sim\n");
    printf("|\t      [2] Nao\n");
    printf("|\t   > ");
    scanf("%d", &opcao);
    if(opcao == 1)
        corrige_matriz(matriz_zero, conf, naoEncontradas);
    printf("|\n|\t   Deseja adicionar mais palavras a matriz?\n");
    printf("|\t      [1] Sim\n");
    printf("|\t      [2] Nao\n");
    printf("|\t   > ");
    scanf("%d", &opcao);
    if(opcao == 1){
        printf("|\n|\t   Quantas palavras deseja adicionar?\n");
        printf("|\t   > ");
        scanf("%d", &qtdPalavras);
        printf("|\n|\t   Digite as palavras a serem inseridas\n");
        for(i = 0; i < qtdPalavras; i++){
            printf("|\t   > ");
            scanf("%s", &palavrasExtras[i]);
        }
        corrige_matriz(matriz_zero, conf, palavrasExtras);
    }
    printf("*\n\n");


}
