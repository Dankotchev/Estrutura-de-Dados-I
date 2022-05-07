/*
    EXERCÍCIO 03:
    Para organizar o chá de cozinha de Maria Eduarda, sua irmã mais nova, Gabriela, enviou um e-mail
    para todas as suas amigas convidando-as para se reunirem no salão de festa de sua casa.
    Ela solicitou que cada convidada levasse junto com o presente uma receita culinária de sua
    preferência para enriquecer o livro de receitas virtual que será dado para Maria Eduarda
    antes do dia do casamento. Para facilitar a organização das receitas, Gabriela pediu a um(a)
    amigo(a) do curso de Sistemas de Informação (você!!!) que fizesse um programa em que fosse
    possível cadastrar (ordenando pelo título) e exibir as receitas na tela do computador a qualquer
    momento que ela quisesse. Foi solicitado também que este sistema ficasse pronto até o dia da festa,
    para que fosse possível cada convidada cadastrar sua receita previamente. As informações
    solicitadas no momento do cadastro deverão ser: título da receita, descrição dos ingredientes,
    tipo (doce ou salgado) e o nome da pessoa que presenteou Maria Eduarda com a receita.
    Utilize os conceitos de lista simplesmente encadeada para implementar uma solução para o
    problema acima.

    Autor: Danilo Domingues Quirino
    Versão: 2204.30
*/

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TT 30
#define TD 50

typedef struct sReceita
{
    char tituloReceita[TT];
    char descricaoIngredientes[TD];
    unsigned char tipo;
} RECEITA;

typedef struct sLivroReceita
{
    RECEITA pagina;
    char presenteador[TD];
    struct cell *next;
} LIVRO;

void inicializar(LIVRO **lista)
{
    *lista = NULL;
}

LIVRO *getNode()
{
    return (LIVRO *)malloc(sizeof(LIVRO));
}

int listaVazia(LIVRO *lista)
{
    if (lista == NULL)
        return 1;
    return 0;
}

void exibirLivro(LIVRO *lista)
{
    while (lista != NULL)
    {
        printf("");
        if (lista->pagina.tipo == 1)
            printf("Tipo: Doce\n");
        else
            printf("Tipo: Salgado\n");
        printf("Receita: %s\n", lista->pagina.tituloReceita);
        printf("Ingredientes: %s\nPresente de: %s\n", lista->pagina.descricaoIngredientes,
               lista->presenteador);
        lista = lista->next;
        printf("-----\n\n");
    }
}

// Resolver isso
// void ordenarCrescente(LIVRO **lista);

void inserirFim(LIVRO **lista, RECEITA entrada, char nomeP[])
{
    LIVRO *inserir, *aux;

    inserir = getNode();
    if (inserir != NULL)
    {
        strcpy(inserir->presenteador, nomeP);
        inserir->pagina = entrada;
        if (listaVazia(*lista))
        {
            *lista = inserir;
        }
        else
        {
            aux = *lista;
            while (aux->next != NULL)
            {
                aux = aux->next;
            }
            aux->next = inserir;
        }
        // ordenarCresente(lista);
    }
    else
    {
        printf("\nErro na alocacao do no");
        return;
    }
}

void lerTexto(char *texto, int tamanho)
{
    // fflush(stdin);
    __fpurge(stdin);
    fgets(texto, tamanho, stdin);
    if (texto[strlen(texto) - 1] == '\n')
    {
        texto[strlen(texto) - 1] = '\0';
    }
}

RECEITA lerPresente()
{
    RECEITA ler;
    unsigned char tipo;

    printf("Qual o Titulo da Receita: ");
    lerTexto(ler.tituloReceita, TT - 1);
    printf("Descricao dos Ingredientes: ");
    lerTexto(ler.descricaoIngredientes, TD - 1);
    do
    {
        printf("Qual o tipo da Receita:\n1 - Doce\t2 - Salgado\t:: ");
        scanf("%c", &tipo);
    } while (tipo < '1' || tipo > '2');
    ler.tipo = tipo;

    return ler;
}

int gerirMenu()
{
    int op;
    printf("\n----------\n\tLIVRO DE RECEITA DE MARIA EDUARDA");
    printf("\nEscolha a operacao desejada.\n");
    printf("\n1 -\tApresentar Receitas");
    printf("\n0 -\tEncerrar.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &op);
    } while (op < 0 || op > 1);
    return op;
}

int main()
{
    LIVRO *lista;
    char nome[TD], continuar;
    RECEITA presente;
    int op;

    inicializar(&lista);

    printf("Cha de Cozinha de Maria Eduarda\nCadastro de Presentes: Receitas\n");
    do
    {
        printf("Informe os Dados do Presente...\n");
        printf("Quem esta presenteando Maria Eduarda: ");
        lerTexto(nome, TD);
        presente = lerPresente();
        inserirFim(&lista, presente, nome);

        printf("Cadastrar outro presente?\n\tS/N :: ");
        // fflush(stdin);
        __fpurge(stdin);
        scanf("%c", &continuar);
        continuar = toupper(continuar);

    } while (continuar != 'N');

    do
    {
        op = gerirMenu();
        switch (op)
        {
        case 1:
            printf("\n\t\tLivro de Receitas\n");
            exibirLivro(lista);
            break;

        case 0:
            printf("Encerrando...");
            break;
        }
    } while (op != 0);
    return 0;
}