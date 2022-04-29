/*
	EXERCÍCIO 02:
	Leia um vetor de 16 posições e troque os 8 primeiros valores pelos 8 últimos e vice-e versa.
	Escreva ao final o vetor obtido..

	Autor: Danilo Domingues Quirino
	Versão: 2202.10
*/

// Bibliotecas
#include <stdio.h>

void preencherVetor(int vetor[])
{
	int i;
	for (i = 0; i < 16; i++)
	{
		printf("informe o valor da posicao %d: ", i);
		scanf("%d", &vetor[i]);
	}
}

void trocarPosicao(int vetor[])
{
	int j = 8; // metade do vetor
	for (int i = 0; i < j; i++)
	{
		int aux;
		aux = vetor[i];
		vetor[i] = vetor[i + j];
		vetor[i + j] = aux;
	}
}

void apresentarVetor(int vetor[])
{
	for (int i = 0; i < 16; i++)
	{
		printf("%d, ", vetor[i]);
	}
}

void main()
{
	int vetor[16];
	preencherVetor(vetor);
	trocarPosicao(vetor);
	apresentarVetor(vetor);
}
