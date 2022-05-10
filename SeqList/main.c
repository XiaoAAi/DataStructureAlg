/**
 * 1.首先，视频给的程序是存在问题的，因为Ubuntu编译环境更加苛刻，存在空指针现象！
 * 2.Insert函数中 加入到list->node[pos]中的是数值，不是地址;原因是：申请空间的时候，使用的是sizeof(TSeqListNode) * capacity  而不是 sizeof(TSeqListNode*) * capacity; 又因为unsigned int 是 4Byte正好和地址字节一样，所以没有出错！
 * 3.也可以使用地址进行顺序现行表，但是需要有固定内存！
*/
#include "../includes.h"
#include "SeqList.h"

#define MAX   10

int main(void)
{
    int *tmp = NULL;
    int index = 0;

    printf("Start:%s-%s\n", __DATE__, __TIME__);
    SeqList* slist = SeqList_Create(10);
    printf("Addr:0x%.4X\n", (SeqList*)&slist);
    SeqList_Clear(slist);
    printf("One-len:%d, capacity:%d\n", SeqList_Length(slist), SeqList_Capacity(slist));

    for(index=0; index<MAX; index++)
    {
        if(SeqList_Insert(slist, &index, 0) != TRUE)
            break;
    }

    for(index=0; index<MAX; index++)
    {
        printf("%d\t", *(int*)SeqList_Get(slist, index));
    }
    printf("\n");

    printf("Two-len:%d, capacity:%d\n", SeqList_Length(slist), SeqList_Capacity(slist));

    printf("GetVal1:%d\n", *(int*)SeqList_Get(slist, 5));
    printf("val:%d\n", *(int*)SeqList_Pop(slist, 5));
    printf("GetVal:%d\n", *(int*)SeqList_Get(slist, 5));

    printf("Three-len:%d, capacity:%d\n", SeqList_Length(slist), SeqList_Capacity(slist));

    SeqList_Destroy(slist);
}