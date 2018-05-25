/**
 * Inicializa as capacidades de aleatoriedade
*/
void inicializar_aleatoriedade(){
    srand( time( NULL ) );
}

/**
 * Retorna um valor aleatorio no intervalo dado
 * 
 * @param   min     Valor mínimo do intervalo
 * @param   max     Valor máximo do intervalo
 * @returns         Valor aleatorio no intervalo
*/
int intervalo(int min, int max){
    // Seeding aleatório usando o timestamp atual
    return min + (rand() % (max - min));
}

/**
 * Gera uma matriz de caracteres aleatoria
 * 
 * @param   matriz  Matriz de caracteres a ser inscrita
*/
void gerar_matriz_aleatoria(char matriz[MAX_LINHAS][MAX_COLUNAS], Config conf){
    int linha, coluna;
    //Gerador de matriz aleatória
    for (linha = 0; linha < conf.linhas; linha++)
        for (coluna = 0; coluna < conf.colunas; coluna++)
            matriz[linha][coluna] = 'A' + intervalo(0, 25);
}   

/**
 * Gera uma lista de palavras aleatórias a partir da
 * quantidade de palavras e da matriz de caracteres
 * fornecida
 * 
 * @param   palavras        Lista de palavras a ser inscrita
 * @param   matriz          Matriz de caracteres a ser usada como referência
 * @param   conf            Estrutura de configuração
 * @param   num_palavras    Número de palavras
*/
void gerar_palavras_aleatorias(
    Palavra palavras[MAX_PALAVRAS],
    char matriz[MAX_LINHAS][MAX_COLUNAS],
    Config conf){    

    // Implementação
    int i; 
    for (i = 0; i < conf.numPalavras; i++){
        int j, horizontal, locus, posI, compr, acc;
        // Palavra atual
        char palavra[MAX_COMP_PALAVRA];
        
        // Escolhe orientação
        horizontal = intervalo(0, 1); 

        // Aleatoriza posições (linhas/colunas)
        locus = intervalo(0, ( horizontal ? conf.linhas : conf.colunas));
        posI  = intervalo(0, (!horizontal ? conf.linhas : conf.colunas));
        compr = intervalo(1, (!horizontal ? conf.linhas : conf.colunas) - posI - 1);

        printf("%d %d %d %d\n", horizontal, locus, posI, compr);

        // Buscar caracteres da matriz
        for (j = posI; j <= posI + compr - 1; j++, acc++){
            // if(horizontal) 
            //     palavra[acc] = matriz[locus][j];
            // else
            //     palavra[acc] = matriz[j][locus];
            printf("%d %d\n", locus, j);
            // if(horizontal) 
            //     printf("%c", matriz[locus][j]);
            // else
            //     printf("%c", matriz[j][locus]);
            // printf("%c", matriz[acc]);
        }
        printf("\n-\n");
                            
        // palavra[acc] = '\0';

        // Inscreve na lista de palavras
        // Palavra atual = { .encontrada = 0 };
        // for(j = 0; j < acc; j++)
        //     atual.valor[j] = palavra[j];
        // palavras[i] = atual;
    }

}