#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> 

int main(void)
{
    printf("Running ps with execlp\n");
    execlp("ps", "ps", "ax", 0);
    printf("Done.\n");

    return EXIT_SUCCESS;
}
