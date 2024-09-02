#include <stdio.h>

void inverter_vetor() {
    int vetor[20];
    int i, temp;

    // Leitura dos elementos do vetor
    printf("Digite 20 elementos para o vetor:\n");
    for (i = 0; i < 20; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &vetor[i]);
    }

    // Exibe o vetor original
    printf("Vetor original:\n");
    for (i = 0; i < 20; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    // Troca os elementos
    for (i = 0; i < 10; i++) {
        temp = vetor[i];
        vetor[i] = vetor[19 - i];
        vetor[19 - i] = temp;
    }

    // Exibe o vetor após a troca
    printf("Vetor após a troca:\n");
    for (i = 0; i < 20; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    inverter_vetor();
    return 0;
}
