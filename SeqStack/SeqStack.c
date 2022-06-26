/**
 * user: bobo
 * func: 线性表 栈
 */
#include "SeqList.h"
#include "SeqStack.h"

SeqStack* SeqStack_Create(int capacity)
{
    return SeqList_Create(capacity);
}


void SeqStack_Destroy(SeqStack* list)
{
    SeqList_Destroy(list);
}


void SeqStack_Clear(SeqStack* list)
{
    SeqList_Clear(list);
}

int SeqStack_Push(SeqStack* stack, void* item)
{
    return SeqList_Insert(stack, item, SeqList_Length(stack));
}

SeqStack* SeqStack_Pop(SeqStack* stack)
{
    return SeqList_Pop(stack, (SeqList_Length(stack)-1));
}


SeqStack* SeqStack_Top(SeqStack* stack)
{
    return SeqList_Get(stack, (SeqList_Length(stack)-1));
}

int SeqStack_Length(SeqStack* stack)
{
    return SeqList_Length(stack);
}

int SeqStack_Capacity(SeqStack* stack)
{
    return SeqList_Capacity(stack);
}