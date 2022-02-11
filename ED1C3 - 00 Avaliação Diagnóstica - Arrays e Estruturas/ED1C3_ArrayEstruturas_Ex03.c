/*
	EXERCÍCIO 03:
	Leia um vetor de 10 posições e em seguida um valor X qualquer. Seu programa deverá fazer uma 
	busca do valor de X no vetor lido e informar a posição em que foi encontrado
	ou se não foi encontrado.

	Autor: Danilo Domingues Quirino
	Versão: 2202.10
*/

// Bibliotecas
#include <stdio.h>

void leituraVetor(int vetor[])
{
	for (int i = 0; i < 10; i++)
	{

		printf("informe o valor da posicao %d: ", i);
		scanf("%d", &vetor[i]);
	}
}

int lerInt(int x)
{
	printf("\nInforme um valor inteiro para buscar no vetor: ");
	scanf("%d", &x);
	return x;
}

void procurarVetor(int vetor[], int n)
{
	int posicao = -1; // Posição inexistente dentro do vetor, para o caso negativo de busca
	for (int j = 0; j < 10; j++)
	{
		if (vetor[j] == n)
		{
			posicao = j;
		}
	}
	if (posicao != -1)
	{
		printf("\nValor encontrado na posicao %d do vetor", posicao);
	}
	else
	{
		printf("\nValor nao encontrado no vetor");
	}
}

void main()
{
	int vetor[10];
	int valorBuscar;
	leituraVetor(vetor);
	valorBuscar = lerInt(valorBuscar);
	procurarVetor(vetor, valorBuscar);
}
