#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"
#include "app.h"

char getStringValue(char *text, char value_to_return[])
{
    printf("%s", text);
    scanf("%s", value_to_return);

    fflush(stdin);
}

DATE inputDate(){

    DATE _date;

    while(1){
        char date_string[15];
        getStringValue("Insira uma data ex.:[01/12/2022]: ", date_string);

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
        }
    }
}

void str_to_upper(char value[], char value_to_return[])
{
    int i;
    char aux = ' ';

    if(strcmp(value, "") == 0) return;

    for(i = 0; i < strlen(value); i++){
        aux = toupper(value[i]);
        value_to_return[i] = aux;
    }
}


