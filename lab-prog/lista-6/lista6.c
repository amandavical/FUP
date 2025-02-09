#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// Protótipos das funções 
void soma_multiplicacao(int a, int b, char op);
int *gerar_vetor(int tamanho);
void armazenar_indices(int *v, int tamanho, int *menor, int *maior);
void normalizar_vetor(int *v, int tamanho, double *norm);
float *gerar_vetor_float(int tamanho);
void calcular_estatisticas(int *v, int tamanho);
double calcular_mse(int *A, int *B, int tamanho);
double calcular_mae(int *A, int *B, int tamanho);
void gerar_matriz_binaria(int **M, int **S, int N, int t);
int somatorio_diagonal(int **M, int N);
void gerar_matriz_coocorrencia(int *X, int *Y, int **M, int N);

// Questão 1: Soma ou multiplicação
void soma_multiplicacao(int a, int b, char op)
{
    if (op == '+')
        printf("Resultado: %d\n", a + b);
    else if (op == '*')
        printf("Resultado: %d\n", a * b);
    else
        printf("Operação inválida!\n");
}

// Questão 2: Gerar vetor
int *gerar_vetor(int n)
{
    int *vetor = (int *)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
        vetor[i] = rand() % 100;
    return vetor;
}

// Questão 3: Armazenar índices de menor e maior elemento
void armazenar_indices(int *vetor, int n, int *menor, int *maior)
{
    *menor = *maior = 0;
    for (int i = 1; i < n; i++)
    {
        if (vetor[i] < vetor[*menor])
            *menor = i;
        if (vetor[i] > vetor[*maior])
            *maior = i;
    }
}

// Questão 4: Normalização Min-Max
void normalizar_vetor(int *vetor, int n, double *norm)
{
    int min = vetor[0], max = vetor[0];
    for (int i = 1; i < n; i++)
    {
        if (vetor[i] < min)
            min = vetor[i];
        if (vetor[i] > max)
            max = vetor[i];
    }
    for (int i = 0; i < n; i++)
        norm[i] = (double)(vetor[i] - min) / (max - min);
}

// Questão 5: Gerar vetor dinâmico de float
float *gerar_vetor_float(int n)
{
    float *vetor = (float *)malloc(n * sizeof(float));
    for (int i = 0; i < n; i++)
        vetor[i] = (float)rand() / RAND_MAX;
    return vetor;
}

// Questão 6: Média, mediana e moda
int comparar(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

double calcular_media(int *vetor, int n)
{
    int soma = 0;
    for (int i = 0; i < n; i++)
        soma += vetor[i];
    return (double)soma / n;
}

double calcular_mediana(int *vetor, int n)
{
    qsort(vetor, n, sizeof(int), comparar);
    if (n % 2 == 0)
        return (vetor[n / 2 - 1] + vetor[n / 2]) / 2.0;
    else
        return vetor[n / 2];
}

int calcular_moda(int *vetor, int n)
{
    int moda = vetor[0], maxCount = 0;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (vetor[j] == vetor[i])
                count++;
        }
        if (count > maxCount)
        {
            maxCount = count;
            moda = vetor[i];
        }
    }
    return moda;
}

void calcular_estatisticas(int *vetor, int n)
{
    printf("Média: %.2f\n", calcular_media(vetor, n));
    printf("Mediana: %.2f\n", calcular_mediana(vetor, n));
    printf("Moda: %d\n", calcular_moda(vetor, n));
}

// Questão 7: Erro médio quadrático (MSE)
double calcular_mse(int *A, int *B, int n)
{
    double soma = 0.0;
    for (int i = 0; i < n; i++)
        soma += pow(A[i] - B[i], 2);
    return soma / n;
}

// Questão 8: Erro Absoluto Médio (MAE)
double calcular_mae(int *A, int *B, int n)
{
    double soma = 0.0;
    for (int i = 0; i < n; i++)
        soma += fabs(A[i] - B[i]);
    return soma / n;
}

// Questão 9: Gerar matriz binária com base em um limiar
void gerar_matriz_binaria(int **M, int **S, int N, int t)
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            S[i][j] = (M[i][j] > t) ? 1 : 0;
        }
    }
}

// Questão 10: Somatório da diagonal principal
int somatorio_diagonal(int **M, int N)
{
    int soma = 0;
    for (int i = 0; i < N; i++)
        soma += M[i][i];
    return soma;
}

// Questão 11: Matriz de coocorrência
void gerar_matriz_coocorrencia(int *X, int *Y, int **M, int N)
{
    for (int i = 0; i < N; i++)
    {
        M[X[i]][Y[i]]++;
    }
}



int main() {
    srand(time(NULL));
    int escolha;

    do {
        printf("Selecione a questão (1-11) ou 0 para sair: ");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                soma_multiplicacao(3, 5, '+');
                break;

            case 2: {
                int *v = gerar_vetor(5);
                if (v != NULL) {
                    printf("Vetor gerado: ");
                    for (int i = 0; i < 5; i++) {
                        printf("%d ", v[i]);
                    }
                    printf("\n");
                    free(v);
                }
                break;
            }

            case 3: {
                int v[] = {3, 1, 4, 1, 5};
                int menor, maior;
                armazenar_indices(v, 5, &menor, &maior);
                printf("Índice do menor elemento: %d\n", menor);
                printf("Índice do maior elemento: %d\n", maior);
                break;
            }

            case 4: {
                int v[] = {10, 20, 30, 40, 50};
                double norm[5];
                normalizar_vetor(v, 5, norm);
                printf("Vetor normalizado: ");
                for (int i = 0; i < 5; i++) {
                    printf("%.2f ", norm[i]);
                }
                printf("\n");
                break;
            }

            case 5: {
                float *v = gerar_vetor_float(5);
                if (v != NULL) {
                    printf("Vetor de floats gerado: ");
                    for (int i = 0; i < 5; i++) {
                        printf("%.2f ", v[i]);
                    }
                    printf("\n");
                    free(v);
                }
                break;
            }

            case 6: {
                int v[10];
                for (int i = 0; i < 10; i++) {
                    v[i] = rand() % 20;
                }
                calcular_estatisticas(v, 10);
                break;
            }

            case 7: {
                int A[] = {1, 2, 3};
                int B[] = {2, 3, 4};
                printf("MSE: %.2f\n", calcular_mse(A, B, 3));
                break;
            }

            case 8: {
                int *A = gerar_vetor(10);
                int *B = gerar_vetor(10);
                if (A != NULL && B != NULL) {
                    printf("MAE: %.2f\n", calcular_mae(A, B, 10));
                }
                free(A);
                free(B);
                break;
            }

            case 9: {
                int N = 3, t = 5;
                int **M = (int **)malloc(N * sizeof(int *));
                int **S = (int **)malloc(N * sizeof(int *));
            
                if (M != NULL && S != NULL) {
                    for (int i = 0; i < N; i++) {
                        M[i] = (int *)malloc(N * sizeof(int));
                        S[i] = (int *)malloc(N * sizeof(int));
            
                        if (M[i] != NULL && S[i] != NULL) {
                            for (int j = 0; j < N; j++) {
                                M[i][j] = rand() % 10; // Preenche M com valores aleatórios
                            }
                        }
                    }
            
                    // Gera a matriz binária S
                    gerar_matriz_binaria(M, S, N, t);
            
                    // Exibe a matriz M
                    printf("Matriz M:\n");
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            printf("%d ", M[i][j]);
                        }
                        printf("\n");
                    }
            
                    // Exibe a matriz binária S
                    printf("Matriz binária S:\n");
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            printf("%d ", S[i][j]);
                        }
                        printf("\n");
                    }
            
                    // Libera a memória alocada
                    for (int i = 0; i < N; i++) {
                        free(M[i]);
                        free(S[i]);
                    }
                }
            
                free(M);
                free(S);
                break;
            }
            case 10: {
                int N = 3;
                int **M = (int **)malloc(N * sizeof(int *));

                if (M != NULL) {
                    for (int i = 0; i < N; i++) {
                        M[i] = (int *)malloc(N * sizeof(int));

                        if (M[i] != NULL) {
                            for (int j = 0; j < N; j++) {
                                M[i][j] = rand() % 10;
                            }
                        }
                    }

                    printf("Somatório: %d\n", somatorio_diagonal(M, N));

                    for (int i = 0; i < N; i++) {
                        free(M[i]);
                    }
                }

                free(M);
                break;
            }

            case 11: {
                int N = 7;
                int X[7], Y[7];
                int **M = (int **)malloc(N * sizeof(int *));

                if (M != NULL) {
                    for (int i = 0; i < N; i++) {
                        M[i] = (int *)calloc(N, sizeof(int));

                        if (M[i] == NULL) {
                            // Liberar memória alocada anteriormente em caso de falha
                            for (int j = 0; j < i; j++) {
                                free(M[j]);
                            }
                            free(M);
                            printf("Erro ao alocar memória.\n");
                            return 1;
                        }
                    }

                    for (int i = 0; i < N; i++) {
                        X[i] = rand() % N;
                        Y[i] = rand() % N;
                    }

                    gerar_matriz_coocorrencia(X, Y, M, N);

                    printf("Matriz de coocorrência:\n");
                    for (int i = 0; i < N; i++) {
                        for (int j = 0; j < N; j++) {
                            printf("%d ", M[i][j]);
                        }
                        printf("\n");
                    }

                    for (int i = 0; i < N; i++) {
                        free(M[i]);
                    }
                    free(M);
                }
                break;
            }

            case 0:
                printf("Saindo...\n");
                break;

            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (escolha != 0);

    return 0;
}