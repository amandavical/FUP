#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 5 // linhas
#define M 5 // colunas

// Funcao para gerar a matriz com valores aleatórios
void gerarMatriz(unsigned char matriz[N][M]) {
    srand(time(NULL));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            matriz[i][j] = rand() % 256; // Valores entre 0 e 255
        }
    }
}

// Funçao para calcular a LBP
void calcularLBP(unsigned char entrada[N][M], unsigned char lbp[N][M]) {
    int dx[8] = {-1, -1, -1, 0, 1, 1, 1, 0}; // Deslocamentos X dos vizinhos
    int dy[8] = {-1, 0, 1, 1, 1, 0, -1, -1}; // Deslocamentos Y dos vizinhos

    // Percorre a matriz
    for (int i = 1; i < N - 1; i++) { // Ignorar bordas
        for (int j = 1; j < M - 1; j++) {
            unsigned char valorCentral = entrada[i][j];
            unsigned char binario = 0;

            for (int k = 0; k < 8; k++) {
                int vizinhoX = i + dx[k];
                int vizinhoY = j + dy[k];

                if (entrada[vizinhoX][vizinhoY] >= valorCentral) {
                    binario |= (1 << (7 - k)); // Define o bit correspondente
                }
            }

            lbp[i][j] = binario; // att o pixel na matriz LBP
        }
    }
}

// funçao para calcular o histograma
void calcularHistograma(unsigned char lbp[N][M], int histograma[256]) {
    for (int i = 0; i < 256; i++) {
        histograma[i] = 0; // inicializa o histograma
    }

    for (int i = 1; i < N - 1; i++) {
        for (int j = 1; j < M - 1; j++) {
            histograma[lbp[i][j]]++; // incrementa o contador
        }
    }
}

// Funçao para imprimir a matriz
void imprimirMatriz(unsigned char matriz[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            printf("%3d ", matriz[i][j]);
        }
        printf("\n");
    }
}

// Funçao para imprimir o histograma
void imprimirHistograma(int histograma[256]) {
    printf("Histograma LBP:\n");
    for (int i = 0; i < 256; i++) {
        if (histograma[i] > 0) {
            printf("Valor %d: %d vezes\n", i, histograma[i]);
        }
    }
}

int main() {
    unsigned char entrada[N][M];
    unsigned char lbp[N][M] = {0}; // inicialza com 0
    int histograma[256];

    gerarMatriz(entrada);

    printf("Matriz de Entrada:\n");
    imprimirMatriz(entrada);

    calcularLBP(entrada, lbp);

    printf("\nMatriz LBP:\n");
    imprimirMatriz(lbp);

    calcularHistograma(lbp, histograma);

    printf("\n");
    imprimirHistograma(histograma);

    return 0;
}
