#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "application/app.h"
#include "application/helpers.h"
#include "application/menus.h"


//GLOBALS
int index = 0;
FIELDS _fields[10];
//END GLOBALS

int main()
{
    int i, op, _last_value = 0;
    FIELDS _records[15];
    setlocale(LC_ALL, "Portuguese");
    op = 0;

    //DATA FOR TESTS
    strcpy(_fields[0].name, "Mauricio");
    strcpy(_fields[0].land_line, "32220000");

    strcpy(_fields[0].phone_number, "32220000");

    _fields[0].situation = 0;
    _fields[0].index = 0;

    strcpy(_fields[1].name, "Mauro");
    strcpy(_fields[1].land_line, "32220000");

    strcpy(_fields[1].phone_number, "32220000");

    _fields[1].situation = 0;
    _fields[1].index = 1;

    strcpy(_fields[2].name, "Maria");
    strcpy(_fields[2].land_line, "32220000");

    strcpy(_fields[2].phone_number, "32220000");

    _fields[2].situation = 1;
    _fields[2].index = 2;

    index = 3;
    //END DATA FOR TESTS

    while(op != 7){
        switch(main_menu()){
            case 1:
                insertData(_fields, &index);
                break;
            case 2:
                updateData(_fields, &index);
                break;
            case 3:
                removeData(_fields, &index);
                break;
            case 4:
                //searchData(_fields, &index);
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


    for(i = 0; i < index; i++){
        printf("\n==================================================\n");
        printf("\nNome: %s\n", _fields[i].name);
        printf("Data de nascimento: %s/%s/%s\n", _fields[i].birth_date.d, _fields[i].birth_date.m, _fields[i].birth_date.y);
        printf("Telefone fixo: %s\n", _fields[i].land_line);
        printf("Celular: %s\n", _fields[i].phone_number);

        if(_fields[i].situation == 1){
            printf("Situa��o: Na lixeira\n");
        }else{
            printf("Situa��o: Ativo\n");
        }
        printf("\n==================================================\n");
    }

    return 0;
}


