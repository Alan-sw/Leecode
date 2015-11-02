/*
 * =====================================================================================
 *
 *       Filename:  menu4.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/24/2015 03:45:53 PM
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
#include<unistd.h>
#include<termios.h>

char *menu[] = {
    "a --- add new recor",
    "d --- delete record",
    "q --- quit",
    NULL,
};


int getchoice(char *greet, char *choices[], FILE *in, FILE *out);


int main()
{
    int choice = 0;
    FILE *input;
    FILE *output;

    struct termios initial_settings, new_settings;

    if (!isatty(fileno(stdout))) {
       fprintf(stderr, "you are not a terminal\n");
    }
    
    input = fopen("/dev/tty","r");
    output = fopen("/dev/tty","w");

    if (!input || !output) {
        fprintf(stderr, "unable to open /dev/tty\n");
        exit(1);
    }
    
    tcgetattr(fileno(input), &initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~ICANON;
    new_settings.c_lflag &= ~ECHO;
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    new_settings.c_lflag &= ~ISIG;

    if (tcsetattr(fileno(input), TCSANOW, &new_settings) != 0) {
        fprintf(stderr, "counld not set attributes\n");
    }

    do {
        choice = getchoice("please select an action", menu, input, output);
        printf("you have chosen : %c\n", choice);
    } while(choice != 'q');
    tcsetattr(fileno(input), TCSANOW, &initial_settings);

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
        } while(selected == '\n' || selected == '\r');
        
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


