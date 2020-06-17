#ifndef MARRAY_H
#define MARRAY_H

/*
    Minimal "stretchy buffer" or dynamic array implementation.
    Inspired by Sean Barrett's header but implemented by myself
    as an exercise in figuring out wtf is going on.

    This doesn't bother with c++ compatibility.
*/

#include <stdlib.h>
#include <errno.h>

struct mhead {
    int len;
    int cap;
};

#define _mhead(a) ( (struct mhead *)  a - 1 )
#define _mlen(a) ( _mhead(a)->len )
#define _mcap(a) ( _mhead(a)->cap )
#define __mgrow(a) ( (a) == 0 || _mlen(a)+1 > _mcap(a) ? (a) = _mgrow((a), 1, sizeof(*(a))) : 0 )

#define mpush(a, ...) ( __mgrow(a), (a)[_mlen(a)++] = (__VA_ARGS__) )
#define mfree(a) ( (a) ? free(_mhead(a)), (a)=0 : 0 )
#define mcount(a) ( (a) ? _mlen(a) : 0 )

void *_mgrow(void *a, int n, int size)
{
    int cap = a == 0 || _mcap(a) == 0 ? n : _mcap(a)*2;
    struct mhead *r = realloc(a == 0 ? 0 : _mhead(a), cap*size + sizeof(struct mhead));
    if (r) {
        if (!a)
            r->len = 0;
        r->cap = cap;
        return r + 1;
    } else {
        perror("mpush");
        exit(1);
        return NULL;
    }
}

#endif
