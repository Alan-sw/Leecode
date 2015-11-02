/*
 * =====================================================================================
 *
 *       Filename:  ctime.c
 *
 *    Description:  ctime function
 *
 *        Version:  1.0
 *        Created:  08/19/2015 02:59:01 PM
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
#include <time.h>

int main(int argc, char *argv[])
{
    time_t timeval;
    (void)time(&timeval);
    printf("The date is : %s\n", ctime(&timeval));

    return 0;
}
