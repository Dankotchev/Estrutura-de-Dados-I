#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_P 10
#define TAM_CE 50

typedef struct sAluno
{
    char prontuario[TAM_P], nomeCompleto[TAM_CE], endereco[TAM_CE], curso[55];
    int anoIngresso, anoFormatura, num1Tel, num2Tel;
} FORMANDO;

typedef struct cell
{
    FORMANDO alunoFormado;
    int idCurso;
    struct cell *next;
} EGRESSO;


int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tCADASTRO DE ALUNOS EGRESSOS");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.\n");
    printf("\n1 -\tInserir informacoes de Alunos Formando;");
    printf("\n2 -\tRelatorio: Alunos egressos por Cursos;");
    printf("\n3 -\tRelatorio: Alunos egressos por Ano de Formatura;");
    printf("\n0 -\tEncerrar Sistema.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 3);
    return opcao;
}

int selecionarCurso()
{
    int opcao;
    printf("\n1 -\tBacharelado em Ciencia da Computacao;");
    printf("\n2 -\tBacharelado em Engenharia Eletrica;");
    printf("\n3 -\tLicenciatura em Pedagogia;");
    printf("\n4 -\tTecnologia em Processos Gerenciais;");
    printf("\n5 -\tTecnologia em Analise e Desenvolvimento de Sistemas.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &opcao);
    } while (opcao < 1 || opcao > 5);
    return opcao;
}

void lerTexto(char *texto, int tamanho)
{
    fflush(stdin);
    fgets(texto, tamanho, stdin);
    if (texto[strlen(texto) - 1] == '\n')
    {
        texto[strlen(texto) - 1] = '\0';
    }
}

FORMANDO lerInformacoes(int idCurso)
{
    FORMANDO incluir;

    printf("\nInforme os dados do Aluno Egresso:\n");
    printf("Nome:  ");
    lerTexto(incluir.nomeCompleto, TAM_CE);

    printf("Prontuario: ");
    lerTexto(incluir.prontuario, TAM_P);

    printf("Ano de Ingresso: ");
    scanf("%d", &incluir.anoIngresso);

    printf("Ano de Formatura: ");
    scanf("%d", &incluir.anoFormatura);

    printf("Endereco atualizado: ");
    lerTexto(incluir.endereco, TAM_CE);

    printf("Telefone de contato: ");
    scanf("%d", &incluir.num1Tel);

    printf("Telefone de contato secundario: ");
    scanf("%d", &incluir.num2Tel);

    switch (idCurso)
    {
    case 1:
        incluir.curso[55] = "Bacharelado em Ciencia da Computacao\n\0";
        break;

    case 2:
        incluir.curso[55] = "Bacharelado em Engenharia Eletrica\n\0";
        break;

    case 3:
        incluir.curso[55] = "Licenciatura em Pedagogia\n\0";
        break;

    case 4:
        incluir.curso[55] = "Tecnologia em Processos Gerenciais\n\0";
        break;

    case 5:
        incluir.curso[55] = "Tecnologia em Analise e Desenvolvimento de Sistemas\n\0";
        break;
    }

    return incluir;
}

int lerAnoFormatura()
{
    int anno;
    scanf("%d", &anno);
    return anno;
}