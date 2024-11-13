#include <stdio.h>
#include <math.h>

// Questao 1
void questao1() {
    int dia;
    while (1) {
        printf("Digite um numero de 1 a 7 para o dia da semana (0 para sair): ");
        scanf("%d", &dia);
        if (dia == 0) break;
        switch (dia) {
            case 1: printf("domingo\n"); break;
            case 2: printf("segunda\n"); break;
            case 3: printf("terça\n"); break;
            case 4: printf("quarta\n"); break;
            case 5: printf("quinta\n"); break;
            case 6: printf("sexta\n"); break;
            case 7: printf("sabado\n"); break;
            default: printf("Numero de dia nao valido\n");
        }
    }
}

// Questao 2
void questao2() {
    int dia;
    do {
        printf("Digite um numero de 1 a 7 para o dia da semana (0 para sair): ");
        scanf("%d", &dia);
        switch (dia) {
            case 1: printf("Domingo\n"); break;
            case 2: printf("Segunda\n"); break;
            case 3: printf("Terça\n"); break;
            case 4: printf("Quarta\n"); break;
            case 5: printf("Quinta\n"); break;
            case 6: printf("Sexta\n"); break;
            case 7: printf("Sabado\n"); break;
            default: if (dia != 0) printf("Numero de dia nao valido\n");
        }
    } while (dia != 0);
}

// Questao 3
void questao3() {
    int F, fatorial = 1;
    printf("Digite um numero inteiro positivo p/ calcular o fatorial: ");
    scanf("%d", &F);
    for (int i = 1; i <= F; i++) fatorial *= i;
    printf("Fatorial de %d e %d\n", F, fatorial);
}

// Questao 4
void questao4() {
    int anos = 0;
    int jose = 150, pedro = 110;
    while (pedro <= jose) {
        jose += 2;
        pedro += 3;
        anos++;
    }
    printf("Pedrinho vai ser maior que Jose em %d anos\n", anos);
}

// Questao 5
void questao5() {
    int numero, maior = 0, menor = 0, primeiro = 1;
    do {
        printf("Digite um valor (0 para sair): ");
        scanf("%d", &numero);
        if (numero != 0) {
            if (primeiro) {
                maior = menor = numero;
                primeiro = 0;
            } else {
                if (numero > maior) maior = numero;
                if (numero < menor) menor = numero;
            }
        }
    } while (numero != 0);
    printf("Maior numero: %d, Menor numero: %d\n", maior, menor);
}

// Questao 6
void questao6() {
    int voto, paulo = 0, renata = 0, branco = 0, nulo = 0;
    while (1) {
        printf("Vote [5-Paulo, 7-Renata, 0-Branco, outro-Nulo] (numero negativo para encerrar): ");
        scanf("%d", &voto);
        if (voto < 0) break;
        if (voto == 5) paulo++;
        else if (voto == 7) renata++;
        else if (voto == 0) branco++;
        else nulo++;
    }
    int total = paulo + renata + branco + nulo;
    printf("Paulo: %.2f%%\nRenata: %.2f%%\nBranco: %.2f%%\nNulo: %.2f%%\n", 
           (paulo*100.0)/total, (renata*100.0)/total, (branco*100.0)/total, (nulo*100.0)/total);
    if (paulo > renata) printf("Candidato eleito: Paulo\n");
    else if (renata > paulo) printf("Candidato eleito: Renata\n");
    else printf("Empate\n");
}

// Questao 7
void questao7() {
    float a, b;
    printf("Digite o dividendo: ");
    scanf("%f", &a);
    do {
        printf("Digite o divisor (nao pode ser zero): ");
        scanf("%f", &b);
    } while (b == 0);
    printf("Resultado da divisao: %.2f\n", a / b);
}

// Questao 8
void questao8() {
    float valor;
    printf("Digite o valor da mercadoria: ");
    scanf("%f", &valor);
    int entrada = (int)(valor / 3) + (int)(valor / 3 != valor / 3.0); 
    int prestacao = (int)((valor - entrada) / 2);
    printf("Entrada: R$ %d\n2 Prestações de: R$ %d\n", entrada, prestacao);
}

// Questao 9
void questao9() {
    int a = 1, b = 1, c;
    printf("%d %d ", a, b);
    for (int i = 3; i <= 20; i++) {
        c = a + b;
        printf("%d ", c);
        a = b;
        b = c;
    }
    printf("\n");
}

// Questao 10
void questao10() {
    for (int i = 16; i <= 90; i += 4) {
        printf("Quadrado de %d: %d\n", i, i * i);
    }
}

// Questao 11
void questao11() {
    int a, b;
    printf("Digite o limite inferior: ");
    scanf("%d", &a);
    printf("Digite o limite superior: ");
    scanf("%d", &b);
    if (a > b) { int temp = a; a = b; b = temp; }
    for (int i = a; i <= b; i++) if (i % 4 == 0) printf("Quadrado de %d: %d\n", i, i * i);
}

// Questao 12
void questao12() {
    int n;
    printf("Digite um numero: ");
    scanf("%d", &n);
    for (int i = 1; i <= 10; i++) printf("%d x %d = %d\n", n, i, n * i);
}

// Questao 13
void questao13() {
    int a, b, soma = 0;
    printf("Digite o limite inferior: ");
    scanf("%d", &a);
    printf("Digite o limite superior: ");
    scanf("%d", &b);
    if (a > b) { int temp = a; a = b; b = temp; }
    for (int i = a; i <= b; i++) if (i % 2 == 0) soma += i;
    printf("Somatório dos numeros pares: %d\n", soma);
}

// Questao 14
void questao14() {
    int a, b, count = 0;
    printf("Digite o limite inferior: ");
    scanf("%d", &a);
    printf("Digite o limite superior: ");
    scanf("%d", &b);
    if (a > b) { int temp = a; a = b; b = temp; }
    for (int i = a; i <= b; i++) if (i % 3 == 0) count++;
    printf("Quantidade de divisiveis por 3: %d\n", count);
}

// Questao 15
void questao15() {
    for (int i = 0; i <= 7; i++) printf("3^%d = %d\n", i, (int)pow(3, i));
}

// Questao 16
void questao16() {
    int soma = 0;
    for (int i = 0; i <= 200; i++) {
        if ((i <= 100 || (i > 100 && i <= 200)) && i % 5 == 0) soma += i;
    }
    printf("Somatório dos divisiveis por 5 em [0,100] e ]100,200]: %d\n", soma);
}

// Questao 17
void questao17() {
    for (int celsius = 10; celsius <= 100; celsius += 10) {
        printf("%d °C = %.2f °F\n", celsius, celsius * 9.0 / 5.0 + 32);
    }
}

// Questao 18
void questao18() {
    unsigned long long int graos = 1, total = 1;
    for (int i = 2; i <= 64; i++) {
        graos *= 2;
        total += graos;
    }
    printf("Total de graos no tabuleiro: %llu\n", total);
}

// Questao 19
void questao19() {
    int a, b, soma = 0, count = 0;
    printf("Digite o limite inferior: ");
    scanf("%d", &a);
    printf("Digite o limite superior: ");
    scanf("%d", &b);
    if (a > b) { int temp = a; a = b; b = temp; }
    for (int i = a; i <= b; i++) { soma += i; count++; }
    printf("Media aritmetica: %.2f\n", soma / (float)count);
}

// Questao 20
void questao20() {
    int fatorial;
    for (int i = 1; i <= 10; i += 2) {
        fatorial = 1;
        for (int j = 1; j <= i; j++) fatorial *= j;
        printf("Fatorial de %d e %d\n", i, fatorial);
    }
}

// Questao 21
void questao21() {
    int numero, dig1, dig2, dig4, dig5;
    printf("Digite um numero de 5 digitos: ");
    scanf("%d", &numero);
    dig1 = numero / 10000;
    dig2 = (numero / 1000) % 10;
    dig4 = (numero / 10) % 10;
    dig5 = numero % 10;
    if (dig1 == dig5 && dig2 == dig4) printf("e um palindromo\n");
    else printf("Nao e um palindromo\n");
}

// Questao 22
void questao22() {
    int numero, count = 0;
    printf("Digite um numero inteiro: ");
    scanf("%d", &numero);
    while (numero) {
        if (numero % 10 == 7) count++;
        numero /= 10;
    }
    printf("Quantidade de digitos 7: %d\n", count);
}

// Questao 23
void questao23() {
    int x = 5;
    printf("x antes: %d\n", x);
    printf("Pre-incremento: %d\n", ++x);
    printf("x depois: %d\n", x);
    printf("Pós-incremento: %d\n", x++);
    printf("x final: %d\n", x);
}

// Questao 24
void questao24() {
    for (int a = 1; a <= 500; a++) {
        for (int b = a; b <= 500; b++) {
            for (int c = b; c <= 500; c++) {
                if (a * a + b * b == c * c) printf("(%d, %d, %d) e uma tripla de Pitagoras\n", a, b, c);
            }
        }
    }
}

// Questao 25
void questao25() {
    int termos;
    double pi = 0.0;
    printf("Numero de termos | Valor aproximado de π\n");
    for (termos = 1; termos <= 100; termos++) {
        if (termos % 2 == 1) pi += 4.0 / (2 * termos - 1);
        else pi -= 4.0 / (2 * termos - 1);
        printf("      %d         | %.15f\n", termos, pi);
    }
}

// Questao 26
void questao26() {
    printf("Decimal | Binario       | Octal | Hexadecimal\n");
    for (int i = 1; i <= 256; i++) {
        printf("%7d | %10b | %5o | %7X\n", i, i, i, i);
    }
}

// Questao 27
void questao27() {
    int numero, maior = 0, menor = 0, primeiro_numero = 1;
    while (1) {
        printf("digite um numero (numero par negativo para sair): ");
        scanf("%d", &numero);
        if (numero < 0 && numero % 2 == 0) break;
        if (primeiro_numero) {
            maior = menor = numero;
            primeiro_numero = 0;
        } else {
            if (numero > maior) maior = numero;
            if (numero < menor) menor = numero;
        }
    }
    if (maior && menor) printf("Produto do maior pelo menor: %d\n", maior * menor);
    else printf("nenhum numero foi digitado.\n");
}

// Questao 28
void questao28() {
    unsigned char X, Y, resultado;
    printf("Digite o valor de X (0 a 255): ");
    scanf("%hhu", &X);
    do {
        printf("Digite o valor de Y (maior ou igual a 5): ");
        scanf("%hhu", &Y);
    } while (Y < 5);
    printf("Bits de X: ");
    for (int i = 7; i >= 0; i--) printf("%d", (X >> i) & 1);
    printf("\n");
    for (int i = -4; i <= 4; i++) {
        if (i == 0) continue;
        resultado = (Y + i) & 0xFE | (X >> (7 - i) & 1);
        printf("Valor de Y + %d com bit de X escondido: %hhu\n", i, resultado);
    }
}

int main() {
    // Chamadas para as funções das questões
    questao1();
    questao2();
    questao3();
    questao4();
    questao5();
    questao6();
    questao7();
    questao8();
    questao9();
    questao10();
    questao11();
    questao12();
    questao13();
    questao14();
    questao15();
    questao16();
    questao17();
    questao18();
    questao19();
    questao20();
    questao21();
    questao22();
    questao23();
    questao24();
    questao25();
    questao26();
    questao27();
    questao28();
    
    return 0;
}
