/**
 * Contém as funções relacionadas a operações
 * com a matriz de caracteres
 * 
 * @author  Henrique Cunha
 * @info    RA  759023
 * 
 * @author Jonathan Santos
 * @info    RA  759052
 * 
 * @author  Rodrigo Lemos
 * @info    RA 759020
*/

/** 
 * Recebe uma matriz e uma lista de palavras
 * e altera o status de encontrado das palavras
 * caso elas existam em alguma orientação na matriz
 * de caracteres
 * 
 * @param   matriz      Matriz de caracteres
 * @param   palavras    Lista de palavras
 * @param   conf        Estrutura de configuração
*/
void verificar_palavras(char matriz[MAX_LINHAS][MAX_COLUNAS],
                        Palavra palavras[MAX_PALAVRAS],
                        Config conf){
    // Inicializações
    int linha, coluna,                                  // Contadores de posição 
        i, j, acc = 0,                                  // Contadores de propósito geral
        size = conf.linhas * conf.colunas * 2;          // Tamanho dos vetores
    char linhas     [size], linhasReversas    [size],  // Armazena as linhas
         colunas    [size], colunasReversas   [size],  // Armazena as colunas
         diagonais  [size], diagonaisReversas [size];  // Armazena as diagonais
    
    // Linhas
    for(linha = 0; linha < conf.linhas; linha++)
        for(coluna = 0; coluna < conf.colunas; coluna++){
            linhas[acc++] = matriz[linha][coluna];
            if(coluna == conf.colunas - 1)
                linhas[acc++] = '\n';
        }
    
    linhas[acc] = '\0';
    
    for(i = acc - 1, j = 0; i >= 0; i--, j++)
        linhasReversas[j] = linhas[i];
    linhasReversas[acc] = '\0';
    acc = 0;

    // Colunas
    for(coluna = 0; coluna < conf.colunas; coluna++)
        for(linha = 0; linha < conf.linhas; linha++){
            colunas[acc++] = matriz[linha][coluna];
            if(linha == conf.linhas - 1) 
                colunas[acc++] = '\n';
        }
    
    colunas[acc] = '\0';
    
    for(i = acc - 1, j = 0; i >= 0; i--, j++)
        colunasReversas[j] = colunas[i];
    colunasReversas[acc] = '\0';
    acc = 0;
    
    // Diagonais
    for(coluna = -(conf.linhas - 1); coluna < conf.colunas + (conf.linhas - 1); coluna++)
        for(linha = 0; linha < conf.linhas; linha++)
            if(coluna + linha >= 0 && coluna + linha < conf.colunas){
                diagonais[acc++] = matriz[linha][coluna + i];
                if(linha == conf.linhas - 1)
                    diagonais[acc++] = '\n';
            }
    
    diagonais[acc] = '\0';
    
    for(i = acc - 1, j = 0; i >= 0; i--, j++)
        diagonaisReversas[j] = diagonais[i];
    diagonaisReversas[acc] = '\0';

    // Checar palavra por palavra em cada uma das orientações
    for(i = 0; i < conf.numPalavras; i++)
        palavras[i].encontrada =
            strstr(linhas           , palavras[i].valor) != NULL ||
            strstr(linhasReversas   , palavras[i].valor) != NULL ||
            strstr(colunas          , palavras[i].valor) != NULL ||
            strstr(colunasReversas  , palavras[i].valor) != NULL ||
            strstr(diagonais        , palavras[i].valor) != NULL ||
            strstr(diagonaisReversas, palavras[i].valor) != NULL;
}

/**
 * Escreve na matriz recebida dados de um arquivo
 * 
 * @param   matriz         Matriz de caracteres
 * @param   nomeArquivo    Nome do arquivo a ser lido
 * @param   conf           Estrutura de configurações 
*/
void ler_matriz_arquivo(char matriz[MAX_LINHAS][MAX_COLUNAS], char * nomeArquivo, Config * conf){
    FILE * arquivo;
    int linha, coluna;
    // Abre o arquivo
    arquivo = fopen( nomeArquivo, "r" );
    // Pega as linhas e colunas
    fscanf( arquivo, "%d", &conf->linhas );
    fscanf( arquivo, "%d", &conf->colunas );
    // Ignora a quebra de linha após os números
    fgetc(arquivo);
    // Percorre os caracteres
    for(linha = 0; linha < conf->linhas; linha++){
        for(coluna = 0; coluna < conf->colunas;){
            // Pega o caracter atual
            char atual;
            atual = fgetc( arquivo );
            // Verifica se o atual é diferente de espaço
            if(atual != ' '){
                // Atribue à matriz
                matriz[linha][coluna] = atual;
                coluna++;
            }
        }
        // Ignora o caracter de quebra de linha
        fgetc( arquivo );
    }
    // Fecha o arquivo
    fclose(arquivo);
}

/**
 * Imprime uma matriz de caracteres
 * 
 * @param   matriz      Matriz de caracteres
 * @param   conf        Estrutura de configurações
*/
void imprimir_matriz(char matriz[MAX_LINHAS][MAX_COLUNAS], Config conf){
    int linha, coluna;
    for (linha = 0; linha < conf.linhas; linha++){
        printf("|\t");
        for (coluna = 0; coluna < conf.colunas; coluna++)
            printf("%3c%c", matriz[linha][coluna], (coluna == conf.colunas - 1 ? '\n' : ' ') );
    }
}