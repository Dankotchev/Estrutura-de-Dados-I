/*
	EXERCÍCIO 04:
    Desenvolva um programa em Linguagem C que possua uma função que, dada duas listas, L1 e L2,
    concatene L1 com L2 armazenando o resultado em L1.

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
    char valores[TF];
    int tL;
} LISTA;

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tOPERACOES SOBRE UMA LISTA LINEAR");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.");
    printf("\n1 - Inserir elementos na lista L1;");
    printf("\n2 - Inserir elementos na lista L2;");
    printf("\n3 - Concatenar lista L2 em L1;");
    printf("\n0 - Encerrar Sistema.\n");

    do
    {
        printf("Escolha ==> ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 3);
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

int lista_Cheia(LISTA *cLista, LISTA *dLista)
{
    if ((cLista->tL + dLista->tL) == TF)
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
            printf("%c  ", lImprimir->valores[i]);
        }
    }
}

void lista_Inserir(LISTA *inserirLista, int inicio)
{
    // Sempre eh gerada uma nova lista de elementos
    int valor;
    char elemento;

    valor = quantidadeInteiros();
    // 65 e 26 :: gera um intervalo entre 65 e 90 =>  MAIUSCULAS
    // 97 e 26 :: gera um intervalo entre 97 e 122 => minusculas
    for (int i = 0; i < valor; i++)
    {
        inserirLista->valores[i] = inicio + (rand() % 26);
    }
    inserirLista->tL = valor - 1;
    printf("Os elementos inseridos foram: \n");
    lista_ImprimirLista(inserirLista);
    printf("\nElementos inseridos com sucesso.\n");
}

void lista_Concatenar(LISTA *listaUm, LISTA *listaDois)
{
    int posicao;
    if (lista_Vazia(listaUm) || lista_Vazia(listaDois))
    {
        printf("Erro: Lista vazia.\n");
    }
    else
    {
        if (lista_Cheia(listaUm, listaDois))
        {
            printf("Erro: Lista L1 nao tem espaco para armazenar Lista L2.\n");
        }
        else
        {
            for (int i = 0; i <= listaDois->tL; i++)
            {
                listaUm->valores[i + (listaUm->tL + 1)] = listaDois->valores[i];
            }
            listaUm->tL += listaDois->tL + 1;
            printf("A lista L1 eh composta pelos elementos:\n");
            lista_ImprimirLista(listaUm);
        }
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
            lista_Inserir(&listaUM, 65);
            break;

        case 2:
            printf("\nInserir elementos na lista L2;\n");
            lista_Inserir(&listaDOIS, 97);
            break;

        case 3:
            printf("\nConcatenar elementos de L2 em L1.\n");
            lista_Concatenar(&listaUM, &listaDOIS);
            break;

        case 0:
            printf("\n\nENCERRANDO SISTEMA");
            break;
        }
    } while (opcao != 0);
    return 0;
}
