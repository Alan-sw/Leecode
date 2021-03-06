#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <curses.h>

int main(void)
{
    const char witch_one[] = " first witch ";
    const char witch_two[] = " second witch ";
    const char *scan_ptr;

    initscr();
    
    move(5, 15);
    attron(A_BOLD);
    printw("%s", "macbeth");
    attroff(A_BOLD);
    refresh();
    
    sleep(1);

    move(8, 15);
    attron(A_STANDOUT);
    printw("%s", "thunder and ligthning");
    attroff(A_STANDOUT);
    refresh();
    sleep(1);

    move(10, 10);
    printw("%s", "when shall we three meet again");
    move(11, 23);
    printw("%s", "in thunder, ligthning, or in rain?");
    move(13, 10);
    printw("%s", "when the hurlyburly's done,");
    move(14, 23);
    printw("%s", "when the battle's lost and won. ");
    refresh();
    sleep(1);

    attron(A_DIM);
    scan_ptr = witch_one + strlen(witch_one) - 1;
    while (scan_ptr != witch_one) {
        move(10, 10);
        insch(*scan_ptr--);
    }

    scan_ptr = witch_two + strlen(witch_two) - 1;
    while (scan_ptr != witch_two) {
        move(13, 10);
        insch(*scan_ptr--);
    }

    attroff(A_DIM);
    refresh();
    sleep(1);

    move(LINES - 1, COLS - 1);

    refresh();
    sleep(4);

    endwin();
    
    return 0;
}
