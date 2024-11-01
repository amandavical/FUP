#include <stdio.h>

#define TAMANHO 10

int main() {
    int A[TAMANHO], B[TAMANHO], C[TAMANHO];
    int i;

    // Leitura do vetor A
    printf("Digite 10 elementos para o vetor A:\n");
    for (i = 0; i < TAMANHO; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &A[i]);
    }

    // Leitura do vetor B
    printf("Digite 10 elementos para o vetor B:\n");
    for (i = 0; i < TAMANHO; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &B[i]);
    }

    // Subtrai o primeiro elemento de A do último de B, o segundo elemento de A do penúltimo de B, e assim por diante
    for (i = 0; i < TAMANHO; i++) {
        C[i] = A[i] - B[TAMANHO - 1 - i];
    }

    // Exibe o vetor C
    printf("Vetor C (resultados das subtrações):\n");
    for (i = 0; i < TAMANHO; i++) {
        printf("%d ", C[i]);
    }
    printf("\n");

    return 0;
}
