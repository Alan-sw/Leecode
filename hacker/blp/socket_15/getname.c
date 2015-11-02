/*
 * =====================================================================================
 *
 *       Filename:  getname.c
 *
 *    Description: get info about host 
 *
 *        Created:  10/19/2015 11:30:51 AM
 *       Compiler:  gcc
 *
 *         Author:  Alan Lee , 1127259111@qq.com
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    char *host, **names, **addrs;
    struct hostent *hostinfo;

    if (argc == 1) {
        char myname[256];
        gethostname(myname, 256);
        host = myname;
    } else {
        host = argv[1];
    }

    hostinfo = gethostbyname(host);
    if (!hostinfo) {
        fprintf(stderr, "cannot get info for host : %s\n", host);
        return EXIT_FAILURE;
    }

    printf("result for host %s  : \n", host);
    printf("Name                : %s\n", hostinfo->h_name);
    printf("Aliases             :");
    names = hostinfo->h_aliases;
    while (*names) {
        printf(" %s", *names);
        names++;
    }
    printf("\n");

    if (hostinfo->h_addrtype != AF_INET) {
        perror("not an IP host");
        return EXIT_FAILURE;
    }
    printf("address             :");
    addrs = hostinfo->h_addr_list;
    while (*addrs) {
        printf(" %s", inet_ntoa(*(struct in_addr *)*addrs));
        addrs++;
    }

    printf("\n");
    
    return EXIT_SUCCESS;
}
