/*
 * =====================================================================================
 *
 *       Filename:  client1.c
 *
 *    Description:  socket client 1
 *
 *        Created:  10/16/2015 05:24:54 PM
 *       Compiler:  gcc
 *
 *         Author:  Alan Lee , 1127259111@qq.com
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

int main(void)
{
    int sockfd;
    int len;
    struct sockaddr_un address;
    int resutlt;
    char ch = 'A';

    sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    address.sun_family = AF_UNIX;
    strcpy(address.sun_path, "server_socket");
    len = sizeof(address);

    resutlt = connect(sockfd, (struct sockaddr *)&address, len);
    if (resutlt == -1) {
        perror("oops:client");
        return EXIT_FAILURE;
    }

    write(sockfd, &ch, 1);

    read(sockfd, &ch, 1);
    printf("char from server = %c\n", ch);
    close(sockfd);

    return EXIT_SUCCESS;
}
