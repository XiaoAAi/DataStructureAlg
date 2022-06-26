/**
 * 1.首先，视频给的程序是存在问题的，因为Ubuntu编译环境更加苛刻，存在空指针现象！
 * 2.Insert函数中 加入到list->node[pos]中的是数值，不是地址;原因是：申请空间的时候，使用的是sizeof(TSeqListNode) * capacity  而不是 sizeof(TSeqListNode*) * capacity; 又因为unsigned int 是 4Byte正好和地址字节一样，所以没有出错！
 * 3.也可以使用地址进行顺序现行表，但是需要有固定内存！
*/
#include "../includes.h"
#include "SeqStack.h"

#define MAX   20

int main(void)
{
    SeqStack* stack = SeqStack_Create(MAX);
    int a[10];
    int i = 0;

    for(i=0; i<10; i++)
    {
        a[i] = i;

        SeqStack_Push(stack, (a+i));
    }

    printf("TOP:%d\n", *(int*)SeqStack_Top(stack));
    printf("capacity:%d\n", SeqStack_Capacity(stack));
    printf("Length:%d\n", SeqStack_Length(stack));

    while(SeqStack_Length(stack) > 0)
    {
        printf("POP:%d\n", *(int*)SeqStack_Pop(stack));
    }


    SeqStack_Destroy(stack);
    return 0;
}