#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

#include "configs.h"

//FUNCTIONS
void birthdayList(FIELDS _contacts[], int index);
void ascendingOrder(FIELDS _contacts[], int index);
void create(FIELDS _fields[], int *index);
void update(FIELDS _fields[], int *index);
void _remove(FIELDS _fields[], int *index);

void close(FIELDS _records[], int index);
void open(FIELDS _records[], int *index);

//END FUNCTIONS

#endif // APP_H_INCLUDED
