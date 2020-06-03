#ifndef LAB10_LIST_H
#define LAB10_LIST_H
#include <stdio.h>

typedef struct unit {
    char *name;
    char *info;
    int numOfPickups;
    int numOfFrets;
    int numOfString;
    float menzureLength;
    float neckRadius;
    int *stringsWidth;
} guitar;

typedef struct node_unit {
    guitar *guitar;
    struct node_unit *next;
} node;

node *create_node (FILE *source,int *length);   //создание элеменнта списка     @@
void print_list(node **head);   //вывод списка      @@
void add_first(node **head,FILE *source,int *length);   //добавление элемента на место head     @@
void add_last(node **tail,FILE *source,int *length);   //добавление элемента в конец списка     @@
void invert_list(node **head);  //разворот списка       @@
void insert(node **head, int index,FILE *source,int *length);   //добавление в список элемента на указанную позицию     @@
void pop(node **head,int *length);  //удаление первого элемента     @@
void removeNode(node **head,int i,int *length); //удаляет элемент перед элементом с указанным номером   @@
void delete(node **unit);   //удаление node @@
void clearList(node **head,int length);    //очистка памяти, выделенной под список  @@

#endif //LAB10_LIST_H
