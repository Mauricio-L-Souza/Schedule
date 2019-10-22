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
    int i;
    setlocale(LC_ALL, "Portuguese");
    while(1){
        switch(main_menu()){
            case 1:
                insertData(_fields, &index);
                break;
            case 2:
                break;
            case 3:
                removeData(_fields, &index);
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                break;
            case 7:
                break;
        }
    }

    for(i = 0; i < index; i++){
        printf("%s\n", _fields[i].name);
        printf("%s/%s/%s\n", _fields[i].birth_date.d, _fields[i].birth_date.m, _fields[i].birth_date.y);
        printf("%s\n", _fields[i].land_line);
        printf("%s\n", _fields[i].phone_number);
    }

    return 0;
}


