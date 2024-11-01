#include <stdio.h>
#include <math.h>
#include <ctype.h>

// Questão 1
void questao1() {
    int x;
    printf("Digite um valor inteiro decimal para converter: ");
    scanf("%d", &x);
    printf("Hexadecimal: %X\n", x);
    printf("Octal: %o\n", x);
}

// Questão 2
void questao2() {
    float valor;
    printf("Digite um valor real: ");
    scanf("%f", &valor);
    printf("Valor com uma casa decimal: %.1f\n", valor);
}

// Questão 3
void questao3() {
    int x;
    printf("Digite um valor inteiro: ");
    scanf("%d", &x);
    printf("Triplo: %d\n", 3 * x);
    printf("Quadrado: %d\n", x * x);
    printf("Metade: %.1f\n", x / 2.0);
}

// Questão 4
void questao4() {
    float conta;
    printf("Digite o valor da conta: ");
    scanf("%f", &conta);
    printf("Valor total com taxa: %.2f\n", conta * 1.1);
}

// Questão 5
void questao5() {
    float altura;
    char sexo;
    printf("Digite sua altura (em metros): ");
    scanf("%f", &altura);
    printf("Digite seu sexo (M/F): ");
    scanf(" %c", &sexo);
    
    sexo = toupper(sexo);
    if (sexo == 'M') {
        printf("Peso ideal: %.2f\n", 72.7 * altura - 58);
    } else if (sexo == 'F') {
        printf("Peso ideal: %.2f\n", 62.1 * altura - 44.7);
    } else {
        printf("Sexo inválido.\n");
    }
}

// Questão 6
void questao6() {
    int horas, minutos, segundos, total;
    printf("Digite as horas: ");
    scanf("%d", &horas);
    printf("Digite os minutos: ");
    scanf("%d", &minutos);
    printf("Digite os segundos: ");
    scanf("%d", &segundos);

    total = horas * 3600 + minutos * 60 + segundos;
    printf("Total de segundos: %d\n", total);
}

// Questão 7
void questao7() {
    int valor;
    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);
    printf("Quadrado: %d\n", valor * valor);
}

// Questão 8
void questao8() {
    int valor;
    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);
    printf("Antecessor: %d\n", valor - 1);
    printf("Sucessor: %d\n", valor + 1);
}

// Questão 9
void questao9() {
    float comprimento, largura, altura, volume;
    printf("Digite o comprimento: ");
    scanf("%f", &comprimento);
    printf("Digite a largura: ");
    scanf("%f", &largura);
    printf("Digite a altura: ");
    scanf("%f", &altura);

    volume = comprimento * largura * altura;
    printf("Volume: %.2f\n", volume);
}

// Questão 10
void questao10() {
    float cotacao, reais, dolares;
    printf("Digite a cotação do dólar: ");
    scanf("%f", &cotacao);
    printf("Digite o valor em reais: ");
    scanf("%f", &reais);

    dolares = reais / cotacao;
    printf("Valor em dólares: %.2f\n", dolares);
}

// Questão 11
void questao11() {
    int num1, num2;
    printf("Digite o primeiro número: ");
    scanf("%d", &num1);
    printf("Digite o segundo número: ");
    scanf("%d", &num2);

    printf("Soma: %d\n", num1 + num2);
    printf("Produto: %d\n", num1 * num2);
    printf("Diferença: %d\n", num1 - num2);
    printf("Quociente: %d\n", num1 / num2);
    printf("Resto: %d\n", num1 % num2);
}

// Questão 12
void questao12() {
    int a, b, temp;
    printf("Digite o valor de A: ");
    scanf("%d", &a);
    printf("Digite o valor de B: ");
    scanf("%d", &b);

    temp = a;
    a = b;
    b = temp;

    printf("Após a troca:\nA: %d\nB: %d\n", a, b);
}

// Questão 13
void questao13() {
    float celsius, fahrenheit;
    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &celsius);

    fahrenheit = (9 * celsius + 160) / 5;
    printf("Temperatura em Fahrenheit: %.2f\n", fahrenheit);
}

// Questão 14
void questao14() {
    int dias;
    float salario_bruto, salario_liquido, gratificacao = 0.0;
    printf("Digite o número de dias trabalhados: ");
    scanf("%d", &dias);

    salario_bruto = dias * 50.25;

    if (dias > 20) {
        gratificacao = salario_bruto * 0.3;
    } else if (dias > 10) {
        gratificacao = salario_bruto * 0.2;
    }

    salario_liquido = (salario_bruto + gratificacao) * 0.9; 
    printf("Salário líquido: %.2f\n", salario_liquido);
}

// Questão 15
void questao15() {
    float valor_hora, horas, desconto_inss, salario_bruto, salario_liquido;
    printf("Digite o valor da hora-aula: ");
    scanf("%f", &valor_hora);
    printf("Digite o número de horas trabalhadas: ");
    scanf("%f", &horas);
    printf("Digite o percentual de desconto do INSS: ");
    scanf("%f", &desconto_inss);

    salario_bruto = valor_hora * horas;
    salario_liquido = salario_bruto * (1 - desconto_inss / 100);

    printf("Salário bruto: %.2f\n", salario_bruto);
    printf("Salário líquido: %.2f\n", salario_liquido);
}

// Questão 16
void questao16() {
    int valor;
    printf("Digite um valor inteiro: ");
    scanf("%d", &valor);
    printf("Valor absoluto: %d\n", abs(valor));
}

// Questão 17
void questao17() {
    float raio;
    printf("Digite o raio do círculo: ");
    scanf("%f", &raio);

    printf("Diâmetro: %.2f\n", 2 * raio);
    printf("Circunferência: %.2f\n", 2 * 3.14159 * raio);
    printf("Área: %.2f\n", 3.14159 * raio * raio);
}

// Questão 18
void questao18() {
    printf("Retângulo:\n");
    printf("**********\n");
    printf("*        *\n");
    printf("**********\n\n");

    printf("Elipse:\n");
    printf("   ***   \n");
    printf(" *     * \n");
    printf("   ***   \n\n");

    printf("Seta:\n");
    printf("   *\n");
    printf("  ***\n");
    printf(" *****\n");
    printf("   *\n");
    printf("   *\n\n");

    printf("Losango:\n");
    printf("   *\n");
    printf("  * *\n");
    printf(" *   *\n");
    printf("  * *\n");
    printf("   *\n");
}

// Questão 19
void questao19() {
    int numero;
    printf("Digite um número: ");
    scanf("%d", &numero);
    printf("O número é %s\n", (numero % 2) ? "ímpar" : "par");
}

// Questão 20
void questao20() {
    int a, b;
    printf("Digite o primeiro número: ");
    scanf("%d", &a);
    printf("Digite o segundo número: ");
    scanf("%d", &b);
    printf("%d %s múltiplo de %d\n", a, (a % b) ? "não é" : "é", b);
}

// Questão 21
void questao21() {
    printf("A: %d\n", 'A');
    printf("B: %d\n", 'B');
    printf("C: %d\n", 'C');
    printf("a: %d\n", 'a');
    printf("b: %d\n", 'b');
    printf("c: %d\n", 'c');
    printf("0: %d\n", '0');
    printf("1: %d\n", '1');
    printf("2: %d\n", '2');
    printf("$: %d\n", '$');
    printf("*: %d\n", '*');
    printf("+: %d\n", '+');
    printf("/: %d\n", '/');
    printf("Espaço: %d\n", ' ');
}

// Questão 22
void questao22() {
    int numero, invertido = 0;
    printf("Digite um número de três dígitos: ");
    scanf("%d", &numero);

    while (numero != 0) {
        invertido = invertido * 10 + numero % 10;
        numero /= 10;
    }

    printf("Número invertido: %d\n", invertido);
}

// Questão 23
void questao23() {
    int x, n;
    printf("Digite o valor de x: ");
    scanf("%d", &x);
    printf("Digite o valor de n: ");
    scanf("%d", &n);

    printf("Resultado: %d\n", x << n); // Usando operador binário de deslocamento
}

// Questão 24
void questao24() {
    int tempo, horas, minutos, segundos;
    printf("Digite o tempo em segundos: ");
    scanf("%d", &tempo);

    horas = tempo / 3600;
    minutos = (tempo % 3600) / 60;
    segundos = tempo % 60;

    printf("%d horas, %d minutos e %d segundos\n", horas, minutos, segundos);
}

// Questão 25
void questao25() {
    float x1, y1, x2, y2, distancia;
    printf("Digite as coordenadas x e y do primeiro ponto: ");
    scanf("%f %f", &x1, &y1);
    printf("Digite as coordenadas x e y do segundo ponto: ");
    scanf("%f %f", &x2, &y2);

    distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    printf("Distância entre os pontos: %.2f\n", distancia);
}

// Questão 26
void questao26() {
    float num1, num2, num3;
    printf("Digite três números: ");
    scanf("%f %f %f", &num1, &num2, &num3);

    float media_aritmetica = (num1 + num2 + num3) / 3;
    float media_geometrica = pow(num1 * num2 * num3, 1.0/3.0);

    printf("Média aritmética: %.2f\n", media_aritmetica);
    printf("Média geométrica: %.2f\n", media_geometrica);
}

// Função para escolher a questão
void menu() {
    int escolha;
    printf("Digite o número da questão que deseja executar (1 a 26), ou 0 para sair: ");
    scanf("%d", &escolha);

    switch(escolha) {
        case 1: questao1(); break;
        case 2: questao2(); break;
        case 3: questao3(); break;
        case 4: questao4(); break;
        case 5: questao5(); break;
        case 6: questao6(); break;
        case 7: questao7(); break;
        case 8: questao8(); break;
        case 9: questao9(); break;
        case 10: questao10(); break;
        case 11: questao11(); break;
        case 12: questao12(); break;
        case 13: questao13(); break;
        case 14: questao14(); break;
        case 15: questao15(); break;
        case 16: questao16(); break;
        case 17: questao17(); break;
        case 18: questao18(); break;
        case 19: questao19(); break;
        case 20: questao20(); break;
        case 21: questao21(); break;
        case 22: questao22(); break;
        case 23: questao23(); break;
        case 24: questao24(); break;
        case 25: questao25(); break;
        case 26: questao26(); break;
        case 0: printf("Saindo...\n"); break;
        default: printf("Opção inválida. Tente novamente.\n"); break;
    }
}

int main() {
    int opcao;
    do {
        menu();
        printf("\nDeseja escolher outra questão? Digite 1 para sim, 0 para não: ");
        scanf("%d", &opcao);
    } while(opcao != 0);

    return 0;
}
