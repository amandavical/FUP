#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

int eh_palindromo(char str[]) {
    int i, j;
    int len = strlen(str);

    // Convertendo todos os caracteres para minúsculas para comparação insensível a maiúsculas/minúsculas
    for (i = 0; i < len; i++) {
        str[i] = tolower(str[i]);
    }

    // Comparando os caracteres da string do início e do final
    for (i = 0, j = len - 1; i < j; i++, j--) {
        if (str[i] != str[j]) {
            return 0; // Não é um palíndromo
        }
    }
    return 1; // É um palíndromo
}

int main() {
    char str[MAX];

    // Leitura da string
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remover o caractere de nova linha, se presente
    str[strcspn(str, "\n")] = '\0';

    // Verificar se a string é um palíndromo
    if (eh_palindromo(str)) {
        printf("A string '%s' é um palíndromo.\n", str);
    } else {
        printf("A string '%s' não é um palíndromo.\n", str);
    }

    return 0;
}
