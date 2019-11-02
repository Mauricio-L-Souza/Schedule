#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

#include "configs.h"

int main_menu();
void list_menu(FIELDS _records[], int length);
void trash_menu(FIELDS _records[], int *length);

#endif // MENUS_H_INCLUDED
