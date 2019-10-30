#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "app.h"
#include "helpers.h"


void create(FIELDS _contacts[], int *index){
    char name[21] = "", land_line[12] = "", phone_number[12] = "";

    getStringValue("Nome: ", name);
    str_to_upper(name, name);
    strcpy(_contacts[*index].name, name);

    _contacts[*index].birth_date = inputDate();

    getStringValue("Telefone fixo: ", land_line);
    strcpy(_contacts[*index].land_line, land_line);

    getStringValue("Celular: ", phone_number);
    strcpy(_contacts[*index].phone_number, phone_number);

    _contacts[*index].situation = 0;
    _contacts[*index].index = *index;

    *index = *index + 1;
}

void update(FIELDS _contacts[], int *index)
{

}

void _remove(FIELDS _contacts[], int *index)
{
	FIELDS _records[SIZE_SEARCH];
	int selected = 0, lastItem = 0;

    searchData(_contacts, index, _records, 0, &lastItem);

    if (lastItem > 0) {
        listALL(_records, lastItem);

        printf("Escolha um deles para prosseguir: ");
        scanf("%d", &selected);


        _records[selected].situation = 1;//
        printf("\nSTEP 2\n");//
        _contacts[_records[selected].index] = _records[selected];//
    }else{
        printf("Nenhum registro encontrado\n");
        system("pause");
    }
}



void searchData(FIELDS _records[], int *index, FIELDS _searchedData[], int option, int *lastItem)
{
    char str4search [21] = "";

    printf("Digite o nome que deseja procurar: ");
    scanf("%s", &str4search);

    str_to_upper(str4search, str4search);

    int count = 0, i;
    for(i = 0; i < *index; i++){
        if(str4search[0] != '*'){
            if(strcmpi(_records[i].name, str4search) == 0)
            {
                _searchedData[count] = _records[i];
                count++;
                break;
            }else if(strcasecmp(_records[i].name, str4search) &&
                    (_records[i].name[0] == str4search[0]) &&
                    (count < 10) && (_records[i].situation == option))
            {
                _searchedData[count] = _records[i];
                count++;
            }
        }else if(count < 10){
            _searchedData[count] = _records[i];
            count++;
        }
    }

    *lastItem = count;
}

void close(FIELDS _records[], int *index)
{
    FILE *_file = fopen("_contacts.txtx", "ab+");

    int i;

    for (i = 0; i < *index; i++)
    {
        fwrite(_records, sizeof(FIELDS), 1, _file);
        fseek(_file, sizeof(FIELDS), SEEK_END);
    }

    printf("Dados gravados com sucesso!\n");
    getch();
}

void open(FIELDS _records[], int *index)
{
    FILE *_file = fopen("_contacts.txtx", "ab+");
    int lenght = 0;

    if(_file == NULL){
        printf("Algo errado\n");
        exit(1);
    }

    fseek(_file, -sizeof(FIELDS), SEEK_END);
    lenght = ftell(_file);

    *index = lenght/sizeof(FIELDS) + 1;
    printf("%d\n", *index);
    int i;

    for (i = 0; i < *index; i++)
    {
        fread(_records + i, sizeof(FIELDS), 1, _file);
        fseek(_file, -2*sizeof(FIELDS), SEEK_CUR);
    }
    fclose(_file);
}

void ascendingOrder(FIELDS _contacts[], int *last_position)
{

}

void birthdayList(FIELDS _contacts[], int *index)
{

}

void listALL(FIELDS _records[], int tam)
{
    system("cls || clear");
    int i;
    printf("\t\t\tLISTAGEM DE CONTATOS\n\n");
    for (i = 0; i < tam; i++){
        printf("================================\n");
        printf("Contato %d                      |\n", i+1);
        printf("================================\n");
        printf("\tÍndice: %d\n", _records[i].index);
        printf("\tNome: %s\n", _records[i].name);
        printf("\n================================\n\n");
    }

    system("pause");
}
