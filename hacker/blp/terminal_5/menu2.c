/*
 * =====================================================================================
 *
 *       Filename:  menu1.c
 *
 *    Description:  menu process 1
 *
 *        Version:  1.0
 *        Created:  08/20/2015 03:36:33 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Alan Lee (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char *menu[] = {
    "a --- add new recor",
    "d --- delete record",
    "q --- quit",
    NULL,
};

int getchoice(char *greet,char *choices[]);

int main(int argc, char *argv[])
{
    int choice = 0;

    if (!isatty(fileno(stdout))) {
        fprintf(stderr, "you are not a terminal\n");
        return 1;
    }

    do {
        choice = getchoice("please select an action", menu);
        printf("You have chosen : %c\n", choice);
    } while(choice != 'q');

    return 0;
}


int getchoice(char *greet, char *choices[])
{
    int chosen = 0;
    int selected;
    char **option;

    do {
        printf("choice : %s\n", greet);
        option = choices;
        while (*option) {
            printf("%s\n", *option);
            option++;
        }

        do {
            selected = getchar();
        } while(selected == '\n');

        option = choices;
        while (*option) {
            if (selected == *option[0]) {
                chosen = 1;
                break;
            }
            option++;
        }
        if (!chosen) {
            printf("Incorrect choice , select again\n");
        }
    } while(!chosen);

    return selected;
}














































