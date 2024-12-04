/*
 ============================================================================
 Autor: Amanda
 Data: 03/12/2024
 Descrição: Este programa foi feito para demonstrar diversas operações em vetores, 
 strings e matrizes. Possui fins didáticos, com conceitos de programação em C
 como manipulação de arrays, strings e algoritmos básicos.
 ============================================================================
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#define TAM_VETOR 15
#define TAM_STRING 100
#define TAM_MATRIZ 3

// funçao 1: soma do menor e maior elemento do vetor
void somaMenorMaior() {
    float vetor[TAM_VETOR];
    float maior, menor, soma;

    printf("digite %d elementos para o vetor:\n", TAM_VETOR);
    for (int i = 0; i < TAM_VETOR; i++) {
        scanf("%f", &vetor[i]);
    }

    maior = menor = vetor[0];
    for (int i = 1; i < TAM_VETOR; i++) {
        if (vetor[i] > maior) maior = vetor[i];
        if (vetor[i] < menor) menor = vetor[i];
    }

    soma = maior + menor;
    printf("a soma do menor e maior elemento e: %.2f\n", soma);
}

// funçao 2: verificar se a string contem o caractere
void verificarCaractere() {
    char string[TAM_STRING], caractere;
    int encontrado = 0;

    printf("Digite uma string: ");
    getchar();
    fgets(string, TAM_STRING, stdin);
    printf("Digite um caractere: ");
    scanf(" %c", &caractere);

    for (int i = 0; string[i] != '\0'; i++) {
        if (string[i] == caractere) {
            encontrado = 1;
            break;
        }
    }

    if (encontrado)
        printf("O caractere '%c' esta presente na string.\n", caractere);
    else
        printf("O caractere '%c' nao esta presente na string.\n", caractere);
}

// Funçao 3: contar caracteres sem strlen()
void contarCaracteres() {
    char string[TAM_STRING];
    int contador = 0;

    printf("Digite uma string: ");
    getchar();
    fgets(string, TAM_STRING, stdin);

    while (string[contador] != '\0' && string[contador] != '\n') {
        contador++;
    }

    printf("A quantidade de caracteres na string e: %d\n", contador);
}

// funçao 4: comparar duas strings
void compararStrings() {
    char string1[TAM_STRING], string2[TAM_STRING];
    int escolha;

    printf("Digite a primeira string: ");
    getchar();
    fgets(string1, TAM_STRING, stdin);
    printf("Digite a segunda string: ");
    fgets(string2, TAM_STRING, stdin);

    string1[strcspn(string1, "\n")] = '\0';
    string2[strcspn(string2, "\n")] = '\0';

    printf("Escolha o metodo:\n1 - Com strcmp()\n2 - Sem strcmp()\n");
    scanf("%d", &escolha);

    if (escolha == 1) {
        if (strcmp(string1, string2) == 0)
            printf("As strings sao iguais.\n");
        else
            printf("As strings sao diferentes.\n");
    } else {
        int iguais = 1;
        for (int i = 0; string1[i] != '\0' || string2[i] != '\0'; i++) {
            if (string1[i] != string2[i]) {
                iguais = 0;
                break;
            }
        }
        if (iguais)
            printf("as strings sao iguais.\n");
        else
            printf("as strings sao diferentes.\n");
    }
}

// funçao 5: concatenar duas strings
void concatenarStrings() {
    char string1[TAM_STRING], string2[TAM_STRING];
    int escolha;

    printf("Digite a primeira string: ");
    getchar();
    fgets(string1, TAM_STRING, stdin);
    printf("Digite a segunda string: ");
    fgets(string2, TAM_STRING, stdin);

    string1[strcspn(string1, "\n")] = '\0';

    printf("Escolha o metodo:\n1 - Com strcat()\n2 - Sem strcat()\n");
    scanf("%d", &escolha);

    if (escolha == 1) {
        strcat(string1, string2);
    } else {
        int i = 0, j = 0;
        while (string1[i] != '\0') {
            i++;
        }
        while (string2[j] != '\0' && string2[j] != '\n') {
            string1[i] = string2[j];
            i++;
            j++;
        }
        string1[i] = '\0';
    }

    printf("a string concatenada es: %s\n", string1);
}

// Funçao 6: apresentar string na forma inversa
void inverterString() {
    char string[TAM_STRING];
    int tamanho;

    printf("Digite uma string: ");
    getchar();
    fgets(string, TAM_STRING, stdin);

    tamanho = strlen(string);
    if (string[tamanho - 1] == '\n') {
        string[tamanho - 1] = '\0';
        tamanho--;
    }

    printf("String invertida: ");
    for (int i = tamanho - 1; i >= 0; i--) {
        putchar(string[i]);
    }
    printf("\n");
}

// funçao 7: media aritmetica e geometrica de vetor aleatorio
void mediasVetorAleatorio() {
    int vetor[3];
    float soma = 0, produto = 1;

    srand(time(NULL));
    for (int i = 0; i < 3; i++) {
        vetor[i] = rand() % 20; // intervalo [0, 19]
        soma += vetor[i];
        produto *= vetor[i];
    }

    printf("Vetor gerado: %d, %d, %d\n", vetor[0], vetor[1], vetor[2]);
    printf("Media aritmetica: %.2f\n", soma / 3);
    printf("Media geometrica: %.2f\n", pow(produto, 1.0 / 3));
}

// Funçao 8: Ordenar vetor aleatorio com seleçao e bolha
void ordenarVetor() {
    int vetor[100], inicio, fim, escolha;

    printf("digite o inicio e o fim do intervalo para gerar números aleatorios: ");
    scanf("%d %d", &inicio, &fim);

    srand(time(NULL));
    for (int i = 0; i < 100; i++) {
        vetor[i] = rand() % (fim - inicio + 1) + inicio;
    }

    printf("Escolha o metodo de ordenaçao:\n1 - Seleçao\n2 - Bolha\n");
    scanf("%d", &escolha);

    if (escolha == 1) {
        for (int i = 0; i < 100 - 1; i++) {
            for (int j = i + 1; j < 100; j++) {
                if (vetor[i] > vetor[j]) {
                    int temp = vetor[i];
                    vetor[i] = vetor[j];
                    vetor[j] = temp;
                }
            }
        }
    } else {
        for (int i = 0; i < 100 - 1; i++) {
            for (int j = 0; j < 100 - i - 1; j++) {
                if (vetor[j] > vetor[j + 1]) {
                    int temp = vetor[j];
                    vetor[j] = vetor[j + 1];
                    vetor[j + 1] = temp;
                }
            }
        }
    }

    printf("Vetor ordenado: ");
    for (int i = 0; i < 100; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Funçao 9: Elementos da diagonal principal
void diagonalPrincipal() {
    int matriz[TAM_MATRIZ][TAM_MATRIZ];

    printf("Digite os elementos da matriz 3x3:\n");
    for (int i = 0; i < TAM_MATRIZ; i++) {
        for (int j = 0; j < TAM_MATRIZ; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("Elementos da diagonal principal: ");
    for (int i = 0; i < TAM_MATRIZ; i++) {
        printf("%d ", matriz[i][i]);
    }
    printf("\n");
}

// Funçao 10: Contar ocorrências de x na matriz
void contarOcorrencias() {
    int matriz[TAM_MATRIZ][TAM_MATRIZ];
    int x, contador = 0;

    srand(time(NULL));
    for (int i = 0; i < TAM_MATRIZ; i++) {
        for (int j = 0; j < TAM_MATRIZ; j++) {
            matriz[i][j] = rand() % 10; // valores entre 0 e 9
        }
    }

    printf("Digite um valor para ser buscado na matriz: ");
    scanf("%d", &x);

    for (int i = 0; i < TAM_MATRIZ; i++) {
        for (int j = 0; j < TAM_MATRIZ; j++) {
            if (matriz[i][j] == x) {
                contador++;
            }
        }
    }

    printf("O número %d aparece %d vezes nessa matriz gerada.\n", x, contador);
}

int main() {
    int opcao;

    do {
        printf("\nEscolha uma opçao (0 para sair):\n");
        printf("1 - Soma do menor e maior elemento do vetor\n");
        printf("2 - Verificar se um caractere esta na string\n");
        printf("3 - Contar caracteres sem strlen()\n");
        printf("4 - Comparar duas strings\n");
        printf("5 - Concatenar duas strings\n");
        printf("6 - Apresentar string na forma inversa\n");
        printf("7 - Media aritmetica e geometrica de vetor aleatorio\n");
        printf("8 - Ordenar vetor aleatorio\n");
        printf("9 - Elementos da diagonal principal da matriz\n");
        printf("10 - Contar ocorrências de x na matriz\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0: break;
            case 1: somaMenorMaior(); break;
            case 2: verificarCaractere(); break;
            case 3: contarCaracteres(); break;
            case 4: compararStrings(); break;
            case 5: concatenarStrings(); break;
            case 6: inverterString(); break;
            case 7: mediasVetorAleatorio(); break;
            case 8: ordenarVetor(); break;
            case 9: diagonalPrincipal(); break;
            case 10: contarOcorrencias(); break;
            default: printf("Opçao invalida\n");
        }
    } while (opcao != 0);

    return 0;
}
