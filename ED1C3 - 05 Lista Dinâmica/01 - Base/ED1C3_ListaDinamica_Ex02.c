/*
    EXERCÍCIO 02:
    Na manhã do dia 15 de agosto de 2011 o site de internet “O Globo” publicou a notícia de que a
    empresa Google anunciou em seu blog corporativo a compra da Motorola pelo valor de US$ 12,5 bilhões.
    Essa notícia pegou de surpresa os funcionários da Motorola que ficaram animados ao ouvir a
    declaração do diretor geral da Google: “Estamos ansiosos para receber os funcionários da Motorola
    em nossa família de Googlers”. Diante do compromisso da Motorola com o desenvolvimento Android,
    os gerentes fizeram uma reunião com os líderes de projeto, responsáveis pelo setor, para que
    algumas atividades fossem concluídas antes da integração das duas companhias. Dentre os módulos
    a serem finalizados destacou-se o módulo de contato para celular, que deverá ser implementado no
    prazo máximo de dois dias. Este módulo deverá possibilitar a inserção/listagem/remoção/pesquisa
    de contatos por nome no celular, respeitando a ordem alfabética. Na inserção de um novo contato
    deverá ser possível cadastrar dois números de telefone e o toque de chamada (ringtone)
    personalizado para cada usuário. Como parte dos requisitos foi solicitada a implementação
    usando a linguagem C utilizando os conceitos de lista linear dinâmica.

    Autor: Danilo Domingues Quirino
    Versão: 2204.
*/

#include <stdio.h>
#include <stdlib.h>
#include "ED1C3_ListaDinamica_Ex02Utilidades.h"

CONTATOS *inicializar(CONTATOS *lista)
{
    lista = NULL;
    return lista;
}

CONTATOS *getNode()
{
    return (CONTATOS *)malloc(sizeof(CONTATOS));
}

void freeNode(CONTATOS *no)
{
    free(no);
}

int listaVazia(CONTATOS *lista)
{
    if (lista == NULL)
        return 1;
    return 0;
}

CONTATOS *ordenarContatos(CONTATOS *lista)
{
    CONTATOS *atual, *anterior, *proximo;

    atual = lista;

    while (atual != NULL)
    {
        proximo = atual->next;
        anterior = atual;
        if (strcmp(atual->contatinho.nomeCompleto, proximo->contatinho.nomeCompleto) > 0)
        {
            atual->next = atual->next->next;
            proximo->next = atual;
            anterior->next = proximo;
        }
        atual = atual->next->next;
    }
    return lista;
}

CONTATOS *inserirContato(CONTATOS *lista, CAD x)
{
    CONTATOS *inserir;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->contatinho = x;
        inserir->next = lista;
        lista = inserir;

        lista = ordenarContatos(lista);
        return lista;
    }
    else
    {
        printf("\nErro na alocacao do no");
        return NULL;
    }
}

void listarContatos(CONTATOS *lista)
{
    CONTATOS *auxiliar;

    auxiliar = lista;
    if (!listaVazia(lista))
    {
        while (auxiliar != NULL)
        {
            printf("\nNome: %s\tTelefone (1): %d\tTelefone (2): %d\n\tRingtone: %s\n",
                   auxiliar->contatinho.nomeCompleto, auxiliar->contatinho.num1Tel,
                   auxiliar->contatinho.num2Tel, auxiliar->contatinho.ringtone);
            auxiliar = auxiliar->next;
        }
    }
    else
        printf("\nNao ha contatos cadastrados");
}

CONTATOS *removerInicio(CONTATOS *lista)
{
    CONTATOS *remover;

    remover = lista;
    if (!listaVazia(lista))
    {
        lista = remover->next;
        freeNode(remover);
        return lista;
    }
    else
    {
        printf("\nAgenda de Contatos vazia.");
        return NULL;
    }
}

CONTATOS *pesquisar(CONTATOS *lista, char nome[])
{
    CONTATOS *procurar;

    if (!listaVazia(lista))
    {
        procurar = lista;
        while (procurar != NULL)
        {
            if (strcmp(procurar->contatinho.nomeCompleto, nome) == 0)
                return procurar;
            procurar = procurar->next;
        }
    }
    return NULL;
}

CONTATOS *removerContato(CONTATOS *lista, char nome[])
{
    CONTATOS *remover;
    CONTATOS *auxiliar;

    if ((remover = pesquisar(lista, nome)) != NULL)
    {
        auxiliar = lista;
        if (auxiliar == remover)
        {
            lista = removerInicio(lista);
            printf("\nContato Removido.");
            return lista;
        }

        else
        {
            while (auxiliar->next != remover)
                auxiliar = auxiliar->next;
            auxiliar->next = remover->next;
            printf("\nContato Removido.");
            freeNode(remover);
        }
        return lista;
    }
    return NULL;
}

void buscarContato(CONTATOS *lista, char nome[])
{
    CONTATOS *buscarApresentar;

    if ((buscarApresentar = pesquisar(lista, nome)) != NULL)
    {
        printf("\nNome: %s\tTelefone (1): %d\tTelefone (2): %d\n\tRingtone: %s\n",
               buscarApresentar->contatinho.nomeCompleto, buscarApresentar->contatinho.num1Tel,
               buscarApresentar->contatinho.num2Tel, buscarApresentar->contatinho.ringtone);
    }
    else
        printf("\nContato nao existe na Agenda de Contatos.");
}

int main()
{

    CONTATOS *lista;
    lista = inicializar(lista);
    int opcao, idCurso;
    char nomeBuscar[50];

    do
    {
        opcao = gerirMenu();

        switch (opcao)
        {
        case 1:
            printf("\nInserindo novo Contato:");
            lista = inserirContato(lista, lerInformacoes());
            break;

        case 2:
            printf("\nListando os Contatos:\n");
            listarContatos(lista);
            break;

        case 3:
            printf("\nRemovendo um contato:\nInforme o nome a remover: ");
            lerTexto(nomeBuscar, 50);
            lista = removerContato(lista, nomeBuscar);
            break;

        case 4:
            printf("Buscar Contato:\nInforme o nome o nome a buscar: ");
            lerTexto(nomeBuscar, 50);
            buscarContato(lista, nomeBuscar);

        case 0:
            printf("\nENCERRANDO SISTEMA");
            break;
        }

    } while (opcao != 0);

    return 0;
}
