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
void verificar_palavras(
    char matriz[MAX_LINHAS][MAX_COLUNAS],
    Palavra palavras[MAX_PALAVRAS],
    Config conf){
    
}

/**
 * Escreve na matriz recebida dados de um arquivo
 * 
 * @param   matriz         Matriz de caracteres
 * @param   nomeArquivo    Nome do arquivo a ser lido
 * @param   conf           Estrutura de configurações 
*/
void ler_matriz_arquivo(char matriz[MAX_LINHAS][MAX_COLUNAS], char * nomeArquivo, Config conf){
}

/**
 * Imprime uma matriz de caracteres
 * 
 * @param   matriz      Matriz de caracteres
 * @param   conf        Estrutura de configurações
*/
void imprimir_matriz(char matriz[MAX_LINHAS][MAX_COLUNAS], Config conf){
    int linha, coluna;
    for (linha = 0; linha < conf.linhas; linha++)
        for (coluna = 0; coluna < conf.colunas; coluna++)
            printf("%3c%c", matriz[linha][coluna], (coluna == conf.colunas - 1 ? '\n' : ' ') );
}