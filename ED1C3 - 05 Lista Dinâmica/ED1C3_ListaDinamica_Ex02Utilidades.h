#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 50

typedef struct sContato
{
    char nomeCompleto[TAM], ringtone[TAM];
    int num1Tel, num2Tel;
} CAD;

typedef struct cell
{
    CAD contatinho;
    struct cell *next;
} CONTATOS;

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tCONTATOS");
    printf("\nEscolha a operacao desejada.\n");
    printf("\n1 -\tInserir novo Contato;");
    printf("\n2 -\tListar todos os Contatos;");
    printf("\n3 -\tRemover Contato;");
    printf("\n4 -\tBuscar Contato;");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 4);
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

CAD lerInformacoes()
{
    CAD incluir;

    printf("Nome:  ");
    lerTexto(incluir.nomeCompleto, TAM);

    printf("Numero de Telefone (1): ");
    scanf("%d", &incluir.num1Tel);

    printf("Numero de Telefone (2):  ");
    scanf("%d", &incluir.num2Tel);

    printf("Ringtone: ");
    lerTexto(incluir.ringtone, TAM);

    return incluir;
}