#include "LinkStack.h"
#include "../includes.h"


int main(void)
{
    LinkStack* stack = LinkStack_Create();
    int a[10];
    int i = 0;

    for(i=0; i<10; i++)
    {
        a[i] = i;

        LinkStack_Push(stack, (a+i));
    }

    printf("TOP:%d\n", *(int*)LinkStack_Top(stack));
    printf("Length:%d\n", LinkStack_Length(stack));

    for(i=0; i<5; i++)
    {
         printf("POP:%d\n", *(int*)LinkStack_Pop(stack));
    }

    // while(LinkStack_Length(stack) > 0)
    // {
    //     printf("POP:%d\n", *(int*)LinkStack_Pop(stack));
    // }

    LinkStack_Clear(stack);

    // for(i=0; i<5; i++)
    // {
    //      printf("POP:%d\n", *(int*)LinkStack_Pop(stack));
    // }

    LinkStack_Destroy(stack);
    return 0;
}

