#include <stdio.h>
#include <string.h>

#define N 6

int result[999999], tempa[999999], tempb[999999];
int n, dot, len_tempa, len_tempb;
char str[N];

void mult()
{   
    int i = 1, j = 1;
    memset(result, 0, sizeof(result));
    printf("***************");
    for (i = 1; i <= len_tempb; ++i) {
        printf("%d", tempb[i]);
    }
    printf("***************");
    printf("\n");
    
    for(i = 1; i <= len_tempb; i++) {
        for(j = 1; j <= len_tempa; j++) {
            result[i + j - 1] += tempa[j] * tempb[i];
            if (result[i + j - 1] > 9) {
                result[i + j ] += result[i + j - 1] / 10;
                result[i + j - 1] %= 10; 
            }
        }//end of tempa
    }//end of tempb
    

    if (result[len_tempa + len_tempb - 1] > 9) {
        result[len_tempa + len_tempb] += result[len_tempa + len_tempb - 1] / 10;
        result[len_tempa + len_tempb - 1] %= 10;
        len_tempb = len_tempa + len_tempb;
    } else {
        len_tempb = len_tempa + len_tempb - 1;
    }

    printf("***************");
    printf("the length of tempb is : %d\n", len_tempb);
    printf("***************");
    for (i = 1; i <= len_tempb; ++i) {
        tempb[i] = result[i];
    }
}

int main(void)
{
    int i, j;
    memset(tempb, 0, sizeof(tempb));
    memset(tempa, 0, sizeof(tempa));

    while ((scanf("%s %d", str, &n)) != EOF) {
        dot = -1;
        for (i = 0, j = 1; i < N; ++i) {
            if (str[i] == '.') {
               dot = i; 
            } else {
                tempa[j] = str[i] - '0';
                tempb[j] = tempa[j];
                j++;
            }
        }

        if (dot == -1) {
            len_tempa = len_tempb = N;
        } else {
            len_tempa = len_tempb = N - 1;
        }

        for (i = 1; i < n; ++i) {
            mult();
        }

        for (i = 1; i <= len_tempb; ++i) {
            printf("%d", tempb[i]);
        }
        printf("\n");



    }// end of main while
    


    return 0;
}
