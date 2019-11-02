#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "application/app.h"
#include "application/menus.h"


//GLOBALS
int index = 0;
FIELDS _contacts[SIZE_ARR_CONTACTS];
//END GLOBALS

int main()
{
    open(_contacts, &index);
    FIELDS _records[SIZE_SEARCH];

    int op, last_index;
    setlocale(LC_ALL, "Portuguese");

    op = 0;


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
                searchData(_contacts, index, _records, 0, &last_index);
                if(last_index == 0) {
                    printf("O que você procura não foi encontrado!\nAperte qualquer tecla para continuar...");
                    getch();
                    break;
                }
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
    close(_contacts, &index);

    return 0;
}


