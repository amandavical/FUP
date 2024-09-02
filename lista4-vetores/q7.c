#include <stdio.h>

#define MAX_TAMANHO 10

// Função para ordenar o vetor em ordem crescente
void ordenar_vetor(int vetor[], int tamanho) {
    int i, j, temp;

    // Algoritmo de ordenação por bolha (bubble sort)
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                // Troca os elementos de lugar
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }
}

int main() {
    int N, i;
    int vetor[MAX_TAMANHO];

    // Leitura do tamanho do vetor
    do {
        printf("Digite o número de elementos no vetor (1 a 10): ");
        scanf("%d", &N);
    } while (N < 1 || N > MAX_TAMANHO);

    // Leitura dos elementos do vetor
    printf("Digite os %d elementos do vetor:\n", N);
    for (i = 0; i < N; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Ordena o vetor
    ordenar_vetor(vetor, N);

    // Exibe o vetor ordenado
    printf("Vetor ordenado em ordem crescente:\n");
    for (i = 0; i < N; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
