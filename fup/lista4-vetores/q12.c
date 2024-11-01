#include <stdio.h>

#define MAX_DIGITOS 10  

// Função para somar duas sequências de dígitos
void somar_sequencias(int seq1[], int seq2[], int resultado[], int n) {
    int carry = 0;

    // Realiza a soma da direita para a esquerda
    for (int i = n - 1; i >= 0; i--) {
        int soma = seq1[i] + seq2[i] + carry;
        resultado[i] = soma % 10;    // O dígito da unidade
        carry = soma / 10;           // O carry para a próxima iteração
    }

    // Se ainda houver carry após a última iteração, deve ser adicionado ao início do resultado
    if (carry > 0) {
        // Move os elementos para a direita para inserir o carry no início
        for (int i = n; i > 0; i--) {
            resultado[i] = resultado[i - 1];
        }
        resultado[0] = carry;
    }
}

int main() {
    int n;
    int seq1[MAX_DIGITOS], seq2[MAX_DIGITOS], resultado[MAX_DIGITOS + 1] = {0};  // +1 para o carry potencial

    // Leitura do tamanho das sequências
    printf("Digite o número de dígitos das sequências (máximo %d): ", MAX_DIGITOS);
    scanf("%d", &n);

    // Verifica se o número de dígitos não excede o máximo permitido
    if (n > MAX_DIGITOS) {
        printf("Número de dígitos excede o limite máximo de %d.\n", MAX_DIGITOS);
        return 1;
    }

    // Leitura da primeira sequência
    printf("Digite os dígitos da primeira sequência (um por linha):\n");
    for (int i = 0; i < n; i++) {
        printf("Dígito %d: ", i + 1);
        scanf("%d", &seq1[i]);
    }

    // Leitura da segunda sequência
    printf("Digite os dígitos da segunda sequência (um por linha):\n");
    for (int i = 0; i < n; i++) {
        printf("Dígito %d: ", i + 1);
        scanf("%d", &seq2[i]);
    }

    // Chama a função para somar as duas sequências
    somar_sequencias(seq1, seq2, resultado, n);

    // Exibe o resultado
    printf("Resultado da soma:\n");
    for (int i = 0; i <= n; i++) {
        printf("%d ", resultado[i]);
    }
    printf("\n");

    return 0;
}
