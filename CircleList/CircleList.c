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


int CircleList_Insert(CircleList* list, CircleListNode* node, int pos)
{
    TCircleList* slist = (TCircleList*)list;
    int ret = (slist != NULL) && (pos >= 0) && (pos <= slist->length) && (node != NULL);
    int i = 0;

    if(ret)
    {
        CircleListNode* current = (CircleListNode*)list;
        CircleListNode* plast = (CircleListNode*)list;

        for(i=0; i<pos && current->next!=NULL; i++)
        {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;

        if(slist->length == 0)
        {
            slist->slider = node;
            node->next = node;
        }
        else
        {
            for(i=0; i<(CircleList_Length(slist)+1); i++)
            {
                plast = plast->next;
            }
            plast->next = slist->header.next;
        }

        slist->length += 1;
    }

    return ret;
}


CircleListNode* CircleList_Get(CircleList* list, int pos)
{
    TCircleList* slist = (TCircleList*)list;
    static CircleListNode* ret = NULL;
    int i = 0;

    if(slist!=NULL && pos>=0)
    {
        CircleListNode* current = (CircleListNode*)list;

        for(i=0; i<pos; i++)
        {
            current = current->next;
        }

        ret = current->next;
    }

    return ret;
}


CircleListNode* CircleList_Delete(CircleList* list, int pos)
{
    TCircleList* slist = (TCircleList*)list;
    static CircleListNode* ret = NULL;
    int i=0;

    if(list!=NULL && pos>=0)
    {
        CircleListNode* current = (CircleListNode*)list;
        CircleListNode* pfirst = slist->header.next;
        CircleListNode* plast = (CircleListNode*)CircleList_Get(slist, (slist->length-1));

        for(i=0; i<pos; i++)
        {
            current = current->next;
        }

        ret = current->next;
        current->next = ret->next;

        slist->length -= 1;

        if(pfirst == ret)
        {
            slist->header.next = ret->next;
            plast->next = ret->next;
        }

        if(slist->slider == ret)
        {
            slist->slider = ret->next;
        }

        if(slist->length == 0)
        {
            slist->header.next = NULL;
            slist->slider = NULL;
        }
    }

    return ret;
}

CircleListNode* CircleList_DeleteNode(CircleList* list, CircleListNode* node);
//设置 游标位于头指针
CircleListNode* CircleList_Reset(CircleList* list);
// 返回当前 游标
CircleListNode* CircleList_Current(CircleList* list);
//返回下一个游标
CircleListNode* CircleList_Next(CircleList* list);

