#include <stdlib.h>
#include <stdio.h>

#include "list.h"
#include "trash.h"

int main_menu(){
    int op = 0;
    do{
        op = 0;
        system("cls || clear");

        printf("==================================================================\n");
        printf("\n AGENDA \n");
        printf("\n1 - Incluir\n2 - Alterar\n3 - Excluir\n4 - Buscas\n");
        printf("5 - Acessar menu de listagem\n");
        printf("6 - Acssar lixeira\n");
        printf("7 - Sair\n");
        printf("\n==================================================================\n");

        getIntValue("\nDigite a opção desejada:\n>> ", &op);

        if(op>=1 && op <= 7) break;
        else{
            wait("A operação escolhida não existe!");
            fflush(stdin);
            continue;
        }

    }while(1);

    return op;
}

void list_menu (FIELDS _records[], int length)
{
    int op;
    do{
        op = 0;
        system("cls || clear");

        printf("==================================================================\n");
        printf("\n LISTAGEM \n");
        printf("\n1 - Listar por ordem alfabetica.\n");
        printf("2 - Listar por aniversariante do mês\n");
        printf("3 - Listar todos");
        printf("4 - Voltar ao menu principal\n");
        printf("\n==================================================================\n");

        getIntValue("\nDigite a opção desejada:\n>> ", &op);

        switch(op){
            case 1:
                wait("");
                break;
            default:
                wait("\nA operação escolhida não existe!");
                fflush(stdin);
                break;
        }

        if(op!=5){
            continue;
        }
    }while(op != 5);
}

void trash_menu(FIELDS _records[], int *length)
{
    int op;
    do{
        op = 0;
        system("cls || clear");

        printf("==================================================================\n");
        printf("\n LIXEIRA \n");
        printf("\n1 - Listar items da lixeira.\n");
        printf("2 - Restaurar um item da lixeira\n");
        printf("3 - Restaurar todos os itens da lixeira\n");
        printf("4 - Deletar um item da lixeira\n");
        printf("5 - Esvaziar lixeira\n");
        printf("6 - Voltar ao menu principal\n");
        printf("\n==================================================================\n");

        getIntValue("\nDigite a opção desejada:\n>> ", &op);
        fflush(stdin);

        switch(op){
            case 1:
                listContactsInTrash(_records, *length);
                break;
            case 2:
                restoreOne(_records, *length);
                break;
            case 3:
                restoreAll(_records, *length);
                break;
            case 4:
                printf("%d\n", op);
                deleteOne(_records, length);
                break;
            case 5:
                deleteALL(_records, length);
                break;
            case 6:
                break;
            default:
                wait("\nA operação escolhida não existe!");
                fflush(stdin);
                break;
        }

        if(op >= 1 && op < 6) continue;

    }while(op!=6);
}
