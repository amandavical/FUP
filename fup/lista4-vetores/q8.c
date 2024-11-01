#include <stdio.h>
#include <math.h>  // Necessário para a função pow()

#define TAMANHO 20

int main() {
    int A[TAMANHO];
    int i;
    int S = 0;

    // Leitura dos elementos do vetor A
    printf("Digite 20 elementos para o vetor A:\n");
    for (i = 0; i < TAMANHO; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    // Cálculo de S conforme a expressão
    for (i = 0; i < TAMANHO / 2; i++) {
        S += pow(A[i] - A[TAMANHO - 1 - i], 2);
    }

    // Exibição do valor de S
    printf("O valor de S é: %d\n", S);

    return 0;
}
