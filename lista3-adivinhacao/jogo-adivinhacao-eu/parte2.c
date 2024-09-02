#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
2) Temos ainda alguns números mágicos em nosso código. Use
#defines para a quantidade de tentativas por níveis.
*/

#define NUMERO_DE_TENTATIVAS 3


int main(void) {
    int limiteInferior, limiteSuperior;
    int chute, numerosecreto;
    int acertou = 0;  // Variavel para verificar se o usuario acertou

    srand((unsigned int)time(NULL)); // Inicializa o gerador de numeros aleatorios

    printf("Digite o limite inferior (0 a 99): ");
    scanf("%d", &limiteInferior);
    printf("Digite o limite superior (0 a 99): ");
    scanf("%d", &limiteSuperior);

    if (limiteInferior < 0) limiteInferior = 0;
    if (limiteSuperior > 99) limiteSuperior = 99;
    if (limiteInferior > limiteSuperior) {
        printf("O limite inferior nao pode ser maior que o limite superior.\n");
        return 1;
    }

    numerosecreto = limiteInferior + rand() % (limiteSuperior - limiteInferior + 1);

    for (int i = 1; i <= NUMERO_DE_TENTATIVAS; i++) {
        printf("Tentativa %d de %d. Qual o seu chute?\n", i, NUMERO_DE_TENTATIVAS);
        scanf("%d", &chute);

        if (chute < limiteInferior || chute > limiteSuperior) {
            printf("Seu chute deve estar entre %d e %d!\n", limiteInferior, limiteSuperior);
            i--; // Nao conta como uma tentativa
            continue;
        }

        if (chute == numerosecreto) {
            printf("Parabens, voce acertou!\n");
            acertou = 1;
            break; // Sai do loop se acertou
        } else {
            if (chute > numerosecreto) {
                printf("Seu chute foi maior que o numero secreto!\n");
            } else {
                printf("Seu chute foi menor que o numero secreto!\n");
            }
        }
    }

    if (!acertou) {
        printf("Voce perdeu! O numero secreto era %d.\n", numerosecreto);
    }

    return 0;
}
