#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "forca.h"

char palavrasecreta[TAMANHO_PALAVRA];
char chutes[26];
int chutesdados = 0;
int maxChutes; // Armazena o número máximo de chutes permitidos

// Função que verifica se a letra existe na palavra secreta
int letraexiste(char letra) {
    for(int j = 0; j < strlen(palavrasecreta); j++) {
        if(letra == palavrasecreta[j]) {
            return 1;
        }
    }
    return 0;
}

// Função que conta o número de chutes errados
int chuteserrados() {
    int erros = 0;
    for(int i = 0; i < chutesdados; i++) {
        if(!letraexiste(chutes[i])) {
            erros++;
        }
    }
    return erros;
}

// Função que verifica se o jogador foi enforcado (baseado no número máximo de chutes)
int enforcou() {
    return chuteserrados() >= maxChutes;
}

// Função que verifica se o jogador ganhou
int ganhou() {
    for(int i = 0; i < strlen(palavrasecreta); i++) {
        if(!jachutou(palavrasecreta[i])) {
            return 0;
        }
    }
    return 1;
}

// Função de abertura do jogo
void abertura() {
    printf("/****************/\n");
    printf("/ Jogo de Forca */\n");
    printf("/****************/\n\n");
}

/* 
1) Não permitir que o usuário digite nada além de letras maiúsculas:
   Adicionado um laço que garante que o usuário só pode inserir letras de 'A' a 'Z'.
   Caso o caractere esteja fora desse intervalo, uma nova entrada é solicitada.
*/
void chuta() {
    char chute;
    do {
        printf("Qual letra? ");
        scanf(" %c", &chute);

        // Verifica se o caractere está entre 'A' e 'Z'
        if(chute < 'A' || chute > 'Z') {
            printf("Por favor, insira uma letra MAIÚSCULA entre A e Z.\n");
        }
    } while(chute < 'A' || chute > 'Z'); // Se não estiver no intervalo, repete o pedido

    if(letraexiste(chute)) {
        printf("Você acertou: a palavra tem a letra %c\n\n", chute);
    } else {
        printf("\nVocê errou: a palavra NÃO tem a letra %c\n\n", chute);
    }

    chutes[chutesdados] = chute;
    chutesdados++;
}

// Função que verifica se uma letra já foi chutada
int jachutou(char letra) {
    int achou = 0;
    for(int j = 0; j < chutesdados; j++) {
        if(chutes[j] == letra) {
            achou = 1;
            break;
        }
    }
    return achou;
}

// Função que desenha a forca com base no número de erros
void desenhaforca() {
    int erros = chuteserrados();

    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");

    for(int i = 0; i < strlen(palavrasecreta); i++) {
        if(jachutou(palavrasecreta[i])) {
            printf("%c ", palavrasecreta[i]);
        } else {
            printf("_ ");
        }
    }
    printf("\n");
}

/* 
2) Não permitir a inserção de palavras duplicadas:
   Adicionada uma função `palavraexiste` que verifica se a palavra já está no arquivo antes de adicioná-la.
*/
int palavraexiste(char* palavra) {
    FILE* f = fopen("palavras.txt", "r");
    if(f == 0) {
        printf("Banco de dados de palavras não disponível\n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    char palavraexistente[TAMANHO_PALAVRA];
    for(int i = 0; i < qtddepalavras; i++) {
        fscanf(f, "%s", palavraexistente);
        if(strcmp(palavra, palavraexistente) == 0) { //Compara - se iguais retorna 0
            fclose(f);
            return 1; // Palavra já existe
        }
    }

    fclose(f);
    return 0; // Palavra não existe
}

// Função para escolher uma palavra aleatória
void escolhepalavra() {
    FILE* f;
    f = fopen("palavras.txt", "r");
    if(f == 0) {
        printf("Banco de dados de palavras não disponível\n\n");
        exit(1);
    }

    int qtddepalavras;
    fscanf(f, "%d", &qtddepalavras);

    srand(time(0));
    int randomico = rand() % qtddepalavras;

    for(int i = 0; i <= randomico; i++) {
        fscanf(f, "%s", palavrasecreta);
    }

    fclose(f);
}

/* 
3) Só permitir a inserção de uma nova palavra se o jogador ganhar:
   A função `adicionapalavra` só é chamada após a vitória do jogo.
*/
void adicionapalavra() {
    char quer;

    printf("Você deseja adicionar uma nova palavra no jogo (S/N)?");
    scanf(" %c", &quer);

    if(quer == 'S') {
        char novapalavra[TAMANHO_PALAVRA];

        printf("Digite a nova palavra, em letras maiúsculas: ");
        scanf("%s", novapalavra);

        if(palavraexiste(novapalavra)) {
            printf("Essa palavra já existe no banco de dados!\n");
        } else {
            FILE* f = fopen("palavras.txt", "r+");
            if(f == 0) {
                printf("Banco de dados de palavras não disponível\n\n");
                exit(1);
            }

            int qtd;
            fscanf(f, "%d", &qtd);
            qtd++;
            fseek(f, 0, SEEK_SET);
            fprintf(f, "%d", qtd);

            fseek(f, 0, SEEK_END);
            fprintf(f, "\n%s", novapalavra);

            fclose(f);
            printf("Palavra adicionada com sucesso!\n");
        }
    }
}

/*
4) Perguntar ao usuário o nível de dificuldade:
   Adicionada uma função `configuraDificuldade` que permite ao usuário escolher o nível de dificuldade.
   O número máximo de chutes é ajustado de acordo com a dificuldade escolhida.
*/
void configuraDificuldade() {
    int dificuldade;
    printf("Escolha o nível de dificuldade (1 - Fácil, 2 - Médio, 3 - Difícil): ");
    scanf("%d", &dificuldade);

    switch(dificuldade) {
        case 1:
            maxChutes = 10; // Fácil
            break;
        case 2:
            maxChutes = 7;  // Médio
            break;
        case 3:
            maxChutes = 5;  // Difícil
            break;
        default:
            printf("Nível de dificuldade inválido. Definindo como Fácil.\n");
            maxChutes = 10;
    }
}

/* 
5) Ao final do jogo, salvar o nome do usuário e sua pontuação em um arquivo ranking.txt:
   Adicionada uma função `salvarRanking` que solicita o nome do usuário e salva a pontuação no arquivo `ranking.txt`.
*/
void salvarRanking(int pontuacao) {
    char nome[50];
    FILE* f = fopen("ranking.txt", "a");
    if(f == 0) {
        printf("Não foi possível abrir o arquivo de ranking.\n");
        return;
    }

    printf("Digite seu nome: ");
    scanf(" %49[^\n]", nome); // Lê o nome do usuário, permitindo espaços

    fprintf(f, "%s: %d\n", nome, pontuacao);
    fclose(f);
}

int main() {
    abertura();
    configuraDificuldade(); // Solicita o nível de dificuldade
    escolhepalavra();

    int pontuacao = 0; // Armazena a pontuação

    do {
        desenhaforca();
        chuta();
    } while (!ganhou() && !enforcou());

    if(ganhou()) {
        printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");

        pontuacao = maxChutes - chuteserrados(); // Pontuação baseada no número de chutes restantes
        printf("Sua pontuação é: %d\n", pontuacao);

        adicionapalavra(); // Permite adicionar nova palavra apenas após ganhar
        salvarRanking(pontuacao); // Salva o nome do usuário e a pontuação
    } else {
        printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavrasecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
    }
}
