
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define A_MEGABYTE  1024 * 1024
#define PHY_MEG_MEGS  (1024 * 4)

int main(void)
{
    char *some_memory;
    size_t size_to_allocate = A_MEGABYTE;
    int megs_obtained = 0;

    while (megs_obtained < (PHY_MEG_MEGS)) {
        some_memory = (char *)malloc(size_to_allocate);

        if (some_memory != NULL) {
            megs_obtained++;
        } else {
            return EXIT_FAILURE;
        }
    }
    printf(" now allocated %d Megabytes\n", megs_obtained);

    return EXIT_SUCCESS;
}
