/*
	EXERCÍCIO 07:
    Na cidade de Presidente Epitácio o carnaval é uma festa que conta com a participação de um grande
    número de foliões, incluindo moradores da cidade e visitantes de outras localidades.
    A festa acontece na orla da cidade, que é ocupada por barracas para venda de bebidas, lanches e
    artigos em geral. Para garantir o sucesso da festa, a prefeitura define, todos os anos,
    um número máximo de barracas que poderão ser instaladas no local da festa. Para o ano de 2019
    foi prevista a instalação de 50 barracas, as quais serão alugadas pelos comerciantes interessados.
    Porém, todo ano a prefeitura apresenta dificuldades para gerenciar informações como, por exemplo:
        - número de barracas ocupadas e livres; 
        - dados do locatário (nome, CPF); 
        - situação dos aluguéis (pagos ou não);
        - produtos que serão comercializados. 
    Para facilitar o gerenciamento dessas  informações a prefeitura contratou os serviços de uma
    empresa de TI para desenvolver um programa na linguagem C que atenda as seguintes requisições,
    utilizando os conceitos de lista estática:
        a) Todas as barracas deverão possuir uma identificação, bem como o nome e CPF do
        locatário responsável pelo aluguel, situação do aluguel (pago ou não), identificação do
        produto que será comercializado (1: bebida, 2: lanches, 3: artigos em geral);
        b) O aluguel de barracas deverá acontecer por ordem de chegada, ou seja, o comerciante que 
        chegar primeiro ficará com a primeira barraca, o que chegar na sequência ficará com a
        segunda barraca e assim por diante;
        c) Ao solicitar o aluguel de uma barraca, o locatário deverá fornecer ao funcionário da prefeitura
        as informações necessárias para cadastro (item (a));
        d) O sistema deverá ser capaz de gerar os seguintes relatórios:
            i)  Relatório com os dados dos locatários inadimplentes (pessoas que não efetuaram o pagamento da reserva)
            exibindo a identificação da barraca;
            ii) Relatório exibindo a lista de barracas livres e ocupadas (pelo número de identificação de cada barraca)
            apresentando ao final de cada listagem a soma total.

	Autor: Danilo Domingues Quirino
	Versão: 2202.18
*/

// Bibliotecas
#include <stdio.h>
#include <string.h>

#define TF 50

typedef struct sComerciantes
{
    int id;
    char nome[50];
    char cpf[11];
    int situAluguel; // 1 - ok ; 0 - inadiplente
    int tipoProduto;
} COMERCIANTE;

typedef struct sBarracas
{
    COMERCIANTE locatarios[TF];
    int ocupacao;
} BARRACA;

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tCARNAVAL PRESIDENTE EPITACIO");
    printf("\n\tSistema de Gerenciamento de Alugueis de Barracas Comerciais");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.");
    printf("\n1 - Alugar Espaco Barraca Comercial;");
    printf("\n2 - Imprimir Relatorio: Locatarios inadiplentes;");
    printf("\n3 - Imprimir Relatorio: Espacos de Barracas Livres e Ocupadas;");
    printf("\n0 - Encerrar Sistema.\n");

    do
    {
        printf("Escolha ==> ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 3);
    return opcao;
}

void lista_Inicializar(BARRACA *iLista)
{
    iLista->ocupacao = -1;
}

int lista_Cheia(BARRACA *cLista)
{
    if (cLista->ocupacao + 1 == TF)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int lista_Vazia(BARRACA *vLista)
{
    if (vLista->ocupacao == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void leitura_Strings(char *variavel, int tamanho)
{
    fflush(stdin);
    fgets(variavel, tamanho, stdin);
    if (variavel[strlen(variavel) - 1] == '\n')
    {
        variavel[strlen(variavel) - 1] = '\0';
    }
    fflush(stdin);
}

void comerciante_Leitura(COMERCIANTE *novaEntrada, int id)
{
    printf("Informe os dados do solicitante ::\n");
    novaEntrada->id = id;
    printf("Solicitacao de aluguel n# %d\n", id);
    printf("Nome do Locatario :: ");
    leitura_Strings(novaEntrada->nome, 50);
    printf("CPF do Locatario :: ");
    leitura_Strings(novaEntrada->cpf, 12);
    printf("Quail tipo de produto sera comercializado ::");
    printf("\n\t(1: Bebida, 2: Lanches, 3: Outros Artigos) :: ");
    scanf("%d", &novaEntrada->tipoProduto);
    printf("Situacao Aluguel :: \n\t(1: Pago, 0: nao Pago) :: ");
    scanf("%d", &novaEntrada->situAluguel);
}

void comerciante_Imprimir(COMERCIANTE *imprimir)
{
    printf("~~~~~\nBarraca ID :: %d\n", imprimir->id);
    printf("Nome Locatario :: %s\n", imprimir->nome);
    printf("CPF do Locatario :: %s\n", imprimir->cpf);
    printf("Tipo de produto sendo comercializado ::");
    switch (imprimir->tipoProduto)
    {
    case 1:
        printf("\t1: Bebidas\n");
        break;
    case 2:
        printf("\t1: Lanches\n");
        break;
    case 3:
        printf("\t1: Outros Artigos\n");
        break;
    }
    printf("Situacao do Aluguel :: \t%d: Inadiplente\n", imprimir->situAluguel);
}

void lista_Inserir(BARRACA *alugando)
{
    COMERCIANTE locatario;

    if (lista_Cheia(alugando))
    {
        printf("Erro: Nao ha mais Barracas disponiveis para alugar.\n");
    }
    else
    {
        comerciante_Leitura(&locatario, alugando->ocupacao + 1); // olhar no projeto AP2
        alugando->locatarios[alugando->ocupacao + 1] = locatario;
        alugando->ocupacao++;
    }
}

void relatorio_Inadiplentes(BARRACA *inquilinos)
{
    if (lista_Vazia(inquilinos))
    {
        printf("Erro: Ainda nao ha inquilinos nas barracas.\n");
    }
    else
    {
        for (int i = 0; i <= inquilinos->ocupacao; i++)
        {
            if (inquilinos->locatarios[i].situAluguel == 0)
            {
                comerciante_Imprimir(&inquilinos->locatarios[i]);
            }
        }
    }
}

void relatorio_BarracaLivresOcupadas(BARRACA *disponibilidade)
{
    if (lista_Vazia(disponibilidade))
    {
        printf("Erro: Ainda nao ha inquilinos nas barracas.\n");
    }
    else
    {
        printf("\nAs barracas ocupadas sao as de numero: ");
        for (int i = 0; i <= disponibilidade->ocupacao; i++)
        {
            printf("%d, ", i);
        }
        printf("\nAs barracas livres sao as de numero: ");
        for (int i = disponibilidade->ocupacao + 1; i < TF; i++)
        {
            printf("%d, ", i);
        }
        printf("\nEstao ocupadas %d espacos de barracas;\nEstao disponiveis %d espacos de barracas.\n",
               disponibilidade->ocupacao + 1, TF - (disponibilidade->ocupacao + 1));
    }
}

int main()
{
    int opcao;
    BARRACA bar;
    lista_Inicializar(&bar);

    do
    {
        opcao = gerirMenu();
        switch (opcao)
        {
        case 1:
            printf("\nAlugar Espaco Barraca Comercial.\n");
            lista_Inserir(&bar);
            break;

        case 2:
            printf("\nImprimir Relatorio: Locatarios inadiplente.\n");
            relatorio_Inadiplentes(&bar);
            break;

        case 3:
            printf("\nImprimir Relatorio: Espacos de Barracas Livres e Ocupadas.\n");
            relatorio_BarracaLivresOcupadas(&bar);
            break;
        case 0:

            printf("\n\nENCERRANDO SISTEMA");
            break;
        }
    } while (opcao != 0);
    return 0;
}
