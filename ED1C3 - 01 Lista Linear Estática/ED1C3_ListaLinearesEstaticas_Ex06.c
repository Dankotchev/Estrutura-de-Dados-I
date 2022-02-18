/*
	EXERCÍCIO 06:
    Desenvolva um programa em Linguagem C que dada uma lista L1 seu inverso seja armazenado em uma lista L2.

	Autor: Danilo Domingues Quirino
	Versão: 2202.17
*/

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TF 100

typedef struct sListaLinear
{
    int valores[TF];
    int tL;
} LISTA;

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tOPERACOES SOBRE UMA LISTA LINEAR");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.");
    printf("\n1 - Inserir elementos na lista L1;");
    printf("\n2 - Inverter elementos de L1 e armazenar em lista L2;");
    printf("\n0 - Encerrar Sistema.\n");

    do
    {
        printf("Escolha ==> ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 2);
    return opcao;
}

int quantidadeInteiros()
{
    int intValor;
    printf("Informe a quantidade de elementos a ser inserido na lista: ");
    scanf("%d", &intValor);
    return intValor;
}

int validarPosicao(LISTA *valLista)
{
    int posicao;
    do
    {
        printf("\nInforme a posicao de um elemento para ser retirado da lista: ");
        scanf("%d", &posicao);
        if (posicao < 0 || posicao > valLista->tL)
        {
            printf("Erro: Posicao fora dos limites da lista.\n");
        }
    } while (posicao < 0 || posicao > valLista->tL);
    return posicao;
}

void lista_Inicializar(LISTA *iLista)
{
    iLista->tL = -1;
}

int lista_Vazia(LISTA *vLista)
{
    if (vLista->tL == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void lista_ImprimirLista(LISTA *lImprimir)
{
    if (lista_Vazia(lImprimir))
    {
        printf("Erro: Lista vazia.\n");
    }
    else
    {
        for (int i = 0; i <= lImprimir->tL; i++)
        {
            printf("%d  ", lImprimir->valores[i]);
        }
    }
}

void lista_Inserir(LISTA *inserirLista)
{
    // Sempre eh gerada uma nova lista de elementos
    int valor;

    valor = quantidadeInteiros();
    for (int i = 0; i < valor; i++)
    {
        inserirLista->valores[i] = 1 + (rand() % 100);
    }
    inserirLista->tL = valor - 1;
    printf("Os elementos inseridos foram: \n");
    lista_ImprimirLista(inserirLista);

    printf("\nElemento Inserido com sucesso.\n");
}

void lista_Inverter(LISTA *listaUm, LISTA *listaDois)
{
    int posicao;
    int j = listaUm->tL;
    listaDois->tL = listaUm->tL;
    if (lista_Vazia(listaUm) || lista_Vazia(listaDois))
    {
        printf("Erro: Lista vazia.\n");
    }
    else
    {
        for (int i = 0; i <= listaUm->tL; i++)
        {
            listaDois->valores[j] = listaUm->valores[i];
            j--;
        }
        printf("A lista L2 tem os seguintes elementos:\n");
        lista_ImprimirLista(listaDois);
    }
}

int main()
{
    srand(time(NULL));
    int opcao;
    LISTA listaUM, listaDOIS;
    lista_Inicializar(&listaUM);
    lista_Inicializar(&listaDOIS);

    do
    {
        opcao = gerirMenu();
        switch (opcao)
        {
        case 1:
            printf("\nInserir elementos na lista L1;\n");
            lista_Inserir(&listaUM);
            break;

        case 2:
            printf("\nInverter elementos de L1 e armazenar em lista L2;\n");
            lista_Inverter(&listaUM, &listaDOIS);
            break;

        case 0:
            printf("\n\nENCERRANDO SISTEMA");
            break;
        }
    } while (opcao != 0);
    return 0;
}
