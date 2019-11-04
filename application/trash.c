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
    listALL(items_for_delete, length_arr_del, 0);

    int arr_index[SIZE_ARR_CONTACTS], n = 0;

    map_indexes(items_for_delete, length_arr_del, &n, arr_index);

    reorder_contact_array(_records, length, arr_index, _records);

    wait("A lixeira foi esvaziada!");
}

void deleteOne(FIELDS _records[], int *length)
{
    FIELDS items_for_delete[SIZE_SEARCH];

    int length_arr_del = 0;

    searchData(_records, *length,items_for_delete, 1, &length_arr_del);

    if (length_arr_del == 0) {
        wait("Nenhum registro encontrado\n");
        return ;
    }

    int arr_index[1], n = 0;

    listALL(items_for_delete, length_arr_del, 0);

    getIntValue("Escolha um index para prosseguir: ", &arr_index[0]);

    map_indexes(items_for_delete, length_arr_del, &n, arr_index);

    reorder_contact_array(_records, length, arr_index, _records);

    wait("O item foi deletado com sucesso!");
}

void restoreAll(FIELDS _records[], int length)
{
    int i;
    for(i = 0; i < length; i++){
        if(_records[i].situation == 1){
            _records[i].situation = 0;
        }
    }

    wait("\nOs registros foram restaurados com sucesso!");
}

void restoreOne(FIELDS _records[], int length)
{
    FIELDS items_for_restore[SIZE_ARR_CONTACTS];

    int length_arr_res = 0;

    getSearchedData(_records, length,items_for_restore, 1, &length_arr_res, "*");

    if(length_arr_res == 0){
        wait("A lixeira está vazia!");
        return ;
    }

    listALL(items_for_restore, length_arr_res, 1);

    int i;

    getIntValue("Digite o indice do contado para restaura-lo\n>> ", &i);

    _records[i].situation = 0;

    wait("\n O contato foi restaurado com sucesso!");
}

void listContactsInTrash(FIELDS _records[], int length)
{
    int i, _empty = 1, cur_pos = 0;
    for(i = 0; i < length; i++){
        if(_records[i].situation == 1){
            listOne(_records[i], cur_pos, 0);
            _empty = 0;
            cur_pos++;
        }
    }
    if(_empty){
        wait("\nA lixeira está vazia!");
        return;
    }
    wait(NULL);
}
