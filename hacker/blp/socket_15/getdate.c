/*
 * =====================================================================================
 *
 *       Filename:  getdate.c
 *
 *    Description:  get date and time
 *
 *        Created:  10/19/2015 02:40:54 PM
 *       Compiler:  gcc
 *
 *         Author:  Alan Lee , 1127259111@qq.com
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>

int main(int argc, char *argv[])
{
    char *host;
    int sockfd;
    int len, result;
    struct sockaddr_in address;
    struct hostent *hostinfo;
    struct servent *servinfo;
    char buffer[128];

    if (argc == 1) {
        host = "localhost";
    } else {
        host = argv[1];
    }

    hostinfo = gethostbyname(host);
    if (!hostinfo) {
        fprintf(stderr, "no host : %s\n", host);
        return EXIT_FAILURE;
    }

    servinfo = getservbyname("daytime", "tcp");
    if (!servinfo) {
        fprintf(stderr, "no daytime service\n");
        return EXIT_FAILURE;
    }

    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    address.sin_family = AF_INET;
    address.sin_port = servinfo->s_port;
    address.sin_addr = *(struct in_addr *)*hostinfo->h_addr_list;

    len = sizeof(address);
    
    result = connect(sockfd, (struct sockaddr *)&address, len);
    if (result == -1) {
        perror("oops:getdate");
        return EXIT_FAILURE;
    }
    
    result = read(sockfd, buffer, sizeof(buffer));
    buffer[result] = '\0';
    printf("read %d bytes: %s", result, buffer);

    close(sockfd);

    return EXIT_SUCCESS;
}
