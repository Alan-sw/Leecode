/*
 * =====================================================================================
 *
 *       Filename:  strftime.c
 *
 *    Description:  strftime and strptime function
 *
 *        Version:  1.0
 *        Created:  08/19/2015 03:12:11 PM
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
#include <string.h>

#define _XOPEN_SOURCE

int main(int argc, char *argv[])
{
    struct tm *tm_ptr, timesturct;
    time_t the_time;
    char buf[256];
    char *result;

    (void)time(&the_time);
    tm_ptr = localtime(&the_time);
    strftime(buf, 256, "%A %d %B, %I:%S %p", tm_ptr);

    printf("strftime give: %s\n", buf);

    strcpy(buf, "Wed 19 Aug 2015, 15:16 will do fine");

    printf("calling strptime with: %s\n", buf);

    tm_ptr = &timesturct;
    result = strptime(buf, "%a %d %b %Y, %R", tm_ptr);
    printf("strptime consumed up to: %s\n", result);

    printf("strptime gives:\n");
    printf("date: %02d/%02d/%02d\n", tm_ptr->tm_year % 100, tm_ptr->tm_mon  + 1, tm_ptr->tm_mday);
    printf("time: %02d:%02d\n", tm_ptr->tm_hour, tm_ptr->tm_min);


    return 0;
}

