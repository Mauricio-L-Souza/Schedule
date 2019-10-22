#ifndef APP_H_INCLUDED
#define APP_H_INCLUDED

typedef struct{
    char d[3], m[3], y[5];
}DATE;// um registro separado para a data!

typedef struct{
    char name[30];
    char land_line[11], phone_number[12];
    char situation;
    int modified;
    DATE birth_date;
}FIELDS;//Essa aqui é um registro, eu coloquei com o typedef Pra criar um tipo novo e eu poder usar lá em baixo!


//FUNCTIONS
void birthdayList(FIELDS _fields[], int *index);// litagem por aniversário
void ascendingOrder(FIELDS _fields[], int *index);//ordem alfabética
void insertData(FIELDS _fields[], int *index);//inserção de dados de cada "Contato";
void updateData(FIELDS _fields[], int *index);
void removeData(FIELDS _fields[], int *index);

void close();

FIELDS* searchData(FIELDS _fields[], int *index);// essa função irá retornar um "Contato ou mais caso encontre! (Mas aindo tô pensando qual a melhor forma de fazer)."
//END FUNCTIONS


//CONSTRUCTOR

#endif // APP_H_INCLUDED
