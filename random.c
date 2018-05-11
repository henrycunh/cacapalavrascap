/**
 * Retorna um número aleatório no intervalo [min, max]
 * 
 * @param min       Número mínimo
 * @param max       Número máximo
 * @return          Número aleatório gerado
*/
int intervalo(int min, int max){
    srand( time( NULL ) );
    return min + (rand() % (max - min + 1));
}

void gerar_matriz_aleatoria(){}

void gerar_lista_aleatoria(){}