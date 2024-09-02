#include <stdio.h>
#include <ctype.h>

#define MAX 100

void converter_primeira_letra_maiuscula(char str[]) {
    int i = 0;
    int nova_palavra = 1; // Marca se estamos no início de uma nova palavra

    while (str[i] != '\0') {
        if (isspace(str[i])) {
            nova_palavra = 1; // Próximo caractere será o início de uma nova palavra
        } else if (nova_palavra) {
            str[i] = toupper(str[i]); // Converte a primeira letra da nova palavra para maiúscula
            nova_palavra = 0; // Já não estamos mais no início de uma nova palavra
        } else {
            str[i] = tolower(str[i]); // Converte o restante dos caracteres para minúsculas
        }
        i++;
    }
}

int main() {
    char str[MAX];

    // Leitura da string
    printf("Digite uma string: ");
    fgets(str, sizeof(str), stdin);

    // Remover o caractere de nova linha, se presente
    str[strcspn(str, "\n")] = '\0';

    // Converter a primeira letra de cada palavra para maiúscula
    converter_primeira_letra_maiuscula(str);

    // Exibir a string modificada
    printf("String com primeiras letras maiúsculas: '%s'\n", str);

    return 0;
}
