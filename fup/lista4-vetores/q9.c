#include <stdio.h>

#define TAMANHO 15

int main() {
    int vetor[TAMANHO];
    int i;
    int maior, menor;
    int posicao_maior, posicao_menor;

    // Leitura dos elementos do vetor
    printf("Digite 15 elementos para o vetor:\n");
    for (i = 0; i < TAMANHO; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Inicialização dos valores de maior e menor
    maior = vetor[0];
    menor = vetor[0];
    posicao_maior = 0;
    posicao_menor = 0;

    // Percorre o vetor para encontrar o maior e o menor elementos
    for (i = 1; i < TAMANHO; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
            posicao_maior = i;
        }
        if (vetor[i] < menor) {
            menor = vetor[i];
            posicao_menor = i;
        }
    }

    // Exibição dos resultados
    printf("Maior elemento: %d\n", maior);
    printf("Posição do maior elemento: %d\n", posicao_maior);
    printf("Menor elemento: %d\n", menor);
    printf("Posição do menor elemento: %d\n", posicao_menor);

    return 0;
}
