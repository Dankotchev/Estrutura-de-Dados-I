/*
    EXERCÍCIO 01:
    É tradição em algumas Universidades oferecer o Baile Anual de Ex-Alunos no início do mês de
    dezembro de todos os anos. Com o objetivo de reencontrar os antigos colegas de curso e retornar
    aos lugares do tempo da graduação as turmas se reúnem de 5 em 5 anos para festejar.
    Visando trazer essa tradição para o campus do IFSP de Presidente Epitácio foi solicitado ao
    CTI-PEP o desenvolvimento de uma aplicação simples para cadastramento dos dados de cada
    formando do IFSP-PEP (prontuário, nome completo, nome do curso, ano de ingresso,
    ano de formatura, endereço e dois telefones de contato). Além disso, foi solicitado que a
    aplicação fosse capaz de gerar dois tipos de relatórios, o primeiro contendo as informações
    de todos os ex-alunos separados por curso, e o segundo contendo as informações dos alunos separados
    pelo ano de formatura. Utilize os conceitos de lista linear dinâmica para desenvolver a aplicação e,
    desta forma, atender plenamente o pedido solicitado.

    Autor: Danilo Domingues Quirino
    Versão: 2204.08
*/

#include <stdio.h>
#include <stdlib.h>
#include "ED1C3_ListaDinamica_Ex01Utilidades.h"

EGRESSO *inicializar(EGRESSO *lista)
{
    lista = NULL;
    return lista;
}

EGRESSO *getNode()
{
    return (EGRESSO *)malloc(sizeof(EGRESSO));
}

void freeNode(EGRESSO *no)
{
    free(no);
}

int listaVazia(EGRESSO *lista)
{
    if (lista == NULL)
        return 1;
    return 0;
}

void relatorioCurso(EGRESSO *lista, int id)
{
    EGRESSO *auxiliar;
    int existencia = 0;

    auxiliar = lista;
    if (!listaVazia(lista))
    {
        while (auxiliar != NULL)
        {
            if (auxiliar->idCurso == id)
            {
                printf("\nProntuario: %s\tNome Completo: %s\n",
                       auxiliar->alunoFormado.prontuario, auxiliar->alunoFormado.nomeCompleto);
                printf("Ano de Ingresso: %d\tAno de Formatura: %d\n",
                       auxiliar->alunoFormado.anoIngresso, auxiliar->alunoFormado.anoFormatura);
                printf("Endereco: %s\tTelefone 1: %d\tTelefone 2: %d",
                       auxiliar->alunoFormado.endereco, auxiliar->alunoFormado.num1Tel, auxiliar->alunoFormado.num2Tel);
                printf("\n");

                existencia = 1;
            }
            auxiliar = auxiliar->next;
        }
        if (!existencia)
            printf("\nNao ha alunos para exibir no filtro atual.\n");
    }
    else
        printf("\nNao ha alunos cadastrados");
}

void relatorioAno(EGRESSO *lista, int anno)
{
    EGRESSO *auxiliar;
    int existencia = 0;

    auxiliar = lista;
    if (!listaVazia(lista))
    {
        while (auxiliar != NULL)
        {
            if (auxiliar->alunoFormado.anoFormatura == anno)
            {
                printf("\nProntuario: %s\tNome Completo: %s\n",
                       auxiliar->alunoFormado.prontuario, auxiliar->alunoFormado.nomeCompleto);
                printf("Curso: %s\tAno de Ingresso: %d\n",
                       auxiliar->alunoFormado.curso, auxiliar->alunoFormado.anoIngresso);
                printf("Endereco: %s\tTelefone 1: %d\tTelefone 2: %d",
                       auxiliar->alunoFormado.endereco, auxiliar->alunoFormado.num1Tel, auxiliar->alunoFormado.num2Tel);
                printf("\n");

                existencia = 1;
            }
            auxiliar = auxiliar->next;
        }
        if (!existencia)
            printf("\nNao ha alunos para exibir no filtro atual.\n");
    }
    else
        printf("\nNao ha alunos cadastrados");
}

EGRESSO *inserirLista(EGRESSO *lista, FORMANDO x, int id)
{
    EGRESSO *inserir;

    inserir = getNode();
    if (inserir != NULL)
    {
        inserir->alunoFormado = x;
        inserir->idCurso = id;
        inserir->next = lista;
        lista = inserir;
        return lista;
    }
    else
    {
        printf("\nErro na alocacao do no");
        return NULL;
    }
}

int main()
{

    EGRESSO *lista;
    lista = inicializar(lista);
    int opcao, idCurso;

    do
    {
        opcao = gerirMenu();

        switch (opcao)
        {
        case 1:
            printf("\nCadastro de alunos Formandos\nSelecione o curso do Aluno Formando: ");
            idCurso = selecionarCurso();
            lista = inserirLista(lista, lerInformacoes(idCurso), idCurso);
            break;

        case 2:
            printf("\nRelatorio: Selecione o curso desejado: \n");
            relatorioCurso(lista, selecionarCurso());
            break;

        case 3:
            printf("\nRelatorio: Selecione o Ano de Formatura: \n");
            relatorioAno(lista, lerAnoFormatura());
            break;

        case 0:
            printf("\nENCERRANDO SISTEMA");
            break;
        }

    } while (opcao != 0);

    return 0;
}
