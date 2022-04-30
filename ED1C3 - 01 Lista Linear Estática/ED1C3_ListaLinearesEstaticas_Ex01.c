/*
	EXERCÍCIO 01:
	Desenvolva um programa em Linguagem C que permita fazer as seguintes operações sobre
	uma lista linear estática de números inteiros positivos:
		(a) inserir um elemento em uma posição específica;
		(b) remover um elemento de uma posição específica;
		(c) acessar um elemento de uma posição específica;
		(d) procurar um determinado elemento.
		(e) exibir os elementos do vetor
	Quantos bytes seu programa principal ocupa para armazenar dados?
	OBS: Defina funções para cada operação.

	Autor: Danilo Domingues Quirino
	Versão: 2202.16
*/

// Bibliotecas
#include <stdio.h>
#define TAMANHOFISICO 100

typedef struct sListaLinear
{
	int valores[TAMANHOFISICO];
	int tmLogico;
} LISTA;

int gerirMenu()
{
	int opcao;
	printf("\n----------\n\tOPERACOES SOBRE UMA LISTA LINEAR");
	printf("\nEscolha a operacao desejada, informando o codigo correpondente.");
	printf("\n1 - Inserir um elemento em uma posicao especifica;");
	printf("\n2 - Remover um elemento de uma posicao especifica;");
	printf("\n3 - Acessar um elemento de uma posicao especifica;");
	printf("\n4 - Procurar um elemento derteminado;");
	printf("\n5 - Exibir os elementos da lista;");
	printf("\n0 - Encerrar Sistema.\n");

	do
	{
		printf("Escolha ==> ");
		scanf("%d", &opcao);
	} while (opcao < 0 || opcao > 5);
	return opcao;
}

int lerInteiro() // Leitura de todas as entradas de inteiros do programa
{
	int elm;
	do
	{
		scanf("%d", &elm);
		if (elm < 0)
		{
			printf("Erro: Valor invalido, apenas valores inteiros e positicos.\nInforme novamente o valor: ");
		}
	} while (elm < 0);
	return elm;
}

int validarPosicao(LISTA *umaLista, int a)
{
	int posicao;
	do
	{
		printf("\nInforme a posicao de um elemento: ");
		posicao = lerInteiro();
		if (posicao < 0 || posicao > (*umaLista).tmLogico + a)
		{
			printf("Erro: Posicao fora dos limites da lista.\n");
		}
	} while (posicao < 0 || posicao > (*umaLista).tmLogico + a);
	return posicao;
}

void lista_Inicializar(LISTA *umaLista)
{
	(*umaLista).tmLogico = -1;
}

int lista_Cheia(LISTA *umaLista)
{
	if ((*umaLista).tmLogico + 1 == TAMANHOFISICO)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int lista_Vazia(LISTA *umaLista)
{
	if ((*umaLista).tmLogico == -1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void lista_InserirPosicaoN(LISTA *umaLista)
{
	int posicao, elemento;
	if (lista_Cheia(umaLista))
	{
		printf("Erro: lista cheia.\n");
	}
	else
	{
		posicao = validarPosicao(umaLista, 1);
		printf("\nInforme o elemento que deseja inserir na lista: ");
		elemento = lerInteiro();
		for (int i = (*umaLista).tmLogico + 1; i > posicao; i--)
		{
			(*umaLista).valores[i] = (*umaLista).valores[i - 1];
		}
		(*umaLista).valores[posicao] = elemento;
		(*umaLista).tmLogico++;
		//printf("\n--- tmLogico %d", (*umaLista).tmLogico);
	}
}

void lista_RemoverPosicaoN(LISTA *umaLista)
{
	int posicao;
	if (lista_Vazia(umaLista))
	{
		printf("Erro: Lista vazia.\n");
	}
	else
	{
		posicao = validarPosicao(umaLista, 0);
		for (int i = posicao; i < (*umaLista).tmLogico; i++)
		{
			(*umaLista).valores[i] = (*umaLista).valores[i + 1];
		}
		(*umaLista).tmLogico--;
	}
}

void lista_BuscarPosicaoN(LISTA *umaLista)
{
	int posicao;
	if (lista_Vazia(umaLista))
	{
		printf("Erro: Lista vazia.\n");
	}
	else
	{
		posicao = validarPosicao(umaLista, 0);
		printf("O elemento da lista na posicao #%d: %d.\n", posicao, (*umaLista).valores[posicao]);
	}
}

void lista_BuscarElemento(LISTA *umaLista)
{
	int elemento, naoExistencia = 1;
	if (lista_Vazia(umaLista))
	{
		printf("Erro: Lista vazia.\n");
	}
	else
	{
		printf("Informe o elemento a ser procurado na lista: ");
		elemento = lerInteiro();
		for (int i = 0; i < (*umaLista).tmLogico; i++)
		{
			if ((*umaLista).valores[i] == elemento)
			{
				printf("\nPosicao #%d", i);
				naoExistencia = 0;
			}
		}
		if (naoExistencia)
			printf("\nElemento nao encontrado na lista.");
	}
}

void lista_ImprimirLista(LISTA *umaLista)
{
	if (lista_Vazia(umaLista))
	{
		printf("Erro: Lista vazia.\n");
	}
	else
	{
		for (int i = 0; i <= (*umaLista).tmLogico; i++)
		{
			printf("[#%d] => %d; ", i, (*umaLista).valores[i]);
		}
	}
}

int main()
{
	int opcao, tamanhoMemoria;
	tamanhoMemoria = 4 * TAMANHOFISICO;

	LISTA listaIntPos;
	lista_Inicializar(&listaIntPos);
	printf("Esse programa eh capaz de armazenar em memoria %d item; ocupado assim %d bytes.\n",
			TAMANHOFISICO, tamanhoMemoria);
	printf("\"1 Inteiro ocupa 4 bytes, logo %d valores inteiro ocupam %d bytes.\"", 
			TAMANHOFISICO, tamanhoMemoria);

	do
	{
		opcao = gerirMenu();
		switch (opcao)
		{
		case 1:
			printf("\nInserir um elemento na lista na posicao especifica.\n");
			lista_InserirPosicaoN(&listaIntPos);
			break;

		case 2:
			printf("\nRemover um elemento da lista de uma posicao especifica.\n");
			lista_RemoverPosicaoN(&listaIntPos);
			break;

		case 3:
			printf("\nAcessar um elemento atraves de sua posicao na lista\n");
			lista_BuscarPosicaoN(&listaIntPos);
			break;

		case 4:
			printf("\nProcurar um elemento na lista.\n");
			lista_BuscarElemento(&listaIntPos);
			break;

		case 5:
			printf("\nMostrando os elementos da lista e suas posicoes.\n");
			lista_ImprimirLista(&listaIntPos);
			break;

		case 0:
			printf("\n\nENCERRANDO SISTEMA");
			break;
		}
	} while (opcao != 0);
	return 0;
}
