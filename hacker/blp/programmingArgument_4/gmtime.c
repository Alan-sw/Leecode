/*
 * =====================================================================================
 *
 *       Filename:  gmtime.c
 *
 *    Description:  difftime gmtime
 *
 *        Version:  1.0
 *        Created:  08/19/2015 11:42:36 AM
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
    struct tm *tm_ptr;
    time_t the_time;

    (void)time(&the_time);
    tm_ptr = localtime(&the_time);
    printf("Raw time is %ld\n", the_time);
    printf("localtime gives:\n");
    printf("date: %02d/%02d/%02d\n", tm_ptr->tm_year+1900, tm_ptr->tm_mon + 1, tm_ptr->tm_mday);
    printf("time: %02d:%02d:%02d\n", tm_ptr->tm_hour, tm_ptr->tm_min, tm_ptr->tm_sec);
    return 0;
}

