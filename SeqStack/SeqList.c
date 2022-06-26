/**
 * user: bobo
 * func: 线性表相关函数
 */
#include "SeqList.h"

typedef  unsigned int  TSeqListNode;

//线性表结构提
typedef struct _tag_SeqList
{
    int capacity;
    int length;
    TSeqListNode* node;
} TSeqList;

//创建线性表 
SeqList* SeqList_Create(int capacity)
{   
    TSeqList* ret = NULL;

    if (capacity >= 0)
        ret = (TSeqList*)malloc(sizeof(TSeqList) + sizeof(TSeqListNode) * capacity);
    
    if(ret != NULL)
    {
        ret->capacity = capacity;
        ret->length = 0;
        ret->node = (TSeqListNode*)(ret + 1);
    }

    return ret;
}


//销毁线性表
void SeqList_Destroy(SeqList* list)
{
    free(list);
}


//清空线性表
void SeqList_Clear(SeqList* list)
{
    TSeqList* slist = (TSeqList*)list;

    if(slist != NULL)
    {
        slist->length = 0;
    }
}


//获取线性表的元素个数
//返回值：-1 失败   >=0 正常
int SeqList_Length(SeqList* list)
{
    TSeqList* slist = (TSeqList*) list;

    if(slist != NULL)
        return slist->length;
    
    return -1;
}


//获取线性表的最大存储值
//返回值：-1 失败   >=0 正常
int SeqList_Capacity(SeqList* list)
{
    TSeqList* slist = (TSeqList*) list;

    if(slist != NULL)
        return slist->capacity;
    return -1;
}


//插入元素
//参数：pos的值[0:capacity-1] 
//返回值：False:添加失败   TRUE:添加成功
BOOL SeqList_Insert(SeqList* list, SeqListNode* node, int pos)
{
    TSeqList* slist = (TSeqList*)list;
    BOOL ret = FALSE;
    int cnt = 0;

    
    ret = (slist != NULL) && (slist->length+1 <= slist->capacity) && (pos >= 0) && (pos < slist->capacity);

    if(ret)
    {
        if(pos > slist->length)
            pos = slist->length;

        for(cnt=slist->length; cnt>pos; cnt--)
        {
            slist->node[cnt] = slist->node[cnt-1];
        }

        slist->node[cnt] = *(TSeqListNode*)node;

        slist->length += 1;
    }

    return ret;
}


//获取pos位置的元素
SeqListNode* SeqList_Get(SeqList* list, int pos)
{
    TSeqList* slist = (TSeqList*)list;
    SeqListNode* ret = NULL;

    if(slist != NULL && pos >= 0 && pos < slist->length)   
        ret = (SeqListNode*)&(slist->node[pos]);
    
    return ret;
}



//检出pos位置的元素
SeqListNode* SeqList_Pop(SeqList* list, int pos)
{
    TSeqList* slist = (TSeqList*)list;
    int cnt = 0;
    SeqListNode* ptr = SeqList_Get(slist, pos);
    static TSeqListNode ret = 0x00;

    if(ptr != NULL)
    {
        ret = *(TSeqListNode*)ptr;

        for(cnt=pos+1; cnt<slist->length; cnt++)
        {
            slist->node[cnt-1] = slist->node[cnt];
        }
        slist->length -= 1;
    }

    return (SeqListNode*)&ret;
}


