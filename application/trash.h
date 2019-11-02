#ifndef TRASH_H_INCLUDED
#define TRASH_H_INCLUDED

#include "configs.h"

void deleteALL(FIELDS _records[], int *lenght);

void deleteOne(FIELDS _records[], int *lenght);

void restoreAll(FIELDS _records[], int *lenght);

void restoreOne(FIELDS _records[], int *lenght);

#endif // TRASH_H_INCLUDED
