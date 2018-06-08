// Programa p18.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h> // necessário para time()

#define MAX_TAM 50
                          // Documentação função "random"
// Objetivo/valor de retorno:
// retornar um valor randomico que varia de valor randomico até randomico resto
// n
// Parâmetros:
//- int n: numero inteiro n
int Rrandom(int n) {
	return rand() % n;
}
                          // Documentação função "existe"
// Objetivo/valor de retorno:
  //se vetor[i] for igual a k (return 0 significa que o retorno à função é falso, portando n retorna)/ (return 1 significa q o retorno é verdade então executa a função dnv)
// Parâmetros:
  //-inteiro n
  //-vetor inteiro
  //- inteiro k  

int existe(int n, int vet[], int r) {
	int i;
  
	for (i = 0; i < n; i++)
		if (vet[i] == r)
			return 1;
	return 0;
}

int main(int args, char *arg[]) {
	int i, j, n, r;
	int vet[MAX_TAM], pos[MAX_TAM], v_ord[MAX_TAM];

	// Inicializar gerador de números aleatórios
	srand((unsigned)time(NULL));

	// Gerar o vetor inicial
	n = Rrandom(MAX_TAM) + 1; // tamanho do vetor
	i = 0;
	do {
		r = Rrandom(100) + 1;
		if (existe(i, vet, r) == 0) {
			vet[i] = r;
			i++;
		}
	} while (i < n);
	printf("Vetor inicial:\n");
	for (i = 0; i < n; i++)
		printf("%d ", vet[i]);
	printf("\n\n");

	// Determinar posicao no vetor ordenado
	for (i = 0; i < n; i++) {
		pos[i] = 0;
		for (j = 0; j < n; j++)
			if (vet[i] > vet[j])
				pos[i]++;
		v_ord[pos[i]] = vet[i];
	}

	// Exibir o vetor ordenado
	printf("Vetor ordenado:\n");
	for (i = 0; i < n; i++)
		printf("%d ", v_ord[i]);
	printf("\n\n");
	return 0;
}