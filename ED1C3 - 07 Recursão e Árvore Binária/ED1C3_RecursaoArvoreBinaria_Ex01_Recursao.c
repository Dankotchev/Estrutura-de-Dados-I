/*
    EXERCÍCIO 01:
    Desenvolva um programa em Linguagem C que permita fazer as seguintes operações sobre uma lista
    simplesmente encadeada:
        a. Calcular o comprimento da lista;
        b. Somar todos os elementos da lista;
        c. Multiplicar todos os elementos da lista;
        d. Imprimir os elementos ímpares a partir do início da lista;
        e. Imprimir os elementos pares da lista na ordem inversa.

    * Para cada operação acima desenvolva uma função recursiva. Desenvolva também uma função menu
    para que o usuário possa selecionar a opção desejada.

    Autor: Danilo Domingues Quirino
    Versão: 2206.20
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info;
    struct cell *proximo;
} NOH;

void inicializar(NOH **lista)
{
    *lista = NULL;
}

NOH *getNode()
{
    return (NOH *)malloc(sizeof(NOH));
}

void freeNode(NOH *no)
{
    free(no);
}

int vazia(NOH *lista)
{
    if (lista == NULL)
        return 1;
    return 0;
}

void exibirOrdemDireta(NOH *lista)
{
    if (!vazia(lista))
    {
        printf("%d\t", lista->info);
        exibirOrdemDireta(lista->proximo);
    }
}

void exibirParesOI(NOH *lista)
{
    if (!vazia(lista))
    {
        exibirParesOI(lista->proximo);
        if (lista->info % 2 == 0)
            printf("%d\t", lista->info);
    }
}

void exibirImparesOD(NOH *lista)
{
    if (!vazia(lista))
    {
        if (lista->info % 2 != 0)
            printf("%d\t", lista->info);
        exibirImparesOD(lista->proximo);
    }
}

void inserirInicio(NOH **lista, int x)
{
    NOH *inserir;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->info = x;
        inserir->proximo = *lista;
        *lista = inserir;
    }
    else
    {
        printf("\nErro na alocacao do no");
        exit(1);
    }
}

int calcularComprimento(NOH *lista)
{
    if (vazia(lista))
        return 0;
    else
        return (calcularComprimento(lista->proximo) + 1);
}

int somarElementos(NOH *lista)
{
    if (vazia(lista))
        return 0;
    else
        return (lista->info + somarElementos(lista->proximo));
}

void multiplicarK(NOH **lista, int k)
{
    if (vazia(lista))
        return;
    else {
        multiplicarK((*lista)->proximo, k);
        (*lista)->info = (k * (*lista)->info);
        //multiplicarK((*lista)->proximo, k);
    }
}

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tRECURSIVIDADE");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.\n");
    printf("\n1 -\tInserir elementos na Lista");
    printf("\n2 -\tExibir a Lista (Ordem Direta)");
    printf("\n3 -\tComprimento da Lista");
    printf("\n4 -\tSomatorio dos elementos da Lista");
    printf("\n5 -\tMultiplicar os elemtos da Lista com uma constante");
    printf("\n6 -\tExibir elementos Impares (Ordem Inversa)");
    printf("\n7 -\tExibir elementos Pares (Ordem Direta)");
    printf("\n0 -\tEncerrar Sistema.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 7);
    return opcao;
}

int leituraValor()
{
    int v;
    printf("\tInforme um valor :: ");
    scanf("%d", &v);
    return v;
}

int main()
{

    NOH *lista;
    inicializar(&lista);
    int opcao;

    do
    {
        opcao = gerirMenu();

        switch (opcao)
        {
        case 1:
            printf("\tInsercao de valores na Arvore");
            inserirInicio(&lista, leituraValor());
            break;

        case 2:
            printf("\tExibir a arvore (Ordem Direta)\n");
            exibirOrdemDireta(lista);
            break;

        case 3:
            printf("\tA lista possui %d elementos de comprimento.\n", calcularComprimento(lista));
            break;

        case 4:
            printf("\tO somatario dos elementos da lista eh igual a %d", somarElementos(lista));
            break;

        case 5:
            printf("\tMultiplicar os valores da lista por uma constante :: \n");
            multiplicarK(&lista, leituraValor());
            break;

        case 6:
            printf("\tElementos Pares em Ordem Direta ::\n");
            exibirParesOI(lista);
            break;

        case 7:
            printf("\tElementos Impares em Ordem Inversa :: \n");
            exibirImparesOD(lista);
            break;

        case 0:
            printf("\nENCERRANDO SISTEMA");
            break;
        }

    } while (opcao != 0);

    return 0;
}
