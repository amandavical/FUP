#include <stdio.h>
#include <string.h>

#define MAX_TAM 100

// Função para encontrar a palavra mais longa na frase
void encontrar_palavra_mais_longa(const char *frase) {
    char palavra[MAX_TAM];
    char palavra_mais_longa[MAX_TAM];
    int tam_palavra = 0;
    int tam_palavra_mais_longa = 0;
    int i = 0;

    while (1) {
        // Ler a próxima palavra da frase
        if (sscanf(&frase[i], "%s", palavra) != 1) {
            break; // Termina quando não há mais palavras
        }

        tam_palavra = strlen(palavra);
        if (tam_palavra > tam_palavra_mais_longa) {
            tam_palavra_mais_longa = tam_palavra;
            strcpy(palavra_mais_longa, palavra);
        }

        // Avança para a próxima palavra
        i += tam_palavra + 1; // +1 para pular o espaço
    }

    printf("A palavra mais longa é: %s\n", palavra_mais_longa);
}

int main() {
    char frase[MAX_TAM];

    // Leitura da frase
    printf("Digite uma frase (máximo de 100 caracteres): ");
    fgets(frase, sizeof(frase), stdin);

    // Remove a nova linha que pode ser adicionada por fgets
    frase[strcspn(frase, "\n")] = 0;

    // Encontrar e exibir a palavra mais longa
    encontrar_palavra_mais_longa(frase);

    return 0;
}
