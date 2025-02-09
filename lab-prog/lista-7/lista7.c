#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Questao 1: Estrutura aluno
typedef struct {
    float nota1, nota2;
} Aluno;

void lerAluno(Aluno *a) {
    printf("Digite as duas notas do aluno: ");
    scanf("%f %f", &a->nota1, &a->nota2);
}

float calcularMediaAluno(Aluno a) {
    return (a.nota1 + a.nota2) / 2;
}

// Questao 2: Estrutura estoque
typedef struct {
    char nomePeca[50];
    int numeroPeca;
    float preco;
    int quantidade;
} Estoque;

void lerEstoque(Estoque *e) {
    printf("Digite o nome da peca: ");
    scanf("%s", e->nomePeca); //(*ponteiro).membro
    printf("Digite o numero da peca: ");
    scanf("%d", &e->numeroPeca);
    printf("Digite o preco da peca: ");
    scanf("%f", &e->preco);
    printf("Digite a quantidade em estoque: ");
    scanf("%d", &e->quantidade);

    // extra: exibir estoque
    printf("\n====Detalhes da Peca:======\n");
    printf("Nome: %s\n", e->nomePeca);  
    printf("Numero: %d\n", e->numeroPeca);
    printf("Preco: %.2f\n", e->preco);
    printf("Quantidade em estoque: %d\n", e->quantidade);
    printf("=========================\n");
}


// Questao 3: Estrutura para vetor de numeros aleatórios
typedef struct {
    int *valores;
    int quantidade;
} Vetor;

void gerarVetor(Vetor *v, int tamanho) {
    v->quantidade = tamanho;
    v->valores = (int *)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++) {
        v->valores[i] = rand() % 100;
    }
}

float calcularMediaVetor(Vetor v) {
    int soma = 0;
    for (int i = 0; i < v.quantidade; i++) {
        soma += v.valores[i];
    }
    return (float)soma / v.quantidade;
}

// Questao 4: Array de alunos e media
void calcularMediaAlunos(Aluno alunos[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Media do aluno %d: %.2f\n", i + 1, calcularMediaAluno(alunos[i]));
    }
}

// Questao 5: Estrutura disciplina com professor
typedef struct {
    char nome[50];
} Professor;

typedef struct {
    char nomeDisciplina[50];
    Professor prof;
} Disciplina;

void lerDisciplina(Disciplina *d) {
    printf("Digite o nome da disciplina: ");
    scanf("%s", d->nomeDisciplina);
    printf("Digite o nome do professor: ");
    scanf("%s", d->prof.nome);
}

int main() {
    // Questao 1
    Aluno a;
    lerAluno(&a);
    printf("Media do aluno: %.2f\n", calcularMediaAluno(a));

    // Questao 2
    Estoque e;
    lerEstoque(&e);

    // Questao 3
    Vetor v;
    gerarVetor(&v, 10);
    printf("Media do vetor: %.2f\n", calcularMediaVetor(v));
    free(v.valores);

    // Questao 4
    Aluno alunos[3];
    for (int i = 0; i < 3; i++) {
        printf("Aluno %d:\n", i + 1);
        lerAluno(&alunos[i]);
    }
    calcularMediaAlunos(alunos, 3);

    // Questao 5
    Disciplina d;
    lerDisciplina(&d);
    printf("Disciplina: %s, Professor: %s\n", d.nomeDisciplina, d.prof.nome);

    return 0;
}
