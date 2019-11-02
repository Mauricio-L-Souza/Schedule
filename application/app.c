#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

    searchData(_contacts, *index, _records, 0, &lastItem);

    if (lastItem == 0) {
        printf("Nenhum registro encontrado\n");
        system("pause");
        return;
    }

    listALL(_records, lastItem);

    getIntValue("\nEscolha um deles para prosseguir: ", &selected);

    _records[selected].situation = 1;//
    _contacts[_records[selected].index] = _records[selected];//
}

void _search(FIELDS _records[], int index)
{
    FIELDS _searched[SIZE_SEARCH];
    int last_index;

    searchData(_records, index, _searched, 0, &last_index);

    if(last_index == 0) {
        wait("O que voc� procura n�o foi encontrado!");
        return;
    }

    listALL(_records, last_index);
}

void ascendingOrder(FIELDS _contacts[], int length)
{

}

void birthdayList(FIELDS _contacts[], int index)
{

}

//ARQUIVOS
void close(FIELDS _records[], int *index)
{
    FILE *_file = fopen("_contacts.txtx", "wb");

    if(!_file) {
        printf("o arquivo n�o foi encontrado!\n");
        exit(1);
    }

    fwrite(_records, sizeof(FIELDS),*index, _file);
    fclose(_file);

    wait("Dados gravados com sucesso!");
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

    while(!feof(_file))
    {
        if (fread(&_records[n], sizeof(FIELDS), 1, _file) != 1) break;
        n++;
    }

    fclose(_file);
}
