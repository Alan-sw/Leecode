#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>

double my_sqrt(double x) {
    assert(x >= 0.0);

    return sqrt(x);
}

int main(void)
{
    printf("sqrt +2 = %g\n", my_sqrt(2.0));
    printf("sqrt -2 = %g\n", my_sqrt(-2.0));

    return EXIT_SUCCESS;
}
