/*
    EXERCÍCIO 07:
    Num sistema de arquivos, um catálogo de todos os arquivos é organizado como uma árvore de busca
    binária. Cada nó denota um arquivo e especifica seu nome e, entre outras coisas, a data de seu
    último acesso, codificada como um inteiro. Escreva um programa que percorra a árvore e apague
    todos os arquivos cujos últimos acessos tenham sido anteriores a uma certa data. As chaves do
    catálogo são os nomes dos arquivos.

    Autor: Danilo Domingues Quirino
    Versão: 2206.20
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define TT 50

typedef struct sArquivo
{
    int dataAcesso; // Formato yyyymmdd => 20220620
    char nomeArquivo[TT];

} ARQ;

typedef struct sCell
{
    ARQ arquivo;
    struct sCell *esquerda;
    struct sCell *direita;
} NOH;

void plantarArvore(NOH **raiz)
{
    *raiz = NULL;
}

NOH *getNode()
{
    return (NOH *)malloc(sizeof(NOH));
}

void freeNode(NOH *no)
{
    free(no);
}

int arvoreVazia(NOH *raiz)
{
    if (raiz == NULL)
        return 1;
    return 0;
}

void inserir(NOH **raiz, ARQ arquivo)
{
    if (arvoreVazia(*raiz))
    {
        *raiz = getNode();
        (*raiz)->esquerda = NULL;
        (*raiz)->direita = NULL;
        (*raiz)->arquivo = arquivo;
    }
    else
    {
        if ((strcmp(arquivo.nomeArquivo, (*raiz)->arquivo.nomeArquivo)) < 0) // Arquivo menor que raiz, Antes no alfabeto
            inserir(&((*raiz)->esquerda), arquivo);
        else
            inserir(&((*raiz)->direita), arquivo);
    }
}

void imprimirEmOrdem(NOH *raiz)
{
    if (!arvoreVazia(raiz))
    {
        imprimirEmOrdem(raiz->esquerda);
        printf("\tNome do arquivo: %s\n", raiz->arquivo.nomeArquivo);
        printf("\t\tUltimo acesso: %d\n", raiz->arquivo.dataAcesso);
        imprimirEmOrdem(raiz->direita);
    }
}

ARQ lerInfoArq()
{
    ARQ arquivo;

    printf("Data de ultimo Acesso (yyyyMMdd): ");
    scanf("%d", &arquivo.dataAcesso);

    printf("Nome do Arquivo: ");
    // fflush(stdin);
    __fpurge(stdin);
    fgets(arquivo.nomeArquivo, TT, stdin);
    if (arquivo.nomeArquivo[strlen(arquivo.nomeArquivo) - 1] == '\n')
    {
        arquivo.nomeArquivo[strlen(arquivo.nomeArquivo) - 1] = '\0';
    }

    return arquivo;
}

void apagarArquivo(NOH **raiz, int dataLimite)
{
    // Árvore vazia
    if (arvoreVazia(raiz))
        return;
    else
    {
        // O nó em questão é um nó a ser removido
        if ((*raiz)->arquivo.dataAcesso <= dataLimite)
        {

            // Remoção de nós folhas (Aqueles sem nós filhos)
            if ((*raiz)->esquerda == NULL && (*raiz)->direita == NULL)
            {
                printf("Arquivo: %s, com ultima data de acesso em %d removido.",
                       (*raiz)->arquivo.nomeArquivo, (*raiz)->arquivo.dataAcesso);
                freeNode(raiz);
                return;
            }

            // Remoção de nó com dois nós filhos
            // VOLTAR AQUI
            else if ((*raiz)->esquerda != NULL && (*raiz)->direita != NULL)
            {
                ARQ arquivo;
                NOH *aux = (*raiz)->esquerda;

                while (aux->direita != NULL)
                    aux = aux->direita;
                arquivo = (*raiz)->arquivo;
                (*raiz)->arquivo = aux->arquivo;
                aux->arquivo = arquivo;
                apagarArquivo((*raiz)->esquerda, dataLimite);
                return;
            }
            else
            {
                // remover nós que possuem apenas 1 filho
                NOH *aux;
                if ((*raiz)->esquerda != NULL)
                    aux = (*raiz)->esquerda;
                else
                    aux = (*raiz)->direita;
                freeNode(raiz);
                return;
            }
        }
        

        else
        {
            apagarArquivo((*raiz)->esquerda, dataLimite);
            apagarArquivo((*raiz)->direita, dataLimite);
        }
    }
}

int gerirMenu()
{
    int op;
    printf("\n----------\n\tLISTA DE CANAIS DE TELEVISAO DA CTBC");
    printf("\nEscolha a operacao desejada.\n");
    printf("\n1 -\tInserir um arquivo");
    printf("\n2 -\tApresentar os aquivos salvos");
    printf("\n3 -\tApagar arquivos antigos");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &op);
    } while (op < 0 || op > 3);
    return op;
}

int main()
{
    NOH *arvoreBinaria;
    int dataLimite = 0;
    int op;

    plantarArvore(&arvoreBinaria);

    do
    {
        op = gerirMenu();
        switch (op)
        {
        case 1:
            printf("\tInserir um novo Arquivo ::\n");
            inserir(&arvoreBinaria, lerInfoArq());
            break;

        case 2:
            printf("\tApresentar os Arquivos Salvos ::\n");
            imprimirEmOrdem(arvoreBinaria);
            break;

        case 3:
            printf("\tApagar arquivos antigos::\n");
            printf("\tInforme uma data limite (yyyyMMdd): ");
            scanf("%d", &dataLimite);
            // apagarArquivo(&ArvoreBinaria, dataLimite);
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    } while (op != 0);
    return 0;
}
