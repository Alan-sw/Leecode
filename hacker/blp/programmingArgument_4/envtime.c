/*
 * =====================================================================================
 *
 *       Filename:  envtime.c
 *
 *    Description:  show time function  
 *
 *        Version:  1.0
 *        Created:  08/19/2015 11:35:05 AM
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
#include <unistd.h>

int main(int argc, char *argv[])
{
    int i;
    time_t the_time;
    for (i = 0; i <= 10; ++i) {
        the_time = time((time_t*)0);
        printf("The time is %ld\n", the_time);
        sleep(2);
    }

    return 0;
}

