// incluindo as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// definindo as constantes
#define FACIL_TENTATIVAS 20
#define MEDIO_TENTATIVAS 15
#define DIFICIL_TENTATIVAS 6

/*
4) Não deixe o usuário jogar o mesmo número na sequência. Se ele
jogou o número “2”, errou, e jogou novamente o “2”, avise-o de que ele
já jogou esse número, e não conte como uma tentativa. Para isso, crie
uma variável que guardará o “último número chutado”. (Não tente
guardar todos os números chutados nesse momento. Aprenderemos
como fazer isso mais para frente.)
*/

int main() {
    char jogarNovamente;
    
    do {
        int chute, acertou, nivel, totaldetentativas, limiteInferior, limiteSuperior;
        double pontos = 1000;
        int numerosecreto, ultimoChute = -1;
        
        // imprimindo cabeçalho bonito do jogo
        printf("\n\n");
        printf("          P  /_\\  P                              \n");
        printf("         /_\\_|_|_/_\\                            \n");
        printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
        printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
        printf("    |\" \"  |  |_|  |\"  \" |                     \n");
        printf("    |_____| ' _ ' |_____|                         \n");
        printf("          \\__|_|__/                              \n");
        printf("\n\n");

        // capturando os limites do intervalo
        printf("Digite o limite inferior: ");
        scanf("%d", &limiteInferior);
        printf("Digite o limite superior: ");
        scanf("%d", &limiteSuperior);

        // verificando validade dos limites
        if (limiteInferior >= limiteSuperior) {
            printf("Limite inferior deve ser menor que o limite superior.\n");
            return 1; // encerra o programa com erro
        }

        // gerando um número secreto aleatório
        srand(time(0));
        numerosecreto = limiteInferior + rand() % (limiteSuperior - limiteInferior + 1);

        // escolhendo o nível de dificuldade
        printf("Qual o nível de dificuldade?\n");
        printf("(1) Fácil (2) Médio (3) Difícil\n\n");
        printf("Escolha: ");
        scanf("%d", &nivel);

        switch(nivel) {
            case 1: 
                totaldetentativas = FACIL_TENTATIVAS;
                break;
            case 2:
                totaldetentativas = MEDIO_TENTATIVAS;
                break;
            default:
                totaldetentativas = DIFICIL_TENTATIVAS;
                break;
        }

        // loop principal do jogo
        for(int i = 1; i <= totaldetentativas; i++) {
            printf("-> Tentativa %d de %d\n", i, totaldetentativas);
            printf("Chute um número entre %d e %d: ", limiteInferior, limiteSuperior);
            scanf("%d", &chute);

            // tratando chute de número fora do intervalo
            if(chute < limiteInferior || chute > limiteSuperior) {
                printf("Número fora do intervalo!\n");
                i--;
                continue;
            }

            // tratando chute de número negativo
            if(chute < 0) {
                printf("Você não pode chutar números negativos\n");
                i--;
                continue;
            }

            // verificando chute repetido
            if(chute == ultimoChute) {
                printf("Você já chutou esse número!\n");
                i--;
                continue;
            }

            // verifica se acertou, foi maior ou menor
            acertou = chute == numerosecreto;
            ultimoChute = chute;

            if(acertou) {
                break;
            } else if(chute > numerosecreto) {
                printf("\nSeu chute foi maior do que o número secreto!\n\n");
            } else {
                printf("\nSeu chute foi menor do que o número secreto!\n\n");
            }

            // calcula a quantidade de pontos
            double pontosperdidos = abs(chute - numerosecreto) / 2.0;
            pontos = pontos - pontosperdidos;
        }

        // imprimindo mensagem de vitória ou derrota
        printf("\n");
        if(acertou) {
            printf("             OOOOOOOOOOO               \n");
            printf("         OOOOOOOOOOOOOOOOOOO           \n");
            printf("      OOOOOO  OOOOOOOOO  OOOOOO        \n");
            printf("    OOOOOO      OOOOO      OOOOOO      \n");
            printf("  OOOOOOOO  #   OOOOO  #   OOOOOOOO    \n");
            printf(" OOOOOOOOOO    OOOOOOO    OOOOOOOOOO   \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO  \n");
            printf("OOOO  OOOOOOOOOOOOOOOOOOOOOOOOO  OOOO  \n");
            printf(" OOOO  OOOOOOOOOOOOOOOOOOOOOOO  OOOO   \n");
            printf("  OOOO   OOOOOOOOOOOOOOOOOOOO  OOOO    \n");
            printf("    OOOOO   OOOOOOOOOOOOOOO   OOOO     \n");
            printf("      OOOOOO   OOOOOOOOO   OOOOOO      \n");
            printf("         OOOOOO         OOOOOO         \n");
            printf("             OOOOOOOOOOOO              \n");
            printf("\nParabéns! Você acertou!\n");
            printf("Você fez %.2f pontos. Até a próxima!\n\n", pontos);
        } else {
            printf("       \\|/ ____ \\|/    \n");   
            printf("        @~/ ,. \\~@      \n");   
            printf("       /_( \\__/ )_\\    \n");   
            printf("          \\__U_/        \n");
            printf("\nVocê perdeu! Tente novamente!\n\n");
        }

        printf("Você deseja jogar novamente? (1 para Sim, 0 para Não): ");
        scanf(" %c", &jogarNovamente);  // Espaço antes de %c para ignorar espaços em branco

    } while(jogarNovamente == '1');

    return 0;
}
