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
    _fields[*index].index = *index;

    *index = *index + 1;
}

void updateData(FIELDS _fields[], int *index)
{

}

void removeData(FIELDS _fields[], int *index)
{
	FIELDS _records[SIZE_SEARCH];
	int selected = 0, lastItem = 0;

    searchData(_fields, index, _records, 1, &lastItem);

    listALL(_records, lastItem);

    printf("Escolha um deles para prosseguir: ");
    scanf("%d", &selected);

    printf("\nSTEP 1\n");//
    _records[selected].situation = 1;//
    printf("\nSTEP 2\n");//
	_fields[_records[selected].index] = _records[selected];//
}



void searchData(FIELDS _records[], int *index, FIELDS _searchedData[], int option, int *lastItem)
{
    char str4search [21] = "";

    printf("Digite o nome que deseja procurar: ");
    scanf("%s", &str4search);

    switch(option){
        case 1:
            getData(_records, _searchedData, str4search, *index, 0, lastItem);
            break;

        case 2:
            getData(_records, _searchedData, str4search, *index, 1, lastItem);
            break;
    }
}

void close(FIELDS _fields[], int *index){}

void ascendingOrder(FIELDS _fields[], int *index){}

void birthdayList(FIELDS _fields[], int *index){}


void getData(FIELDS _records[], FIELDS _seachedData[], char str4search[], int index, int situation, int *lastItem)
{
    int count = 0, i;
    for(i = 0; i < index; i++){
        if(strcasecmp(_records[i].name, str4search) && count < 10 && _records[i].situation == situation){
            _searchedData[count] = _records[i];
            count++;
		}
    }

    *lastItem = count;
}


void listALL(FIELDS _records[], int tam)
{
    int i;

    for (i = 0; i < tam; i++){
        printf("Índice: \n", _records[i].index);
        printf("Nome: \n", _records[i].name);
    }
}
