/*
 * =====================================================================================
 *
 *       Filename:  sizeterm.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/25/2015 09:38:31 AM
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
#include <term.h>
#include <curses.h>

int main(void)
{
    int nrows, ncolumns;
    
    setupterm(NULL, fileno(stdout), (int*)0);

    nrows = tigetnum("lines");
    ncolumns = tigetnum("cols");

    printf("this terminal has %d columns and %d rows\n", ncolumns, nrows);

    return 0;
}
