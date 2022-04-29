#include <stdio.h>
#include <stdlib.h>

typedef struct sProduto
{
    int id;
    char nome[50];
    int estoque;
    float pVenda;
} PRODUTO;

int main ()
{
    PRODUTO *prod;
    int n, m;

    printf("Informe quantos produtos inserir: ");
    scanf("%d", &n);

    prod = (PRODUTO *) malloc(n * sizeof(PRODUTO));

    for (int i = 0; i < n; i++)
    {
        printf("\nProduto #%d :: ", i+1);
        printf("Informe o codigo do Produto: ");
        scanf("%d", &prod[i].id);

        printf("Informe o nome do Produto: ");
        fflush(stdin);
        gets(prod[i].nome);

        printf("Informe o estoque atual do produto: ");
        scanf("%d", &prod[i].estoque);

        printf("Informe o Preco de Venda do Produto: ");
        scanf("%d", &prod[i].pVenda);
    }

    m = sizeof(prod) / sizeof(PRODUTO);
    for(int i = 0; i < m; i++)
    {
        printf("\nProduto ID: %d", prod[i].id);
    }


}
