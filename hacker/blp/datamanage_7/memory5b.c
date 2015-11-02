#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    char z = *(const char *)0;
    printf("I read form location zero\n");

    return EXIT_SUCCESS;
}
