/*
	EXERCÍCIO 05:
	Considere um cadastro de produtos de um estoque, com as seguintes informações para cada produto:
		- Código de identificação do produto: representado por um valor inteiro;
		- Nome do produto: com até 50 caracteres;
		- Quantidade disponível no estoque: representado por um número inteiro;
		- Preço de venda: representado por um valor real

		a) Defina uma estrutura em C, denominada produto, que tenha os campos apropriados para guardar as informações de um produto;
		b) Crie um conjunto de 10 produtos e peça ao usuário para entrar com as informações de cada produto;
		c) Encontre o produto com o maior preço de venda;
		d) Encontre o produto com a maior quantidade disponível no estoque.

	Autor: Danilo Domingues Quirino
	Versão: 2202.
*/

// Bibliotecas
#include <stdio.h>
#define TT 3

typedef struct produtosEstoque
{
	int codigoID;
	char nomeProduto[50];
	int quantidadeEstoque;
	float precoVenda;
} produto;

int gerirMenu()
{
	int opcao;
	printf("----------\n\tSISTEMA DE GERENCIAMENTO DE PRODUTOS");
	printf("\nEscolha a operacao desejada, informando o codigo correpondente.");
	printf("\n1 - Inserir um conjunto de produtos;");
	printf("\n2 - Encontrar o produto com maior Preco de Venda;");
	printf("\n3 - Encontrar o produto com o maior Estoque;");
	printf("\n0 - Encerrar Sistema.");

	do
	{
		printf("\nEscolha ==> ");
		scanf("%d", &opcao);
	} while (opcao < 0 || opcao > 3);
	return opcao;
}

void verificar (produto verificacao[])
{
	if (verificacao[] != NULL)
	{
		/* code */
	}
	
}

void leituraDados(produto leitura[])
{
	for (int i = 0; i < TT; i++)
	{
		printf("Insira as informacoes do produto %d ::\n", i + 1);
		printf("Nome do Produto :: ");
		scanf("%s", leitura[i].nomeProduto);
		fflush(stdin);
		printf("Codigo de Identificacao :: ");
		scanf("%d", &leitura[i].codigoID);
		printf("Quantidade em Estoque :: ");
		scanf("%d", &leitura[i].quantidadeEstoque);
		printf("Preco de Venda :: ");
		scanf("%f", &leitura[i].precoVenda);
		printf("-----\n");
	}
}

void apresentarMaiorPreco(produto produtos[])
{
	float maiorPreco = produtos[0].precoVenda;
	int posicao = 0;
	for (int i = 1; i < TT; i++)
	{
		if (produtos[i].precoVenda > maiorPreco)
		{
			maiorPreco = produtos[i].precoVenda;
			posicao = i;
		}
	}
	printf("\nO produto %s possui o maior Preco de Venda.\n\tSua valor eh de R$ %0.2f.\n\n", produtos[posicao].nomeProduto, produtos[posicao].precoVenda);
}

void apresentarMaiorEstoque(produto produtos[])
{
	float maiorEstoque = produtos[0].quantidadeEstoque;
	int posicao = 0;
	for (int i = 1; i < TT; i++)
	{
		if (produtos[i].quantidadeEstoque > maiorEstoque)
		{
			maiorEstoque = produtos[i].quantidadeEstoque;
			posicao = i;
		}
	}
	printf("\nO produto %s possui o maior Estoque.\n\tSeu estoque atual eh de %d unidades.\n\n", produtos[posicao].nomeProduto, produtos[posicao].quantidadeEstoque);
}

int main()
{
	produto produtos[TT];
	int opcao;

	do
	{
		opcao = gerirMenu();
		switch (opcao)
		{
		case 1:
			verificar(produtos);
			leituraDados(produtos);
			break;
		
		case 2:
			apresentarMaiorPreco(produtos);
			break;

		case 3:
			apresentarMaiorEstoque(produtos);
			break; 

		case 0:
			printf("\n\nENCERRANDO SISTEMA");
			break;
		}
	} while (opcao != 0);
	

	
	


	return 0;
}
