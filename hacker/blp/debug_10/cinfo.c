#include <stdio.h>
#include <stdlib.h>

int main(void)
{
#ifdef DEBUG
    printf("Complied: %s, at %s\n",__DATE__, __TIME__);
    printf("This is line %d of file %s\n", __LINE__, __FILE__);
#endif
    printf("hello world\n");
    return EXIT_SUCCESS;
}
