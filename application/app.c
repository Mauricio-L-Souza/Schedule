#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"

void create(FIELDS _contacts[], int *index)
{
    char name[21] = "", land_line[12] = "", phone_number[12] = "", *text = "\n|\tCRIANDO CONTATOS";

    showTypedValues(_contacts[*index], text);

    getStringValue("\nNome: ", name);
    str_to_upper(name, name);
    strcpy(_contacts[*index].name, name);

    showTypedValues(_contacts[*index], text);
    _contacts[*index].birth_date = inputDate();

    do{
        showTypedValues(_contacts[*index], text);
        getStringValue("Telefone fixo: ", land_line);

        if(validatePhoneNumber(1, land_line)){
            strcpy(_contacts[*index].land_line, land_line);
            break;
        }else{
            wait("O campo telefone fixo deve conter 10 digitos ex.: 9999999999.\nSendo os dois primeiros ddd e os seguites o numero de telefone!\n");
        }
    }while(1);

    do{
        showTypedValues(_contacts[*index], text);
        getStringValue("Celular: ", phone_number);

        if(validatePhoneNumber(2, phone_number)){
            strcpy(_contacts[*index].phone_number, phone_number);
            break;
        }else{
            wait("O campo telefone fixo deve conter 10 digitos ex.: 9999999999.\nSendo os dois primeiros ddd e os seguites o numero de telefone!\n");
        }

    }while(1);

    showTypedValues(_contacts[*index], text);
    wait(NULL);

    _contacts[*index].situation = 0;
    _contacts[*index].index = *index;

    *index = *index + 1;
    wait("\n\nContato criado com sucesso!");
}

void update(FIELDS _contacts[], int *index)
{
    char *text = "\n\tATUALIZANDO CONTATOS";

    FIELDS _searchedData[SIZE_SEARCH] = {};

    int length = 0, selected, op;

    searchData(_contacts, *index, _searchedData, 0, &length);

    if(length == 0){
        wait("Nenhum registro encontrado!");
        return;
    }

    listALL(_searchedData, length, 0);

    getIntValue("\nDigite o �ndice desejado para prosseguir: ", &selected);

    system("cls || clear");

    showTypedValues(_contacts[selected], text);
    getIntValue("\n\n1 - editar nome\n2 - Editar anivers�rio\n3 - Editar Telefone fixo\n3 - Editar celular\nDigite a op��o desejada\n>> ", &op);

    if(op == 1){
        char name[21] = "";

        getStringValue("Nome: ", name);

        str_to_upper(name, name);
        strcpy(_contacts[selected].name, name);
        showTypedValues(_contacts[selected], text);

        wait("\nContato alterado com sucesso!");
    }

    if(op == 2){
        _contacts[selected].birth_date = inputDate();
    }

    if(op == 3){
        char land_line[12] = "";
        do{
            showTypedValues(_contacts[selected], text);
            getStringValue("Telefone fixo: ", land_line);

            if(validatePhoneNumber(1, land_line)){
                strcpy(_contacts[selected].land_line, land_line);
                break;
            }else{
                wait("O campo telefone fixo deve conter 10 digitos ex.: 9999999999.\nSendo os dois primeiros ddd e os seguites o numero de telefone!\n");
            }
        }while(1);
    }

    if(op == 4){
        char phone_number[12] = "";
        do{
            showTypedValues(_contacts[selected], text);
            getStringValue("Celular: ", phone_number);

            if(validatePhoneNumber(2, phone_number)){
                strcpy(_contacts[selected].phone_number, phone_number);
                break;
            }else{
                wait("O campo telefone fixo deve conter 10 digitos ex.: 9999999999.\nSendo os dois primeiros ddd e os seguites o numero de telefone!\n");
            }
        }while(1);
    }
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

    listALL(_records, lastItem, 0);

    getIntValue("\nEscolha um deles para prosseguir: ", &selected);

    _records[selected].situation = 1;
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

    listALL(_searched, last_index, 1);
}

void ascendingOrder(FIELDS _contacts[], int index)
{
    int i, j, k, l;
	FIELDS aux[1];
	for (i = 0; i < index - 1; i++) {
		for (j = index-1; j >0; j--) {
			l = strcmpi(_contacts[i].name, _contacts[j].name);
			if (l >= 0) {
				aux[0] = _contacts[i];
				_contacts[i] = _contacts[j];
				_contacts[j] = aux[0];
			}
		}
	}

	for(i = 0; i< index; i++){
        listOne(_contacts[i], i, 0);
	}
	wait("");
}

void birthdayList(FIELDS _contacts[], int index)
{
    int i, j, k,l, m;
	FIELDS aux;
	for (i = 0; i < index -1; i++) {
		for (j = 1; j < index; j++) {
			l= atoi(_contacts[i].birth_date.m);
			m= atoi(_contacts[j].birth_date.m);
			if (l > m) {
				aux = _contacts[i];
				_contacts[i] = _contacts[j];
				_contacts[j] = aux;
			}

			if (l == m) {

				if (l > m) {
					aux = _contacts[i];
					_contacts[i] = _contacts[j];
					_contacts[j] = aux;
				}
			}
		}
	}

    for(i = 0; i< index; i++){
        printf("anivers�rio: %s/%s/%s\n", _contacts[i].birth_date.d, _contacts[i].birth_date.m, _contacts[i].birth_date.y);
	}
	wait("");
}

//ARQUIVOS
void close(FIELDS _records[], int index)
{
    FILE *_file = fopen("_contacts.txtx", "wb");

    if(!_file) {
        printf("o arquivo n�o foi encontrado!\n");
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
