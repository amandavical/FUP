#include <stdio.h>
#include <ctype.h>

#define MAX 256 // Tamanho máximo da frase

// Função para contar o número de palavras na frase
int contar_palavras(const char *frase) {
    int count = 0;
    int em_palavra = 0;

    while (*frase) {
        if (isspace(*frase)) {
            // Se encontramos um espaço, terminamos uma palavra
            em_palavra = 0;
        } else if (!em_palavra) {
            // Se não estamos em uma palavra e encontramos um caractere não espaço, iniciamos uma nova palavra
            em_palavra = 1;
            count++;
        }
        frase++;
    }
    return count;
}

int main() {
    char frase[MAX];

    // Leitura da frase
    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    // Contar e exibir o número de palavras
    int num_palavras = contar_palavras(frase);
    printf("Número de palavras na frase: %d\n", num_palavras);

    return 0;
}
