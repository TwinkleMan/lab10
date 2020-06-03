#include <stdio.h>
#include <stdlib.h>
#include "dataRead.h"
#include "list.h"
#include "menu.h"

int main() {
    char *name = NULL;
    node *head = NULL, *tail = NULL;
    FILE *df = NULL;
    int i,length,deleteNumber,count = 0;
    char flag,trash;
    do {
        system("cls");
        mainMenu();
        flag = getchar();
        getchar();
        i = 0;
        if (flag == '\n') while ((trash = getchar()) != '\n') i++;
        if (i) {
            flag = '`';
        }
        switch (flag) {
            case '1':
                //ввод значений и работа
                do {
                    system("cls");
                    startMenu();
                    flag = getchar();
                    getchar();
                    i = 0;
                    if (flag == '\n') while ((trash = getchar()) != '\n') i++;
                    if (i) {
                        flag = '`';
                    }
                    switch (flag) {
                        case '1':
                            //file inp
                            while (df == NULL) {
                                name = getInput();
                                df = fopen(name, "r");
                                if (df == NULL) {
                                    printf("File %s is not found!\n\n",name);
                                }
                            }
                            puts("File opened successfully!");
                            puts("Press ENTER to continue!");
                            getchar();
                            system("cls");
                            count = lenCount(df);
                            if (count >= 1) {
                                length = 0;
                                add_first(&head,df,&length);
                                tail = head;
                                head->next = tail;
                                for (i = 0;i < (count - 1);i++) {
                                    add_last(&tail,df,&length);
                                }
                                puts("File read successfully!");
                            } else {
                                puts("The file is empty!");
                            }
                            puts("Press ENTER to continue");
                            fseek(df,0,SEEK_SET);
                            getchar();
                            fclose(df);
                            break;
                        case '2':
                            //keyboard inp
                            do {
                                system("cls");
                                puts("Enter dataline with split symbols:");
                                df = stdin;
                                if (count == 0) {   //Если это первый ввод
                                    add_first(&head,df,&length);
                                    tail = head;
                                    head->next = tail;
                                    tail->next = NULL;
                                    count++;
                                } else {
                                    add_last(&tail,df,&length);
                                    count++;
                                }
                                puts("Enter one more line? (1 - Yes/2 - No)");
                                flag = getchar();
                                getchar();
                            } while (flag == '1');
                            break;
                        case '3':
                            //delete node
                            do {
                                system("cls");
                                deleteMenu();
                                flag = getchar();
                                getchar();
                                i = 0;
                                if (flag == '\n') while ((trash = getchar()) != '\n') i++;
                                if (i) {
                                    flag = '`';
                                }
                                switch (flag) {
                                    case '1':
                                        //pop
                                        pop(&head,&length);
                                        puts("\nPress ENTER to return...");
                                        getchar();
                                        break;
                                    case '2':
                                        //task delete
                                        puts("Enter (number of node you want to delete)+1:");
                                        scanf("%d",&deleteNumber);
                                        getchar();
                                        removeNode(&head,deleteNumber,&length);
                                        puts("Press ENTER to return...");
                                        getchar();
                                        break;
                                    case '8':
                                        break;
                                    default:
                                        system("cls");
                                        puts("There's no such paragraph!");
                                        puts("Press ENTER when ready...");
                                        do {
                                            flag = getchar();
                                        } while (flag != '\n');
                                }
                            } while (flag != '8');
                            break;
                        case '4':
                            //print list
                            print_list(&head);
                            puts("Press ENTER to return...");
                            getchar();
                            break;
                        case '9':
                            break;
                        default:
                            system("cls");
                            puts("There's no such paragraph!");
                            puts("Press ENTER when ready...");
                            do {
                                flag = getchar();
                            } while (flag != '\n');
                    }
                } while (flag != '9');
                break;
            case '2':
                //вывод справки
                system("cls");
                info();
                i = 0;
                getchar();
                break;
            case '0':
                //выход из программы
                if (name != NULL) {
                    free(name);
                    name = NULL;
                }
                clearList(&head,length);
                break;
            default:
                system("cls");
                puts("There's no such paragraph!");
                puts("Press ENTER when ready...");
                do {
                    flag = getchar();
                } while (flag != '\n');
        }
    } while (flag != '0');

    return 0;
}
