#include "helpers.h"

void listALL(FIELDS _records[], int tam)
{
    system("cls || clear");
    int i;
    printf("\t\t\tLISTAGEM DE CONTATOS\n\n");

    for (i = 0; i < tam; i++){
        printf("================================\n");
        printf("Contato %d                      |\n", i+1);
        printf("================================\n");
        printf("\tÍndice: %d\n", _records[i].index);
        printf("\tNome: %s\n", _records[i].name);
        printf("\n================================\n\n");
    }

    wait("");
}

void listOne(FIELDS _record, int i)
{
    printf("\n================================\n");
    printf("Contato %d                      |\n", i+1);
    printf("================================\n");
    printf("\tÍndice: %d\n", _record.index);
    printf("\tNome: %s\n", _record.name);
    printf("\n================================\n\n");
}
