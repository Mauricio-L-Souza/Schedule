#include "helpers.h"

void listALL(FIELDS _records[], int tam, int op)
{
    system("cls || clear");
    int i;
    printf("\t\t\tLISTAGEM DE CONTATOS\n\n");

    for (i = 0; i < tam; i++){
        listOne(_records[i], i, op);
    }

    wait("");
}

void listOne(FIELDS _record, int i, int op)
{
    char landLine[15] = "";
    getBeautifulNumberPhone(1, _record.land_line, landLine);

    char phoneNumber[17] = "";
    getBeautifulNumberPhone(2, _record.phone_number, phoneNumber);

    printf("\n================================\n");
    printf("Contato %d                      |\n", i+1);
    printf("================================\n");

    if(op) printf("Índice: %d\n", _record.index);
    else printf("Índice: %d\n", i);

    printf("Nome: %s\n", _record.name);
    printf("Data de aniversário: %s/%s/%s\n", _record.birth_date.d, _record.birth_date.m, _record.birth_date.y);
    printf("Telefone fixo: %s\n", landLine);
    printf("Celular: %s\n", phoneNumber);

    printf("\n================================\n\n");
}


void showTypedValues(FIELDS _record, char *text)
{
    system("cls || clear");
    printf("\n================================\n");
    printf("%s      |\n", text);
    printf("\n================================\n");

    if(strcmp(_record.name, "") == 0) return;
    printf("\nNome: %s\n", _record.name);

    if(strcmp(_record.birth_date.d, "") == 0) return;
    printf("Data de aniversário: %s/%s/%s\n", _record.birth_date.d, _record.birth_date.m, _record.birth_date.y);

    if(strcmp(_record.land_line, "") == 0) return;
    char landLine[15] = "";
    getBeautifulNumberPhone(1, _record.land_line, landLine);
    printf("Telefone fixo: %s\n", landLine);

    if(strcmp(_record.phone_number, "") == 0) return;
    char phoneNumber[17] = "";
    getBeautifulNumberPhone(2, _record.phone_number, phoneNumber);
    printf("Celular: %s\n", phoneNumber);
}
