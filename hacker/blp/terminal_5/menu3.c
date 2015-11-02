/*
 * =====================================================================================
 *
 *       Filename:  menu3.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/21/2015 11:14:50 AM
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


int getchoice(char *greet, char *choices[], FILE *in, FILE *out);

int main(int argc, char *argv[])
{
    int choice = 0;
    FILE *input;
    FILE *output;

    if (!isatty(fileno(stdout))) {
       fprintf(stderr, "you are not a terminal\n");
    }
    
    input = fopen("/dev/tty","r");
    output = fopen("/dev/tty","w");

    if (!input || !output) {
        fprintf(stderr, "unable to open /dev/tty\n");
        exit(1);
    }
   
    do {
        choice = getchoice("please select an actin", menu, input, output);
        printf("you have chosen : %c\n", choice);
    } while(choice != 'q');

    return 0;
}


int getchoice(char *greet, char *choices[], FILE *in, FILE *out)
{
    int chosen = 0;
    int selected;
    char **option;

    do {
        fprintf(out, "choice : %s\n", greet);
        option = choices;
        while (*option) {
            fprintf(out, "%s\n", *option);
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
            fprintf(out, "incorrect choices , selected again\n");
        }
        
    } while(!chosen);

    return selected;
}


