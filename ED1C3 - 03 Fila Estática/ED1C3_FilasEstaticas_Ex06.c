/*
    EXERCÍCIO 06:
    Escreva um programa em Linguagem C que forneça o maior, o menor e a média aritmética
    dos elementos de uma fila.

    Autor: Danilo Domingues Quirino
    Versão: 2203.19
*/

#include <stdio.h>
#include <ctype.h>
#define TM 100

typedef struct sfila
{
    float itens[TM];
    int inicio, fim;
} FILA;

void fila_Inicializar(FILA *f)
{
    f->inicio = TM - 1;
    f->fim = TM - 1;
}

int verificarFila(FILA *f)
{
    if (f->inicio == f->fim)
        return 1;
    return 0;
}

void queue(FILA *f, float x)
{
    // Incrementar
    if (f->fim == (TM - 1))
    {
        f->fim = 0;
    }
    else
    {
        f->fim++;
    }

    if (verificarFila(f))
    {
        printf("Erro. Fila Cheia.");
        f->fim--;
        if (f->fim == -1)
        {
            f->fim = TM - 1;
        }
        return;
    }

    f->itens[f->fim] = x;
}

float dequeue(FILA *f)
{
    if (!verificarFila(f))
    {
        if (f->inicio == TM - 1)
        {
            f->inicio = 0;
        }
        else
        {
            f->inicio++;
        }
    }
    else
    {
        printf("Erro. Fila Vazia");
    }
    return f->itens[f->inicio];
}

void imprimirFila(FILA *f)
{
    int i = (f->inicio + 1) % TM;
    if (!verificarFila(f))
    {
        printf("\nA forma da fila eh a seguinte:\n");
        while (i != ((f->fim + 1) % TM))
        {
            printf("%.2f ", f->itens[i]);
            i = (i + 1) % TM;
        }
    }
    else
    {
        printf("\nErro. Pilha Vazia.");
    }
}

float maiorValor(FILA *f)
{
    FILA filaAuxiliar;
    float valorAtual, maior = f->itens[f->inicio];

    // Encontrando o maior valor, removendo itens por itens e guardando em uma fila auxiliar
    while (!verificarFila(f))
    {
        valorAtual = dequeue(f);
        if (valorAtual > maior)
        {
            maior = valorAtual;
        }
        queue(&filaAuxiliar, valorAtual);
    }

    // Devolvendo os itens da fila auxiliar para a principal
    while (!verificarFila(&filaAuxiliar))
    {
        queue(f, dequeue(&filaAuxiliar));
    }
    return maior;
}

float menorValor(FILA *f)
{
    FILA filaAuxiliar;
    float valorAtual, menor = f->itens[f->inicio];

    // Encontrando o menor valor, removendo itens por itens e guardando em uma fila auxiliar
    while (!verificarFila(f))
    {
        valorAtual = dequeue(f);
        if (valorAtual < menor)
        {
            menor = valorAtual;
        }
        queue(&filaAuxiliar, valorAtual);
    }

    // Devolvendo os itens da fila auxiliar para a principal
    while (!verificarFila(&filaAuxiliar))
    {
        queue(f, dequeue(&filaAuxiliar));
    }
    return menor;
}

float mediaValor(FILA *f)
{
    float somatorio = 0, x;
    int contagem = 0;

    FILA aux;

    fila_Inicializar(&aux);

    while (!verificarFila(f))
    {
        x = dequeue(f);
        somatorio += x;
        contagem++;
        queue(&aux, x);
    }

    while (!verificarFila(&aux))
    {
        queue(f, dequeue(&aux));
    }

    return somatorio / contagem;
}

void inserirElementosFila(FILA *f)
{
    char continuar;
    float valor;
    do
    {
        printf("\nInforme um valor: ");
        scanf("%f", &valor);
        queue(f, valor);

        printf("\nDeseja inserir outro elemento?\n\tS - Sim\n\tN - Nao\n\tEscolha: ");
        fflush(stdin);
        scanf("%c", &continuar);
        continuar = toupper(continuar);
    } while (continuar != 'N');
}

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tOPERACOES SOBRE FILAS ESTATICAS");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.\n");
    printf("\n1 -\tInserir elementos na fila;");
    printf("\n2 -\tRemover elementos da fila;");
    printf("\n3 -\tEncontrar o MENOR valor da fila;");
    printf("\n4 -\tEncontrar o MAIOR valor da fila;");
    printf("\n5 -\tMedia dos valores da fila;");
    printf("\n6 -\tImpressao da fila;");
    printf("\n0 -\tEncerrar Sistema.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 6);
    return opcao;
}

int main()
{
    FILA f;
    int opcao;
    float valor;

    fila_Inicializar(&f);

    do
    {
        opcao = gerirMenu();
        switch (opcao)
        {
        case 1:
            printf("\nInserir elementos na Fila.");
            inserirElementosFila(&f);
            break;

        case 2:
            printf("\nRemover elementos da Fila.");
            printf("\nO elemento removido foi o %.2f", dequeue(&f));
            break;

        case 3:
            // Não está apresentando nem o menor, nem o maior valor
            valor = menorValor(&f);
            printf("\nO Menor valor da fila eh %.2f", valor);
            break;

        case 4:
            printf("\nO Maior valor na fila eh %.2f", maiorValor(&f));
            break;

        case 5:
            printf("\nO valor medio dos elementos da fila eh %.2f", mediaValor(&f));
            break;

        case 6:
            printf("\nImpressao da fila:");
            imprimirFila(&f);
            break;

        case 0:
            printf("\nENCERRANDO O SISTEMA.");
            break;
        }
    } while (opcao != 0);

    return 0;
}