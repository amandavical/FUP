#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Questao 1
void trocarValores() {
    printf("\nQuestao 1************************************************\n");
    int a, b, c;
    a = 10;
    b = 20;
    c = a;
    a = b;
    b = c;
    printf("a: %d, b: %d\n", a, b);
}

// Questao 2
void calcularArea() {
    printf("\nQuestao 2************************************************\n");
    float base, altura, area;
    printf("Qual o valor da largura do seu terreno em metros?\n");
    scanf("%f", &base);
    printf("Qual o valor do comprimento do terreno em metros?\n");
    scanf("%f", &altura);
    area = base * altura;
    printf("A area do seu terreno e %.2f metros quadrados\n", area);
}

// Questao 3
void calcularFerraduras() {
    printf("\nQuestao 3************************************************\n");
    int quantidade_cavalos, total_ferraduras;
    printf("Quantos cavalos tem no seu haras?\n");
    scanf("%d", &quantidade_cavalos);
    total_ferraduras = quantidade_cavalos * 4;
    printf("Total de ferraduras necessarias: %d\n", total_ferraduras);
}

// Questao 4
void calcularVendaPaesBroas() {
    printf("\nQuestao 4************************************************\n");
    int quantidade_paes, quantidade_broas;
    float valor_paes, valor_broas, total_venda, valor_poupanca;
    printf("Quantidade de paes vendidos:\n");
    scanf("%d", &quantidade_paes);
    printf("Quantidade de broas vendidas:\n");
    scanf("%d", &quantidade_broas);
    valor_paes = quantidade_paes * 0.50;
    valor_broas = quantidade_broas * 1.50;
    total_venda = valor_paes + valor_broas;
    valor_poupanca = total_venda * 0.10;
    printf("Valor arrecadado com vendas: %.2f\n", total_venda);
    printf("Valor a guardar na poupanca: %.2f\n", valor_poupanca);
}

// Questao 5
void calcularDiasVida() {
    printf("\nQuestao 5************************************************\n");
    int idade_anos, dias_vida;
    printf("Qual e a sua idade em anos?\n");
    scanf("%d", &idade_anos);
    dias_vida = idade_anos * 365;
    printf("Voce ja viveu aproximadamente %d dias.\n", dias_vida);
}

// Questao 6
void calcularLitrosGasolina() {
    printf("\nQuestao 6************************************************\n");
    float valor_litro, valor_pagamento, litros_colocados;
    printf("Qual e o preco do litro da gasolina?\n");
    scanf("%f", &valor_litro);
    printf("Quanto voce pagou pela gasolina?\n");
    scanf("%f", &valor_pagamento);
    litros_colocados = valor_pagamento / valor_litro;
    printf("Voce conseguiu colocar %.2f litros de gasolina no tanque.\n", litros_colocados);
}

// Questao 7
void calcularValorRefeicao() {
    printf("\nQuestao 7************************************************\n");
    float peso_prato, valor_pagar;
    printf("Qual e o peso do prato montado pelo cliente (em quilos)?\n");
    scanf("%f", &peso_prato);
    valor_pagar = peso_prato * 32.00;
    printf("Valor a pagar: %.2f\n", valor_pagar);
}

// Questao 8
void calcularDiasPassados() {
    printf("\nQuestao 8************************************************\n");
    int dia, mes, dias_passados;
    printf("Digite o dia:\n");
    scanf("%d", &dia);
    printf("Digite o mes:\n");
    scanf("%d", &mes);
    dias_passados = (mes - 1) * 30 + dia;
    printf("Dias passados desde o inicio do ano: %d\n", dias_passados);
}

// Questao 9
void valorBlusas() {
    printf("\nQuestao 9************************************************\n");
    int qtd_blusaP, qtd_blusaM, qtd_blusaG;
    float valor_total;
    printf("Qual a quantidade de camisetas pequenas vendidas?\n");
    scanf("%d", &qtd_blusaP);
    printf("Qual a quantidade de camisetas medias vendidas?\n");
    scanf("%d", &qtd_blusaM);
    printf("Qual a quantidade de camisetas grandes vendidas?\n");
    scanf("%d", &qtd_blusaG);
    valor_total = (qtd_blusaP * 10) + (qtd_blusaM * 12) + (qtd_blusaG * 15);
    printf("O valor arrecadado com essa venda e: %.2f\n", valor_total);
}

// Questao 10
void calcularDistancia() {
    printf("\nQuestao 10************************************************\n");
    int x1, y1, x2, y2;
    float distancia;
    
    printf("Coordenada X do primeiro ponto: ");
    scanf("%d", &x1);
    printf("Coordenada Y do primeiro ponto: ");
    scanf("%d", &y1);
    printf("Coordenada X do segundo ponto: ");
    scanf("%d", &x2);
    printf("Coordenada Y do segundo ponto: ");
    scanf("%d", &y2);
    
    distancia = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    printf("A distância entre os pontos e: %.2f\n", distancia);
}


// Questao 11
void calcularTempoSemAcidentes() {
    printf("\nQuestao 11************************************************\n");
    int dias_trabalhados;
    printf("Digite a quantidade de dias de trabalho sem acidentes: ");
    scanf("%d", &dias_trabalhados);
    
    printf("O tempo de trabalho sem acidentes e de: %d anos, %d meses e %d dias\n",
           dias_trabalhados / 365, 
           (dias_trabalhados % 365) / 30, 
           (dias_trabalhados % 365) % 30);
}

// Questao 12
void lerSalario() {
    printf("\nQuestao 12************************************************\n");
    float salario_inicial;
    printf("Qual o valor do seu salario? ");
    scanf("%f", &salario_inicial);
    
    printf("Salario inicial: R$ %.2f\n", salario_inicial);
    printf("Salario com o aumento: R$ %.2f\n", salario_inicial * 1.15);
    printf("Salario final: R$ %.2f\n", salario_inicial * 1.15 * 0.92);
}

// Questao 13
void separarDigitos() {
    printf("\nQuestao 13************************************************\n");
    int numero;
    printf("Digite um numero inteiro de ate tres digitos: ");
    scanf("%d", &numero);
    
    printf("CENTENA = %d\n", numero / 100);
    printf("DEZENA = %d\n", (numero % 100) / 10);
    printf("UNIDADE = %d\n", numero % 10);
}

// Questao 14
void calcularAreaPizza() {
    printf("\nQuestao 14************************************************\n");
    const float valor_pi = 3.14;
    float raio_pizza;
    printf("Qual o raio da sua pizza? ");
    scanf("%f", &raio_pizza);
    
    printf("A area da pizza e: %.2f\n", valor_pi * pow(raio_pizza, 2));
}

// Questao 15
void porcentagemVotosEleitores() {
    printf("\nQuestao 15************************************************\n");
    int total_eleitores, votos_validos, votos_brancos, votos_nulos;
    printf("Digite o numero total de eleitores: ");
    scanf("%d", &total_eleitores);
    
    printf("Digite o numero de votos validos: ");
    scanf("%d", &votos_validos);
    
    printf("Digite o numero de votos em branco: ");
    scanf("%d", &votos_brancos);
    
    printf("Digite o numero de votos nulos: ");
    scanf("%d", &votos_nulos);
    
    printf("Percentual de votos validos: %.2f%%\n", (votos_validos * 100.0) / total_eleitores);
    printf("Percentual de votos em branco: %.2f%%\n", (votos_brancos * 100.0) / total_eleitores);
    printf("Percentual de votos nulos: %.2f%%\n", (votos_nulos * 100.0) / total_eleitores);
}

// Questao 16
void calcularIngredientesSanduiche() {
    printf("\nQuestao 16************************************************\n");
    int num_sanduiches;
    printf("Digite a quantidade de sanduiches a fazer: ");
    scanf("%d", &num_sanduiches);
    
    printf("Quantidade de queijo necessaria: %.2f kg\n", (num_sanduiches * 2 * 50) / 1000.0);
    printf("Quantidade de presunto necessaria: %.2f kg\n", (num_sanduiches * 50) / 1000.0);
    printf("Quantidade de carne necessaria: %.2f kg\n", (num_sanduiches * 100) / 1000.0);
}

// Questao 17
void converterCelsiusParaFahrenheit() {
    printf("\nQuestao 17************************************************\n");
    float temperatura_celsius;
    printf("Digite a temperatura em Celsius: ");
    scanf("%f", &temperatura_celsius);
    
    printf("A temperatura em Fahrenheit e: %.2f °F\n", (9.0 / 5.0) * temperatura_celsius + 32);
}

// Questao 18
void calcularSalarioBL() {
    printf("\nQuestao 18************************************************\n");
    float salario_hora_normal, salario_hora_extra, horas_normais, horas_extra;
    printf("Digite o valor do salario por hora normal: ");
    scanf("%f", &salario_hora_normal);
    
    printf("Digite o valor do salario por hora extra: ");
    scanf("%f", &salario_hora_extra);
    
    printf("Digite a quantidade de horas normais trabalhadas: ");
    scanf("%f", &horas_normais);
    
    printf("Digite a quantidade de horas extras trabalhadas: ");
    scanf("%f", &horas_extra);
    
    float salario_bruto = (salario_hora_normal * horas_normais) + (salario_hora_extra * horas_extra);
    printf("Salario bruto: R$ %.2f\n", salario_bruto);
    printf("Salario liquido: R$ %.2f\n", salario_bruto * 0.90);
}

// Questao 19
void calcularGastoGranja() {
    printf("\nQuestao 19************************************************\n");
    int quantidade_frangos;
    printf("Quantidade de frangos na granja: ");
    scanf("%d", &quantidade_frangos);
    
    printf("Gasto total para marcar os frangos: R$ %.2f\n",
           (quantidade_frangos * 4.00) + (quantidade_frangos * 2 * 3.50));
}

// Questao 20
void calcularNovelosPorBlusa() {
    printf("\nQuestao 20************************************************\n");
    int quantidade_blusas, quantidade_novelos;
    printf("Quantidade de blusas de la produzidas: ");
    scanf("%d", &quantidade_blusas);
    
    printf("Quantidade total de novelos de la utilizados: ");
    scanf("%d", &quantidade_novelos);
    
    printf("Quantidade de novelos de la por blusa: %.2f\n", (float)quantidade_novelos / quantidade_blusas);
}

// Questao 21
void calcularLitros() {
    printf("\nQuestao 21************************************************\n");
    int qtd_lata, qtd_garrafaM, qtd_garrafaG;
    printf("Quantas latas de 350ml voce comprou? ");
    scanf("%d", &qtd_lata);
    printf("Quantas garrafas de 600ml voce comprou? ");
    scanf("%d", &qtd_garrafaM);
    printf("Quantas garrafas de 2 litros voce comprou? ");
    scanf("%d", &qtd_garrafaG);
    
    printf("Total de litros de refrigerante comprados: %.2f\n", 
           (qtd_lata * 0.35) + (qtd_garrafaM * 0.6) + (qtd_garrafaG * 2));
}

// Questao 22
void lerMoedas() {
    printf("\nQuestao 22************************************************\n");
    int qtd_moedas_5cent, qtd_moedas_10cent, qtd_moedas_25cent, qtd_moedas_50cent, qtd_moedas_1real;
    printf("Quantidade de moedas de 5 centavos: ");
    scanf("%d", &qtd_moedas_5cent);
    printf("Quantidade de moedas de 10 centavos: ");
    scanf("%d", &qtd_moedas_10cent);
    printf("Quantidade de moedas de 25 centavos: ");
    scanf("%d", &qtd_moedas_25cent);
    printf("Quantidade de moedas de 50 centavos: ");
    scanf("%d", &qtd_moedas_50cent);
    printf("Quantidade de moedas de 1 real: ");
    scanf("%d", &qtd_moedas_1real);
    
    printf("Valor total economizado em reais: %.2f\n", 
           (qtd_moedas_5cent * 0.05) + (qtd_moedas_10cent * 0.1) + (qtd_moedas_25cent * 0.25) + 
           (qtd_moedas_50cent * 0.5) + (qtd_moedas_1real * 1));
}

// Questao 23
void calcularLitrosRefresco() {
    printf("\nQuestao 23************************************************\n");
    float litros_refresco;
    printf("Qual a quantidade de litros de refresco desejada? ");
    scanf("%f", &litros_refresco);
    
    printf("Para %.2f litros de refresco, sao necessarios:\n", litros_refresco);
    printf("agua mineral: %.2f litros\n", (litros_refresco * 8) / 10);
    printf("Suco de maracuja: %.2f litros\n", (litros_refresco * 2) / 10);
}

// Questao 24
void calcularMedia() {
    printf("\nQuestao 24************************************************\n");
    float nota1, nota2;
    printf("Digite sua primeira nota: ");
    scanf("%f", &nota1);
    printf("Digite sua segunda nota: ");
    scanf("%f", &nota2);
    
    printf("A média ponderada das notas é: %.2f\n", 
           ((nota1 * 2) + (nota2 * 3)) / 5);
}

// Questao 25
void salarioComissao() {
    printf("\nQuestao 25************************************************\n");
    float salario_fixo, comissao_vendas;
    printf("Qual seu salario fixo? ");
    scanf("%f", &salario_fixo);
    printf("Qual o valor de suas vendas? ");
    scanf("%f", &comissao_vendas);
    
    printf("Sua comissao: %.2f\n", comissao_vendas * 0.04);
    printf("Salario final: %.2f\n", salario_fixo + (comissao_vendas * 0.04));
}

// Questao 26
void calcularPeso() {
    printf("\nQuestao 26************************************************\n");
    float peso_kg;
    printf("Digite seu peso (kg): ");
    scanf("%f", &peso_kg);
    
    printf("Seu peso em gramas: %.2f\n", peso_kg * 1000);
    printf("Seu novo peso se voce engordar 15%%: %.2f\n", peso_kg * 1.15);
    printf("Seu peso se voce emagrecer 20%%: %.2f\n", peso_kg * 0.80); 
}

// Questao 27
void calcularAreaTrapezio() {
    printf("\nQuestao 27************************************************\n");
    float base_maior, base_menor, altura;
    printf("Digite o valor da base maior do trapézio: ");
    scanf("%f", &base_maior);
    printf("Digite o valor da base menor do trapézio: ");
    scanf("%f", &base_menor);
    printf("Digite o valor da altura do trapézio: ");
    scanf("%f", &altura);
    
    printf("A area do trapézio é: %.2f\n", (base_maior + base_menor) * altura / 2);
}

// Questao 28
void calcularAreaQuadrado() {
    printf("\nQuestao 28************************************************\n");
    float lado;
    printf("Digite o valor do lado do quadrado: ");
    scanf("%f", &lado);
    
    printf("A area do quadrado é: %.2f\n", lado * lado);
}

// Questao 29
void calcularAreaLosango() {
    printf("\nQuestao 29************************************************\n");
    float diagonal_maior, diagonal_menor;
    printf("Digite o valor da diagonal maior do losango: ");
    scanf("%f", &diagonal_maior);
    printf("Digite o valor da diagonal menor do losango: ");
    scanf("%f", &diagonal_menor);
    
    printf("A area do losango é: %.2f\n", (diagonal_maior * diagonal_menor) / 2);
}

// Questao 30
void calcularSalariosMinimos() {
    printf("\nQuestao 30************************************************\n");
    float salario_minimo, salario_funcionario;
    printf("Digite o valor do salario minimo: ");
    scanf("%f", &salario_minimo);
    printf("Digite o valor do salario do funcionario: ");
    scanf("%f", &salario_funcionario);
    
    printf("O funcionario ganha %.2f salarios minimos.\n", salario_funcionario / salario_minimo);
}

// Questao 31
void calcularIdade() {
    printf("\nQuestao 31************************************************\n");
    int ano_nascimento, ano_atual;
    printf("Quando voce nasceu? ");
    scanf("%d", &ano_nascimento);
    printf("Digite o ano atual: ");
    scanf("%d", &ano_atual);

    int idade_anos = ano_atual - ano_nascimento;
    printf("Idade em anos: %d\n", idade_anos);
    printf("Idade em meses: %d\n", idade_anos * 12);
    printf("Idade em dias: %d\n", idade_anos * 365);
    printf("Idade em semanas: %d\n", (idade_anos * 365) / 7);
}

// Questao 32
void calcularRestanteSalario() {
    printf("\nQuestao 32************************************************\n");
    float salario, conta1, conta2;
    printf("Digite o salario de Joao: ");
    scanf("%f", &salario);
    printf("Digite o valor da primeira conta atrasada: ");
    scanf("%f", &conta1);
    printf("Digite o valor da segunda conta atrasada: ");
    scanf("%f", &conta2);

    float multa = 0.02;
    float total_contas = conta1 * (1 + multa) + conta2 * (1 + multa);
    printf("Saldo restante apos pagar as contas: %.2f\n", salario - total_contas);
}

// Questao 33
void calcularSalario() {
    printf("\nQuestao 33************************************************\n");
    int horas_trabalhadas, horas_extras;
    float salario_minimo;
    printf("Digite o numero de horas trabalhadas: ");
    scanf("%d", &horas_trabalhadas);
    printf("Digite o valor do salario minimo: ");
    scanf("%f", &salario_minimo);
    printf("Digite o numero de horas extras trabalhadas: ");
    scanf("%d", &horas_extras);

    float valor_hora = salario_minimo * 0.01; 
    float valor_hora_extra = valor_hora * 1.4; 
    float salario_bruto = horas_trabalhadas * valor_hora;
    float salario_horas_extra = horas_extras * valor_hora_extra;

    printf("Salario a receber: %.2f\n", salario_bruto + salario_horas_extra);
}

// Questao 34
void converterMoeda() {
    printf("\nQuestao 34************************************************\n");
    float dinheiro_reais;
    printf("Digite a quantidade de dinheiro em reais: ");
    scanf("%f", &dinheiro_reais);

    const float cotacao_dolar = 5.65;
    const float cotacao_marco = 3.27;
    const float cotacao_libra = 7.48;

    printf("Valor em dolares: %.2f\n", dinheiro_reais / cotacao_dolar);
    printf("Valor em marcos alemaes: %.2f\n", dinheiro_reais / cotacao_marco);
    printf("Valor em libras esterlinas: %.2f\n", dinheiro_reais / cotacao_libra);
}

// Questao 35
void converterTempo() {
    printf("\nQuestao 35************************************************\n");
    float tempo_minutos;
    printf("Digite o tempo em minutos: ");
    scanf("%f", &tempo_minutos);

    int horas = (int)tempo_minutos / 60;
    int minutos = (int)tempo_minutos % 60;
    int segundos = (int)((tempo_minutos - (horas * 60 + minutos)) * 60);

    printf("Tempo em horas: %d\n", horas);
    printf("Tempo em minutos: %d\n", minutos);
    printf("Tempo em segundos: %d\n", segundos);
}

// Questao 36
void converterBagagem() {
    printf("\nQuestao 36************************************************\n");
    const float POLEGADA_CM = 2.54;
    float altura_cm, largura_cm, comprimento_cm;
    printf("Digite a altura da bagagem em centimetros: ");
    scanf("%f", &altura_cm);
    printf("Digite a largura da bagagem em centimetros: ");
    scanf("%f", &largura_cm);
    printf("Digite o comprimento da bagagem em centimetros: ");
    scanf("%f", &comprimento_cm);

    float perimetro_cm = 2 * (altura_cm + largura_cm + comprimento_cm);
    printf("Perimetro em centimetros: %.2f\n", perimetro_cm);
    printf("Perimetro em polegadas: %.2f\n", perimetro_cm / POLEGADA_CM);
}

int main() {
    trocarValores();
    calcularArea();
    calcularFerraduras();
    calcularVendaPaesBroas();
    calcularDiasVida();
    calcularLitrosGasolina();
    calcularValorRefeicao();
    calcularDiasPassados();
    valorBlusas();
    calcularDistancia();
    calcularTempoSemAcidentes();
    lerSalario();
    separarDigitos();
    calcularAreaPizza();
    porcentagemVotosEleitores();
    calcularIngredientesSanduiche();
    converterCelsiusParaFahrenheit();
    calcularSalarioBL();
    calcularGastoGranja();
    calcularNovelosPorBlusa();
    calcularLitros();
    lerMoedas();
    calcularLitrosRefresco();
    calcularMedia();
    salarioComissao();
    calcularPeso();
    calcularAreaTrapezio();
    calcularAreaQuadrado();
    calcularAreaLosango();
    calcularSalariosMinimos();
     calcularIdade();
    calcularRestanteSalario();
    calcularSalario();
    converterMoeda();
    converterTempo();
    converterBagagem();
    return 0;
}
