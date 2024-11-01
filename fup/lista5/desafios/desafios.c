#include <stdio.h>
#include <math.h>

/* Escreva uma função que receba dois inteiros, a e b, e calcule a potência a^b */
void calcularPotencia() {
    int a, b, resultado = 1;  // resultado inicializado com 1

    printf("Digite o valor de A (inteiro): ");
    scanf("%d", &a);

    printf("Digite o valor de B (inteiro): ");
    scanf("%d", &b);

    // Calcula a potência de 'a' elevado a 'b'
    for (int i = 0; i < b; i++) {  // O loop deve rodar b vezes
        resultado = resultado * a;
    }

    printf("A elevado a B: %d\n", resultado);  // Passa o valor, não o endereço
}

/* Escreva um programa que peça um número ao usuário e, com esse
número, faça o programa escrever um arquivo tabuada.txt com a
tabuada de 1 até 20 daquele número. Supondo o número 2 de entrada, a
saída deve ser no formato 2 x 1 = 2, e assim por diante. */

void tabuada() {
    int numero;
    FILE *arquivo;  // Ponteiro para o arquivo

    // Solicita ao usuário um número
    printf("Digite um número: ");
    scanf("%d", &numero);

    // Abre o arquivo "tabuada.txt" no modo de escrita
    arquivo = fopen("tabuada.txt", "w");

    // Verifica se o arquivo foi aberto com sucesso
    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo!\n");
        return 1;  // Encerra o programa em caso de erro
    }

    // Escreve a tabuada de 1 até 20 no arquivo
    for (int i = 1; i <= 20; i++) {
        fprintf(arquivo, "%d x %d = %d\n", numero, i, numero * i);
    }

    // Fecha o arquivo
    fclose(arquivo);

    // Informa o usuário que o arquivo foi criado
    printf("Tabuada do número %d foi gravada no arquivo 'tabuada.txt'.\n", numero);
}

/* Dados n e uma sequência de n números inteiros, determinar a soma dos
números pares. */

void somapares(){
    int n, num, soma_pares = 0;

    // Solicita ao usuário o valor de n
    printf("Digite o valor de n (quantidade de números): ");
    scanf("%d", &n);

    // Definir os números da sequência 
    for (int i = 0; i < n; i++){
        printf("Digite o número %d", i);
        scanf("%d", &num);

        // Verifica se o número é par
        if (num % 2 == 0){
            soma_pares = soma_pares + num;
        }
    }

     printf("Total da soma dos números pares: %d\n", soma_pares);
}
/* 4) Escreva uma função que nos diz se um número é primo ou não. */

/* Função que nos diz se um número é primo ou não */
int ehPrimo(int num) {
    if (num <= 1) {
        return 0;  // Números menores ou iguais a 1 não são primos
    }
    if (num == 2) {
        return 1;  // O número 2 é o único número primo par
    }
    if (num % 2 == 0) {
        return 0;  // Números pares maiores que 2 não são primos
    }

    // Verifica divisores de 3 até a raiz quadrada de num
    for (int i = 3; i <= sqrt(num); i += 2) {
        if (num % i == 0) {
            return 0;  // Se for divisível por qualquer i, não é primo
        }
    }
    
    return 1;  // Se não encontrou divisores, o número é primo
}

/* Função para solicitar e verificar se o número é primo */
void verificarPrimo() {
    int numero;

    printf("Digite um numero para verificar se e primo: ");
    scanf("%d", &numero);

    if (ehPrimo(numero)) {
        printf("%d e um número primo.\n", numero);
    } else {
        printf("%d não e um número primo.\n", numero);
    }
}

/* Função que calcula a soma dos primos em um intervalo */
void somaPrimosNoIntervalo() {
    int num1, num2, soma = 0;

    // Solicita dois números ao usuário
    printf("Digite o primeiro número do intervalo: ");
    scanf("%d", &num1);
    printf("Digite o segundo número do intervalo: ");
    scanf("%d", &num2);

    // Garantir que num1 seja menor ou igual a num2
    if (num1 > num2) {
        int temp = num1;
        num1 = num2;
        num2 = temp;
    }

    // Verifica todos os números no intervalo [num1, num2]
    for (int i = num1; i <= num2; i++) {
        if (ehPrimo(i)) {
            soma += i;  // Se for primo, adiciona à soma
        }
    }

    // Exibe a soma dos números primos no intervalo
    printf("A soma dos números primos no intervalo [%d, %d] é: %d\n", num1, num2, soma);
}

/* Função que soma todos os elementos de um array */
int somaArray(int arr[], int tamanho) {
    int soma = 0;
    for (int i = 0; i < tamanho; i++) {
        soma += arr[i];  // Adiciona cada elemento à soma
    }
    return soma;
}

/* Função para ler e somar elementos de um array */
void lerESomarArray() {
    int n;

    // Solicita o número de elementos
    printf("Digite o número de elementos do array: ");
    scanf("%d", &n);

    int arr[n];  // Cria um array com o tamanho fornecido

    // Lê os elementos do array
    printf("Digite os %d elementos do array:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Elemento %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Calcula a soma dos elementos do array
    int soma = somaArray(arr, n);
    printf("A soma dos elementos do array é: %d\n", soma);
}


int main() {
    calcularPotencia();
    tabuada();
    somapares();
    verificarPrimo();
    somaPrimosNoIntervalo();
    lerESomarArray();
    return 0;
}
