#ifndef HELPERS_H_INCLUDED
#define HELPERS_H_INCLUDED

#include "helpers.h"
#include "configs.h"

char getStringValue(char *text, char value_to_return[]);

void str_to_upper(char value[], char value_to_return[]);
void reorder_contact_array(FIELDS _records[], int *index, int arr_index[], FIELDS reordered_arr[]);
void map_indexes(FIELDS _records[], int *lenght, int n, int arr_index[]);
void searchData(FIELDS _records[], FIELDS _searchedData[], int option, int *lastItem);
void getSearchedData(FIELDS _records[], FIELDS _searchedData[], int option, int *lastItem, char str4search[]);

DATE inputDate();

#endif // HELPERS_H_INCLUDED
