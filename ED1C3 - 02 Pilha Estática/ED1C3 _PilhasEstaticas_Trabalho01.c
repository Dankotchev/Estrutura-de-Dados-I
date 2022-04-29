
/*
    TRABALHO N#01 :
    Considerando um programa em linguagem C que armazene em uma pilha P os seguintes dados: nome, idade e sexo.
    A partir desta pilha, codifique uma função que seja capaz de gerar duas outras pilhas: PF e PM,
    contendo, cada uma: nome e idade, sendo que a pilha PF armazena dados das pessoas femininas
    e a pilha PM das masculinas. Após este processo, exiba o conteúdo das duas pilhas.

    Autor: Danilo Domingues Quirino
    Versão: 2203.08
*/

// Bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define TM 100
#define TNOME 30

typedef struct sDados
{
    char sexo;
    char nome[TNOME];
    int idade;

} DADOS;

typedef struct sPilha
{
    DADOS informacoes [TM];
    int topo;
} PILHA;



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

void imprimirSemDesempilhar(PILHA *umaPilha)
{
    if (pilha_Vazia(umaPilha))
    {
        printf("Pilha vazia no momento.\n");
    }
    else
    {
        for (int i = umaPilha->topo; i >= 0; i--)
        {
            printf("|Nome: %s | Idade: %d |\n",
                   umaPilha->informacoes[i].nome, umaPilha->informacoes[i].idade);
            printf("|--------------------------|\n");
        }
    }
}

void push(PILHA *umaPilha, DADOS cadastro)
{
    if (pilha_Cheia(umaPilha))
    {
        printf("Erro. Pilha cheia no momento.\n");
    }
    else
    {
        umaPilha->topo++;
        umaPilha->informacoes[umaPilha->topo] = cadastro;
    }
}

DADOS pop(PILHA *umaPilha)
{
    DADOS cadastro;

    if (pilha_Vazia(umaPilha))
    {
        printf("Erro. Pilha vazia no momento.\n");
    }
    else
    {
        cadastro = umaPilha->informacoes[umaPilha->topo];
        umaPilha->topo--;
        return cadastro;
    }
}

void separarPilha(PILHA *pg, PILHA *fp, PILHA *mp)
{
    DADOS cadastroAtual;
    while (!pilha_Vazia(pg))
    {
        cadastroAtual = pop(pg);
        if (cadastroAtual.sexo == 'F')
        {
            push(fp, cadastroAtual);
        }
        else
        {
            push(mp, cadastroAtual);
        }
    }
}

void leituraInformacoes(PILHA *pilhaGeral)
{
    DADOS leitor;
    do
    {
        printf("\n\t### Insira as informacoes da pessoa.\n");
        printf("(Para sair do cadastro, digite S ao informar o sexo.)\n\n");
        printf("\tInforme o sexo\n\t(M - Masculino; F - Feminino)\n\t==> ");
        fflush(stdin);
        scanf("%c", &leitor.sexo);
        leitor.sexo = toupper(leitor.sexo);
        if (leitor.sexo != 'S')
        {
            fflush(stdin);
            printf("\tInsira o nome: ");
            scanf("%s", leitor.nome);
            //fgets(leitor.nome, TNOME-1, stdin);
            printf("\tInsira a idade: ");
            scanf("%d", &leitor.idade);
            push(pilhaGeral, leitor);
        }
    }
    while (leitor.sexo != 'S');
}


int main()
{
    PILHA pilhaGeral, femininoPilha, masculinoPilha;
    pilha_Inicializar(&pilhaGeral);
    pilha_Inicializar(&femininoPilha);
    pilha_Inicializar(&masculinoPilha);


    leituraInformacoes(&pilhaGeral);
    separarPilha(&pilhaGeral, &femininoPilha, &masculinoPilha);
    printf("\nA pilha contendo apenas dados Femininos eh:\n");
    imprimirSemDesempilhar(&femininoPilha);
    printf("\nA pilha contendo apenas dados Masculinos eh:\n");
    imprimirSemDesempilhar(&masculinoPilha);

    return 0;
}