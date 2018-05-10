/**
 * Lê o arquivo e escreve as informações na
 * matriz de caracteres
 * 
 * @param nome_arquivo  Nome do arquivo a ser lido
 * @return              Boolean indicando se foi bem sucedido
*/
int ler_matriz_de_arquivo(char * nome_arquivo){
    int linha, coluna;
    FILE * arquivo;
    // Abre o arquivo
    arquivo = fopen(nome_arquivo, "r");
    // Verifica se o arquivo foi aberto com sucesso
    if(arquivo == NULL)
        return 0; // Se não foi, retorna falso e encerra a função

    // Percorre o arquivo char a char
    for(linha = 0; linha < H - 1;)
        for(coluna = 0; coluna < W;){
            char atual;
            // Lê o char
            fscanf(arquivo, "%c", &atual);
            // Verifica se é de fato uma letra
            if(atual != ' ' && atual != '\n'){
                matriz[linha][coluna] = atual; // Atribue à matriz
                coluna++; // Aumenta a contagem
            } 
            // Verifica se é uma quebra de linha
            else if(atual == '\n')
                linha++; 
        }
    // Fecha o arquivo
    fclose(arquivo); 
    // Retorna true
    return 1;
}


void verificar_palavras(){
    int  linha, coluna, i, j, acc = 0;
    char linhas     [W * H], linhas_reversas    [W * H],
         colunas    [W * H], colunas_reversas   [W * H],
         diagonais  [W * H], diagonais_reversas [W * H];
    
    // Linhas
    for(linha = 0; linha < H; linha++)
        for(coluna = 0; coluna < W; coluna++)
            linhas[acc++] = matriz[linha][coluna];
    linhas[acc] = '\0';
    for(i = acc - 1, j = 0; i >= 0; i--, j++)
        linhas_reversas[j] = linhas[i];
    linhas_reversas[acc] = '\0';
    acc = 0;
    // Colunas
    for(coluna = 0; coluna < W; coluna++)
        for(linha = 0; linha < H; linha++)
            colunas[acc++] = matriz[linha][coluna];
    colunas[acc] = '\0';
    for(i = acc - 1, j = 0; i >= 0; i--, j++)
        colunas_reversas[j] = colunas[i];
    colunas_reversas[acc] = '\0';
    acc = 0;
    // Diagonais
    for(coluna = -(H - 1); coluna < W + (H - 1); coluna++)
        for(linha = 0; linha < H; linha++)
            if(coluna + linha >= 0 && coluna + linha < W)
                diagonais[acc++] = matriz[linha][coluna + i];
    diagonais[acc] = '\0';
    for(i = acc - 1, j = 0; i >= 0; i--, j++)
        diagonais_reversas[j] = diagonais[i];
    diagonais_reversas[acc] = '\0';

    // Checar palavra por palavra em cada uma das orientações
    for(i = 0; i < quantidade_palavras; i++){
        if(strstr(linhas, palavras[i].val) != NULL){
            palavras[i].encontrado = 
            palavras[i].orientacao = 1;
        } else if ( strstr(linhas_reversas, palavras[i].val) != NULL ){
            palavras[i].encontrado = 1;
            palavras[i].orientacao = 2;
        } else if ( strstr(colunas, palavras[i].val) != NULL ){
            palavras[i].encontrado = 1;
            palavras[i].orientacao = 3;
        } else if ( strstr(colunas_reversas, palavras[i].val) != NULL ){
            palavras[i].encontrado = 1;
            palavras[i].orientacao = 4;
        } else if ( strstr(diagonais, palavras[i].val) != NULL ){
            palavras[i].encontrado = 1;
            palavras[i].orientacao = 5;
        } else if ( strstr(diagonais_reversas, palavras[i].val) != NULL ){
            palavras[i].encontrado = 1;
            palavras[i].orientacao = 6;
        }
    }
}

/**
 * Imprime a matriz de caracteres
*/
void imprimir_matriz(){
    int linha, coluna;
    for(linha = 0; linha < H; linha++)
        for(coluna = 0; coluna < W; coluna++)
            printf("%c%c", matriz[linha][coluna], coluna == W - 1 ? '\n' : ' ');
}
