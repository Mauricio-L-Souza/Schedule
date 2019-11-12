#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"
#include "app.h"

void create(FIELDS _contacts[], int *index)
{
    char name[21] = "", land_line[12] = "", phone_number[12] = "", *text = "\n|\tCRIANDO CONTATOS";

    showTypedValues(_contacts[*index], text);

    getName(_contacts[*index].name);

    showTypedValues(_contacts[*index], text);

    _contacts[*index].birth_date = inputDate();

    showTypedValues(_contacts[*index], text);

    getLandLine(_contacts[*index].land_line);

    showTypedValues(_contacts[*index], text);

    getPhone(_contacts[*index].phone_number);

    showTypedValues(_contacts[*index], text);

    _contacts[*index].situation = 0;
    _contacts[*index].index = *index;

    *index = *index + 1;

    wait("\n\nContato criado com sucesso!\n");
}

void update(FIELDS _contacts[], int *index)
{
    char *text = "\n\tATUALIZANDO CONTATOS";

    FIELDS _searchedData[SIZE_SEARCH] = {};

    int length = -1, selected, op;

    searchData(_contacts, *index, _searchedData, 0, &length);

    if(length == -1) return;

    if(length == 0){
        wait("Nenhum registro encontrado!");
        return;
    }

    listALL(_searchedData, length, 0);

    getIntValue("\nDigite o índice desejado para prosseguir ou -1 para cancelar: ", &selected);

    if(selected == -1) return;

    system("cls || clear");

    showTypedValues(_contacts[selected], text);
    getIntValue("\n\n1 - editar nome\n2 - Editar aniversário\n3 - Editar Telefone fixo\n3 - Editar celular\nDigite a opção desejada\n>> ", &op);

    if(op == 1){
        getName(_contacts[selected].name);
        showTypedValues(_contacts[selected], text);
    }

    if(op == 2){
        _contacts[selected].birth_date = inputDate();
        showTypedValues(_contacts[selected], text);
    }

    if(op == 3){
        showTypedValues(_contacts[selected], text);
        getLandLine(_contacts[selected].land_line);
    }

    if(op == 4){
        showTypedValues(_contacts[selected], text);
        getPhone(_contacts[selected].phone_number);
    }

    wait("Contato atualizado com sucesso!");
}

void _remove(FIELDS _contacts[], int *index)
{
    system("cls || clear || reset");
	FIELDS _records[SIZE_SEARCH];
	int selected = 0, lastItem = -1;

    searchData(_contacts, *index, _records, 0, &lastItem);

    if (lastItem == -1) return;

    if (lastItem == 0) {
        wait("\nNenhum registro encontrado\n");
        return;
    }

    listALL(_records, lastItem, 0);

    getIntValue("\nDigite o índice desejado para prosseguir ou -1 para cancelar: ", &selected);

    if(selected == -1) return;

    _records[selected].situation = 1;
    _contacts[_records[selected].index] = _records[selected];

    wait("\n O contato foi deletado com sucesso!");
}

void _search(FIELDS _records[], int index)
{
    FIELDS _searched[SIZE_SEARCH];
    int last_index = -1;

    searchData(_records, index, _searched, 0, &last_index);

    if(last_index == -1) return;

    if(last_index == 0) {
        wait("\nO que você procura não foi encontrado!");
        return;
    }

    listALL(_searched, last_index, 1);
}

void ascendingOrder(FIELDS _contacts[], int index)
{
    int i, j, aux_pos;
	FIELDS aux;
	for (i = 0; i < index; i++) {
        aux_pos = i;
		for (j = i + 1; j < index; j++) {
			if (strcmpi(_contacts[i].name, _contacts[j].name) >= 0) {
				aux = _contacts[i];
				_contacts[i] = _contacts[j];
				_contacts[j] = aux;
			}
			aux_pos++;
		}
	}
}

void birthdayList(FIELDS _contacts[], int index)
{
    int i = 0, j, aux_pos;

	FIELDS aux;

	while (i < index) {
	    aux_pos = i;
		for (j = i + 1; j < index; j++) {
			if (atoi(_contacts[aux_pos].birth_date.m) > atoi(_contacts[j].birth_date.m)) {
				aux = _contacts[aux_pos];
				_contacts[aux_pos] = _contacts[j];
				_contacts[j] = aux;
			}
			aux_pos++;
		}
		i++;
	}
}

//ARQUIVOS
void close(FIELDS _records[], int index)
{
    FILE *_file = fopen("_contacts.txtx", "wb");

    if(!_file) {
        printf("o arquivo não foi encontrado!\n");
        exit(1);
    }

    fwrite(_records, sizeof(FIELDS), index, _file);
    fclose(_file);
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

void getName(char *name)
{
    char _name[21] = "";

    getStringValue("Nome: ", _name);

    str_to_upper(_name, _name);
    strcpy(name, _name);
}

void getPhone(char *phone)
{
    char phone_number[12] = "";
    do{
        getStringValue("Celular: ", phone_number);

        if(validatePhoneNumber(2, phone_number)){
            strcpy(phone, phone_number);
            break;
        }
        wait("\nO campo telefone fixo deve conter 10 digitos ex.: 9999999999.\nSendo os dois primeiros ddd e os seguites o numero de telefone!\n");
    }while(1);
}

void getLandLine(char *landLine)
{
    char land_line[12] = "";
    do{
        getStringValue("Telefone fixo: ", land_line);

        if(validatePhoneNumber(1, land_line)){
            strcpy(landLine, land_line);
            break;
        }
        wait("\nO campo telefone fixo deve conter 10 digitos ex.: 9999999999.\nSendo os dois primeiros ddd e os seguites o numero de telefone!\n");
    }while(1);
}

