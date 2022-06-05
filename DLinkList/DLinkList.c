#include "DLinkList.h"

typedef struct _tag_LinkList
{
    DLinkListNode header;
    DLinkListNode* slider;
    int length;
}TDLinkList;

// typedef struct _tag_LinkListData
// {
//     LinkListNode next;
//     int value;
// };

//创建
DLinkList* DLinkList_Create()
{
    TDLinkList* list = (TDLinkList*)malloc(sizeof(TDLinkList));

    if(list != NULL)
    {
        list->length = 0;
        list->header.next = NULL;
        list->header.pre = NULL;
        list->slider = NULL;
    }

    return list;
}

//销毁
void DLinkList_Destroy(DLinkList* list)
{
    free(list);
} 


//清空
void DLinkList_Clear(DLinkList* list)
{
    TDLinkList* slist = (TDLinkList*) list;
    if(slist != NULL)
    {
        slist->header.next = NULL;
        slist->header.pre = NULL;
        slist->slider = NULL;
        slist->length = 0;
    }    
}  

//获取长度
int DLinkList_GetLength(DLinkList* list)
{
    TDLinkList* slist = (TDLinkList*)list;
    int ret = -1;

    if(slist != NULL)
    {
        ret = slist->length;
    }

    return ret;
}   

//插入元素
int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos)
{
    TDLinkList* slist = (TDLinkList*)list;
    int ret = (slist != NULL) && (node != NULL) && (pos >= 0);
    int i = 0;

    if(ret)
    {
        DLinkListNode* current = (DLinkListNode*)slist;
        DLinkListNode* next = NULL;

        for(i=0; i<pos && current->next!=NULL; i++)
        {
            current = current->next;
        }
        next = current->next;
        
        current->next = node;
        node->next = next;

        if(next != NULL)
        {
            next->pre = node;
        }
        
        node->pre = current;

        if(slist->length == 0)
        {
            node->pre = NULL;
            slist->slider = node;
        }

        slist->length += 1;
    }

    return ret;
}  


//获取某一位元素
DLinkListNode* DLinkList_Get(DLinkList* list, int pos)
{
    TDLinkList* slist = (TDLinkList*) list;
    DLinkListNode* ret = NULL;
    int cnt = pos;

    if(slist!= NULL && pos>=0 && pos<slist->length)
    {
        DLinkListNode* current = (DLinkListNode*)slist;

        while(cnt--)
        {
            current = current->next;
        }

        ret = current->next;
    }

    return ret;
}


//删除某一位元素
DLinkListNode* DLinkList_Delete(DLinkList* list, int pos)
{
    TDLinkList* slist = (TDLinkList*) list;
    DLinkListNode* ret = NULL;
    int cnt = pos;

    if(slist!= NULL && pos>=0 && pos<slist->length)
    {
        DLinkListNode* current = (DLinkListNode*)slist;
        DLinkListNode* next = NULL;

        while(cnt--)
        {
            current = current->next;
        }

        ret = current->next;
        next = ret->next;

        current->next = next;   

        if(next != NULL)
        {
            next->pre = current;
            if(current == (DLinkListNode*)slist)
            {
                next->pre = NULL;
            }
        }

        if(slist->slider == ret)
        {
            slist->slider = next;
        } 

        slist->length -= 1; 
    }    
    
    return ret;
}   



DLinkListNode* DLinkList_DeleteNode(DLinkListNode* list, DLinkListNode* node)
{
    TDLinkList* slist = (TDLinkList*) list;
    DLinkListNode* ret = NULL;
    int cnt = 0;   

    if(slist != NULL)
    {
        DLinkListNode* current = (DLinkListNode*)list;

        for(cnt=0; cnt<slist->length; cnt++)
        {
            if(current->next == node)
            {
                ret = current->next;
                break;
            }

            current = current->next;
        }

        if(ret != NULL)
        {
            DLinkList_Delete(slist, cnt);
        }
    }

    return ret;
}


DLinkListNode* DLinkList_Reset(DLinkList* list)
{
    TDLinkList* slist = (TDLinkList*)list;
    DLinkListNode* ret = NULL;

    if(slist != NULL)
    {
        slist->slider = slist->header.next;
        ret = slist->slider;
    }
    
    return ret;
}



DLinkListNode* DLinkList_Current(DLinkList* list)
{
    TDLinkList* slist = (TDLinkList*)list;
    DLinkListNode* ret = NULL;  

    if(slist != NULL)
    {
        ret = slist->slider;
    }

    return ret;
}


DLinkListNode* DLinkList_Next(DLinkList* list)
{
    TDLinkList* slist = (TDLinkList*)list;
    DLinkListNode* ret = NULL;  

    if(slist!=NULL && slist->slider!=NULL)
    {
        ret = slist->slider;
        if(ret->next != NULL)
        {
            slist->slider = ret->next;
        }
        
    }

    return ret;
}


DLinkListNode* DLinklist_Pre(DLinkList* list)
{
    TDLinkList* slist = (TDLinkList*)list;
    DLinkListNode* ret = NULL;  

    if(slist != NULL && slist->slider != NULL)
    {
        ret = slist->slider;
        if(ret->pre != NULL)
        {
            slist->slider = ret->pre;
        }  
    }

    return ret;
}



