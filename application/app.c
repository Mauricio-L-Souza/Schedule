#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "app.h"
#include "helpers.h"

void Destructor(){

}

void insertData(FIELDS _fields[], int index){// pra registrar os "CONTATOS".
    char name[21] = "", land_line[12] = "", phone_number[12] = "";

    printf("Nome: ");
    scanf("%s", &name);

    strcpy(_fields[index].name, name);//pega o Nome
    printf("Chegou: ");
    _fields[index].birth_date = inputDate();//Pega a data de aniversário

    printf("Telefone fixo: ");
    scanf("%s", &land_line);

    strcpy(_fields[index].land_line, land_line);//pega o telefone fixo

    printf("Celular: ");
    scanf("%s", &phone_number);

    strcpy(_fields[index].phone_number, phone_number);//Pega o celular

    _fields[index].situation = 0;// seta a situação como Presente (de acordo com o professor).
    _fields[index].modified = 0;// eu fiz pra usar quando for salvar o arquivo mas talvez nem seja necessário.


    index++;// incrementa qual será o proximo index pra salvar o proximo "contato".
}

void updateData(FIELDS _fields, int index){}

void removeData(FIELDS _fields, int index)
{
	FIELDS _record  = searchData()[0];//Eu estou retornando um array por isso o [0] pra pegar a primeira posição
	// ou ao menos espero que venha um array

	_record.situation = 1; //seta como removido pra lixeira

	_fields[_record.modified] = _record;// essa é a linha da gambiarra.

	//Testar  agora

}

//Implementação agora !

FIELDS* searchData(FIELDS _fields, int index)//faz a busca pelo nome
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

void close(FIELDS _fields, int index){}

void ascendingOrder(FIELDS _fields, int index){}

void birthdayList(FIELDS _fields, int index){}
