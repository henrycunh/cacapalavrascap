/**
 * Define funções de comunicação entre a aplicação e
 * o usuário.
 */

/* Recebe as opções utilizadas ao decorrer da aplicação */
void definir_opcoes(){
    printf("\t$ Configurar de Opcoes\n");
    // Tamanho da Matriz
    printf("\t\t+ Digite as dimensoes da matriz de caracteres\n");
    printf("\t\t.\t Largura: ");
    scanf("%d", &W);
    printf("\t\t.\t Altura : ");
    scanf("%d", &H);
    // Obtenção da matriz
    printf("\t\t+ Obtencao da matriz\n");
    printf("\t\t.\t1) Por meio de entrada do usuario\n");
    printf("\t\t.\t2) Por meio de um arquivo\n");
    // printf("\t\t.\t3) Gerado aleatoriamente\n\t\t.\n");
    printf("\t\t.\tOpcao: ");
    scanf("%d", &matriz_opt);
    // Obtenção da matriz
    printf("\t\t+ Obtencao da lista de palavras\n");
    printf("\t\t.\t1) Por meio de entrada do usuario\n");
    printf("\t\t.\t2) Por meio de um arquivo\n");
    // printf("\t\t.\t3) Gerado aleatoriamente\n\t\t.\n");
    printf("\t\t\\\tOpcao: ");
    scanf("%d", &lista_opt);
}

/**
 * Recebe a matriz de caracteres a partir dos dados
 * digitados pelo usuário 
*/
void receber_matriz_teclado(){
    int linha, coluna;
    printf("\t$ Matriz de Caracteres\n");
    printf("\t\t+ Digite a matriz, linha apos linha\n");
    for(linha = 0; linha < H; linha++){
        printf("\t\t# ");
        for(coluna = 0; coluna < W;){
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
 * Recebe o nome do arquivo, e carrega a matriz
 * a partir dos dados contidos nele
*/
void receber_matriz_arquivo(){
    char nome_arquivo[256];

    printf("\t$ Matriz de Caracteres\n");
    printf("\t\t+ Digite o nome do arquivo\n");
    printf("\t\t# ");
    scanf("%s", &nome_arquivo);

    ler_matriz_de_arquivo( nome_arquivo );
}

void receber_lista_teclado(){
    int i = 0;
    printf("\t$ Lista de palavras\n");
    printf("\t\t+ Digite as palavras, digite um . para sair\n");
    printf("\t\t# ");
    while(1){
        char palavra[64];
        scanf("%s", &palavra);
        if(palavra[0] != '.'){
            palavras[i].encontrado =
            palavras[i].orientacao = 0;
            strcpy(palavras[i].val, palavra);
            i++;
        } else 
            break;
        printf("\t\t# ");
    }
    quantidade_palavras = i;
}


void receber_lista_arquivo(){
    char nome_arquivo[256];

    printf("\t$ Lista de palavras\n");
    printf("\t\t+ Digite o nome do arquivo\n");
    printf("\t\t# ");
    scanf("%s", &nome_arquivo);

    ler_palavras_de_arquivo( nome_arquivo );
}


void receber_lista_aleatoria(){

}


void dispor_resultado(){
    int i;
    printf("\t$ Palavras encontradas\n");
    for(i = 0; i < quantidade_palavras; i++)
        if(palavras[i].encontrado)
            printf("\t\t+ %s\n", palavras[i].val);
    printf("\t$ Palavras nao encontradas\n");
    for(i = 0; i < quantidade_palavras; i++)
        if(!palavras[i].encontrado)
            printf("\t\t+ %s\n", palavras[i].val);
}