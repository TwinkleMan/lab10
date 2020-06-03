#include "menu.h"
#include <stdio.h>

void mainMenu()
{
    puts("Welcome to the linear list lab!\n");
    puts("1 - enter data");
    puts("2 - info");
    puts("0 - exit");
}

void info()
{
    puts("This program reads data from .csv file (or entered manually from keyboard) and creates a linear list from it.\n");
    puts("All the data should be entered in line with split symbols\nEXAMPLE: 'name;info;number;2;5;123;23' (no split symbol at the end of line)\n");
    puts("To delete node you need to enter number of unit (count starts with '1', NOT '0').\n");
    puts("Press ENTER to return...");
}

void startMenu()
{
    puts("1 - enter from file");
    puts("2 - enter from keyboard");
    puts("3 - delete node");
    puts("4 - print list");
    puts("9 - return");
}

void deleteMenu()
{
    puts("1 - classic delete ('pop')");
    puts("2 - task delete (delete unit before node with entered number)");
    puts("8 - return");
}
