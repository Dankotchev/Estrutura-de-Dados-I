/*
	EXERCÍCIO 04:
	Leia um vetor de 10 posições e em seguida um valor X qualquer. Seu programa deverá
	fazer uma busca do valor de X no vetor lido. Caso encontre o valor deverá ser removido
	do vetor.

	Autor: Danilo Domingues Quirino
	Versão: 2202.10
*/

// Bibliotecas
#include <stdio.h>

void leituraVetor(int vetor[])
{
	for (int i = 0; i < 10; i++)
	{

		printf("informe um valor para a posicao %d do vetor: ", i);
		scanf("%d", &vetor[i]);
	}
}

int leituraNumero()
{
	int y;
	printf("\nInforme um valor inteiro para buscar e eliminar do vetor: ");
	scanf("%d", &y);
	return y;
}

void procurarValor(int vet[], int x)
{
	for (int i = 0; i < 10; i++)
	{
		if (vet[i] == x)
		{
			vet[i] = 0;
		}
	}
}

void apresentarVetor(int apresentar[], int x)
{
	printf("\nO vetor, apos a eliminacao do valor %d ficou desta maneira:\n", x);
	for (int i = 0; i < 10; i++)
	{
		printf("%d,", apresentar[i]);
	}
}

void main()
{
	int vetor[10];
	int x;
	leituraVetor(vetor);
	x = leituraNumero();
	procurarValor(vetor, x);
	apresentarVetor(vetor, x);
}
