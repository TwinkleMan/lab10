#include "dataRead.h"
#include "list.h"
#include <stdlib.h>
#include <string.h>

char **getData(FILE *source)
{
    char **arrData = NULL;
    char *input = NULL;
    int i,shift,count,len,errorCount,trigger = 0;

    strRead(source,&input);
    len = strlen(input);
    for (i = 0,count = 0;i < len;i++) {
        if (input[i] == split) {
            count++;
        }
    }

    arrData = (char**)malloc(sizeof(char*) * (count + 1));
    if (arrData != NULL) {
        for (i = 0,errorCount = 0;i <= count;i++,errorCount++) {
            arrData[i] = (char*)malloc(sizeof(char) * len);
            if (arrData[i] != NULL) trigger = 1;
            else {
                trigger = 0;
                i = count;
            }
        }
        if (trigger) {
            count = 0;
            shift = 0;
            for (i = 0;i < len;i++) {
                if (input[i] != split) {
                    arrData[count][i - shift] = input[i];
                } else {
                    arrData[count][i - shift] = '\0';
                    count++;
                    shift = i + 1;
                }
            }
            arrData[count][i - shift] = '\0';
        } else {
            clearStrArray(arrData,errorCount);
        }
    }

    free(input);
    input = NULL;
    return arrData;
}

void clearStrArray(char **arr,int count)
{
    int i;

    for (i = 0;i < count;i++) {
        free(arr[i]);
        arr[i] = NULL;
    }
    free(arr);
    arr = NULL;
}

void strRead(FILE *df, char **dest)
{
    char symbol = '\0';
    int length = 0, multiplier = 1,errCount = 0;

    (*dest) = (char *)malloc(sizeof(char) * (readStep + 1));
    while (symbol != '\n') {
        symbol = fgetc(df);
        if (symbol >= 32) {
            if ((length % readStep == 0) && (length != 0)) {
                multiplier++;
                (*dest) = (char *) realloc((*dest), sizeof(char) * (readStep * multiplier + 1));
                if ((*dest) == NULL) {
                    perror("Ooops, looks like there's an error with memory reassignment...");
                    exit(1);
                }
            }
            (*dest)[length] = symbol;
            length++;
        } else errCount++;
    }
    (*dest)[length] = '\0';
}

char *getInput()
{
    char *name = NULL;

    name = (char*)malloc(sizeof(char) * maxlen);
    puts("Enter filename:");
    fgets(name,(maxlen - referenceBuff),stdin);
    name[strlen(name) - 1] = '\0';
    if (strcmp(name,"standard") == 0) {
        name = "stdin";
    } else {
        strcat(name, ".csv");
    }
    return name;
}

int lenCount(FILE *filename)
{
    int i = 0;
    char symbol = '\0';

    while (symbol != EOF) {
        symbol = fgetc(filename);
        if (symbol == '\n') {
            i++;
        }
    }
    fseek(filename,0,SEEK_SET);
    return i;
}
