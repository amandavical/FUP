#include <stdio.h>

#define NUM_ALUNOS 50
#define TAM_GABARITO 10
#define MIN_ACERTOS 6

void verificar_aprovacao() {
    char gabarito[TAM_GABARITO];
    char respostas[TAM_GABARITO];
    int i, j, acertos;

    // Leitura do gabarito
    printf("Digite o gabarito da prova (10 caracteres):\n");
    for (i = 0; i < TAM_GABARITO; i++) {
        printf("Resposta %d: ", i + 1);
        scanf(" %c", &gabarito[i]);
    }

    // Processa as respostas de cada aluno
    for (i = 0; i < NUM_ALUNOS; i++) {
        printf("Digite as respostas do aluno %d (10 caracteres):\n", i + 1);
        for (j = 0; j < TAM_GABARITO; j++) {
            printf("Resposta %d: ", j + 1);
            scanf(" %c", &respostas[j]);
        }

        // Conta o número de acertos
        acertos = 0;
        for (j = 0; j < TAM_GABARITO; j++) {
            if (respostas[j] == gabarito[j]) {
                acertos++;
            }
        }

        // Exibe o número de acertos e a mensagem de aprovação ou reprovação
        printf("Aluno %d:\n", i + 1);
        printf("Número de acertos: %d\n", acertos);
        if (acertos >= MIN_ACERTOS) {
            printf("APROVADO\n");
        } else {
            printf("REPROVADO\n");
        }
    }
}

int main() {
    verificar_aprovacao();
    return 0;
}
