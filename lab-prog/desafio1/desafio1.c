#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// funcao para exibir o estado dos armarios
void exibirArmarios(unsigned char controle) {
    printf("\nestado atual dos armarios:\n");
    for (int i = 7; i >= 0; i--) { 
        // verifica se o armario esta ocupado usando o operador and (&)
        int ocupado = controle & (1 << i);
        if (ocupado) {
            printf("armario %d: ocupado\n", i);
        } else {
            printf("armario %d: livre\n", i);
        }
    }
    printf("\n");
}

// funcao para ocupar um armario aleatorio
void ocuparArmario(unsigned char *controle) {
    // verifica se todos os armarios estao ocupados (todos os bits sao 1)
    if (*controle == 0xFF) {
        printf("todos os armarios estao ocupados. nao e possivel ocupar mais.\n");
        return;
    }

    int armario;
    // escolhe um armario livre aleatoriamente
    do {
        armario = rand() % 8; // gera um numero aleatorio entre 0 e 7
    } while (*controle & (1 << armario)); // verifica se o armario ja esta ocupado

    // marca o armario como ocupado (liga o bit com a porta OU ou mantém ligado se já estiver)
    *controle |= (1 << armario);
    printf("armario %d foi ocupado.\n", armario);
}

// funcao para liberar um armario escolhido pelo usuario
void liberarArmario(unsigned char *controle) {
    int armario;
    // solicita ao usuario o numero do armario a ser liberado
    printf("digite o numero do armario para liberar (0-7): ");
    scanf("%d", &armario);

    // verifica se o numero esta no intervalo valido
    if (armario < 0 || armario > 7) {
        printf("numero de armario invalido. escolha entre 0 e 7.\n");
        return;
    }

    // verifica se o armario esta ocupado
    if (!(*controle & (1 << armario))) {
        printf("o armario %d ja esta livre.\n", armario);
        return;
    }

    // marca o armario como livre (desliga o bit)
    *controle &= ~(1 << armario);
    printf("armario %d foi liberado.\n", armario);
}

int main() {
    unsigned char controle = 0x00; // começa com todos os armarios livres (00000000)
    int opcao;
    
    srand(time(NULL)); // inicializa o gerador de numeros aleatorios

    do {
        exibirArmarios(controle); // exibe o estado atual dos armarios

        printf("***menu***\n");
        printf("1. ocupar armario\n");
        printf("2. liberar armario\n");
        printf("3. sair\n");
        printf("escolha uma opcao: ");
        scanf("%d", &opcao);

        // executa a acao de acordo com a opcao escolhida
        switch (opcao) {
            case 1:
                ocuparArmario(&controle);
                break;
            case 2:
                liberarArmario(&controle); 
                break;
            case 3:
                printf("encerrando o programa. ate mais!\n");
                break;
            default:
                printf("escolha uma opção válida.\n");
        }
    } while (opcao != 3); // continua ate o usuario escolher "sair"

    return 0;
}
