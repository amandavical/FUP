#include <stdio.h>

int encontrar_segmento_soma_maxima(int vetor[], int tamanho) {
    int max_atual = vetor[0];
    int max_global = vetor[0];

    for (int i = 1; i < tamanho; i++) {
        max_atual = (vetor[i] > max_atual + vetor[i]) ? vetor[i] : (max_atual + vetor[i]);
        if (max_atual > max_global) {
            max_global = max_atual;
        }
    }

    return max_global;
}

int main() {
    int n;

    // Leitura do número de elementos
    printf("Digite o número de elementos da sequência: ");
    scanf("%d", &n);

    // Verifica se o número de elementos é positivo
    if (n <= 0) {
        printf("Número de elementos deve ser positivo.\n");
        return 1;
    }

    int vetor[n];

    // Leitura dos elementos da sequência
    printf("Digite os %d números inteiros:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Encontrar e exibir a soma máxima do segmento
    int soma_maxima = encontrar_segmento_soma_maxima(vetor, n);
    printf("A soma do segmento de soma máxima é %d\n", soma_maxima);

    return 0;
}
