#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "marray.h"

void build_list(int **array)
{
    mpush(*array, 1);
    mpush(*array, 2);
    mpush(*array, 3);
    mpush(*array, 4);
    mpush(*array, 5);
    mpush(*array, 6);
    mpush(*array, 7);
    mpush(*array, 8);
}

int main(int argc, char **argv)
{
    
    int *array = NULL;
    build_list(&array);
    
    int top = mcount(array);

    while(top > 0) {
        printf("%d \n", array[--top]);
    }

    int *array_copy = mcopy(array);
    assert(mcount(array_copy) == mcount(array));
    for(int i = 0; i<mcount(array_copy); i++)
        assert(array_copy[i] == array_copy[i]);

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
