#include "StaticList.h"
/**
 * 为什么将Node[0]作为Header来使用？
 * 答：主要是插入的时候，header.next指向的必定是node[0];在循环遍历的时候不方便遍历查询，header需要特殊处理！
*/
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

    list = (TStaticList*)malloc(sizeof(TStaticList) + sizeof(TStaticListNode) * (capacity+1));

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
        for(cnt=1; cnt<=slist->capacity; cnt++)
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
    TStaticList* slist = (TStaticList*)list;
    int retCapacity = -1;

    if(slist != NULL)
        retCapacity = slist->capacity;

    return retCapacity;
}


//插入元素
int StaticList_Insert(StaticList* list, StaticListNode* node, int pos)
{
    TStaticList* slist = (TStaticList*)list;
    int current = 0;
    int index = 0;
    int i = 0;
    int ret = (slist != NULL) && (slist->header.data <= slist->capacity)\
     && (pos>=0) &&  (node != NULL);  
        
    if(ret)
    { 
        slist->node[0] = slist->header;

        for(i=0; i<slist->capacity; i++)
        {
            if(slist->node[i].next == AVAILABLE)
            {
                index = i;
                break;
            }
        }

        slist->node[index].data = (unsigned int)*(unsigned int*)node;

        for(i=0; (i<pos)&&(slist->node[current].next != 0); i++)
        {
            current = slist->node[current].next;
            // printf("Insert-current:%d\n", current);
        }

        slist->node[index].next = slist->node[current].next;
        slist->node[current].next = index;

        slist->node[0].data += 1;

        slist->header = slist->node[0];

        // printf("Insert:%d, %d, %d\n", slist->header.data, slist->header.next, current);
    }     

    return ret; 
}


//获取某一位置的元素
StaticListNode* StaticList_Get(StaticList* list, int pos)
{
    TStaticList* slist = (TStaticList*)list;
    static StaticListNode* ret = NULL;
    int current = 0;
    int obj = 0;
    int i = 0;

    if(slist!=NULL && pos>=0 && pos<slist->header.data)
    {
        slist->node[0] = slist->header;

        for(i=0; i<pos; i++)
        {
            current = slist->node[current].next;
        }

        obj = slist->node[current].next;

        ret = (StaticListNode*)&(slist->node[obj].data);
        // printf("Get:%d, %d\n", slist->node[current].data, slist->node[current].next);
    }

    return ret;
}


//删除某一位置的元素
StaticListNode* StaticList_Delete(StaticList* list, int pos)
{
    TStaticList* slist = (TStaticList*)list;
    static StaticListNode* ret = NULL;
    int current = 0;
    int obj = 0;
    int i = 0; 

    if(slist!=NULL && pos>=0 && pos<slist->header.data)
    {
        slist->node[0] = slist->header;

        for(i=0; i<pos; i++)
        {
            current = slist->node[current].next;
        }

        obj = slist->node[current].next;
        slist->node[current].next = slist->node[obj].next;
        slist->node[0].data -= 1;

        slist->header = slist->node[0];

        slist->node[obj].next = AVAILABLE;

        ret = (StaticListNode*)&(slist->node[obj].data);
    }

    return ret;
}






