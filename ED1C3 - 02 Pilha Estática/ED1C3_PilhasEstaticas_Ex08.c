/*
    EXERCÍCIO 08:
    Desenvolva um programa em Linguagem C que contenha todas as funções básicas apresentadas em
    sala de aula para uma estrutura de dados do tipo Pilha e que seja capaz de executar as
    funções solicitadas nos três últimos exercícios.
    Observação: Crie um menu para interação com o usuário.

    Autor: Danilo Domingues Quirino
    Versão: 2202.25
*/

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TM 100

typedef struct sPilha
{
    int itens[TM];
    int topo;
} PILHA;

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tOPERACOES SOBRE PILHAS ESTATICAS");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.\n");
    printf("\n1 -\tInserir elementos na Pilha;");
    printf("\n2 -\tRemover elementos na Pilha;");
    printf("\n3 -\tInverter a Ordem da Pilha;");
    printf("\n4 -\tTrocar de Posição o valor do Topo da Pilha com o valor da Base da Pilha;");
    printf("\n5 -\tOrganizar a Pilha com valores Pares na Base e valores Ímpares no Topo;");
    printf("\n6 -\tVisualizar a Pilha;");
    printf("\n0 -\tEncerrar Sistema.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 6);
    return opcao;
}

void ImprimirSemDesempilhar(PILHA *umaPilha)
{
    if (pilha_Vazia(umaPilha))
    {
        printf("Erro. Pilha vazia no momento.\n");
    }
    else
    {
        printf("A pilha, neste momento, esta desta maneira:\n");
        printf(" _____________\n");
        for (int i = umaPilha->topo; i >= 0; i--)
        {
            printf("|    %-5d    |   %d \n", umaPilha->itens[i], i);
            printf("|-------------|\n");
        }
    }
}

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

void push(PILHA *umaPilha, int x)
{

    umaPilha->topo++;
    umaPilha->itens[umaPilha->topo] = x;
}

int pop(PILHA *umaPilha)
{
    int x;

    x = umaPilha->itens[umaPilha->topo];
    umaPilha->topo--;
    return x;
}

// Demais funções

void manipular_InserirElementos(PILHA *manipularPilha, int quantidade)
{
    srand(time(NULL));
    if (quantidade + manipularPilha->topo > TM - 1)
    {
        quantidade = (TM - 1) - (manipularPilha->topo);
        printf("Reajustando o valor informado para %d valores, evitando que a pilha estoure.\n",
               quantidade);
    }

    for (int i = 0; i < quantidade; i++)
    {
        push(manipularPilha, (1 + rand() % 1000));
    }
}

void manipular_RemoverElementos(PILHA *manipularPilha, int quantidade)
{
    int desempilhado;

    if (quantidade > manipularPilha->topo + 1)
    {
        quantidade = manipularPilha->topo + 1;
        printf("Reajustando o valor informado para o maximo (%d) de valores presentes na pilha.\n",
               manipularPilha->topo);
    }

    for (int i = 0; i < quantidade; i++)
    {
        desempilhado = pop(manipularPilha);
    }
}

void auxiliar_OrganizarPilha(PILHA *auxiliarPilha, PILHA *auxPilha)
// Recebe a pilha do menu vazia, uma pilha auxiliar e empilha os elementos da auxiliar na outra
{
    while (!pilha_Vazia(auxPilha))
    {
        push(auxiliarPilha, pop(auxPilha));
    }
}

void manipular_OrganizarPilha(PILHA *manipularPilha)
// Recebe a pilha do menu, e separa em duas pilhas auxiliares diferentes
{
    PILHA pilhaPares, pilhaImpares;
    int valor;
    pilha_Inicializar(&pilhaPares);
    pilha_Inicializar(&pilhaImpares);

    // Primeira Etapa: Separar valores e duas pilhas diferentes
    while (!pilha_Vazia(manipularPilha))
    {
        valor = pop(manipularPilha);
        if (valor % 2 == 0)
        {
            push(&pilhaPares, valor);
        }
        else
        {
            push(&pilhaImpares, valor);
        }
    }

    // Segunda Etapa: Reunir valores na pilha do menu seguindo a regra estabelecida
    auxiliar_OrganizarPilha(manipularPilha, &pilhaPares);
    auxiliar_OrganizarPilha(manipularPilha, &pilhaImpares);
}

// Funções do MENU

void menu_InserirElementos(PILHA *menuPilha)
{
    int quantidade;
    if (pilha_Cheia(menuPilha))
    {
        printf("Erro. Pilha totalmente cheia.\n");
    }
    else
    {
        printf("Informe quantos valores que deseja empilhar na pilha: ");
        scanf("%d", &quantidade);
        manipular_InserirElementos(menuPilha, quantidade);
    }
}

void menu_RemoverElementos(PILHA *menuPilha)
{
    int quantidade;
    if (pilha_Vazia(menuPilha))
    {
        printf("Erro. Pilha ainda vazia.\n");
    }
    else
    {
        printf("Informe quantos valores que deseja desempilhar da pilha: ");
        scanf("%d", &quantidade);
        manipular_RemoverElementos(menuPilha, quantidade);
    }
}

void menu_InverterPilha(PILHA *menuPilha)
{
    int vet[TM];
    int qntPilha;
    if (pilha_Vazia(menuPilha))
    {
        printf("Erro. Pilha ainda vazia.\n");
    }
    else
    {
        printf("Invertendo a pilha...\n");
        qntPilha = menuPilha->topo;
        for (int i = 0; i < qntPilha; i++)
        {
            vet[i] = pop(menuPilha);
        }
        for (int j = 0; j < qntPilha; j++)
        {
            push(menuPilha, vet[j]);
        }
        printf("Pilha invertida!\n");
    }
}

void menu_TrocaTopoBase(PILHA *menuPilha)
{
    PILHA pilhaAuxiliar;
    char topoParaBase, baseParaTopo;

    if (pilha_Vazia(menuPilha))
    {
        printf("Erro. Pilha ainda vazia.\n");
    }
    else
    {
        pilha_Inicializar(&pilhaAuxiliar);

        // Primeiro etapa: separar o topo e a base em variaveis, e inserir elementos intermediarios
        // em uma pilha auxiliar (de forma invertida).
        topoParaBase = pop(menuPilha);
        while (menuPilha->topo != 0)
        {
            push(&pilhaAuxiliar, pop(menuPilha));
        }
        baseParaTopo = pop(menuPilha);

        // Segunda etapa: inserir o topo, agora na base, retornar os elementos intermediarios para a
        // pilha original em seus devidos lugares, e finalizar inserindo a base, agora no topo da
        // pilha.
        push(menuPilha, topoParaBase);
        while (!pilha_Vazia(&pilhaAuxiliar))
        {
            push(menuPilha, pop(&pilhaAuxiliar));
        }
        push(menuPilha, baseParaTopo);
    }
}

void menu_OrganizarParesImpares(PILHA *menuPilha)
{
    if (pilha_Vazia(menuPilha))
    {
        printf("Erro. Pilha ainda vazia.\n");
    }
    else
    {
        printf("Ordenando a pilha...\n");
        manipular_OrganizarPilha(menuPilha);
        printf("Pilha organizada!\n");
    }
}

int main()
{
    PILHA stack;
    int opcao;

    pilha_Inicializar(&stack);

    do
    {
        opcao = gerirMenu();
        switch (opcao)
        {
        case 1:
            printf("\nInserir Elementos na Pilha.\n");
            menu_InserirElementos(&stack);
            break;

        case 2:
            printf("\nRemover Elementos na Pilha.\n");
            menu_RemoverElementos(&stack);
            break;

        case 3:
            printf("\nInverter a Ordem da Pilha.\n");
            menu_InverterPilha(&stack);
            break;

        case 4:
            printf("\nTrocar de Posição o valor do Topo da Pilha com o valor da Base da Pilha;\n");
            menu_TrocaTopoBase(&stack);
            break;

        case 5:
            printf("\nOrganizar a Pilha com valores Pares na Base e valores Ímpares no Topo;\n");
            menu_OrganizarParesImpares(&stack);
            break;
        case 6:
            printf("\nVizualizar a Pilha;\n");
            ImprimirSemDesempilhar(&stack);
            break;

        case 0:
            printf("\n\nENCERRANDO SISTEMA");
            break;
        }
    } while (opcao != 0);

    return 0;
}
