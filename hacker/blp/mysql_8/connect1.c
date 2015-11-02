#include <stdio.h>
#include <stdlib.h>
#include "mysql/mysql.h"

int main(void)
{
    MYSQL *conn_ptr;

    conn_ptr = mysql_init(NULL);
    if (!conn_ptr) {
        fprintf(stderr, "mysql_init failed\n");
        return EXIT_FAILURE;
    }

    conn_ptr = mysql_real_connect(conn_ptr, "localhost", "google", "paradise", 
                                    "foo", 0, NULL, 0);

    if (conn_ptr) {
        printf("connection success\n");
    } else {
        printf("connection failed\n");
    }

    mysql_close(conn_ptr);


    return EXIT_SUCCESS;
}

