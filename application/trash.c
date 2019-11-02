#include "helpers.h"
#include "configs.h"

void deleteALL(FIELDS _records[], int *lenght)
{
    FIELDS items_for_delete[SIZE_ARR_CONTACTS];

    int lenght_arr_del = 0;

    getSearchedData(_records, items_for_delete, lenght, 1, lenght_arr_del, "*");

    if(lenght_arr_del == 0){
        printf("A lixeira está vazia!\nAperte qualquer tecla para continuar...");
        getch();
        return ;
    }

    int arr_index[SIZE_ARR_CONTACTS];
    map_indexes(items_for_delete, lenght_arr_del, 0, arr_index);

    reorder_contact_array(_records, lenght, arr_index, _records);

    printf("A lixeira foi esvaziada!\nAperte qualquer tecla para continuar...");
    getch();
}

void deleteOne(FIELDS _records[], int *lenght)
{
    FIELDS items_for_delete[SIZE_SEARCH];

    int lenght_arr_del = 0;
    int arr_index[1];

    searchData(_records, items_for_delete, 1, lenght_arr_del);

    if (lenght_arr_del == 0) {
        printf("Nenhum registro encontrado\n");
        system("pause");
        return ;
    }

    listALL(_records, lenght_arr_del);

    printf("Escolha um deles para prosseguir: ");
    scanf("%d", &arr_index[0]);

    map_indexes(items_for_delete, lenght_arr_del, 0, arr_index);

    reorder_contact_array(_records, lenght, arr_index, _records);

    printf("A lixeira foi esvaziada!\nAperte qualquer tecla para continuar...");
    getch();
}

void restoreAll()
{

}

void restoreOne()
{

}
