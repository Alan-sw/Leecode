/*
 * =====================================================================================
 *
 *       Filename:  limits.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/20/2015 11:00:49 AM
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
#include <sys/types.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>


/* 
 * ===  FUNCTION  ======================================================================
 *         Name:  work
 *  Description:  
 * =====================================================================================
 */
void work()
{
    FILE *f;
    int i;
    double x = 4.5;

    f = tmpfile();
    for (i = 0; i < 10000; ++i) {
        fprintf(f, "Do some output\n");
        if (ferror(f)) {
            fprintf(stderr, "Error writing to tmeporary file\n");
            exit(1);
        }
    }

    for (i = 0; i < 1000000; ++i) {
        x = log(x * x + 3.21);
    }

}		/* -----  end of function work  ----- */

int main(int argc, char *argv[])
{
    struct rusage r_usage;
    struct rlimit r_limit;
    int priority;

    work();
    getrusage(RUSAGE_SELF, &r_usage);
    printf("CPU usage: User = %ld.%06ld, System = %ld.%06ld\n", 
            r_usage.ru_utime.tv_sec, r_usage.ru_utime.tv_usec,
            r_usage.ru_stime.tv_sec, r_usage.ru_stime.tv_usec);

    priority = getpriority(PRIO_PROCESS, getpid());
    printf("Current priority = %d\n", priority);

    getrlimit(RLIMIT_FSIZE, &r_limit);
    printf("Current FSIZE limit : soft = %ld, hard = %ld\n", 
            r_limit.rlim_cur, r_limit.rlim_max);


    return 0;
}










