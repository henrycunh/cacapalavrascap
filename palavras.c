int ler_palavras_de_arquivo(char * nome_arquivo){
    int contador = 0;
    FILE * arquivo;
    arquivo = fopen(nome_arquivo, "r");

    if(arquivo == NULL)
        return 0;

    while(!feof(arquivo)){
        palavras[contador].encontrado =
        palavras[contador].orientacao = 0;
        fscanf(arquivo, "%s", &palavras[contador].val);
        contador++;
    }
    
    quantidade_palavras = contador;
    
    fclose(arquivo);
    return 1;
}


void imprimir_palavras(){
    int i;
    for(i = 0; i < quantidade_palavras; i++)
        printf("%s\n", palavras[i].val);
}
