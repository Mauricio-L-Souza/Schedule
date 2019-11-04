#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>

#include "application/app.h"
#include "application/menus.h"


//GLOBALS
int index = 0;
FIELDS _contacts[SIZE_ARR_CONTACTS] = {};
//END GLOBALS

int main()
{
    open(_contacts, &index);

    int op = 0;
    setlocale(LC_ALL, "Portuguese");

    while(op != 7){
        fflush(stdin);
        switch(main_menu()){
            case 1:
                create(_contacts, &index);
                break;
            case 2:
                update(_contacts, &index);
                close(_contacts, index);
                break;
            case 3:
                _remove(_contacts, &index);
                close(_contacts, index);
                break;
            case 4:
                _search(_contacts, index);
                break;
            case 5:
                ascendingOrder(_contacts,index);
                fflush(stdin);
                break;
            case 6:
                trash_menu(_contacts, &index);
                close(_contacts, index);
                break;
            case 7:
                op = 7;
                fflush(stdin);
                break;
        }
    }
    close(_contacts, index);

    return 0;
}
