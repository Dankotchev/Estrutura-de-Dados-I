/*
	EXERCÍCIO 02:
	Desenvolva um programa em Linguagem C que permita ao usuário inserir e remover elementos
	nos extremos de uma sequência de itens, ou seja, no início e no final de uma lista linear estática.

	Autor: Danilo Domingues Quirino
	Versão: 2202.16
*/

// Bibliotecas
#include <stdio.h>
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
	printf("\n1 - Inserir um elemento no INICIO da lista;");
	printf("\n2 - Inserir um elemento no FIM da lista;");
	printf("\n3 - Remover um elemento do INICIO da lista;");
	printf("\n4 - Remover um elemento do FIM da lista;");
	printf("\n5 - Exibir os elementos da lista;");
	printf("\n0 - Encerrar Sistema.\n");

	do
	{
		printf("Escolha ==> ");
		scanf("%d", &opcao);
	} while (opcao < 0 || opcao > 5);
	return opcao;
}

int lerValores()
{
	int x;
	printf("Informe o valor desejado: ");
	scanf("%d", &x);
	return x;
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

void lista_InserirInicio(LISTA *iILista)
{
	int valor;
	if (lista_Cheia(iILista))
	{
		printf("Erro: lista cheia.\n");
	}
	else
	{
		valor = lerValores();
		for (int i = iILista->tL + 1; i > 0; i--)
		{
			iILista->valores[i] = iILista->valores[i - 1];
		}
		iILista->valores[0] = valor;
		iILista->tL++;
		printf("Elemento Inserido com sucesso.\n");
	}
}

void lista_InserirFim(LISTA *iFLista)
{
	int valor;
	if (lista_Cheia(iFLista))
	{
		printf("Erro: lista cheia.\n");
	}
	else
	{
		valor = lerValores();
		iFLista->valores[iFLista->tL + 1] = valor;
		iFLista->tL++;
		printf("Elemento Inserido com sucesso.\n");
	}
}

void lista_RemoverInicio(LISTA *rILista)
{
	if (lista_Vazia(rILista))
	{
		printf("Erro: lista Vazia.\n");
	}
	else
	{
		for (int i = 0; i < rILista->tL; i++)
		{
			rILista->valores[i] = rILista->valores[i + 1];
		}
		rILista->tL--;
	}
	printf("Elemento Removido com sucesso.\n");
}

void lista_RemoverFim(LISTA *rFLista)
{
	if (lista_Vazia(rFLista))
	{
		printf("Erro: lista vazia.\n");
	}
	else
	{
		rFLista->tL--;
	}
	printf("Elemento Removido com sucesso.\n");
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
			printf("[#%d] => %d; ", i, lImprimir->valores[i]);
		}
	}
}

int main()
{
	int opcao;

	LISTA uLista;
	lista_Inicializar(&uLista);

	do
	{
		opcao = gerirMenu();
		switch (opcao)
		{
		case 1:
			printf("\nInserir um elemento no inicio da lista.\n");
			lista_InserirInicio(&uLista);
			break;

		case 2:
			printf("\nInserir um elemento no fim da lista.\n");
			lista_InserirFim(&uLista);
			break;

		case 3:
			printf("\nRemover um elemento do inicio da fila.\n");
			lista_RemoverInicio(&uLista);
			break;

		case 4:
			printf("\nRemover um elemento do fim da fila.\n");
			lista_RemoverFim(&uLista);
			break;

		case 5:
			printf("\nMostrando os elementos da lista e suas posicoes.\n");
			lista_ImprimirLista(&uLista);
			break;

		case 0:
			printf("\n\nENCERRANDO SISTEMA");
			break;
		}
	} while (opcao != 0);
	return 0;
}