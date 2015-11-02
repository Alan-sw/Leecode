#include <unistd.h>
#include <stdlib.h>
#include <curses.h>
#include <stdio.h>

#define LOCAL_ESCAPE_KEY 27

int main(void)
{
    int key;
    
    initscr();
    crmode();
    keypad(stdscr, TRUE);
    noecho();
    clear();
    mvprintw(5, 5, "key pad demonstration. Prss 'q' to quit");
    move(7, 5);
    refresh();
    key = getch();

    while (key != ERR && key != 'q') {
        move(7, 5);
        clrtoeol();

        if ( (key >= 'A' && key <= 'Z') ||
                (key >= 'a' && key <= 'z')) {
            printw("key was %c", (char)key);
        } else {
            switch (key) {
                case LOCAL_ESCAPE_KEY:
                    printw("%s", "escape key");
                    break;
                case KEY_END:
                    printw("%s", "End key");
                    break;
                case KEY_BEG:
                    printw("%s", "begining key");
                    break;
                case KEY_RIGHT:
                    printw("%s", "right key");
                    break;
                case KEY_LEFT:
                    printw("%s", "left key");
                    break;
                case KEY_UP:
                    printw("%s", "up key");
                    break;
                case KEY_DOWN:
                    printw("%s", "down key");
                    break;
                default:
                    printw("unmatched - %d", key);
                    break;
            }
        }
        refresh();
        key = getch();
    }

    endwin();
    
    return 0;
}
