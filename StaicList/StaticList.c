#include "StaticList.h"

typedef struct _tag_StaticListNode
{
    unsigned int data;
    int next;
}TStaticListNode;

typedef struct _tag_StaticList
{
    int capacity;
    TStaticListNode header;
    TStaticListNode node[];
}TStaticList;

#define AVAILABLE       (-1)

//创建
StaticList* StaticList_Create(int capacity)
{
    TStaticList* list = NULL;
    if(capacity < 0)
        return NULL;

    list = (TStaticList*)malloc(sizeof(TStaticList) + sizeof(TStaticListNode) * capacity);

    if(list != NULL)
    {
        int cnt = 0;
        list->capacity = capacity;
        list->header.data = 0;
        list->header.next = 0;

        for(cnt=0; cnt<list->capacity; cnt++)
        {
            list->node[cnt].next = AVAILABLE;
        }
    }

    return (StaticList*)list;
}


//销毁
void StaticList_Destroy(StaticList* list)
{
    free(list);
}


//清理
void StaticList_Clear(StaticList* list)
{
    TStaticList* slist = (TStaticList*)list;
    if(slist != NULL)
    {
        int cnt = 0;
        slist->header.data = 0;
        slist->header.next = 0;
        for(cnt=0; cnt<slist->capacity; cnt++)
        {
            slist->node[cnt].next = AVAILABLE;
        }        
    }
}


//返回长度
int StaticList_Length(StaticList* list)
{
    int retLen = -1;
    TStaticList* slist = (TStaticList*)list;
    if(slist != NULL)
    {
        retLen = slist->header.data;
    }

    return retLen;
}


//返回最大存储量
int StaticList_Capacity(StaticList* list)
{
    int retCapacity = -1;
    TStaticList* slist = (TStaticList*)list;
    if(slist != NULL)
    {
        retCapacity = slist->capacity;
    }

    return retCapacity;
}


//插入元素
int StaticList_Insert(StaticList* list, StaticListNode* node, int pos);
//获取某一位置的元素
StaticListNode* StaticList_Get(StaticList* list, int pos);
//删除某一位置的元素
StaticListNode* StaticList_Delete(StaticList* list, int pos);






