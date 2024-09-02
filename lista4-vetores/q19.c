#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para converter uma string para maiúsculas
void to_uppercase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = toupper(str[i]);
    }
}

// Função para contar as ocorrências de uma palavra em uma frase
int contar_ocorrencias(char *frase, char *palavra) {
    int count = 0;
    char *pos = frase;
    int len = strlen(palavra);

    // Converte a frase e a palavra para maiúsculas
    to_uppercase(frase);
    to_uppercase(palavra);

    // Procura pela palavra na frase
    while ((pos = strstr(pos, palavra)) != NULL) {
        count++;
        pos += 1; // Avança apenas um caractere para encontrar ocorrências sobrepostas
    }

    return count;
}

int main() {
    char frase[100];
    char palavra[50];

    // Lê a frase e a palavra do usuário
    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);
    frase[strcspn(frase, "\n")] = '\0'; // Remove o caractere de nova linha

    printf("Digite uma palavra: ");
    fgets(palavra, sizeof(palavra), stdin);
    palavra[strcspn(palavra, "\n")] = '\0'; // Remove o caractere de nova linha

    int ocorrencias = contar_ocorrencias(frase, palavra);
    printf("A palavra '%s' ocorre %d vezes na frase.\n", palavra, ocorrencias);

    return 0;
}
