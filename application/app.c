#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"
#include "helpers.h"

void Destructor(){

}

void insertData(FIELDS _fields[], int *index){
    char name[21] = "", land_line[12] = "", phone_number[12] = "";

    printf("Nome: ");
    scanf("%s", &name);

    strcpy(_fields[*index].name, name);

    _fields[*index].birth_date = inputDate();

    printf("Telefone fixo: ");
    scanf("%s", &land_line);

    strcpy(_fields[*index].land_line, land_line);

    printf("Celular: ");
    scanf("%s", &phone_number);

    strcpy(_fields[*index].phone_number, phone_number);

    _fields[*index].situation = 0;
    _fields[*index].modified = 0;

    *index = *index + 1;
}

void updateData(FIELDS _fields[], int *index){}

void removeData(FIELDS _fields[], int *index)
{
	FIELDS _record  = searchData(_fields, index);

	_record.situation = 1;

	_fields[_record.modified] = _record;
}



FIELDS searchData(FIELDS _fields[], int *index)
{
    FIELDS _records;
    int i;
    char str4search [21] = "";
    char *aux;

    printf("Digite o nome que deseja procurar: ");
    scanf("%s", &str4search);

    for(i = 0; i < *index; i++){
        if(strcasecmp(_fields[i].name, str4search)){
            printf("%s", _fields[i].name);
            _records = _fields[i];
            _records.modified = i;
		}
    }
    return _records;
}

void close(FIELDS _fields[], int *index){}

void ascendingOrder(FIELDS _fields[], int *index){}

void birthdayList(FIELDS _fields[], int *index){}
