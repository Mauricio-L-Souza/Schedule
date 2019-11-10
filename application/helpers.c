#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "helpers.h"
#include "configs.h"

void getStringValue(char *text, char value_to_return[])
{
    fflush(stdin);
    printf("%s", text);
    scanf("%s", value_to_return);

    fflush(stdin);
}

void getIntValue(char *text, int *value_to_return)
{
    fflush(stdin);
    printf("%s", text);
    scanf("%d", value_to_return);

    fflush(stdin);
}

void wait(char *text){
    if(text){
        printf("%s\nAperte qualquer tecla para continuar...\n", text);
    }else{
        printf("Aperte qualquer tecla para continuar...\n");
    }
    getch();
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

        for(j = 0; j < lenght_index; j++){

            if(i == arr_index[j]) continue;

            aux[items_count] = _records[i];
            items_count++;
        }
    }

    for(i = 0; i < items_count; i++){
        reordered_arr[i] = aux[i];
    }

    *index = i;
}

void map_indexes(FIELDS _records[], int lenght, int n, int arr_index[])
{
    if(n > lenght - 1) return;
    arr_index[n] = _records[n].index;
    n++;
    map_indexes(_records, lenght, n, arr_index);
}


void searchData(FIELDS _records[], int lenght, FIELDS _searchedData[], int option, int *lastItem)
{
    char str4search [21] = "";

    getStringValue("Digite o nome que deseja procurar ou * para listar todos: ", str4search);

    str_to_upper(str4search, str4search);

    getSearchedData(_records, lenght, _searchedData, option, lastItem, str4search);
}


void getSearchedData(FIELDS _records[], int lenght, FIELDS _searchedData[], int option, int *lastItem, char str4search[])
{
    int count = 0, i;

    for(i = 0; i < lenght; i++)
        if(strcmpi(_records[i].name, str4search) == 0)
        {
            _searchedData[count] = _records[i];
            count++;
            break;
        }
    if(count > 0){
        *lastItem = count;
        return ;
    }

    for(i = 0; i < lenght; i++){
        if(str4search[0] != '*'){
            if(strcasecmp(_records[i].name, str4search) &&
                    (_records[i].name[0] == str4search[0]) &&
                    (count < 10) && (_records[i].situation == option))
            {
                _searchedData[count] = _records[i];
                count++;
            }
        }else if(count < 10){
                if(_records[i].situation != option) continue;
                _searchedData[count] = _records[i];
                count++;
        }
    }

    *lastItem = count;
}

int validatePhoneNumber(int type, char number[])
{
    if(type == 1 && strlen(number) == 10 &&  strtoull(number, NULL, 10) > 0) return 1;
    else if(type == 2 && strlen(number) == 11 &&  strtoull(number, NULL, 10) > 0) return 1;

    return 0;
}

void getBeautifulNumberPhone(int type, char number[], char beautified_number[])
{
    int i = 1, cur_pos = 0;
    if(type == 1){
        beautified_number[0] = '(';
        beautified_number[3] = ')';
        beautified_number[4] = ' ';
        beautified_number[9] = '-';

        while(i < 14){
            if((i > 0 && i < 3) || (i > 4 && i < 9) || (i > 9))
            {
                beautified_number[i] = number[cur_pos];
                cur_pos ++;
            }
            i++;
        }
    }else{
        if(type == 2){
            beautified_number[0] = '(';
            beautified_number[3] = ')';
            beautified_number[4] = ' ';
            beautified_number[6] = ' ';
            beautified_number[11] = '-';

            while(i < 16){
                if((i > 0 && i < 3) || (i == 5) || (i > 6 && i < 11) || (i > 11))
                {
                    beautified_number[i] = number[cur_pos];
                    cur_pos ++;
                }
                i++;
            }
        }
    }
}
