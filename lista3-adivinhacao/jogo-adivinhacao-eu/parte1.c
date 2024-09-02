#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
1) Hoje o jogo escolhe um número entre 0 e 99. Deixe o usuário
escolher esse limite. Você precisa capturar esses dois números dele,
e usá-los na hora de calcular o número randômico.
*/

int main(void) {
    int limiteInferior, limiteSuperior;
    int chute, numerosecreto;
    int acertou = 0;  // Variável para verificar se o usuário acertou

    srand((unsigned int)time(NULL)); // Inicializa o gerador de números aleatórios

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

    for (int i = 1; i <= 3; i++) { // Numero de tentativas
        printf("Tentativa %d de 3. Qual o seu chute?\n", i);
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
