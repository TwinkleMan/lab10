#ifndef LAB10_DATAREAD_H
#define LAB10_DATAREAD_H
#include <stdio.h>

enum values {
    readStep = 15,
    maxlen = 45,
    referenceBuff = 5,
    constFields = 7,
    split = ';',
};

char **getData(FILE *source);    //формирование из строки массива данных для структуры  @@
void strRead(FILE *df, char **dest); //считывает одну строку из файла   @@
void clearStrArray(char **arr,int count);   //очистка массива данных    @@
char *getInput();   //выбор источника ввода     @@
int lenCount(FILE *filename);  //подсчет количества строк в файле   @@

#endif //LAB10_DATAREAD_H
