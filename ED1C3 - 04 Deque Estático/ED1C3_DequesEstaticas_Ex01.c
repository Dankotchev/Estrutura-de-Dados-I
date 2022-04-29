/*
    EXERCÍCIO 01:
    Codifique, compile e execute um programa em Linguagem C que permita fazer as seguintes
    operações sobre um deque linear estático circular formada por elementos do tipo int:

​       b) inserir um elemento no final do deque (função inserirFim());
​       a) inserir um elemento no início do deque (função inserirInicio());
​       c) remover um elemento no início do deque (função removerInicio());
​       d) remover um elemento no final do deque (função removerFim());
​       e) exibir os elementos do deque usando a impressão não clássica.
​       f) exibir os elementos do deque usando a impressão clássica.
    Observação: Defina uma função menu.

    Autor: Danilo Domingues Quirino
    Versão: 2203.17
*/

#include <stdio.h>
#define TM 150

typedef struct sDeque
{
    int itens[TM];
    int inicio, fim;
} DEQUE;

void dequeInicializar(DEQUE *dq)
{
    dq->inicio = TM - 1;
    dq->fim = TM - 1;
}

int validar(DEQUE *dq)
{
    if (dq->inicio == dq->fim)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void endEnqueue(DEQUE *dq, int x)
{
    if (dq->fim == (TM - 1))
    {
        dq->fim = 0;
    }
    else
    {
        dq->fim++;
    }

    if (validar(dq))
    {
        printf("Erro, deque cheio.");
        dq->fim--;
        if (dq->fim == -1)
        {
            dq->fim = (TM - 1);
        }
        return;
    }
    else
    {
        dq->itens[dq->fim] = x;
    }
}

int startDequeue(DEQUE *dq)
{
    int x;
    if (!validar(dq))
    {
        if (dq->inicio == (TM - 1))
        {
            dq->inicio = 0;
        }
        else
        {
            dq->inicio++;
        }
        x = dq->itens[dq->inicio];
    }
    else
    {
        printf("Erro, deque vazia.");
    }
    return x;
}

void startEnqueue(DEQUE *dq, int x)
{

    if (dq->inicio == 0)
    {
        dq->inicio = TM - 1;
    }
    else
    {
        dq->inicio--;
    }

    if (validar(dq))
    {
        printf("Erro, Deque cheia.");
        dq->inicio = (dq->inicio + 1) % TM; // voltando para a posiçaoo anterior ao decremento
    }

    dq->itens[(dq->inicio + 1) % TM] = x;
}

int endDequeue(DEQUE *dq)
{
    int x = 0;

    if (!validar(dq))
    {
        if (dq->fim == 0)
        {
            dq->fim = (TM - 1);
        }
        else
        {
            dq->fim--;
        }
        //x = dq->itens[dq->fim];
        x = dq->itens[(dq->fim + 1) % TM];
        //printf("\n\t%d",dq->itens[(dq->fim + 1) % TM]);
    }
    else
    {
        printf("\nErro, deque vazia,");
    }
    return x;
}

void impresaoNClassica(DEQUE *dq)
{
    int i = (dq->inicio + 1) % TM;

    if (!validar(dq))
    {
        printf("\nA deque possui a seguinte forma:\n");
        while (i != ((dq->fim + 1) % TM))
        {
            printf("%d ", dq->itens[i]);
            i = (i + 1) % TM;
        }
    }
    else
    {
        printf("\nErro, deque vazia");
    }
}

void impressaoClassica(DEQUE *dq)
{
    DEQUE aux;
    int x;
    dequeInicializar(&aux);

    if (!validar(dq))
    {
        printf("\nA deque possui a seguinte forma:\n");

        while (!validar(dq))
        {
            x = startDequeue(dq);
            endEnqueue(&aux, x);
            printf("%d ", x);
        }
        while (!validar(&aux))
        {
            endEnqueue(dq, startDequeue(&aux));
        }
    }
    else
    {
        printf("\nErro, deque vazia");
    }
}

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tOPERACOES SOBRE DEQUES ESTATICAS");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.\n");
    printf("\n1 -\tInserir elementos no inicio da Deque;");
    printf("\n2 -\tInserir elementos no fim da Deque;");
    printf("\n3 -\tRemover elementos no inicio da Deque;");
    printf("\n4 -\tRemover elementos no fim da Deque;");
    printf("\n5 -\tImprimir Valores: Impressao \"Nao Classica\";");
    printf("\n6 -\tImprimir Valores: Impressao \"Classica\";");
    printf("\n0 -\tEncerrar Sistema.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 6);
    return opcao;
}

int main()
{

    DEQUE d;
    int opcao, valor;
    dequeInicializar(&d);

    do
    {
        opcao = gerirMenu();
        switch (opcao)
        {
        case 1:
            printf("\nInsercao de valores no inicio da Deque.\nInforme um valor: ");
            scanf("%d", &valor);
            startEnqueue(&d, valor);
            break;

        case 2:
            printf("\nInsercao de valores no fim da Deque.\nInforme um valor: ");
            scanf("%d", &valor);
            endEnqueue(&d, valor);
            break;

        case 3:
            printf("\nRemocao de um elemento no inicio da Deque.");
            valor = startDequeue(&d);
            printf("\nValor %d foi removido da Deque.", valor);
            break;

        case 4:
            printf("\nRemocao de um elemento no fim da Deque.");
            valor = endDequeue(&d);
            printf("\nValor %d removido da Deque.", valor);
            break;

        case 5:
            printf("\nImpressao \"nao Classica\" da Deque.");
            impresaoNClassica(&d);
            break;

        case 6:
            printf("\nImpressao \"Classica\" da Deque.");
            impressaoClassica(&d);
            break;

        case 0:
            printf("\nENCERRANDO SISTEMA.");
            break;
        }
    } while (opcao != 0);
    return 0;
}
