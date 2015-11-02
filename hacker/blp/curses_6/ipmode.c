#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include<string.h>

#define PW_LEN 256
#define NAME_LEN 256

int main(void)
{
    char name[NAME_LEN];
    char password[PW_LEN];
    const char *real_password = "xyzzy";
    int i = 0;

    initscr();

    move(5, 10);
    printw("%s", "please login: ");

    move(7, 10);
    printw("%s", "user name : ");
    getstr(name);

    move(8, 10);
    printw("%s", "password : ");
    refresh();

    cbreak();
    noecho();

    memset(password, '\0', sizeof(password));
    while (i < PW_LEN) {
        password[i] = getch();

        if (password[i] == '\n') {
            break;
        }    
        move(8, 20 + i);
        addch('*');
        refresh();
        i++;
    }
    
    echo();
    nocbreak();

    move(11, 10);
    if (strncmp(real_password, password, strlen(real_password)) == 0) {
        printw("%s", "correct");
    } else {
        printw("%s", "wrong");
    }

    printw("%s", " password !");
    refresh();
    sleep(2);

    endwin();

    return 0;
}
