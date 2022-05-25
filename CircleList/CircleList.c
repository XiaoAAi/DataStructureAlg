#include "CircleList.h"

typedef struct _tag_CircleList
{
    CircleListNode header;
    CircleListNode* slider;
    int length;
} TCircleList;




CircleList* CircleList_Create()
{
    TCircleList* slist = (TCircleList*)malloc(sizeof(TCircleList));

    if(slist != NULL)
    {
        slist->header.next = NULL;
        slist->slider = NULL;
        slist->length = 0;
    }

    return slist;
}


void CircleList_Destory(CircleList* list)
{
    free(list);
}


void CircleList_Clear(CircleList* list)
{
    TCircleList* slist = (TCircleList*)list;

    if(slist != NULL)
    {
        slist->header.next = NULL;
        slist->slider = NULL;
        slist->length = 0;        
    }
}


int CircleList_Length(CircleList* list)
{
    TCircleList* slist = (TCircleList*)list;
    
    if(slist != NULL)
    {
        return slist->length;
    }

    return -1;
}


int CircleList_Insert(CircleList* list, CircleListNode* node, int pos);

CircleListNode* CircleList_Get(CircleList* list, int pos);

CircleListNode* CircleList_Delete(CircleList* list, int pos);

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node);
//设置 游标位于头指针
CircleListNode* CircleList_Reset(CircleList* list);
// 返回当前 游标
CircleListNode* CircleList_Current(CircleList* list);
//返回下一个游标
CircleListNode* CircleList_Next(CircleList* list);

