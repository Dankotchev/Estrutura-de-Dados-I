/*
    EXERCÍCIO 08:
    Uma das grandes conquistas dos cidadãos brasileiros que possuem idade superior a 60 anos foi a
    criação da Lei nº 10.741, de 1º de outubro de 2003, que traz em seu texto a regulamentação do
    Estatuto do Idoso. Dentre os vários  Direitos assegurados, o Artigo nº 40 menciona o direito a
    vagas em transportes rodoviários interestaduais, sendo assegurado 2 vagas gratuitas por veículo
    e o restante com desconto de 50% para aqueles que comprovarem ter direito ao benefício e ser de
    baixa renda. Entretanto, várias empresas de transporte rodoviário não fazem esse controle e
    liberam a entrada de idosos em seus veículos, desde que seja realizado o embarque e desembarque
    pela porta da frente (em veículos que possuem duas portas de acesso). Nesses casos, os demais
    passageiros embarcam apenas pela porta de trás e sempre  desembarcam pela porta da frente.
    A "Empresa TransPass" é uma das empresas que cumpre essa lei e que disponibiliza uma linha de
    ônibus (com capacidade máxima de 40 passageiros) que faz o transporte de passageiros entre
    Presidente Epitácio e Presidente Prudente. A cada viagem, os passageiros podem embarcar em
    qualquer um dos pontos de parada ao longo do caminho, seja pela porta dianteira ou pela porta
    traseira, de acordo com a sua idade. Entretanto, o desembarque é realizado somente na cidade de
    destino, o qual é realizado pela porta dianteira do ônibus, seja na cidade de Presidente Epitácio
    ou de Presidente Prudente.

    Para esse cenário, pede-se:
        a) Qual a estrutura mais adequada para solucionar o problema acima?
        (mencionar e detalhar o nome completo da estrutura) Justifique sua resposta;
        b) Codifique uma estrutura que seja capaz de armazenar o nome de uma pessoa e sua idade;
        c) Codifique uma uma estrutura de dados, conforme sugerida no item a), para armazenamento
        dessas pessoas, utilizando a estrutura criada no item b);
        d) Utilizando as estruturas de dados criadas, faça um desenho para representar o estado da
        estrutura para cada uma das etapas descritas abaixo:
            i) Ônibus vazio;
            ii) Cidade de origem: Presidente Epitácio
            iii) Passageiros para embarque na seguinte sequência:
                - Bart, 20 anos;
                - Lisa: 19 anos;
                - Homer Simpson: 62 anos;
                - Marge: 65 anos;
                - Maggie: 15 anos.
            iv) Ponto de parada: Presidente Venceslau
            v) Passageiros para embarque na seguinte sequência:
                - Papai Smurf, 70 anos;
                - Smurfette: 18 anos;
                - Desastrado: 25 anos;
                - Preguiça: 30 anos;
                - Vovô Smurf, 95 anos.
            vi) Ponto de parada: Santo Anastácio
            vii) Passageiros para embarque na seguinte sequência:
                - Bob Esponja, 10 anos;
                - Patrick, 12 anos;
                - Seu Serigueijo, 62 anos.
            viii) Cidade de destino: Presidente Prudente. Todos os passageiros para  desembarque
        e) Codifique, compile e execute um programa que seja capaz de simular o item d) apresentado anteriormente.

    Autor: Danilo Domingues Quirino
    Versão: 2203.20
*/

#include <stdio.h>
#include <string.h>
#define TM 40

typedef struct sPassageiro
{
    char nome[20];
    int idade;
} PASSAGEIRO;

typedef struct sfila
{
    PASSAGEIRO lugares[TM];
    int inicio, fim;
} TRANSPASS;

void inicializar(TRANSPASS *bus)
{
    bus->inicio = TM - 1;
    bus->fim = TM - 1;
}

int verificarOnibus(TRANSPASS *bus)
{
    if (bus->inicio == bus->fim)
        return 1;
    return 0;
}

// Entrada no final da fila
void embarqueTraseira(TRANSPASS *bus, PASSAGEIRO pass)
{
    if (bus->fim == (TM - 1))
    {
        bus->fim = 0;
    }
    else
    {
        bus->fim++;
    }

    if (verificarOnibus(bus))
    {
        printf("Infelizmente o onibus encontra-se lotado");
        bus->fim--;
        if (bus->fim == -1)
        {
            bus->fim = TM - 1;
        }
        return;
    }

    bus->lugares[bus->fim] = pass;
}

// Entrada no inicio da fila (deque)
void embarqueDianteira(TRANSPASS *bus, PASSAGEIRO pass)
{
    if (bus->inicio == 0)
    {
        bus->inicio = TM - 1;
    }
    else
    {
        bus->inicio--;
    }

    if (verificarOnibus(bus))
    {
        printf("\nInfelizmente o onibus encontra-se lotado.");
        bus->inicio = (bus->inicio + 1) % TM;
    }

    bus->lugares[(bus->inicio + 1) % TM] = pass;
}

// Porta dianteira, retirar no inicio da fila
PASSAGEIRO desembarque(TRANSPASS *bus)
{
    if (!verificarOnibus(bus))
    {
        if (bus->inicio == TM - 1)
        {
            bus->inicio = 0;
        }
        else
        {
            bus->inicio++;
        }
    }
    else
    {
        printf("Onibus vazio");
    }
    return bus->lugares[bus->inicio];
}

void pontoDestino(TRANSPASS *bus)
{
    PASSAGEIRO pass;
    while (!verificarOnibus(bus))
    {
        pass = desembarque(bus);
        printf("\nPassageiro: %-20s\tIdade: %d", pass.nome, pass.idade);
    }
}

void lerTexto(char *texto, int tamanho)
{
    fflush(stdin);
    fgets(texto, tamanho, stdin);
    if (texto[strlen(texto) - 1] == '\n')
    {
        texto[strlen(texto) - 1] = '\0';
    }
}

void embarqueOnibus(TRANSPASS *bus)
{
    PASSAGEIRO novoPassageiro;
    int continuar;

    do
    {
        printf("\nNome do Passageiro que esta embarcando: ");
        lerTexto(novoPassageiro.nome, 19);
        printf("Informe a idade: ");
        fflush(stdin);
        scanf("%d", &novoPassageiro.idade);

        if (novoPassageiro.idade > 60)
        {
            embarqueDianteira(bus, novoPassageiro);
        }
        else
        {
            embarqueTraseira(bus, novoPassageiro);
        }

        if (!verificarOnibus(bus))
        {
            printf("\nEmbarcar outro Passageiro?\n\t1 - SIM\n\t0 - NAO");
            do
            {
                printf("\n\tEscolha ==>   ");
                scanf("%d", &continuar);
            } while (continuar < 0 || continuar > 1);
        }

    } while (continuar != 0);
}

int gerirMenu()
{
    int opcao;
    printf("\n----------\n\tTRASNPASS: SISTEMA INFORMACIONAL DE EMBARQUE E DESEMBARQUE");
    printf("\nEscolha a operacao desejada, informando o codigo correpondente.\n");
    printf("\n1 -\tEmbarque de Passageiro;");
    printf("\n2 -\tDesembarque no ponto de Destino;");
    printf("\n0 -\tEncerrar Sistema.\n");

    do
    {
        printf("Escolha ==>   ");
        scanf("%d", &opcao);
    } while (opcao < 0 || opcao > 2);
    return opcao;
}

int main()
{
    TRANSPASS onibus;
    int opcao;

    inicializar(&onibus);

    do
    {
        opcao = gerirMenu();
        switch (opcao)
        {
        case 1:
            printf("\nEmbarque de Passageiros.");
            embarqueOnibus(&onibus);
            break;

        case 2:
            printf("\nDesembarque no Ponto de Destino.");
            pontoDestino(&onibus);
            break;

        case 0:
            printf("\nENCERRANDO O SISTEMA.");
            break;
        }
    } while (opcao != 0);
    return 0;
}