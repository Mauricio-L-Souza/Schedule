#include <stdlib.h>
#include "helpers.h"
#include "list.h"

void deleteALL(FIELDS _records[], int *length)
{
    FIELDS items_for_delete[SIZE_ARR_CONTACTS];

    int length_arr_del = 0;

    getSearchedData(_records, *length,items_for_delete, 1, &length_arr_del, "*");

    if(length_arr_del == 0){
        wait("A lixeira está vazia!");
        return ;
    }
    listALL(items_for_delete, length_arr_del);
    wait("\nDados da lixeira no array");

    int arr_index[SIZE_ARR_CONTACTS], n = 0;

    map_indexes(items_for_delete, length_arr_del, &n, arr_index);

    wait("\nitems mapeados");

    reorder_contact_array(_records, length, arr_index, _records);

    wait("A lixeira foi esvaziada!");
}

void deleteOne(FIELDS _records[], int *length)
{
    FIELDS items_for_delete[SIZE_SEARCH];

    int length_arr_del = 0;

    searchData(_records, length,items_for_delete, 1, length_arr_del);

    if (length_arr_del == 0) {
        wait("Nenhum registro encontrado\n");
        return ;
    }

    int arr_index[1], n = 0;

    listALL(_records, length_arr_del);

    getIntValue("Escolha um index para prosseguir: ", &arr_index[0]);

    map_indexes(items_for_delete, length_arr_del, &n, arr_index);

    reorder_contact_array(_records, length, arr_index, _records);

    wait("O item foi deletado com sucesso!");
}

void restoreAll(FIELDS _records[], int *length)
{

}

void restoreOne(FIELDS _records[], int *length)
{

}

void listContactsInTrash(FIELDS _records[], int length)
{
    int i, _empty = 1;
    for(i = 0; i < length; i++){
        if(_records[i].situation == 1){
            listOne(_records[i], i);
            _empty = 0;
        }
    }
    if(_empty){
        wait("\nA lixeira está vazia!");
        return;
    }
    wait(NULL);
}
