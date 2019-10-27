#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED
# define SIZE_SEARCH 10
typedef struct{
    char d[3], m[3], y[5];
}DATE;// um registro separado para a data!

typedef struct{
    char name[30];
    char land_line[11], phone_number[12];
    char situation;
    int index;
    DATE birth_date;
}FIELDS;//Essa aqui � um registro, eu coloquei com o typedef Pra criar um tipo novo e eu poder usar l� em baixo!


//FUNCTIONS
void birthdayList(FIELDS _fields[], int *index);// litagem por anivers�rio
void ascendingOrder(FIELDS _fields[], int *last_position);//ordem alfab�tica
void insertData(FIELDS _fields[], int *index);//inser��o de dados de cada "Contato";
void updateData(FIELDS _fields[], int *index);
void removeData(FIELDS _fields[], int *index);

void close();

void searchData(FIELDS _records[], int *index, FIELDS _searchedData[], int option, int *lastItem);// essa fun��o ir� retornar um "Contato" ou mais caso encontre! (Mas aindo t� pensando qual a melhor forma de fazer).
//END FUNCTIONS

#endif // APP_H_INCLUDED
