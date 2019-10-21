#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

typedef struct{
    char d[3], m[3], y[5];
}DATE;// um registro separado para a data!

typedef struct{
    char name[30];
    char land_line[11], phone_number[12];
    char situation;
    int modified;
    DATE birth_date;
}FIELDS;//Essa aqui � um registro, eu coloquei com o typedef Pra criar um tipo novo e eu poder usar l� em baixo!

//FUNCTIONS
void birthdayList();// litagem por anivers�rio
void ascendingOrder();//ordem alfab�tica
void insertData();//inser��o de dados de cada "Contato";
void updateData();
void removeData();
FIELDS* searchData();// essa fun��o ir� retornar um "Contato ou mais caso encontre! (Mas aindo t� pensando qual a melhor forma de fazer)."
void list_menu();
void trash_menu();
void close();

//END FUNCTIONS

//HELPERS FUNCTIONS

char *getStringValue(char *text) // N�o serve pra muita coisa, mas amanh�o vou pedir ajuda pro professor sobre isso.
{									//essa fun��o ir� encurtar a m�ximo pra n�o ficar colocando printf e scanf toda hora
    static char value[50] = "";

    printf("%s", text);
    scanf("%s", &value);

    fflush(stdin);

    return value;
}

DATE inputDate(){

    DATE _date;

    while(1){
        char *date_string = getStringValue("Insira uma data ex.:[01/12/2022]: ");// ela � usada aqui pra pegar a data!
        // pra n� ficar ruim de enviar por whats eu paro aqui e j� fa�o outro!
        char *date_values = "";
        if(strlen(date_string) == 10){
            date_values = strtok(date_string, "/");
        }

        if(strlen(date_values) == 2 && (atoi(date_values)>=1 && atoi(date_values)<=31))
        {
            strcpy(_date.d, date_values);
            date_values = strtok(NULL, "/");

            if(strlen(date_values) == 2 && (atoi(date_values)>=1 && atoi(date_values)<=12)){
                strcpy(_date.m, date_values);

                date_values = strtok(NULL, "/");

                if(strlen(date_values) == 4 && atoi(date_values) != 0){
                    strcpy(_date.y, date_values);

                    return _date;
                }
            }
        }else{
            continue;
        }
    }
}

int compareString(char *str, char *str2compare)
{
    int lenght = strlen(str), i;
    char aux_str[50];

}
//END HELPERS

void main_menu(){
    do{
        system("cls || clear");
        int op = 0;

        printf("==================================================================\n");
        printf("\n AGENDA \n");
        printf("\n1 - Incluir\n2 - Alterar\n3 - Excluir\n4 - Buscas\n");
        printf("5 - Acessar menu de listagem\n");
        printf("6 - Acssar lixeira\n");
        printf("7 - Sair\n");
        printf("\n==================================================================\n");
        printf("\ndigite a op��o desejada:\n");
        printf(">> ");
        scanf("%d", &op);

        switch(op){
            case  1:
                insertData();
                break;

            case  2:
                updateData();
                break;

            case  3:
                removeData();
                break;

            case  4:
                searchData();
                break;

            case  5:
                list_menu();
                break;

            case  6:
                trash_menu();
                break;

            case  7:
                close();
                break;

            default:
                printf("A opera��o escolhida n�o existe!");
        }
        if(op == 7){
            break;
        }
    }while(1);
}


//GLOBALS
int index = 0;
FIELDS _fields[10];
//END GLOBALS

int main()
{
    int i;
    setlocale(LC_ALL, "Portuguese");



    main_menu();

	/*
    for(i = 0; i < index; i++){
        printf("%s\n", _fields[i].name);
        printf("%s/%s/%s\n", _fields[i].birth_date.d, _fields[i].birth_date.m, _fields[i].birth_date.y);
        printf("%s\n", _fields[i].land_line);
        printf("%s\n", _fields[i].phone_number);
    }*/

    return 0;
}

void insertData(){// pra registrar os "CONTATOS".
    char name[21] = "", land_line[12] = "", phone_number[12] = "";

    printf("Nome: ");
    scanf("%s", &name);

    strcpy(_fields[index].name, name);//pega o Nome

    _fields[index].birth_date = inputDate();//Pega a data de anivers�rio

    printf("Telefone fixo: ");
    scanf("%s", &land_line);

    strcpy(_fields[index].land_line, land_line);//pega o telefone fixo

    printf("Celular: ");
    scanf("%s", &phone_number);

    strcpy(_fields[index].phone_number, phone_number);//Pega o celular

    _fields[index].situation = 0;// seta a situa��o como Presente (de acordo com o professor).
    _fields[index].modified = 0;// eu fiz pra usar quando for salvar o arquivo mas talvez nem seja necess�rio.


    index++;// incrementa qual ser� o proximo index pra salvar o proximo "contato".
}

void updateData(){}

void removeData()
{
	FIELDS _record  = searchData()[0];//Eu estou retornando um array por isso o [0] pra pegar a primeira posi��o
	// ou ao menos espero que venha um array

	_record.situation = 1; //seta como removido pra lixeira

	_fields[_record.modified] = _record;// essa � a linha da gambiarra.

	//Testar  agora

}

//Implementa��o agora !

FIELDS* searchData()//faz a busca pelo nome
{
    FIELDS _records[15];
    int i, j = 0 ;
    char str4search [21] = "";
    char *aux;

    printf("Digite o nome que deseja procurar: ");
    scanf("%s", &str4search);

    for(i = 0; i < index; i++){
        if(strcasecmp(_fields[i].name, str4search)){
            printf("%s", _fields[i].name);
            _records[j] = _fields[i];
        	j++;
		}
    }
    return _records;
}

void list_menu ()
{
        do{
        system("cls || clear");
        int op = 0;

        printf("==================================================================\n");
        printf("\n LISTAGEM \n");
        printf("\n1 - Listar por ordem alfabetica.\n");
        printf("2 - Listar por aniversariante do m�s\n");
        printf("3 - Voltar ao menu principal\n");
        printf("\n==================================================================\n");
        printf("\nDigite a op��o desejada:\n");
        printf(">> ");
        scanf("%d", &op);

        switch(op){
            case  1:
                ascendingOrder();
                break;

            case  2:
                birthdayList();
                break;

            case  3:
                break;

            default:
                printf("A opera��o escolhida n�o existe!");
        }
        if(op == 7){
            break;
        }
    }while(1);
}
void trash_menu(){}
void close(){}

void ascendingOrder(){}

void birthdayList(){}
