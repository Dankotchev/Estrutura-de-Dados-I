/*
	EXERCÍCIO 03:
	Desenvolva um programa em Linguagem C que permita fazer as seguintes operações sobre uma lista
	linear estática de números reais: inserir um elemento mantendo a ordem crescente entre os
	elementos no vetor; remover um valor indicado pelo usuário, eliminando eventuais “lacunas abertas” com a remoção.

	Autor: Danilo Domingues Quirino
	Versão: 2202.17
*/

// Bibliotecas
#include <stdio.h>
#define TF 100

typedef struct sListaLinear
{
    float valores[TF];
    int tL;
} LISTA;

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tOPERACOES SOBRE UMA LISTA LINEAR");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.");
    printf("\n1 - Inserir um elemento na lista;");
    printf("\n2 - Remover um elemento da lista;");
    printf("\n3 - Exibir os elementos da lista;");
    printf("\n0 - Encerrar Sistema.\n");

    do
    {
        printf("Escolha ==> ");
        scanf("%d", &opcao);
    }
    while (opcao < 0 || opcao > 3);
    return opcao;
}

float lerFloat ()
{
    float fValor;
    printf("Informe o valor a ser inserido na lista: ");
    scanf("%f", &fValor);
    return	fValor;
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
    }
    while (posicao < 0 || posicao > valLista->tL);
    return posicao;
}

void lista_Inicializar(LISTA *iLista)
{
    iLista->tL = -1;
}

int lista_Cheia(LISTA *cLista)
{
    if (cLista->tL + 1 == TF)
    {
        return 1;
    }
    else
    {
        return 0;
    }
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

void ordenarB (LISTA *orderLista)
{
    float aux;
    for	(int i = 0; i < orderLista->tL; i++)
    {
        if(orderLista->valores[orderLista->tL] < orderLista->valores[i])
        {
            aux =orderLista->valores[i];
            orderLista->valores[i] = orderLista->valores[orderLista->tL];
            orderLista->valores[orderLista->tL] = aux;
        }
    }
}

void lista_InserirElemento (LISTA *iiLista)
{
    float valor;
    if (lista_Cheia(iiLista))
    {
        printf("Erro: lista cheia.\n");
    }
    else
    {
        valor = lerFloat();
        iiLista->valores[iiLista->tL+1] = valor;
        iiLista->tL++;
        ordenarB(iiLista);
        printf("Elemento Inserido com sucesso.\n");
    }
}

void lista_RemoverPosicaoN (LISTA *removerLista)
{
    int posicao;
    if (lista_Vazia(removerLista))
    {
        printf("Erro: Lista vazia.\n");
    }
    else
    {
        posicao = validarPosicao(removerLista);
        {
            for (int i = posicao; i < removerLista->tL; i++)
            {
                removerLista->valores[i] = removerLista->valores[i+1];
            }
        }
        removerLista->tL--;
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
            printf("[#%d] => %.2f; ", i, lImprimir->valores[i]);
        }
    }
}

int main ()
{
    int opcao;
    LISTA listaReais;
    lista_Inicializar(&listaReais);

    do
    {
        opcao = gerirMenu();
        switch (opcao)
        {
        case 1:
            printf("\nInserir um elemento na lista.\n");
            lista_InserirElemento(&listaReais);
            break;

        case 2:
            printf("\nRemover um elemento da fila.\n");
            lista_RemoverPosicaoN(&listaReais);
            break;

        case 3:
            printf("\nMostrando os elementos da lista e suas posicoes.\n");
            lista_ImprimirLista(&listaReais);
            break;

        case 0:
            printf("\n\nENCERRANDO SISTEMA");
            break;
        }
    }
    while (opcao != 0);
    return 0;
}
