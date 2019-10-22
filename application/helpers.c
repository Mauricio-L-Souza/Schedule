#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"
#include "app.h"

char *getStringValue(char *text) // Não serve pra muita coisa, mas amanhão vou pedir ajuda pro professor sobre isso.
{									//essa função irá encurtar a máximo pra não ficar colocando printf e scanf toda hora
    static char value[50] = "";

    printf("%s", text);
    scanf("%s", &value);

    fflush(stdin);

    return value;
}

DATE inputDate(){

    DATE _date;

    while(1){
        char *date_string = getStringValue("Insira uma data ex.:[01/12/2022]: ");// ela é usada aqui pra pegar a data!

        char *date_values = "";
        if(strlen(date_string) == 10){
            date_values = strtok(date_string, "/");
        }

        if(strlen(date_values) == 2 && (atoi(date_values)>=1 && atoi(date_values)<=31))
        {
            strcpy(_date.d, date_values);
            date_values = strtok(NULL, "/");

            if(strlen(date_values) == 2 && (atoi(date_values)>=1 && atoi(date_values)<=12)){
                strcpy(_date.m, date_values);

                date_values = strtok(NULL, "/");

                if(strlen(date_values) == 4 && atoi(date_values) != 0){
                    strcpy(_date.y, date_values);

                    return _date;
                }
            }
        }else{
            continue;
        }
    }
}

int compareString(char *str, char *str2compare)
{
    int lenght = strlen(str), i;
    char aux_str[50];

}
