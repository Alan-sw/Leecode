#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>


int main(void)
{
    int file_desc;
    int save_errno;

    file_desc = open("./LCK.test", O_RDWR | O_CREAT | O_EXCL, 0444);
    if (file_desc == -1) {
        save_errno = errno;
        printf("open failed with error %d\n", save_errno);
    } else {
        printf("open succeded\n");
    }

    return 0;
}
