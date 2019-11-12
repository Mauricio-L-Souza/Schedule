#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "application/app.h"
#include "application/menus.h"


//GLOBALS
int _index = 0;
FIELDS _contacts[SIZE_ARR_CONTACTS] = {};
//END GLOBALS

int main()
{
    open(_contacts, &_index);

    int op = 0;
    setlocale(LC_ALL, "Portuguese");

    while(op != 7){
        fflush(stdin);
        switch(main_menu()){
            case 1:
                create(_contacts, &_index);
                close(_contacts, _index);
                break;
            case 2:
                update(_contacts, &_index);
                close(_contacts, _index);
                break;
            case 3:
                _remove(_contacts, &_index);
                close(_contacts, _index);
                break;
            case 4:
                _search(_contacts, _index);
                break;
            case 5:
                list_menu(_contacts, _index);
                fflush(stdin);
                break;
            case 6:
                trash_menu(_contacts, &_index);
                close(_contacts, _index);
                break;
            case 7:
                op = 7;
                fflush(stdin);
                break;
        }
    }
    close(_contacts, _index);

    return 0;
}
