#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//var global de ID
int n = 0;

typedef struct data_base DB;
//Struct padrão da data base
struct data_base
{
    char nome[50];
    int idade;
    int hrs_trb;
    int id;
};
//Structs globais para organização
DB funcs_cads[21];//Ordem de ID(padrão)
DB ordem_alf[21];//Ordem Alfabetica
DB ordem_hrs[21];//Ordem de horario
//Trabalho com varias structs para não
//desorganizar a padrão

//Função para alterar as horas trabalhadas de um funcionario
void alt_hrsTrab(int Id_alt)//recebo o ID do funcionario
{
    DB aux = funcs_cads[Id_alt];//DB auxiliar para prints
    system("cls");
    printf("Horas atuais: %d\n", funcs_cads[Id_alt].hrs_trb);
    printf("Insira as novas horas:\n");
    printf(">> ");
    scanf("%d", &funcs_cads[Id_alt].hrs_trb);
    system("cls");
    printf("Horas alteradas com sucesso!\n");
    printf("%d -> %d", aux.hrs_trb, funcs_cads[Id_alt].hrs_trb);
    getch();
}

//Função para alterar a idade do funcionario
void alt_idade(int Id_alt)//recebo o ID do funcionario
{
    DB aux = funcs_cads[Id_alt];//DB auxiliar para prints
    system("cls");
    printf("Idade atual: %d\n", funcs_cads[Id_alt].idade);
    printf("Insira a nova idade:\n");
    printf(">> ");
    scanf("%d", &funcs_cads[Id_alt].idade);
    system("cls");
    printf("Idade alterado com sucesso!\n");
    printf("%d -> %d", aux.idade, funcs_cads[Id_alt].idade);
    getch();
}

//Função para alterar o nome do funcionario
void alt_nome(int Id_alt)//Recebo o ID do funcionario
{
    DB aux = funcs_cads[Id_alt];//DB auxiliar para prints
    system("cls");
    fflush(stdin);
    printf("Nome atual: %s\n", funcs_cads[Id_alt].nome);
    printf("Insira o novo nome:\n");
    printf(">> ");
    gets(funcs_cads[Id_alt].nome);
    system("cls");
    printf("Nome alterado com sucesso!\n");
    printf("%s -> %s", aux.nome, funcs_cads[Id_alt].nome);
    getch();
}

//Função para editar os cadastros já efetuados
void editar_cadastro()
{
    system("cls");
    int Id_alt, opcao;
    printf("ID do funcionario a ser alterado: ");
    scanf("%d", &Id_alt);//Recebo o ID

    //Verifico se é um ID existente na DB
    if(Id_alt <= n && Id_alt > -1)
    {
        system("cls");
        printf("Funcionario selecionado:\n");
        printf("-> %s\n", funcs_cads[Id_alt].nome);
        printf("Qual dado deseja alterar?\n");
        printf("1 - Nome\n");
        printf("2 - Idade\n");
        printf("3 - Hrs Trab\n");
        printf("4 - Retornar ao menu\n");
        printf("----------------------------\n");
        printf(">> ");
        scanf("%d", &opcao);//Opção do switch
        switch(opcao)
        {
            case 1:
            //Chamo a alteração de nome passando o ID
            alt_nome(Id_alt);
            break;
            case 2:
            //Chamo a alteração de idade passando o ID
            alt_idade(Id_alt);
            break;
            case 3:
            //Chamo a alteração das horas trab passando o ID
            alt_hrsTrab(Id_alt);
            break;
            case 4:
            break;
            default:
            break;
        }
        
    }
    //Se não existir exibo essa mensagem
    else
    {
        printf("Funcionario nao encontrado!");
        getch();
    }

}

//Função para ordenar/printar em ordem de horario
void list_ordemHrs()
{
    DB aux;//DB auxiliar
    for(int i = 0; i < n; i++)
    {
        //Primeiramente:
        //Salvo todos os dados na DB de organização
        ordem_hrs[i] = funcs_cads[i];
    } 

    //Organizo os dados
    for(int i = 0; i < n; i++){
        for(int c = i + 1; c < n; c++){
            //Procedimento simples com 2 "for" para ordenar o vetor
            if(ordem_hrs[c].hrs_trb < ordem_hrs[i].hrs_trb){
                aux = ordem_hrs[i];
                ordem_hrs[i] = ordem_hrs[c];
                ordem_hrs[c] = aux;
            }
        }
    }
    system("cls");
    //Esquema de prints
    printf("Cadastros Organizados:\n");
    printf("----------------------------------------------\n");
    for(int i = 0; i < n; i++){
        printf("Nome:       %s\n", ordem_hrs[i].nome);
        printf("Idade:      %d\n", ordem_hrs[i].idade);
        printf("Horas Trab: %d\n", ordem_hrs[i].hrs_trb);
        printf("Id:         %d\n", ordem_hrs[i].id);
        printf("----------------------------------------------\n");
    }
    getch();
    system("cls");
   
}

//Função para ordenar/printar em ordem de horario
void list_ordemAlf()
{
    DB aux;//DB auxiliar
    int num_hold;//Aux para o resultado do "strcmp"

    for(int i = 0; i < n; i++)
    {
        //Primeiramente:
        //Salvo todos os dados na DB de organização
        ordem_alf[i] = funcs_cads[i];
    } 

    for(int i = 0; i < n; i++)
    {
        for(int c = i + 1; c < n; c++)
        {
            //Procedimento simples com 2 "for" para ordenar o Vetor
            //Uso o "strcmp" para comparar o valor das strings
            num_hold = strcmp(ordem_alf[c].nome, ordem_alf[i].nome);

            //Se a condição for satisfeita ocorre a ordenação
            if(num_hold < 0)
            {
                aux = ordem_alf[i];
                ordem_alf[i] = ordem_alf[c];
                ordem_alf[c] = aux;
            }
        }
    }

    //Esquema de prints
    system("cls");
    printf("Cadastros em ordem Alfabetica:\n");
    printf("----------------------------------------------\n");
    for(int i = 0; i < n; i++){
        printf("Nome:       %s\n", ordem_alf[i].nome);
        printf("Idade:      %d\n", ordem_alf[i].idade);
        printf("Horas Trab: %d\n", ordem_alf[i].hrs_trb);
        printf("Id:         %d\n", ordem_alf[i].id);
        printf("----------------------------------------------\n");
    }
    getch();
    system("cls");
}

//Função de apagar o cadastro de um funcionário
void apagar()
{
    int aux = 0;//int auxiliar
    char nome_inserido[50];//char auxiliar
    system("cls");
    fflush(stdin);
    //Recolho o nome para o processo de remoção
    printf("Insira o nome do func que deseja remover:\n");
    printf(">> ");
    gets(nome_inserido);

    //percorro a matriz para achar o nome do funcionario
    for(int i = 0; i < n; i++)
    {
        //Condição usando o "strcmp"
        if(strcmp(nome_inserido, funcs_cads[i].nome) == 0)
        {
            /*Se a condição for satisfeita, eu re-ordeno o vetor
            a partir do nome selecionado, afim de não perder a
            organização por ID*/
            for(int c = i; c < n; c++)
            {
                funcs_cads[c] = funcs_cads[c + 1];
            }
            /*Zero todas as variaveis na ultima posição do vetor,
            que vai ficar uma copia da penultima, afim de economizar
            memoria*/
            strcpy(funcs_cads[n].nome, "");
            funcs_cads[n].idade = 0;
            funcs_cads[n].hrs_trb = 0;
            n--;//Removo 1 do meu ID maximo
            //Esquema de prints
            printf("Funcionario \"%s\" apagado com sucesso!\n", nome_inserido);
            getch();
            aux = 1;

            //Reordeno todos os ID's
            for(int x = 0; x < n; x++)
            {
                funcs_cads[x].id = x;
            }
        }
    }
    //print simples pro caso do nome não existir
    if(aux == 0)
    {        
        printf("Funcionario nao encontrado!\n");
        getch();
    }
}

//Função para listar os funcionarios(ordem padrão)
void listar()
{
    system("cls");
    //Sistema básico de prints
    printf("Cadastros:\n");
    printf("----------------------------------------------\n");
    for(int i = 0; i < n; i++){
        printf("Nome:       %s\n", funcs_cads[i].nome);
        printf("Idade:      %d\n", funcs_cads[i].idade);
        printf("Horas Trab: %d\n", funcs_cads[i].hrs_trb);
        printf("Id:         %d\n", funcs_cads[i].id);
        printf("----------------------------------------------\n");
    }
    getch();
}

//Função para cadastro de um novo funcionario
void cadastrar()
{
    //Antibug, para o caso de a DB estar cheia
    if(n == 21)
    {
        printf("Voce ja atingiu o numero maximo de cadstros!\n");
        getch();
    }
    //Sistema de coleta de dados
    else
    {
        do{
            system("cls");
            fflush(stdin);
            printf("Nome: ");
            gets(&funcs_cads[n].nome);
            printf("Idade: ");
            scanf("%d", &funcs_cads[n].idade);
            printf("Horas trabalhadas: ");
            scanf("%d", &funcs_cads[n].hrs_trb);
            funcs_cads[n].id = n;//Recebo o ID
            n++;//Incremento o ID maximo

            //Sistema de loop
            printf("Deseja cadastrar outro(s/n)?\n");

        }while(getche() == 's');
    }

}

//Funcão para a exibição de um MENU
void menu()
{
    int opcao;
    //Sistema basico de Menu usando While
    do{
        system("cls");
        printf("---------Menu---------\n");
        printf("1 - Cadastrar\n");
        printf("2 - Listar\n");
        printf("3 - Listar ordem alfabetica\n");
        printf("4 - Listar ordem horario\n");
        printf("5 - Editar cadastro\n");
        printf("6 - Apagar cadastro\n");
        printf("7 - Salvar alteracoes\n");
        printf("0 - Sair\n");
        printf("Selecione uma opcao: ");
        scanf("%d", &opcao);
        switch(opcao)
        {
        case 1:
        //Chamo a função de cadastrar
        cadastrar();
        break;
        case 2:
        //Chamo a listagem (padrão)
        listar();
        break;
        case 3:
        //Chamo a listagem em ordem alfabetica
        list_ordemAlf();
        break;
        case 4:
        //Chamo a listagem em ordem de horario
        list_ordemHrs();
        break;
        case 5:
        //Chamo a função de editar um cadastro
        editar_cadastro();
        break;
        case 6:
        //chamo a função de apagar um cadastro
        apagar();
        break;
        case 7:
        //Chamo a função para salvar as alterações
        salvar();
        break;
        //Fecho o programa
        case 0:
        system("cls");
        printf("Obrigado por usar meu programa!\n");
        printf("Coded by: Guilherme Felipe Pereira\n\n");
        system("pause");
        break;
        }
    }while(opcao != 0);
    system("cls");
    //Pergunto ao final se o usuario deseja salvar
    printf("Deseja salvar as alteracoes(s/n)?");

    //Condição simples
    if(getche() == 's')
    {
        system("cls");
        //chamo a função salvar
        salvar();
    }
}

//Função para Salvar no .txt
void salvar()
{
    //Abertura do arquivo
    FILE* arquivo_b;//Em binario
    //Reescrevo todo o arquivo
    arquivo_b = fopen("db.txt", "wb");

    //Teste simples
    if(arquivo_b == NULL)
    {
        printf("Erro ao abrir o arquivo!\n");
    }
    else
    {
        //Escrevo todos os dados em binário
        for(int i = 0; i < n; i++)
        {
            fwrite(&funcs_cads[i], sizeof(DB), 1, arquivo_b);
        }
        printf("Suas alteracoes foram salvas com sucesso!\n");
    }
    getch();

    fclose(arquivo_b);
}

//Função de Ler o arquivo
void ler()
{
    DB cad;//DB auxiliar
    //Abro o arquivo
    FILE* arquivo;
    //Leio o arquivo em binario
    arquivo = fopen("db.txt", "rb");

    //Salvo o conteúdo no meu vetor de Struct
    if(arquivo != NULL)
    {
        while(fread(&cad, sizeof(DB), 1, arquivo) == 1)
        {
            funcs_cads[n] = cad;
            n++;//Incremento no ID max
        }
    }    
    fclose(arquivo);

}

//Main
int main()
{
    //Chamo a função para ler todo o .txt antes de executar o menu
    ler();
    menu();
}

/*Professor, optei por manipular o TXT usando vetores de struct,
pois achei uma boa solução e completamente viável, estava com
algumas dificuldades na manipulação direta do TXT, então, 
resolvi dessa maneira.*/