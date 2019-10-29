#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "application/app.h"
#include "application/helpers.h"
#include "application/menus.h"


//GLOBALS
int index = 0;
FIELDS _contacts[10];
//END GLOBALS

int main()
{
    open(_contacts, &index);
    FIELDS _records[SIZE_SEARCH];

    int i, op, last_index;
    setlocale(LC_ALL, "Portuguese");
    op = 0;

    //DATA FOR TESTS
    strcpy(_contacts[0].name, "Mauricio");
    strcpy(_contacts[0].land_line, "32220000");

    strcpy(_contacts[0].phone_number, "32220000");

    _contacts[0].situation = 0;
    _contacts[0].index = 0;

    strcpy(_contacts[1].name, "Mauro");
    strcpy(_contacts[1].land_line, "32220000");

    strcpy(_contacts[1].phone_number, "32220000");

    _contacts[1].situation = 0;
    _contacts[1].index = 1;

    strcpy(_contacts[2].name, "Maria");
    strcpy(_contacts[2].land_line, "32220000");

    strcpy(_contacts[2].phone_number, "32220000");

    _contacts[2].situation = 1;
    _contacts[2].index = 2;

    index = 3;
    //END DATA FOR TESTS

    while(op != 7){
        switch(main_menu()){
            case 1:
                create(_contacts, &index);
                break;
            case 2:
                update(_contacts, &index);
                break;
            case 3:
                _remove(_contacts, &index);
                break;
            case 4:
                searchData(_contacts, &index, _records, 0, &last_index);
                listALL(_records, last_index);
                break;
            case 5:

                break;
            case 6:

                break;
            case 7:
                op = 7;
                break;
        }
    }


    /*for(i = 0; i < index; i++){
        printf("\n==================================================\n");
        printf("\nNome: %s\n", _contacts[i].name);
        printf("Data de nascimento: %s/%s/%s\n", _contacts[i].birth_date.d, _contacts[i].birth_date.m, _contacts[i].birth_date.y);
        printf("Telefone fixo: %s\n", _contacts[i].land_line);
        printf("Celular: %s\n", _contacts[i].phone_number);

        if(_contacts[i].situation == 1){
            printf("Situação: Na lixeira\n");
        }else{
            printf("Situação: Ativo\n");
        }
        printf("\n==================================================\n");
    }*/

    return 0;
}


