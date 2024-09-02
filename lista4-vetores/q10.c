#include <stdio.h>

#define TAMANHO 15

int main() {
    int vetor[TAMANHO];
    int i;
    int maior;

    // Leitura dos elementos do vetor
    printf("Digite 15 elementos para o vetor:\n");
    for (i = 0; i < TAMANHO; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Encontrar o maior valor no vetor
    maior = vetor[0];
    for (i = 1; i < TAMANHO; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];c
        }
    }

    // Multiplicar todos os elementos pelo maior valor
    for (i = 0; i < TAMANHO; i++) {
        vetor[i] *= maior;
    }

    // Exibir o vetor após a multiplicação
    printf("Vetor após a multiplicação pelo maior valor (%d):\n", maior);
    for (i = 0; i < TAMANHO; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    return 0;
}
