#ifndef TRASH_H_INCLUDED
#define TRASH_H_INCLUDED

#include "configs.h"

void deleteALL(FIELDS _records[], int *lenght);

void deleteOne(FIELDS _records[], int *lenght);

void restoreAll(FIELDS _records[], int length);

void restoreOne(FIELDS _records[], int length);

void listContactsInTrash(FIELDS _records[], int length);

#endif // TRASH_H_INCLUDED
