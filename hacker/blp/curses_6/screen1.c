/*
 * =====================================================================================
 *
 *       Filename:  screen1.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/25/2015 03:08:20 PM
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
#include <curses.h>
#include <unistd.h>

int main(void)
{
    initscr();

    move(5, 50);
    printw("%s", "hello world");
    refresh();

    sleep(2);

    endwin();
    return 0;
}
