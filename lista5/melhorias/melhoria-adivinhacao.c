// Incluindo as bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Definindo as constantes
#define FACIL_TENTATIVAS 20
#define MEDIO_TENTATIVAS 15
#define DIFICIL_TENTATIVAS 6

int main() {
    char jogarNovamente;
    
    do {
        int chute, acertou, nivel, totaldetentativas, limiteInferior, limiteSuperior;
        double pontos = 1000;
        int numerosecreto, ultimoChute = -1;
        
        // Imprimindo cabeçalho bonito do jogo
        printf("\n\n");
        printf("          P  /_\\  P                              \n");
        printf("         /_\\_|_|_/_\\                            \n");
        printf("     n_n | ||. .|| | n_n         Bem vindo ao     \n");
        printf("     |_|_|nnnn nnnn|_|_|     Jogo de Adivinhação! \n");
        printf("    |\" \"  |  |_|  |\"  \" |                     \n");
        printf("    |_____| ' _ ' |_____|                         \n");
        printf("          \\__|_|__/                              \n");
        printf("\n\n");

        // Capturando os limites do intervalo
        printf("Digite o limite inferior: ");
        scanf("%d", &limiteInferior);
        printf("Digite o limite superior: ");
        scanf("%d", &limiteSuperior);

        // Verificando validade dos limites
        if (limiteInferior >= limiteSuperior) {
            printf("Limite inferior deve ser menor que o limite superior.\n");
            return 1; // Encerra o programa com erro
        }

        // Gerando um número secreto aleatório
        srand(time(0));
        numerosecreto = limiteInferior + rand() % (limiteSuperior - limiteInferior + 1);

        // Escolhendo o nível de dificuldade
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

        // Loop principal do jogo usando do-while
        int i = 1;
        do {
            printf("-> Tentativa %d de %d\n", i, totaldetentativas);
            printf("Chute um número entre %d e %d: ", limiteInferior, limiteSuperior);
            scanf("%d", &chute);

            // Tratando chute de número fora do intervalo
            if(chute < limiteInferior || chute > limiteSuperior) {
                printf("Número fora do intervalo!\n");
                continue;
            }

            // Tratando chute de número negativo
            if(chute < 0) {
                printf("Você não pode chutar números negativos\n");
                continue;
            }

            // Verificando chute repetido
            if(chute == ultimoChute) {
                printf("Você já chutou esse número!\n");
                continue;
            }

            // Verifica se acertou, foi maior ou menor
            acertou = chute == numerosecreto;
            ultimoChute = chute;

            if(acertou) {
                break;
            } else if(chute > numerosecreto) {
                printf("\nSeu chute foi maior do que o número secreto!\n\n");
            } else {
                printf("\nSeu chute foi menor do que o número secreto!\n\n");
            }

            // Calcula a quantidade de pontos
            double pontosperdidos = abs(chute - numerosecreto) / 2.0;
            pontos = pontos - pontosperdidos;
            i++;
        } while (i <= totaldetentativas && !acertou);

        // Imprimindo mensagem de vitória ou derrota
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
