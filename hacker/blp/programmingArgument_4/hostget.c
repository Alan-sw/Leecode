/*
 * =====================================================================================
 *
 *       Filename:  hostget.c
 *
 *    Description:  gethostname and uname
 *
 *        Version:  1.0
 *        Created:  08/20/2015 09:17:01 AM
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
#include <sys/utsname.h>
#include <unistd.h>

int main()
{
    char computer[256];
    struct utsname uts;

    if (gethostname(computer, 255) != 0 || uname(&uts) < 0) {
        fprintf(stderr, "could not get host information\n");
        return EXIT_FAILURE;
    }

    printf("computer host name is : %s\n", computer);
    printf("system is %s on %s hardware\n", uts.sysname, uts.machine);
    printf("nodename is : %s\n", uts.nodename);
    printf("version is : %s, %s\n", uts.release, uts.version);
    printf("host id is %ld\n", gethostid());


    return 0;
}
