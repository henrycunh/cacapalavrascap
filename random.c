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

