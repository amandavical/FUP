#include <stdio.h>
#include <stdbool.h>

#define TAM_K 15
#define TAM_P 15  // Tamanho máximo do vetor P, já que pode conter até todos os números de K

// Função para verificar se um número é primo
bool eh_primo(int num) {
    if (num <= 1) return false;
    if (num == 2) return true; // O número 2 é o único número primo par
    if (num % 2 == 0) return false; // Números pares maiores que 2 não são primos
    for (int i = 3; i * i <= num; i += 2) {
        if (num % i == 0) return false;
    }
    return true;
}

void encontrar_numeros_primos() {
    int K[TAM_K];
    int P[TAM_P];
    int i, j = 0;

    // Leitura dos valores do vetor K
    printf("Digite 15 valores inteiros não negativos para o vetor K:\n");
    for (i = 0; i < TAM_K; i++) {
        printf("Valor %d: ", i + 1);
        scanf("%d", &K[i]);
    }

    // Encontra números primos e armazena no vetor P
    for (i = 0; i < TAM_K; i++) {
        if (eh_primo(K[i])) {
            P[j] = K[i];
            j++;
        }
    }

    // Exibe o vetor P
    printf("Vetor P (números primos):\n");
    if (j == 0) {
        printf("Nenhum número primo encontrado.\n");
    } else {
        for (i = 0; i < j; i++) {
            printf("%d ", P[i]);
        }
        printf("\n");
    }
}

int main() {
    encontrar_numeros_primos();
    return 0;
}
