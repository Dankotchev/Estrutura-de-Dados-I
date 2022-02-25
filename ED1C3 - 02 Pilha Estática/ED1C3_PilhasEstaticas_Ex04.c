/*
    EXERCÍCIO 05:
    Escreva um programa que seja capaz de ler uma palavra informada pelo usuário e verifique se esta é um palíndromo.

    Autor: Danilo Domingues Quirino
    Versão: 2202.25
*/

// Bibliotecas
#include <stdio.h>
#include <string.h>
#define TM 100

typedef struct sPilha
{
    char letras[TM];
    int topo;
} PILHA;

// Funções referentes a Pilha
void pilha_Inicializar(PILHA *umaPilha)
{
    umaPilha->topo = -1;
}

int pilha_Cheia(PILHA *umaPilha)
{
    if (umaPilha->topo == TM - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int pilha_Vazia(PILHA *umaPilha)
{
    if (umaPilha->topo == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(PILHA *umaPilha, char x)
{
    if (pilha_Cheia(umaPilha))
    {
        printf("\nErro: Pilha cheia.");
    }
    else
    {
        umaPilha->topo++;
        umaPilha->letras[umaPilha->topo] = x;
    }
}

char pop(PILHA *umaPilha)
{
    char x;
    if (pilha_Vazia(umaPilha))
    {
        printf("\nErro: Pilha Vazia.");
    }
    else
    {
        x = umaPilha->letras[umaPilha->topo];
        umaPilha->topo--;
        return x;
    }
}

int comparar_Palavra(char metadeA[], PILHA *metadeB, int m)
{
    int ehPalindromo = 1;
    for (int i = m; i <= metadeB->topo; i++)
    {
        if (metadeA[i] != pop(metadeB))
        {
            ehPalindromo = 0;
        }
    }
    return ehPalindromo;
}

void verificar_Palindromo(char palavraOriginal[])
{
    PILHA auxiliar;
    int m;
    m = (strlen(palavraOriginal) - 1) /2;
    pilha_Inicializar(&auxiliar);

    for (int i = 0; i <= m; i++)
    {
        push(&auxiliar, palavraOriginal[i]);
    }

    if (comparar_Palavra(palavraOriginal, &auxiliar, m))
    {
        printf("\nPalavra eh um palindromo.");
    }
    else
    {
        printf("\nNao eh palindromo");
    }
}

int main()
{
    char palavra[TM];

    printf("Digite a Palavra desejada\n");
    fflush(stdin);
    fgets(palavra, TM-1, stdin);
    verificar_Palindromo(palavra);

    return 0;
}
