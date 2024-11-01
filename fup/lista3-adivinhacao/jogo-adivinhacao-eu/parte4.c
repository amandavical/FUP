#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUMERO_DE_TENTATIVAS 3

/*
4) Não deixe o usuário jogar o mesmo número na sequência. Se ele
jogou o número “2”, errou, e jogou novamente o “2”, avise-o de que ele
já jogou esse número, e não conte como uma tentativa. Para isso, crie
uma variável que guardará o “último número chutado”. (Não tente
guardar todos os números chutados nesse momento. Aprenderemos
como fazer isso mais para frente.)
*/

int main(void) {
    int jogarNovamente;

    do {
        int limiteInferior, limiteSuperior;
        int chute, numerosecreto;
        int acertou = 0;  // Variavel para verificar se o usuario acertou
        int ultimoChute = -1; // Variavel para armazenar o ultimo chute

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

            if (chute == ultimoChute) {
                printf("Voce ja chutou o numero %d antes! Tente outro.\n", chute);
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

            ultimoChute = chute; // Atualiza o ultimo chute
        }

        if (!acertou) {
            printf("Voce perdeu! O numero secreto era %d.\n", numerosecreto);
        }

        printf("Deseja jogar novamente? Digite 1 para sim ou 0 para nao: ");
        scanf("%d", &jogarNovamente);

    } while (jogarNovamente == 1);

    printf("Obrigado por jogar!\n");
    return 0;
}
