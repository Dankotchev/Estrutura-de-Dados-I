/*
	EXERCÍCIO 01:
	Faça um programa para ler um vetor de 12 posições e em seguida ler também dois
	valores X e Y quaisquer correspondentes a duas posições no vetor. Ao final seu programa
	deverá escrever a soma dos valores encontrados nas respectivas posições X e Y.

	Autor: Danilo Domingues Quirino
	Versão: 2202.10
*/

// Bibliotecas
#include <stdio.h>

void leituraVetor(int vetor[])
{
	int i;
	for (i = 0; i < 12; i++)
	{
		printf("informe um numero inteiro para a posicao %d do vetor: ", i);
		scanf("%d", &vetor[i]);
	}
}

int lerInteiro(char chr)
{
	int z;
	do
	{
		printf("\nInforme uma posicao dentro do vetor, para %c ser receber seu valor: ", chr);
		scanf("%d", &z);
	} while (z < -1 || z > 11);
	return z;
}

void somatorio(int vetor[], int x, int y)
{
	int soma;
	soma = vetor[x] + vetor[y];
	printf("\nA soma dos valores buscados eh igual a: %d", soma);
}

void main()
{
	int vetor[12];
	int x, y;
	leituraVetor(vetor);
	x = lerInteiro('X');
	y = lerInteiro('Y');
	printf("%d %d", x, y);
	somatorio(vetor, x, y);
}