/*
    EXERC�CIO 11:
    Desenvolva um programa para distribui��o de senhas para o atendimento em um
    consult�rio, que conta com uma �nica secret�ria e um �nico m�dico. Supondo que n�o
    h� desist�ncias, seu programa deve apoiar as seguintes situa��es: (a) Ao chegar no
    consult�rio, o paciente vai at� a secret�ria e recebe uma senha num�rica para ser
    atendido. (b) Quando o m�dico fica dispon�vel para atender a um novo paciente, a
    secret�ria chama o paciente que est� h� mais tempo na fila.

    Autor: Danilo Domingues Quirino
    Vers�o: 2205.05
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct sCell
{
    int senha;
    struct sCell *next;
} NOH;

void init(NOH **inicio, NOH **fim)
{
    *inicio = NULL;
    *fim = NULL;
}

NOH *getNode()
{
    return (NOH *)malloc(sizeof(NOH));
}

void freeNode(NOH *no)
{
    free(no);
}

int empty(NOH *filaPointer)
{
    if (filaPointer == NULL)
        return 1;
    return 0;
}

void enqueue(NOH **inicio, NOH **fim, int x)
{
    NOH *inserir;
    inserir = getNode();
    if(inserir != NULL)
    {
        inserir->senha = x;
        inserir->next = NULL;

        if (empty(*inicio))
            *inicio = inserir;

        else
            (*fim)->next = inserir;
        *fim = inserir;
    }
    else
    {
        printf("Erro na alocacao do no.\n");
        return;
    }
}

int dequeue (NOH **inicio, NOH **fim)
{
    NOH *remover;
    int x;

    if(!empty(*inicio))
    {
        remover = *inicio;
        *inicio = (*inicio)->next;
        if (*inicio == NULL)
            *fim = NULL;

        x = remover->senha;
        freeNode(remover);
    }
    else
    {
        printf("Erro, fila vazia.\n");
        return NULL;
    }
    return x;
}



int gerirMenu()
{
    int op;
    printf("\n----------\n\tOPERACAO DE FILA DINAMICA");
    printf("\nEscolha a operacao desejada.\n");
    printf("\n1 -\tAtribuir Nova Senha");
    printf("\n2 -\tChamar Senha");
    printf("\n3 -\tApresentar Ultima Senha");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &op);
    }
    while (op < 0 || op > 3);
    return op;
}

/*
Apenas para validar o estado da lista
void exibe (NOH *fila)
{
    printf("Estado da fila: \n");
    while (fila != NULL)
    {
        printf("%d  ", fila->senha);
        fila = fila->next;
    }
}
*/

int main()
{
    NOH *inicio, *fim;
    int op;
    int senhaAtual = 1, ultSenha;

    init(&inicio,&fim);

    do
    {
        op = gerirMenu();
        switch (op)
        {
        case 1:
            printf("\tAtribuicao de Senha :: Senha %d atribuida.\n", senhaAtual);
            enqueue(&inicio,&fim, senhaAtual);
            senhaAtual++;
            break;

        case 2:
            ultSenha = dequeue(&inicio, &fim);
            printf("\tChamando Senha: %d\n", ultSenha);
            break;

        case 3:
            printf("\tApresentar Ultima Senha Chamada: %d\n", ultSenha);
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
        //exibe(inicio);
    }
    while (op != 0);
    return 0;
}
