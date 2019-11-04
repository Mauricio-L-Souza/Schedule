#ifndef LIST_H_INCLUDED
#define LIST_H_INCLUDED

#include "configs.h"

void listALL(FIELDS _records[], int tam, int op);
void listOne(FIELDS _record, int i, int op);
void reorderByIndex(FIELDS _records[], int length);

#endif // LIST_H_INCLUDED
