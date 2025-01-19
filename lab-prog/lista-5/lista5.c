#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define N 7  // Tamanho padrão dos vetores usado nas questões

// Questão 1
void questao1() {
    int a, b, soma;
    int *p1 = &a, *p2 = &b;

    printf("Digite dois numeros: ");
    scanf("%d %d", p1, p2);

    soma = *p1 + *p2;

    printf("Soma: %d\n", soma);
    printf("Endereco da soma: %p\n", (void *)&soma);
}

// Questão 2
void questao2() {
    int a, b, temp;
    int *p1 = &a, *p2 = &b;

    printf("Digite dois numeros: ");
    scanf("%d %d", p1, p2);

    temp = *p1;
    *p1 = *p2;
    *p2 = temp;

    printf("Depois da troca: a = %d, b = %d\n", *p1, *p2);
}

// Questão 3
void questao3() {
    int num, menor;
    int *pNum = &num;

    menor = __INT_MAX__; // Maior valor de inteiro como inicial
    printf("Digite numeros (0 para parar):\n");

    while (1) {
        scanf("%d", pNum);
        if (*pNum == 0) break;
        if (*pNum < menor) menor = *pNum;
    }

    printf("O menor numero fornecido foi: %d\n", menor);
}

// Questão 4
void questao4() {
    int num;
    int *pNum = &num;

    printf("Digite um numero: ");
    scanf("%d", pNum);

    printf("Numero fornecido: %d\n", *pNum);
    printf("Endereco: %p\n", (void *)pNum);
}

// Questão 5
void questao5() {
    char str[100];
    char *pStr = str;
    int tamanho = 0;

    printf("Digite uma string: ");
    scanf("%s", pStr);

    while (*pStr != '\0') {
        tamanho++;
        pStr++;
    }

    printf("O tamanho da string eh: %d\n", tamanho);
}

// Questão 6
void questao6() {
    char str1[100], str2[100];
    char *pStr1 = str1, *pStr2 = str2;

    printf("Digite a primeira string: ");
    scanf("%s", pStr1);

    while (*pStr1 != '\0') {
        *pStr2 = *pStr1;
        pStr1++;
        pStr2++;
    }
    *pStr2 = '\0'; // Adiciona o terminador de string

    printf("Copia da string: %s\n", str2);
}

// Questão 7
void questao7() {
    char str1[100], str2[100];
    char *pStr1 = str1, *pStr2 = str2;

    printf("Digite a primeira string: ");
    scanf("%s", pStr1);

    printf("Digite a segunda string: ");
    scanf("%s", pStr2);

    while (*pStr1 != '\0') pStr1++; // Vai até o final da primeira string

    while (*pStr2 != '\0') {
        *pStr1 = *pStr2;
        pStr1++;
        pStr2++;
    }
    *pStr1 = '\0'; // Adiciona o terminador de string

    printf("Concatenacao das strings: %s\n", str1);
}

// Questão 8
void questao8() {
    char str[100], c;
    char *pStr = str;
    int encontrado = 0;

    printf("Digite uma string: ");
    scanf("%s", pStr);

    printf("Digite um caractere para buscar: ");
    scanf(" %c", &c);

    while (*pStr != '\0') {
        if (*pStr == c) {
            encontrado = 1;
            break;
        }
        pStr++;
    }

    if (encontrado)
        printf("Caractere '%c' encontrado na string.\n", c);
    else
        printf("Caractere '%c' nao encontrado na string.\n", c);
}

// Questão 10
void questao10() {
    int x[N], f[N];

    srand(time(NULL));

    // Gerar vetor X
    printf("Vetor X:\n");
    for (int i = 0; i < N; i++) {
        x[i] = rand() % N;
        printf("%d ", x[i]);
    }
    printf("\n");

    // Calcular o vetor F
    for (int i = 0; i < N; i++) {
        f[i] = 0;
        for (int j = 0; j < N; j++) {
            if (x[j] == i) {
                f[i]++;
            }
        }
    }

    // Exibir o vetor F
    printf("Vetor F:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", f[i]);
    }
    printf("\n");
}

// Questão 11
void questao11() {
    int x[N], y[N], m[N][N];

    srand(time(NULL));

    // Gerar vetores X e Y
    printf("Vetor X:\n");
    for (int i = 0; i < N; i++) {
        x[i] = rand() % N;
        printf("%d ", x[i]);
    }
    printf("\n");

    printf("Vetor Y:\n");
    for (int i = 0; i < N; i++) {
        y[i] = rand() % N;
        printf("%d ", y[i]);
    }
    printf("\n");

    // Calcular a matriz M
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            m[i][j] = (x[i] == y[j]);
        }
    }

    // Exibir a matriz M
    printf("Matriz M:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", m[i][j]);
        }
        printf("\n");
    }
}

// Questão 12
void questao12() {
    int x[N], y[N];

    srand(time(NULL));

    // Gerar vetor X
    printf("Vetor X:\n");
    for (int i = 0; i < N; i++) {
        x[i] = rand() % N;
        printf("%d ", x[i]);
    }
    printf("\n");

    // Calcular vetor Y com base nas condições
    for (int i = 0; i < N; i++) {
        int r = rand() % 11;
        if (r >= 0 && r < 3) {
            y[i] = x[i];
        } else if (r >= 3 && r < 5) {
            y[i] = x[i] - 1;
        } else if (r >= 5 && r < 7) {
            y[i] = x[i] + 1;
        } else if (r >= 8 && r < 9) {
            y[i] = x[i] - 2;
        } else if (r >= 9 && r <= 10) {
            y[i] = x[i] + 2;
        }
    }

    // Exibir vetor Y
    printf("Vetor Y:\n");
    for (int i = 0; i < N; i++) {
        printf("%d ", y[i]);
    }
    printf("\n");
}

// Menu principal
int main() {
    int opcao;

    do {
        printf("\nEscolha uma questao para executar (1 a 12, 0 para sair): ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: questao1(); break;
            case 2: questao2(); break;
            case 3: questao3(); break;
            case 4: questao4(); break;
            case 5: questao5(); break;
            case 6: questao6(); break;
            case 7: questao7(); break;
            case 8: questao8(); break;
            case 10: questao10(); break;
            case 11: questao11(); break;
            case 12: questao12(); break;
            case 0: printf("Encerrando o programa.\n"); break;
            default: printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
