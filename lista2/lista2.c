#include <stdio.h>
#include <ctype.h>

void calcularNumeroDaSorte() {
    float valorCompra;
    int anoNascimento, idade;
    int numeroDaSorte;

    printf("\n--- Calcular Numero da Sorte ---\n");
    printf("Informe o valor total da compra: ");
    scanf("%f", &valorCompra);
    printf("Informe o ano de nascimento: ");
    scanf("%d", &anoNascimento);

    idade = 2024 - anoNascimento;

    /*
    Calcula o número da sorte com base no valor da compra:
    - Se o valor da compra for exatamente 500.00, o número da sorte
     é a idade ao quadrado.
    - Se o valor for menor que 500.00, o número da sorte é 5000 menos
     o produto do valor da compra e a idade.
    - Se o valor for maior que 500.00, o número da sorte é 50000 menos
     o produto do valor da compra e a idade.
    */
    numeroDaSorte = valorCompra == 500.00 ? idade * idade : 
                    (valorCompra < 500.00 ? 5000 - (valorCompra * idade) : 
                    50000 - (valorCompra * idade));

    printf("Seu numero da sorte e: %d\n", numeroDaSorte);
}

void calcularFinanciamento() {
    float salario, financiamento, salarioConjuge = 0;

    printf("\n--- Calcular Financiamento ---\n");
    printf("Informe o valor do salario: ");
    scanf("%f", &salario);
    printf("Informe o valor do financiamento pretendido: ");
    scanf("%f", &financiamento);

    if (financiamento > 5 * salario) {
        printf("Informe o valor do salario do cônjuge: ");
        scanf("%f", &salarioConjuge);
    }

     // Verifica se o valor do financiamento é menor ou igual a cinco vezes a soma do salário e do salário do cônjuge.
     // Se a condição for verdadeira, imprime "Financiamento concedido."
     // Caso contrário, imprime "Financiamento negado."
    printf(financiamento <= 5 * (salario + salarioConjuge) ? "Financiamento concedido.\n" : "Financiamento negado.\n");

    printf("Obrigado por nos consultar.\n");
}

void calcularCondominio() {
    int opcao;
    float valorCondominio = 350.00;
    float taxas[] = {30.00, 12.00, 50.00, -20.00};

    printf("\n--- Calcular Valor do Condominio ---\n");
    printf("Selecione o tipo de animal de estimacao (1-Gato, 2-Papagaio, 3-Cao, 4-Nenhum): ");
    scanf("%d", &opcao);

    /* 
   Adiciona ou subtrai a taxa correspondente ao tipo de animal selecionado:
   - Se a opcao estiver entre 1 e 4 (inclusive), o valor da taxa correspondente é adicionado ao valor do condomínio.
   - Caso contrário (opcao fora do intervalo 1 a 4), é subtraído R$20.00 do valor do condomínio.
   
   O operador ternário (opcao >= 1 && opcao <= 4) ? taxas[opcao - 1] : -20.00 funciona assim:
   - Se a condicao opcao >= 1 && opcao <= 4 for verdadeira, a expressão retorna taxas[opcao - 1].
   - Se for falsa, retorna -20.00.
    */
    valorCondominio += (opcao >= 1 && opcao <= 4) ? taxas[opcao - 1] : -20.00;

    printf("O valor do condominio e: R$%.2f\n", valorCondominio);
}

void calcularSomaOuMultiplicacao() {
    int A, B, C;

    printf("\n--- Somar ou Multiplicar A e B ---\n");
    printf("Informe o valor de A: ");
    scanf("%d", &A);
    printf("Informe o valor de B: ");
    scanf("%d", &B);
    C = (A == B) ? A + B : A * B;

    printf("O resultado C e: %d\n", C);
}

void verificarDivisibilidade() {
    int num;

    printf("\n--- Verificar Divisibilidade ---\n");
    printf("Informe um numero inteiro: ");
    scanf("%d", &num);

    if (num % 10 == 0) {
        printf("O numero e divisivel por 10.\n");
    } 
    if (num % 5 == 0) {
        printf("O numero e divisivel por 5.\n");
    } 
    if (num % 2 == 0) {
        printf("O numero e divisivel por 2.\n");
    } 
    else {
        printf("O numero nao e divisivel por 10, 5 ou 2.\n");
    }
}

void calcularIMC() {
    float peso, altura, imc;
    char sexo;

    printf("\n--- Calcular IMC ---\n");
    printf("Informe o peso (em kg): ");
    scanf("%f", &peso);
    printf("Informe a altura (em metros): ");
    scanf("%f", &altura);
    printf("Informe o sexo (M para masculino, F para feminino): ");
    scanf(" %c", &sexo);

    imc = peso / (altura * altura);
    sexo = toupper(sexo);

    printf("Seu IMC e: %.2f\n", imc);

    if (sexo == 'M') {
        if (imc < 20.7) {
            printf("Abaixo do peso.\n");
        } else if (imc <= 26.4) {
            printf("Peso normal.\n");
        } else if (imc <= 27.8) {
            printf("Marginalmente acima do peso.\n");
        } else if (imc <= 31.1) {
            printf("Acima do peso ideal.\n");
        } else {
            printf("Obeso.\n");
        }
    } else if (sexo == 'F') {
        if (imc < 19.1) {
            printf("Abaixo do peso.\n");
        } else if (imc <= 25.8) {
            printf("Peso normal.\n");
        } else if (imc <= 27.3) {
            printf("Marginalmente acima do peso.\n");
        } else if (imc <= 32.3) {
            printf("Acima do peso ideal.\n");
        } else {
            printf("Obesa.\n");
        }
    } else {
        printf("Sexo invalido.\n");
    }
}

void calcularAumentoSalario() {
    float salario, novoSalario;
    int funcao;

    printf("\n--- Calcular Aumento de Salario ---\n");
    printf("Informe o salario atual: ");
    scanf("%f", &salario);
    printf("Informe a funcao (1-Tecnico, 2-Gerente, 3-Demais): ");
    scanf("%d", &funcao);

    switch (funcao) {
        case 1:
            novoSalario = salario * 1.50;
            break;
        case 2:
            novoSalario = salario * 1.30;
            break;
        case 3:
            novoSalario = salario * 1.20;
            break;
        default:
            printf("Funcao invalida.\n");
            return;
    }

    printf("O novo salario e: R$%.2f\n", novoSalario);
}

void calcularValorVenda() {
    float valorCompra, valorVenda;

    printf("\n--- Calcular Valor de Venda ---\n");
    printf("Informe o valor de compra do produto: ");
    scanf("%f", &valorCompra);

    if (valorCompra < 20.00) {
        valorVenda = valorCompra * 1.45;
    } else {
        valorVenda = valorCompra * 1.30;
    }

    printf("O valor de venda e: R$%.2f\n", valorVenda);
}

void avaliarMediaAluno() {
    float media;
    char conceito;

    printf("\n--- Avaliar Media do Aluno ---\n");
    printf("Informe a media do aluno: ");
    scanf("%f", &media);

    if (media >= 9.0) {
        conceito = 'A';
    } else if (media >= 7.5) {
        conceito = 'B';
    } else if (media >= 6.0) {
        conceito = 'C';
    } else if (media >= 4.0) {
        conceito = 'D';
    } else {
        conceito = 'E';
    }

    printf("O conceito do aluno e: %c\n", conceito);

    if (conceito == 'A' || conceito == 'B' || conceito == 'C') {
        printf("APROVADO\n");
    } else {
        printf("REPROVADO\n");
    }
}

void calcularDescontoINSS() {
    float salario, desconto;

    printf("\n--- Calcular Desconto do INSS ---\n");
    printf("Informe o salario: ");
    scanf("%f", &salario);

    if (salario <= 600) {
        desconto = 0;
        printf("Isento de desconto do INSS.\n");
    } else if (salario <= 1200) {
        desconto = salario * 0.20;
    } else if (salario <= 2000) {
        desconto = salario * 0.25;
    } else {
        desconto = salario * 0.30;
    }

    if (desconto > 0) {
        printf("O desconto do INSS e: R$%.2f\n", desconto);
    }
}

void calcularParcelas() {
    float valorVista, valorTotal, valorParcela;
    int parcelas;

    printf("--- Loja de Eletrodomesticos ---\n");
    printf("Informe o valor da compra à vista: R$ ");
    scanf("%f", &valorVista);
    
    printf("Informe o numero de parcelas desejadas (1, 2 ou 3): ");
    scanf("%d", &parcelas);

    if (parcelas <= 1) {
        // Pagamento à vista
        valorTotal = valorVista;
        valorParcela = valorTotal;
        parcelas = 1;
    } else if (parcelas == 2) {
        // Pagamento em 2 vezes
        valorTotal = valorVista * 1.10;
        valorParcela = valorTotal / 2;
    } else if (parcelas == 3) {
        // Pagamento em 3 vezes
        valorTotal = valorVista * 1.20;
        valorParcela = valorTotal / 3;
    } else {
        // Parcelas acima de 3
        parcelas = 3;
        valorTotal = valorVista * 1.20;
        valorParcela = valorTotal / 3;
    }

    printf("Numero de parcelas: %d\n", parcelas);
    printf("Valor de cada parcela: R$ %.2f\n", valorParcela);
    printf("Valor total a ser pago: R$ %.2f\n", valorTotal);
}

void calcularHospedagem(){
    char tipoApartamento;
    int numeroDiarias;
    float valorDiaria, valorConsumoInterno;
    float valorTotalDiarias, subtotal, taxaServico, totalGeral;

    // Entrada de dados
    printf("Informe o tipo do apartamento utilizado (A, B, C ou D): ");
    scanf(" %c", &tipoApartamento);
    printf("Informe o numero de diarias utilizadas: ");
    scanf("%d", &numeroDiarias);
    printf("Informe o valor do consumo interno: R$ ");
    scanf("%f", &valorConsumoInterno);

    // Determinacao do valor da diaria
    switch (tipoApartamento) {
        case 'A':
        case 'a':
            valorDiaria = 150.00;
            break;
        case 'B':
        case 'b':
            valorDiaria = 100.00;
            break;
        case 'C':
        case 'c':
            valorDiaria = 75.00;
            break;
        case 'D':
        case 'd':
            valorDiaria = 175.00;
            break;
        default:
            printf("Tipo de apartamento invalido.\n");
            break; // Saida do programa em caso de erro
    }

    // Calculo dos valores
    valorTotalDiarias = numeroDiarias * valorDiaria;
    subtotal = valorTotalDiarias + valorConsumoInterno;
    taxaServico = subtotal * 0.10;
    totalGeral = subtotal + taxaServico;

    // Exibicao da conta final
    printf("\n--- Conta Final ---\n");
    printf("Tipo de Apartamento: %c\n", tipoApartamento);
    printf("Numero de Diarias: %d\n", numeroDiarias);
    printf("Valor Unitario da Diaria: R$ %.2f\n", valorDiaria);
    printf("Valor Total das Diarias: R$ %.2f\n", valorTotalDiarias);
    printf("Valor do Consumo Interno: R$ %.2f\n", valorConsumoInterno);
    printf("Subtotal: R$ %.2f\n", subtotal);
    printf("Valor da Taxa de Servico (10%%): R$ %.2f\n", taxaServico);
    printf("Total Geral: R$ %.2f\n", totalGeral);
}

void determinarTurma() {
    int idade;

    // Solicitar a idade da crianca
    printf("Informe a idade da crianca: ");
    scanf("%d", &idade);

    // Determinar a turma com base na idade
    if (idade >= 4 && idade <= 5) {
        printf("Turma A - 4 a 5 anos\n");
    } else if (idade >= 6 && idade <= 8) {
        printf("Turma B - 6 a 8 anos\n");
    } else if (idade >= 9 && idade <= 10) {
        printf("Turma C - 9 a 10 anos\n");
    } else {
        printf("Sem turma - abaixo de 4 anos ou acima de 10 anos\n");
    }
}

void calcularOperacao() {
    int num1, num2;
    char operacao;

    printf("Informe o primeiro numero: ");
    scanf("%d", &num1);

    printf("Informe o segundo numero: ");
    scanf("%d", &num2);

    printf("Informe a operacao desejada (+, -, *, /): ");
    scanf("%c", &operacao);

    switch (operacao) {
        case '+':
            printf("Resultado: %d + %d = %d\n", num1, num2, num1 + num2);
            break;
        case '-':
            printf("Resultado: %d - %d = %d\n", num1, num2, num1 - num2);
            break;
        case '*':
            printf("Resultado: %d * %d = %d\n", num1, num2, num1 * num2);
            break;
        case '/':
            if (num2 != 0) {
                printf("Resultado: %d / %d = %.2f\n", num1, num2, (float)num1 / num2);
            } else {
                printf("Erro: Divisao por zero nao permitida.\n");
            }
            break;
        default:
            printf("Operacao invalida.\n");
            break;
    }
}

void imprimirMesCorrespondente() {
    const char *meses[] = {
        "Janeiro", "Fevereiro", "Marco", "Abril", "Maio", "Junho",
        "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"
    };
    int mes;

    printf("Informe um numero entre 1 e 12: ");
    scanf("%d", &mes);

    if (mes >= 1 && mes <= 12) {
        printf("O mês correspondente e: %s\n", meses[mes - 1]);
    } else {
        printf("Nao existe mes com esse numero.\n");
    }
}


// Funcao principal
int main() {
    int opcao;

    do {
        printf("\n--- Menu Principal ---\n");
        printf("1 - Calcular Numero da Sorte\n");
        printf("2 - Calcular Financiamento\n");
        printf("3 - Calcular Valor do Condominio\n");
        printf("4 - Somar ou Multiplicar A e B\n");
        printf("5 - Verificar Divisibilidade\n");
        printf("6 - Calcular IMC\n");
        printf("7 - Calcular Aumento de Salario\n");
        printf("8 - Calcular Valor de Venda\n");
        printf("9 - Avaliar Media do Aluno\n");
        printf("10 - Calcular Desconto do INSS\n");
        printf("11 - Calcular Parcelas\n");
        printf("12 - Calcular Conta da Hospedagem\n");
        printf("13 - Determinar turma da escolinha\n");
        printf("14 - Calcular Operacoes\n");
        printf("15 - Imprimir mes correspondente\n");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                calcularNumeroDaSorte();
                break;
            case 2:
                calcularFinanciamento();
                break;
            case 3:
                calcularCondominio();
                break;
            case 4:
                calcularSomaOuMultiplicacao();
                break;
            case 5:
                verificarDivisibilidade();
                break;
            case 6:
                calcularIMC();
                break;
            case 7:
                calcularAumentoSalario();
                break;
            case 8:
                calcularValorVenda();
                break;
            case 9:
                avaliarMediaAluno();
                break;
            case 10:
                calcularDescontoINSS();
                break;  
            case 11:
                calcularParcelas();
                break;
            case 12:
                calcularHospedagem();
                break;
            case 13:
                determinarTurma();
                break;
            case 14:
                calcularOperacao();
                break;
            case 15:
                imprimirMesCorrespondente();
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
