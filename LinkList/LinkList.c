#include "LinkList.h"

typedef struct _tag_LinkList
{
    LinkListNode header;
    int length;
}TLinkList;

// typedef struct _tag_LinkListData
// {
//     LinkListNode next;
//     int value;
// };

//创建
LinkList* LinkList_Create()
{
    TLinkList* list = (TLinkList*)malloc(sizeof(TLinkList));

    if(list != NULL)
    {
        list->length = 0;
        list->header.next = NULL;
    }

    return list;
}

//销毁
void LinkList_Destroy(LinkList* list)
{
    free(list);
} 


//清空
void LinkList_Clear(LinkList* list)
{
    TLinkList* slist = (TLinkList*) list;
    if(slist != NULL)
    {
        slist->header.next = NULL;
        slist->length = 0;
    }    
}  

//获取长度
int LinkList_GetLength(LinkList* list)
{
    TLinkList* slist = (TLinkList*)list;
    int ret = -1;

    if(slist != NULL)
    {
        ret = slist->length;
    }

    return ret;
}   

//插入元素
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos)
{
    TLinkList* slist = (TLinkList*)list;
    int ret = (slist != NULL) && (node != NULL) && (pos >= 0);
    int i = 0;

    if(ret)
    {
        LinkListNode* slider = (LinkListNode*)slist;

        for(i=0; i<pos && slider->next!=NULL; i++)
        {
            slider = slider->next;
        }

        node->next = slider->next;
        slider->next = node;

        slist->length += 1;
    }


    return ret;
}  


//获取某一位元素
LinkListNode* LinkList_Get(LinkList* list, int pos)
{
    TLinkList* slist = (TLinkList*) list;
    LinkListNode* ret = NULL;
    int cnt = pos;

    if(slist!= NULL && pos>=0 && pos<slist->length)
    {
        LinkListNode* slider = (LinkListNode*)slist;

        while(cnt--)
        {
            slider = slider->next;
        }

        ret = slider->next;
    }

    return ret;
}


//删除某一位元素
LinkListNode* LinkList_Delete(LinkList* list, int pos)
{
    TLinkList* slist = (TLinkList*) list;
    LinkListNode* ret = NULL;
    int cnt = pos;

    if(slist!= NULL && pos>=0 && pos<slist->length)
    {
        LinkListNode* slider = (LinkListNode*)slist;

        while(cnt--)
        {
            slider = slider->next;
        }

        ret = slider->next;
        slider->next = ret->next;   

        slist->length -= 1; 
    }    
    
    return ret;
}   

