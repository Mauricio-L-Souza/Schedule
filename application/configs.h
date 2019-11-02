#ifndef CONFIGS_H_INCLUDED
#define CONFIGS_H_INCLUDED

#define SIZE_SEARCH 10
#define SIZE_ARR_CONTACTS 100

typedef struct{
    char d[3], m[3], y[5];
}DATE;

typedef struct{
    char name[30];
    char land_line[11], phone_number[12];
    char situation;
    int index;
    DATE birth_date;
}FIELDS;


#endif // CONFIGS_H_INCLUDED
