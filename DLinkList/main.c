#include "DLinkList.h"
#include "../includes.h"


typedef struct _tag_DLinkListData
{
    DLinkListNode header;
    int data;
}TDListData;




int main(void)
{
    int i = 0;
    TDListData v1, v2, v3, v4, v5;
    TDListData v6, v7, v8, v9, v0;
    DLinkList* list = DLinkList_Create();
    TDListData* getVal;
    TDListData* getDel;
    int len = 0;
    printf("Create DLinkList Success\n");

    v1.data = 1;v2.data = 2; v3.data = 3; v4.data = 4; v5.data = 5;
    DLinkList_Insert(list, (DLinkListNode*)&v1, 0);
    DLinkList_Insert(list, (DLinkListNode*)&v2, 0);
    DLinkList_Insert(list, (DLinkListNode*)&v3, 0);
    DLinkList_Insert(list, (DLinkListNode*)&v4, 0);
    DLinkList_Insert(list, (DLinkListNode*)&v5, 0);

    v6.data = 6;v7.data = 7; v8.data = 8; v9.data = 9; v0.data = 10;
    DLinkList_Insert(list, (DLinkListNode*)&v6, DLinkList_GetLength(list));
    DLinkList_Insert(list, (DLinkListNode*)&v7, DLinkList_GetLength(list));
    DLinkList_Insert(list, (DLinkListNode*)&v8, DLinkList_GetLength(list));
    DLinkList_Insert(list, (DLinkListNode*)&v9, DLinkList_GetLength(list));
    DLinkList_Insert(list, (DLinkListNode*)&v0, DLinkList_GetLength(list));

    len = DLinkList_GetLength(list);
    printf("DLinkList_Length:%d\n", len);

    for(i=0; i<len; i++)
    {
        getVal = (TDListData*)DLinkList_Get(list, i);
        printf("Val:%d\n", getVal->data);
    }

    //验证删除pos 3
    getDel = (TDListData*)DLinkList_Delete(list, 3);
    printf("DeleteVal:%d\n", getDel->data);

    //验证删除pos 0
    getDel = (TDListData*)DLinkList_Delete(list, 0);
    printf("DeleteVal:%d\n", getDel->data);

    //验证删除V9
    getDel = (TDListData*)DLinkList_DeleteNode(list, (DLinkListNode*)&v9);
    printf("DeleteNodeVal:%d\n", getDel->data);

    len = DLinkList_GetLength(list);
    printf("DLinkList_Length:%d\n", len);

    //获取slider指针位置
    getVal = (TDListData*)DLinkList_Reset(list);
    printf("DeleteNodeVal:%d\n", getVal->data);

    //slider next查找
    while(len --)
    {
        getVal = (TDListData*)DLinkList_Next(list);
        printf("%d\t", getVal->data);
    }
    printf("\n");

    //slider pre查找
    len = DLinkList_GetLength(list);
    while(len --)
    {
        getVal = (TDListData*)DLinklist_Pre(list);
        printf("%d\t", getVal->data);
    }
    printf("\n");

    //Get current slider
    getVal = (TDListData*)DLinkList_Current(list);
    printf("DeleteNodeVal:%d\n", getVal->data);

    // for(i=0; i<len; i++)
    // {
    //     getVal = (TDListData*)DLinkList_Get(list, i);
    //     printf("DVal:%d\n", getVal->data);
    // }    

    DLinkList_Destroy(list);
}

