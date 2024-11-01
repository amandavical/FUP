#include <stdio.h>

/*
1) Escreva um programa que imprima todos os números pares entre 2 e
50. Para saber se o número é par, basta você ver se o resto da divisão
do número por 2 é igual a 0.
*/

void calcularNumerosPares(){
  for(int i = 2; i <= 50; i++ ){
    if (i % 2 == 0){
        printf("%d\n", i);
    }
  }
}

/*
2) Escreva um programa que imprima a soma de todos os números de
1 até 100. Ou seja, ele calculará o resultado de 1 + 2 + 3 + 4 + ... + 100.
*/

void somaNumeros1a100(){
    int soma = 0;
    for (int i = 1; i <= 100; i++){
       soma = soma + i; 
       printf("%d + %d = %d\n", i, soma - i, soma);  
    }
    printf("Resultado da soma dos numeros de 1 a 100: %d\n", soma);
}

/*
3) Escreva um programa que peça um inteiro ao usuário, e com esse
inteiro, ele imprima, linha a linha, a tabuada daquele número até o 10.
Por exemplo, se ele escolher o número 2, o programa imprimirá: 2x1=2,
2x2=4, 2x3=6, ..., 2x10=20.
*/

 void calcularTabuada(){
    int numero = 0;
    int multiplicacao = 0;
    printf("Digite um numero para ver a tabuada dele:");
    scanf("%d", &numero);
    for (int i = 0; i <= 10; i++){
        multiplicacao = numero * i;
        printf("%d x %d = %d\n", numero, i, multiplicacao);
    }
 }

/*
 4) Implemente uma calculadora. O programa deve pedir 3 números ao
usuário: a, b e operação. Se operação for igual a 1, você deverá
imprimir a soma de a + b. Se ela for 2, a subtração. Se for 3, a
multiplicação. Se for 4, a divisão.
*/

void calculadora(){
    float a, b;
    int operacao;

    printf("Digite o primeiro numero:");
    scanf("%f", &a);

    printf("Digite o segundo numero:");
    scanf("%f", &b);

    printf("Escolha a operação (1 - Soma, 2 - Subtracao, 3 - Multiplicacao, 4 - Divisao): ");
    scanf("%d", &operacao);

    switch (operacao) {
        case 1:
            printf("Resultado da soma: %.2f\n", a + b);
            break;
        case 2:
            printf("Resultado da subtracao: %.2f\n", a - b);
            break;
        case 3:
            printf("Resultado da multiplicaçao: %.2f\n", a * b);
            break;
        case 4:
            if (b != 0) {
                printf("Resultado da divisao: %.2f\n", a / b);
            } else {
                printf("Erro! Divisao por zero nao é permitida.\n");
            }
            break;
        default:
            printf("Escolha uma operacao valida.\n");
    }
}

/*
5) Escreva um programa que peça um número inteiro ao usuário e
imprima o fatorial desse número. Para calcular o fatorial, basta ir
multiplicando pelos números anteriores até 1. Por exemplo, o fatorial
de 4 é 4 * 3 * 2 * 1, que é igual a 24.
*/

void calcularFatorial(){
    int n;
    unsigned long fatorial = 1;  // Usa unsigned long para suportar números maiores

    printf("Digite um numero inteiro para calcular o fatorial: ");
    scanf("%d", &n);

    if (n < 0) {
        printf("Fatorial nao aceita numeros negativos.\n");
    } else {
        // Calcula o fatorial
        for (int i = 1; i <= n; i++) {
            fatorial *= i;
        }
        printf("fatorial de %d: %lu\n", n, fatorial);
    }
}

// 6) Dados três números, imprimi-los em ordem crescente.

void numerarOrdemCrescente() {
    int num1, num2, num3;

    printf("Digite o primeiro numero: ");
    scanf("%d", &num1);
    printf("Digite o segundo numero: ");
    scanf("%d", &num2);
    printf("Digite o terceiro numero: ");
    scanf("%d", &num3);

    // Caso 1: num1 é o menor número
    if (num1 <= num2 && num1 <= num3) {
        // num1 é o menor número. Agora determinar a ordem entre num2 e num3
        if (num2 <= num3) {
            // num2 é o segundo menor ou igual a num3
            printf("%d - %d - %d\n", num1, num2, num3);
        } else {
            // num3 é o segundo menor
            printf("%d - %d - %d\n", num1, num3, num2);
        }
    }
    // Caso 2: num2 é o menor número
    else if (num2 <= num1 && num2 <= num3) {
        // num2 é o menor número. Agora determinar a ordem entre num1 e num3
        if (num1 <= num3) {
            // num1 é o segundo menor ou igual a num3
            printf("%d - %d - %d\n", num2, num1, num3);
        } else {
            // num3 é o segundo menor
            printf("%d - %d - %d\n", num2, num3, num1);
        }
    }
    // Caso 3: num3 é o menor número
    else {
        // num3 é o menor número. Agora determinar a ordem entre num1 e num2
        if (num1 <= num2) {
            // num1 é o segundo menor ou igual a num2
            printf("%d - %d - %d\n", num3, num1, num2);
        } else {
            // num2 é o segundo menor
            printf("%d - %d - %d\n", num3, num2, num1);
        }
    }
}

int main(){
    int opcao;

    do {
        printf("\n--- Menu Principal ---\n");
        printf("1 - calcularNumerosPares\n");
        printf("2 - somaNumeros1a100\n");
        printf("3 - calcularTabuada\n");
        printf("4 - calculadora\n");
        printf("5 - calcularFatorial\n");
        printf("6 - numerarOrdemCrescente\n");
        printf("0 - Sair\n");

        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

         switch (opcao) {
            case 1:
               calcularNumerosPares();
                break;
            case 2:
               somaNumeros1a100();
                break;
            case 3: 
                calcularTabuada();
                break;
            case 4:
                calculadora();
                break;
            case 5:
                calcularFatorial();
                break;
            case 6:
                 numerarOrdemCrescente();
                 break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Selecione uma opcao valida.\n");
                break;
          }
    } while (opcao != 0);

    return 0;
}
