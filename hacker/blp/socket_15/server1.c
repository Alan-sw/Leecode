/*
 * =====================================================================================
 *
 *       Filename:  server1.c
 *
 *    Description:  socket server 1
 *
 *        Created:  10/16/2015 05:31:58 PM
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
    int server_sockfd, client_sockfd;
    int server_len, client_len;
    struct sockaddr_un server_address;
    struct sockaddr_un client_address;

    unlink("server_socket");
    server_sockfd = socket(AF_UNIX, SOCK_STREAM, 0);
    server_address.sun_family = AF_UNIX;
    strcpy(server_address.sun_path, "server_socket");
    server_len = sizeof(server_address);
    bind(server_sockfd, (struct sockaddr*)&server_address, server_len);

    listen(server_sockfd, 5);
    while (1) {
        char ch;
        printf("server waiting\n");
        client_len = sizeof(client_address);

        client_sockfd = accept(server_sockfd, (struct sockaddr *)&client_address, &client_len);
        read(client_sockfd, &ch ,1);
        ch++;
        write(client_sockfd, &ch, 1);
        close(client_sockfd);
    }
    
    return EXIT_SUCCESS;
}
