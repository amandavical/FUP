#include <stdio.h>

#define MAX_SIZE 100  // Tamanho máximo da sequência

// Função para verificar se um número já está no vetor de contagem
int encontrar_indice(float arr[], int n, float num) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == num) {
            return i;
        }
    }
    return -1; // Retorna -1 se o número não for encontrado
}

int main() {
    int n;
    float numeros[MAX_SIZE];
    float contagem[MAX_SIZE];
    int ocorrencias[MAX_SIZE];
    int i, j;

    // Leitura do número de elementos
    printf("Digite o número de elementos da sequência (máximo %d): ", MAX_SIZE);
    scanf("%d", &n);

    // Verifica se o número de elementos não excede o tamanho máximo
    if (n > MAX_SIZE) {
        printf("Número de elementos excede o limite máximo de %d.\n", MAX_SIZE);
        return 1;
    }

    // Leitura da sequência de números reais
    printf("Digite os %d números reais:\n", n);
    for (i = 0; i < n; i++) {
        printf("Número %d: ", i + 1);
        scanf("%f", &numeros[i]);
    }

    // Inicializa o vetor de contagem
    for (i = 0; i < MAX_SIZE; i++) {
        contagem[i] = 0;
        ocorrencias[i] = 0;
    }

    // Contagem das ocorrências
    int contador = 0;
    for (i = 0; i < n; i++) {
        // Verifica se o número já foi contado
        if (encontrar_indice(contagem, contador, numeros[i]) == -1) {
            contagem[contador] = numeros[i];
            ocorrencias[contador] = 1;
            for (j = i + 1; j < n; j++) {
                if (numeros[j] == numeros[i]) {
                    ocorrencias[contador]++;
                }
            }
            contador++;
        }
    }

    // Exibe os resultados
    printf("Contagem de ocorrências:\n");
    for (i = 0; i < contador; i++) {
        printf("%.1f ocorre %d vez%s\n", contagem[i], ocorrencias[i], ocorrencias[i] > 1 ? "es" : "");
    }

    return 0;
}
