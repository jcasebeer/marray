#include <stdio.h>
#include <stdlib.h>

#include "marray.h"

int main(int argc, char **argv)
{
    
    int *array = NULL;

    mpush(array, 1);
    mpush(array, 2);
    mpush(array, 3);
    mpush(array, 4);
    mpush(array, 5);
    mpush(array, 6);
    mpush(array, 7);
    mpush(array, 8);
    int top = mcount(array);

    while(top > 0) {
        printf("%d \n", array[--top]);
    }

    mfree(array); 

    struct a {
        int x, y;
    };

    struct a *a_array = NULL;
    mpush(a_array, (struct a){4,20});
    top = mcount(a_array);
    struct a a = a_array[--top];

    printf("%d %d\n", a.x, a.y);
    
    return 0;
}
