/*
    EXERCÍCIO 02:
    Desenvolva um programa em Linguagem C que permita ao usuário inserir em ordem
    decrescente elementos do tipo char em uma lista linear simplesmente encadeada.
    Desenvolva uma função para a operação de inserção.

    Autor: Danilo Domingues Quirino
    Versão: 2204.14
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    char letra;
    struct cell *next;
} CELULA;

void inicializar(CELULA **lista)
{
    *lista = NULL;
}

CELULA *getNode()
{
    return (CELULA *)malloc(sizeof(CELULA));
}

void exibirLista(CELULA *lista)
{
    while (lista != NULL)
    {
        printf("%c\t", lista->letra);
        lista = lista->next;
    }
    printf("\n");
}

void ordenarDecrescente (CELULA **lista)
{
    CELULA *atual, *anterior, *proximo;

    atual = *lista;

    if (atual->next != NULL)
    {
        while (atual != NULL)
        {
            proximo = atual->next;
            anterior = atual;
            if (atual->letra < proximo->letra)
            {
                atual->next = atual->next->next;
                proximo->next = atual;
                anterior->next = proximo;
            }
            atual = atual->next->next;
        }
    }
    else{}
        //exit(1);
}

void inserirInicio(CELULA **lista, char a)
{
    CELULA *inserir;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->letra = a;
        inserir->next = *lista;
        *lista = inserir;
        ordenarDecrescente(lista);
    }
    else
    {
        printf("\nErro na alocacao do no");
        exit(1);
    }
}

int main()
{
    CELULA *listaCaracteres;
    char c, continuar;

    inicializar(&listaCaracteres);
    do
    {
        printf("Informe uma letra para inserir na lista: ");
        fflush(stdin);
        scanf("%c", &c);

        inserirInicio(&listaCaracteres,c);

        printf("A lista de caracteres eh a seguinte: \n");
        exibirLista(listaCaracteres);

        printf("Deseja inserir outro caracter:\n\tS/N :: ");
        fflush(stdin);
        scanf("%c", &continuar);
        continuar = toupper(continuar);

    }
    while(continuar != 'N');



    return 0;
}
