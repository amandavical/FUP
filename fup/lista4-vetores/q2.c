#include <stdio.h>

void trocar_impar_par() {
    int K[30];
    int i;

    // Leitura dos elementos
    printf("Digite 30 elementos para o vetor:\n");
    for (i = 0; i < 30; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &K[i]);
    }

    // Troca dos elementos de ordem ímpar com os de ordem par
    for (i = 1; i < 30; i += 2) {
        int temp = K[i];
        K[i] = K[i - 1];
        K[i - 1] = temp;
    }

    // Exibe o vetor após a troca
    printf("Vetor após a troca:\n");p
    for (i = 0; i < 30; i++) {
        printf("%d ", K[i]);
    }
    printf("\n");
}

int main() {
    trocar_impar_par();
    return 0;
}
