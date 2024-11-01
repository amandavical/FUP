#include <stdio.h>

int main() {
    int N[20];
    int i, menor, posicao;

    // Leitura dos elementos
    printf("Digite 20 elementos para o vetor:\n");
    for (i = 0; i < 20; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", &N[i]);
    }

    // Inicialmente, assume-se que o menor valor é o primeiro elemento
    menor = N[0];
    posicao = 0;

    // Encontra o menor valor e sua posição
    for (i = 1; i < 20; i++) {
        if (N[i] < menor) {
            menor = N[i];
            posicao = i;
        }
    }

    // Exibe o menor valor e sua posição
    printf("O menor elemento de N é %d e sua posição dentro do vetor é %d.\n", menor, posicao);

    return 0;
}
