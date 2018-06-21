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

/**
 * Atribui zeros na dimensão da matriz e 1 nas posicao sobressalentes
 *
 * @param   matriz      Matriz que sera preenchida
 * @param   Conf        Estrutura de configuracao
*/
void matriz_zerada(char matriz[][MAX_COLUNAS], Config conf) {
    int i, j; //contadores
    for (i = 0; i < conf.linhas; i++)
        for (j = 0; j < conf.colunas; j++)
            matriz[i][j] = '0';
    for(i = 0; i < MAX_LINHAS; i++)
        for(j = 0; j < MAX_COLUNAS; j++)
            if(matriz[i][j] != '0')
                matriz[i][j] = '1'; 
}

/**
 * Verifica se a posicao sorteada pode receber uma letra e verifica casos onde a colisao favorece o preenchimento de palavras
 *
 * @param   pos         Estrutura de posicoes 
 * @param   palavra     Vetor de palavras
 * @param   matriz      Matriz que sera preenchida
*/
int colisao(Posicao pos, char palavra[MAX_LINHAS], char matriz[][MAX_COLUNAS]) {
    int i, flag = 1;
    if(pos.orientacao == 0) {
        for(i = pos.col; i < pos.col + pos.tamanho; i++) {
            if(matriz[pos.lin][i] != palavra[i] && matriz[pos.lin][i] != '0') {
                flag = 0;
                break;
            }
        }
    } else if(pos.orientacao == 1) {
        for(i = pos.lin; i < pos.lin + pos.tamanho; i++) {
            if(matriz[i][pos.col] != palavra[i] && matriz[i][pos.col] != '0') {
                flag = 0;
                break;
            }
        }
    }
    return flag;
}

/**
 *  Coloca a palavra na matriz
 *
 * @param     pos         Estrutura de posições 
 * @param     palavra     Vetor de palavras
 * @param     matriz      Matriz que será preenchida
*/
void escrever_palavra(Posicao pos, char palavra[MAX_LINHAS], char matriz[][MAX_COLUNAS]) {
    int i, j = 0;
    printf("pos: %d %d\n", pos.lin, pos.col); 
    if(pos.orientacao == 0)
        for(int i = pos.col; i < pos.col + pos.tamanho; i++) {
            printf("%d %d %c\n", pos.lin, i, palavra[j]);
            matriz[pos.lin][i] = palavra[j];
            j++;
        }
    else if(pos.orientacao == 1) {
        int k = 0;
        for(int i = pos.lin; i < pos.lin + pos.tamanho; i++) {
            printf("%d %d %c\n", i, pos.col, palavra[k]);
            matriz[i][pos.col] = palavra[k];
            k++;
        }
    }
}

/**
 * Verifica a colisão e escreve as palavras na matriz
 * 
 * @param   palavra     Palavra a ser colocada na matriz
 * @param   matriz      Matriz de caracteres
 * @param   conf        Estrutura de configurações
*/
void encaixar_palavra(char palavra[], char matriz[][MAX_COLUNAS], Config conf) {
    Posicao pos = POS_VAZ;
    pos.orientacao = intervalo(0, 1);
    pos.tamanho = strlen(palavra);
    int i, j, flag = 0;
    for(i = 0; i < conf.linhas; i++){
        for(j = 0; j < conf.colunas; j++){
            pos.lin = i;
            pos.col = j; //aleatorio(0, colunas - 1);
            if(colisao(pos, palavra, matriz)){
                escrever_palavra(pos, palavra, matriz);
                flag = 1;
                break;
            }
        }
        if(flag) break;
    }
}
/**
 * Mostra a matriz para o usuario
 *
 * @param     matriz      Matriz que sera preenchida
 * @param     conf        Estrutura de configurações
*/
void exibe_matriz(char matriz[][MAX_COLUNAS], Config conf) {
    int i, j;
    for(i = 0; i < conf.linhas; i++) {
        for(j = 0; j < conf.colunas; j++)
            printf("%c", matriz[i][j]);
    printf("\n");
    }
}
/**
 * Recursao de todas as funcoes que geram uma matriz a partir de palavras da lista fornecida
 *
 * @param     matriz_zero      Matriz que sera preenchida com as palavras da listas
 * @param     conf             Estrutura de configurações
 * @param     palavras         Matriz de palavras palavras 
*/
void corrige_matriz(char matriz_zero[][MAX_COLUNAS], Config conf, char palavras[][MAX_COLUNAS]) {
    int i;
    matriz_zerada(matriz_zero, conf);
    for (i = 0; i < conf.numPalavras; i++)
        encaixar_palavra(palavras[i], matriz_zero, conf);
    exibe_matriz(matriz_zero, conf);
}

/**
 * Destaca a palavra em uma linha da direita para a esquerda
 *
 * @param     palavras         Lista que contém as palavras do caça-palavras
 * @param     mat              Matriz com as palavras a serem destacadas
 * @param     destaque         Matriz com as palavras destacadas
 * @param     i, j, k          Contadores
 * @param     achou            Ponteiro que armazena 1 caso a palavra seja encontrada
*/
void destaca_lin(char palavras[][MAX_COLUNAS], char mat[][MAX_COLUNAS], char destaque[][MAX_COLUNAS], int i, int j, int k, int *achou) {
    int l;
    if(palavras[i][1] == mat[j][k + 1]) { //Palavra na linha
        *achou = 1;
        for(l = 0; l < strlen(palavras[i]); l++)
            if(palavras[i][l] != mat[j][k + l]) 
                *achou = 0;
        if(*achou == 1)
            for(l = 0; l < strlen(palavras[i]); l++)
                destaque[j][k + l] = mat[j][k + l];
    }
}

/**
 * Destaca a palavra em uma coluna de cima para baixo
 *
 * @param     palavras         Lista que contém as palavras do caça-palavras
 * @param     mat              Matriz com as palavras a serem destacadas
 * @param     destaque         Matriz com as palavras destacadas
 * @param     i, j, k          Contadores
 * @param     achou            Ponteiro que armazena 1 caso a palavra seja encontrada
*/
void destaca_col(char palavras[][MAX_COLUNAS], char mat[][MAX_COLUNAS], char destaque[][MAX_COLUNAS], int i, int j, int k, int *achou) {
    int l;
    if(palavras[i][1] == mat[j + 1][k]) { //Palavra na coluna
        *achou = 1;
        for(l = 0; l < strlen(palavras[i]); l++)
            if(palavras[i][l] != mat[j + l][k]) 
                *achou = 0;
        if(*achou == 1)
            for(l = 0; l < strlen(palavras[i]); l++)
                destaque[j + l][k] = mat[j + l][k];
    }
}

/**
 * Destaca a palavra em uma linha da esquerda para a direita
 *
 * @param     palavras         Lista que contém as palavras do caça-palavras
 * @param     mat              Matriz com as palavras a serem destacadas
 * @param     destaque         Matriz com as palavras destacadas
 * @param     i, j, k          Contadores
 * @param     achou            Ponteiro que armazena 1 caso a palavra seja encontrada
*/
void destaca_lin_inv(char palavras[][MAX_COLUNAS], char mat[][MAX_COLUNAS], char destaque[][MAX_COLUNAS], int i, int j, int k, int *achou) {
    int l;
    if(palavras[i][1] == mat[j][k - 1]) { //Palavra invertida na linha
        *achou = 1;
        for(l = 0; l < strlen(palavras[i]); l++)
            if(palavras[i][l] != mat[j][k - l]) 
                *achou = 0;
        if(*achou == 1)
            for(l = 0; l < strlen(palavras[i]); l++)
                destaque[j][k - l] = mat[j][k - l];
    }
}

/**
 * Destaca a palavra em uma coluna de baixo para cima
 *
 * @param     palavras         Lista que contém as palavras do caça-palavras
 * @param     mat              Matriz com as palavras a serem destacadas
 * @param     destaque         Matriz com as palavras destacadas
 * @param     i, j, k          Contadores
 * @param     achou            Ponteiro que armazena 1 caso a palavra seja encontrada
*/
void destaca_col_inv(char palavras[][MAX_COLUNAS], char mat[][MAX_COLUNAS], char destaque[][MAX_COLUNAS], int i, int j, int k, int *achou) {
    int l;
    if(palavras[i][1] == mat[j - 1][k]) { //Palavra invertida na coluna
        *achou = 1;
        for(l = 0; l < strlen(palavras[i]); l++)
            if(palavras[i][l] != mat[j - l][k]) 
                *achou = 0;
        if(*achou == 1)
            for(l = 0; l < strlen(palavras[i]); l++)
                destaque[j - l][k] = mat[j - l][k];
    }
}

/**
 * Destaca a palavra em uma diagonal para baixo e para a direita
 *
 * @param     palavras         Lista que contém as palavras do caça-palavras
 * @param     mat              Matriz com as palavras a serem destacadas
 * @param     destaque         Matriz com as palavras destacadas
 * @param     i, j, k          Contadores
 * @param     achou            Ponteiro que armazena 1 caso a palavra seja encontrada
*/
void destaca_diag_prin(char palavras[][MAX_COLUNAS], char mat[][MAX_COLUNAS], char destaque[][MAX_COLUNAS], int i, int j, int k, int *achou) {
    int l;
    if(palavras[i][1] == mat[j + 1][k + 1]) { //Palavra na diagonal para baixo
        *achou = 1;
        for(l = 0; l < strlen(palavras[i]); l++)
            if(palavras[i][l] != mat[j + l][k + l])
                *achou = 0;
        if(*achou == 1)
            for(l = 0; l < strlen(palavras[i]); l++)
                destaque[j + l][k + l] = mat[j + l][k + l];
    }
}

/**
 * Destaca a palavra em uma diagonal para baixo e para a esquerda
 *
 * @param     palavras         Lista que contém as palavras do caça-palavras
 * @param     mat              Matriz com as palavras a serem destacadas
 * @param     destaque         Matriz com as palavras destacadas
 * @param     i, j, k          Contadores
 * @param     achou            Ponteiro que armazena 1 caso a palavra seja encontrada
*/
void destaca_diag_rev(char palavras[][MAX_COLUNAS], char mat[][MAX_COLUNAS], char destaque[][MAX_COLUNAS], int i, int j, int k, int *achou) {
    int l;
    if(palavras[i][1] == mat[j + 1][k - 1]) { //Palavra na diagonal invertida para baixo
        *achou = 1;
        for(l = 0; l < strlen(palavras[i]); l++)
            if(palavras[i][l] != mat[j + l][k - l])
                *achou = 0;
        if(*achou == 1)
            for(l = 0; l < strlen(palavras[i]); l++)
                destaque[j + l][k - l] = mat[j + l][k - l];
    }
}

/**
 * Destaca a palavra em uma diagonal para cima e para a direita
 *
 * @param     palavras         Lista que contém as palavras do caça-palavras
 * @param     mat              Matriz com as palavras a serem destacadas
 * @param     destaque         Matriz com as palavras destacadas
 * @param     i, j, k          Contadores
 * @param     achou            Ponteiro que armazena 1 caso a palavra seja encontrada
*/
void destaca_diag_prin_inv(char palavras[][MAX_COLUNAS], char mat[][MAX_COLUNAS], char destaque[][MAX_COLUNAS], int i, int j, int k, int *achou) {
    int l;
    if(palavras[i][1] == mat[j - 1][k + 1]) { //Palavra na diagonal para cima
        *achou = 1;
        for(l = 0; l < strlen(palavras[i]); l++)
            if(palavras[i][l] != mat[j - l][k + l])
                *achou = 0;
        if(*achou == 1)
            for(l = 0; l < strlen(palavras[i]); l++)
                destaque[j - l][k + l] = mat[j - l][k + l];
    }
}

/**
 * Destaca a palavra em uma diagonal para cima e para a esquerda
 *
 * @param     palavras         Lista que contém as palavras do caça-palavras
 * @param     mat              Matriz com as palavras a serem destacadas
 * @param     destaque         Matriz com as palavras destacadas
 * @param     i, j, k          Contadores
 * @param     achou            Ponteiro que armazena 1 caso a palavra seja encontrada
*/
void destaca_diag_rev_inv(char palavras[][MAX_COLUNAS], char mat[][MAX_COLUNAS], char destaque[][MAX_COLUNAS], int i, int j, int k, int *achou) {
    int l;
    if(palavras[i][1] == mat[j - 1][k - 1]) { //Palavra na diagonal invertida para cima
        *achou = 1;
        for(l = 0; l < strlen(palavras[i]); l++)
            if(palavras[i][l] != mat[j - l][k - l])
                *achou = 0;
        if(*achou == 1)
            for(l = 0; l < strlen(palavras[i]); l++)
                destaque[j - l][k - l] = mat[j - l][k - l];
    }
}

/**
 * Recursão das funções que destacam as palavras em uma matriz
 *
 * @param     palavras         Lista que contém as palavras do caça-palavras
 * @param     mat              Matriz com as palavras a serem destacadas
 * @param     destaque         Matriz com as palavras destacadas
 * @param     Conf             Estrutura de configurações
*/
void destaca_palavra(char mat[][MAX_COLUNAS], char destaque[][MAX_COLUNAS], char palavras[][MAX_COLUNAS], Config conf) {
    int i, j, k, achou;
    for(i = 0; i < conf.numPalavras; i++) {
        achou = 0;
        for(j = 0; j < conf.linhas; j++)
            for(k = 0; k < conf.colunas; k++)
                if(palavras[i][0] == mat[j][k]) {
                    destaca_lin(palavras, mat, destaque, i, j, k, &achou);
                    if(achou == 0)
                        destaca_col(palavras, mat, destaque, i, j, k, &achou);
                    if(achou == 0)
                        destaca_lin_inv(palavras, mat, destaque, i, j, k, &achou);
                    if(achou == 0)
                        destaca_col_inv(palavras, mat, destaque, i, j, k, &achou);
                    if(achou == 0)
                        destaca_diag_prin(palavras, mat, destaque, i, j, k, &achou);
                    if(achou == 0)
                        destaca_diag_rev(palavras, mat, destaque, i, j, k, &achou);
                    if(achou == 0)
                        destaca_diag_prin_inv(palavras, mat, destaque, i, j, k, &achou);
                    if(achou == 0)
                        destaca_diag_rev_inv(palavras, mat, destaque, i, j, k, &achou);
                }
    }
}

/**
 * Copia as palavras da estrutura Palavras para uma matriz
 * 
 * @param      matriz       Matriz que receberá as palavras
 * @param      palavras     Estrutura de palavras
 * @param      conf         Estrutura de configurações
*/
void matriz_de_palavras(char matriz[][MAX_COLUNAS], Palavra palavras[MAX_PALAVRAS], Config conf) {
    int i;
    for(i = 0; i < conf.numPalavras; i++)
        strcpy(matriz[i], palavras[i].valor);
}