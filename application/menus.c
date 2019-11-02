#include <stdlib.h>
#include <stdio.h>

#include "menus.h"

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

        printf("\ndigite a opção desejada:\n");
        printf(">> ");

        scanf("%d", &op);

        if(op>=1 && op <= 7) break;
        else{
            printf("A operação escolhida não existe!\n");

            system("pause");
            fflush(stdin);
            continue;
        }

    }while(1);

    return op;
}

int list_menu ()
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

        printf("\nDigite a opção desejada:\n");
        printf(">> ");

        scanf("%d", &op);

        if(op>=1 && op <= 4) break;
        else{
            printf("A operação escolhida não existe!\n");

            system("pause");
            fflush(stdin);
            continue;
        }

    }while(1);

    return op;
}

int trash_menu()
{
    int op;
    do{
        op = 0;
        system("cls || clear");

        printf("==================================================================\n");
        printf("\n LIXEIRA \n");
        printf("\n1 - Listar items da lixeira.\n");
        printf("2 - Restaurar um item da lixeira\n");
        printf("3 - Restaurar todos os items da lixeira");
        printf("4 - Esvaziar lixeira");
        printf("5 - Voltar ao menu principal\n");
        printf("\n==================================================================\n");

        printf("\nDigite a opção desejada:\n");
        printf(">> ");

        scanf("%d", &op);

        if(op>=1 && op <= 5) break;
        else{
            printf("\nA operação escolhida não existe!\n");

            system("pause");
            fflush(stdin);
            continue;
        }

    }while(1);

    return op;
}
