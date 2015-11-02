/*
 * =====================================================================================
 *
 *       Filename:  logmask.c
 *
 *    Description:  logmask
 *
 *        Version:  1.0
 *        Created:  08/20/2015 10:14:52 AM
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
#include <syslog.h>
#include <unistd.h>

int main()
{
    int logmask;
    
    openlog("logmask", LOG_PID|LOG_CONS, LOG_USER);
    syslog(LOG_INFO, "informative message, pid = %d", getpid());
    syslog(LOG_DEBUG, "debug message, should appear");
    logmask = setlogmask(LOG_UPTO(LOG_NOTICE));
    syslog(LOG_DEBUG, "debug message, should not appear");
    printf("logmask is : %d\n", logmask);

    return 0;
}
