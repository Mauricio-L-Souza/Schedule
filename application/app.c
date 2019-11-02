#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "helpers.h"
#include "configs.h"


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

    searchData(_contacts, _records, 0, &lastItem);

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

void close(FIELDS _records[], int *index)
{
    FILE *_file = fopen("_contacts.txtx", "wb");

    if(!_file) {
        printf("o arquivo n�o foi encontrado!\n");
        exit(1);
    }

    fwrite(_records, sizeof(FIELDS),*index, _file);
    fclose(_file);

    printf("Dados gravados com sucesso!\nAperte qualquer tecla para continuar...");
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

    fseek(_file, 0, SEEK_END);
    lenght = ftell(_file);

    *index = lenght/sizeof(FIELDS);

    int n = 0;
    fseek(_file, 0, SEEK_SET);
    for (n=0; !feof(_file); ++n)
    {
        if (fread(&_records[n], sizeof(FIELDS), 1, _file) != 1) break;
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
        printf("\t�ndice: %d\n", _records[i].index);
        printf("\tNome: %s\n", _records[i].name);
        printf("\n================================\n\n");
    }

    system("pause");
}
