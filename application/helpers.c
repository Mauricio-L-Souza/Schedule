#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"
#include "configs.h"

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

void reorder_contact_array(FIELDS _records[], int *index, int arr_index[], FIELDS reordered_arr[])
{
    int lenght_index = sizeof(arr_index) / sizeof(int);
    int i, j, items_count = 0;

    FIELDS aux[SIZE_ARR_CONTACTS];

    for(i = 0; i < *index; i++){
        for(j = 0; j <= lenght_index; j++){
            if(i == arr_index[j]) continue;
            aux[items_count] = _records[i];
            items_count++;
        }
    }

    for(i = 0; i < items_count + 1; i++){
        reordered_arr[i] = aux[i];
    }
}

void map_indexes(FIELDS _records[], int *lenght, int n, int arr_index[])
{
    if(n >= *lenght) return;
    arr_index[n] = _records[n].index;
    n++;
    map_indexes(_records, lenght, n, arr_index);
}


void searchData(FIELDS _records[], FIELDS _searchedData[], int option, int *lastItem)
{
    char str4search [21] = "";

    printf("Digite o nome que deseja procurar: ");
    scanf("%s", &str4search);

    str_to_upper(str4search, str4search);

    getSearchedData(_records, _searchedData, option, lastItem, str4search);
}


void getSearchedData(FIELDS _records[], FIELDS _searchedData[], int option, int *lastItem, char str4search[])
{
    int count = 0, i, lenght;

    lenght = sizeof(_records)/sizeof(FIELDS);

    for(i = 0; i <= lenght; i++){
        if(str4search[0] != '*'){
            if(strcmpi(_records[i].name, str4search) == 0)
            {
                _searchedData[count] = _records[i];
                count++;
                break;
            }else if(strcasecmp(_records[i].name, str4search) &&
                    (_records[i].name[0] == str4search[0]) &&
                    (count < 10) && (_records[i].situation == option))
            {
                _searchedData[count] = _records[i];
                count++;
            }
        }else if(count < 10){
            _searchedData[count] = _records[i];
            count++;
        }
    }

    *lastItem = count;
}
