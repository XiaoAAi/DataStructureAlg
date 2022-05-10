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
    LinkList* list = LinkList_Create();
    printf("Create LinkList Success\n");

    v1.data = 1;v2.data = 2; v3.data = 3; v4.data = 4; v5.data = 5;
    LinkList_Insert(list, (LinkListNode*)&v1, 0);
    LinkList_Insert(list, (LinkListNode*)&v2, 0);
    LinkList_Insert(list, (LinkListNode*)&v3, 0);
    LinkList_Insert(list, (LinkListNode*)&v4, 0);
    LinkList_Insert(list, (LinkListNode*)&v5, 0);

    printf("LinkList_Length:%d\n", LinkList_GetLength(list));


    LinkList_Destroy(list);
}

