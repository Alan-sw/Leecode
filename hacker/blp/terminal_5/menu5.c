#include <stdio.h>
#include <stdlib.h>
#include <term.h>
#include <curses.h>
#include <unistd.h>
#include <termios.h>

static FILE *output_stream = (FILE *)0;


char *menu[] = {
    "a --- add new recor",
    "d --- delete record",
    "q --- quit",
    NULL,
};

int getchoice(char *greet, char *choices[], FILE *in, FILE *out);

int char_to_terminal(int char_to_write);

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
        sleep(1);
    } while(choice != 'q');
    tcsetattr(fileno(input), TCSANOW, &initial_settings);

    return 0;
}

int getchoice(char *greet, char *choices[], FILE *in, FILE *out)
{
    int chosen = 0;
    int selected;
    int screenrow, screencol = 10;
    char **option;
    char *cursor, *clear;

    output_stream = out;

    setupterm(NULL, fileno(out), (int*)0);
    cursor = tigetstr("cup");
    clear = tigetstr("clear");

    screenrow = 4;
    tputs(clear, 1, (int *)char_to_terminal);
    tputs(tparm(cursor, screenrow, screencol), 1, char_to_terminal);
    fprintf(out, "choice : %s\n", greet);
    screenrow += 2;
    option = choices;

    while (*option) {
        tputs(tparm(cursor, screenrow, screencol), 1, char_to_terminal);
        fprintf(out, "%s", *option);
        screenrow++;
        option++;
    }

    fprintf(out, "\n");

    do {
        fflush(out);
        selected  = fgetc(in);
        option = choices;
        
        while (*option) {
            if (selected == *option[0]) {
                chosen = 1;
                break;
            }
            option++;
        }

        if (!chosen) {
            tputs(tparm(cursor, screenrow, screencol), 1, char_to_terminal);
            fprintf(out, "Incorrect choice, select again");
        }
    } while(!chosen);

    tputs(clear, 1, char_to_terminal);
    return selected;
}

int char_to_terminal(int char_to_write)
{
    if (output_stream) {
        putc(char_to_write, output_stream);
    }

    return 0;
}


