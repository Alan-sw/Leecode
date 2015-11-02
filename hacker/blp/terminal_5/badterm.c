/*
 * =====================================================================================
 *
 *       Filename:  badterm.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/24/2015 05:41:01 PM
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
#include<term.h>
#include<curses.h>

int main(void)
{
    setupterm("unlisted", fileno(stdout), (int*)0);
    printf("Done.\n");

    return 0;
}
