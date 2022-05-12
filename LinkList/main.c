#include "LinkList.h"
#include "../includes.h"


typedef struct _tag_LinkListData
{
    LinkListNode header;
    int data;
}TListData;




int main(void)
{
    int i = 0;
    TListData v1, v2, v3, v4, v5;
    TListData v6, v7, v8, v9, v0;
    LinkList* list = LinkList_Create();
    TListData* getVal;
    TListData* getDel;
    int len = 0;
    printf("Create LinkList Success\n");

    v1.data = 1;v2.data = 2; v3.data = 3; v4.data = 4; v5.data = 5;
    LinkList_Insert(list, (LinkListNode*)&v1, 0);
    LinkList_Insert(list, (LinkListNode*)&v2, 0);
    LinkList_Insert(list, (LinkListNode*)&v3, 0);
    LinkList_Insert(list, (LinkListNode*)&v4, 0);
    LinkList_Insert(list, (LinkListNode*)&v5, 0);

    v6.data = 6;v7.data = 7; v8.data = 8; v9.data = 9; v0.data = 10;
    LinkList_Insert(list, (LinkListNode*)&v6, LinkList_GetLength(list));
    LinkList_Insert(list, (LinkListNode*)&v7, LinkList_GetLength(list));
    LinkList_Insert(list, (LinkListNode*)&v8, LinkList_GetLength(list));
    LinkList_Insert(list, (LinkListNode*)&v9, LinkList_GetLength(list));
    LinkList_Insert(list, (LinkListNode*)&v0, LinkList_GetLength(list));

    len = LinkList_GetLength(list);
    printf("LinkList_Length:%d\n", len);

    for(i=0; i<len; i++)
    {
        getVal = (TListData*)LinkList_Get(list, i);
        printf("Val:%d\n", getVal->data);
    }

    getDel = (TListData*)LinkList_Delete(list, 3);
    printf("DeleteVal:%d\n", getDel->data);

    len = LinkList_GetLength(list);
    printf("LinkList_Length:%d\n", len);

    for(i=0; i<len; i++)
    {
        getVal = (TListData*)LinkList_Get(list, i);
        printf("Val:%d\n", getVal->data);
    }    

    LinkList_Destroy(list);
}

