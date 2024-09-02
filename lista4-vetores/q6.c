#include <stdio.h>

#define TAM_VETOR 50

// Função para exibir o vetor
void exibir_vetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função para mostrar o vetor na ordem inversa
void exibir_vetor_inverso(int vetor[], int tamanho) {
    for (int i = tamanho - 1; i >= 0; i--) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função para calcular a mediana
float calcular_mediana(int vetor[], int tamanho) {
    // Ordena o vetor usando o algoritmo de ordenação por bolha
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                int temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
            }
        }
    }

    if (tamanho % 2 == 0) {
        return (vetor[tamanho / 2 - 1] + vetor[tamanho / 2]) / 2.0;
    } else {
        return vetor[tamanho / 2];
    }
}

// Função para calcular o produto dos elementos
long long calcular_produto(int vetor[], int tamanho) {
    long long produto = 1;
    for (int i = 0; i < tamanho; i++) {
        produto *= vetor[i];
    }
    return produto;
}

// Função para calcular a porcentagem de pares positivos
float calcular_porcentagem_pares(int vetor[], int tamanho) {
    int contagem_pares = 0;
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] > 0 && vetor[i] % 2 == 0) {
            contagem_pares++;
        }
    }
    return (contagem_pares / (float)tamanho) * 100;
}

// Função para encontrar e somar números ímpares
void encontrar_impares_e_soma(int vetor[], int tamanho) {
    int soma_impares = 0;
    printf("Números ímpares: ");
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] % 2 != 0) {
            printf("%d ", vetor[i]);
            soma_impares += vetor[i];
        }
    }
    printf("\nSoma dos números ímpares: %d\n", soma_impares);
}

// Função para verificar e listar números repetidos
void verificar_repetidos(int vetor[], int tamanho) {
    printf("Números repetidos: ");
    for (int i = 0; i < tamanho; i++) {
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[i] == vetor[j]) {
                printf("%d ", vetor[i]);
                break;
            }
        }
    }
    printf("\n");
}

int main() {
    int N;
    int vetor[TAM_VETOR];

    // Leitura do vetor
    printf("Digite 50 números para o vetor:\n");
    for (int i = 0; i < TAM_VETOR; i++) {
        printf("Número %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    // Leitura do código de operação
    printf("Digite o código de operação (0-7): ");
    scanf("%d", &N);

    switch (N) {
        case 0:
            // Termina o programa
            printf("Programa encerrado.\n");
            break;
        case 1:
            // Mostra o vetor na ordem como foi lido
            exibir_vetor(vetor, TAM_VETOR);
            break;
        case 2:
            // Mostra o vetor na ordem inversa
            exibir_vetor_inverso(vetor, TAM_VETOR);
            break;
        case 3:
            // Calcula e mostra a mediana
            printf("Mediana: %.2f\n", calcular_mediana(vetor, TAM_VETOR));
            break;
        case 4:
            // Calcula e mostra o produto dos elementos
            printf("Produto dos elementos: %lld\n", calcular_produto(vetor, TAM_VETOR));
            break;
        case 5:
            // Calcula e mostra a porcentagem de pares positivos
            printf("Porcentagem de pares positivos: %.2f%%\n", calcular_porcentagem_pares(vetor, TAM_VETOR));
            break;
        case 6:
            // Mostra os números ímpares e a soma dos ímpares
            encontrar_impares_e_soma(vetor, TAM_VETOR);
            break;
        case 7:
            // Verifica e mostra os números repetidos
            verificar_repetidos(vetor, TAM_VETOR);
            break;
        default:
            printf("Código de operação inválido.\n");
    }

    return 0;
}
