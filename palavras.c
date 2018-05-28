/**
 * Contém funções relacionadas a operações
 * com a lista de arquivos
 * 
 * @author  Henrique Cunha
 * @info    RA  759023
*/

/**
 * Recebe a lista de palavras a partir de um arquivo
 * informado
 * 
 * @param   palavras        Lista de palavras
 * @param   nomeArquivo     Nome do arquivo
 * @param   cong            Estrutura de configurações
*/
void ler_palavras_arquivo(Palavra palavras[MAX_PALAVRAS], char * nomeArquivo, Config * conf){
    int i;
    FILE * arquivo;
    arquivo = fopen( nomeArquivo, "r" );
    fscanf(arquivo, "%d", &conf->numPalavras);
    fgetc(arquivo);
    for(i = 0; i < conf->numPalavras; i++){
        palavras[i].encontrada = 0;
        fscanf(arquivo, "%s", &palavras[i].valor);
    }
    fclose(arquivo);
} 

/**
 * Imprime a lista de palavras
 * 
 * @param   palavras    Lista de palavras
 * @param   conf        Estrutura de configurações
*/
void imprimir_palavras(Palavra palavras[MAX_PALAVRAS], Config conf){
    int i;
    for(i = 0; i < conf.numPalavras; i++)
        printf("|\t* %s\n", palavras[i].valor);        
}