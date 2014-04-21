/********************
 * int 类型的stack
 *
 * ******************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct{
    int *elems;
    int index;
    int alloclength;
} stack;


void stackNew(stack *s)
{
    s->index = 0;
    s->alloclength = 4;
    s->elems = (int *)malloc(4 * sizeof(int));
    assert(s->elems != NULL);
}

void stackDispose(stack *s)
{
    free(s->elems);
}

void stackPush(stack *s, int value)
{
    if(s->index ==s->alloclength)
    {
        s->alloclength *= 2;
        s->elems = realloc(s->elems,s->alloclength * sizeof(int));
        assert(s->elems != NULL);
    }
    s->elems[s->index] = value;
    s->index ++;
}

int stackPop(stack *s)
{
    assert(s->alloclength > 0);
    s->index --;
    return s->elems[s->index];

}

int main()
{
    stack s;
    stackNew(&s);
    for(int i = 0; i < 10; i ++)
        stackPush(&s, i);

    printf("%d\n", stackPop(&s));
    return 0;
}
