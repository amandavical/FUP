#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

void remover_espacos_repetidos(char str[]) {
    int i, j = 0;
    int espaco_em_branco = 0;
    int len = strlen(str);

    for (i = 0; i < len; i++) {
        // Verifica se o caractere é um espaço em branco
        if (isspace(str[i])) {
            // Se o último caractere adicionado não foi um espaço em branco
            if (!espaco_em_branco) {
                str[j++] = str[i]; // Adiciona o espaço ao resultado
                espaco_em_branco = 1; // Marca que o espaço foi adicionado
            }
        } else {
            str[j++] = str[i]; // Adiciona o caractere não-espacial ao resultado
            espaco_em_branco = 0; // Marca que o último caractere não foi um espaço
        }
    }
    str[j] = '\0'; // Adiciona o caractere nulo ao final da string resultante
}

int main() {
    char str[MAX];

    // Leitura da string
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remover o caractere de nova linha, se presente
    str[strcspn(str, "\n")] = '\0';

    // Remover espaços em branco repetidos
    remover_espacos_repetidos(str);

    // Exibir a string modificada
    printf("String sem espaços repetidos: '%s'\n", str);

    return 0;
}
