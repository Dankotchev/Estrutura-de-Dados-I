
#include <stdio.h>
#include <stdlib.h>

typedef struct cell
{
    int info;
    struct cell *next;
}CEDULA;

CEDULA* inicializar (CEDULA *lista)
{
    lista = NULL;
    return lista;
}

CEDULA* getNode()
{
    return (CEDULA *) malloc (sizeof(CEDULA));
}

void freeNode(CEDULA *no)
{
    free(no);
}

int listaVazia(CEDULA *lista)
{
    if (lista == NULL)
        return 1;
    return 0;
}

void exiblirLista(CEDULA *lista)
{
    CEDULA *auxiliar;

    auxiliar = lista;
    while (auxiliar != NULL)
    {
        printf("%d\t", auxiliar->info);
        auxiliar = auxiliar->next;
    }
    printf("\n\n");
}

CEDULA* inserirInicio(CEDULA *lista, int x)
{
    CEDULA *no;

    no = getNode();
    if (no != NULL)
    {
        no->info = x;
        no->next = lista;
        lista = no;
        return lista;
    }
    else
    {
        printf("\nErro na alocacao do no");
        return NULL;
    }
}
CEDULA* inserirFim (CEDULA *lista, int x)
{
    CEDULA *no;
    CEDULA *auxiliar;

    no = getNode();
    if(no != NULL)
    {

    }
}


int main ()
{

CEDULA *lista;

lista = inicializar(lista);



}
