#ifndef _DLINK_LIST_H_
#define _DLINK_LIST_H_
#include "../includes.h"

typedef void DLinkList;
typedef struct _tag_DLinkListNode DLinkListNode;
struct _tag_DLinkListNode
{
    DLinkListNode* next;
    DLinkListNode* pre;
};


DLinkList* DLinkList_Create();//创建
void DLinkList_Destroy(DLinkList* list);  //销毁
void DLinkList_Clear(DLinkList* list);    //清空
int DLinkList_GetLength(DLinkList* list);     //获取长度
int DLinkList_Insert(DLinkList* list, DLinkListNode* node, int pos);   //插入元素
DLinkListNode* DLinkList_Get(DLinkList* list, int pos);    //获取某一位元素
DLinkListNode* DLinkList_Delete(DLinkList* list, int pos);     //删除某一位元素

DLinkListNode* DLinkList_DeleteNode(DLinkListNode* list, DLinkListNode* node);
DLinkListNode* DLinkList_Reset(DLinkList* list);
DLinkListNode* DLinkList_Current(DLinkList* list);
DLinkListNode* DLinkList_Next(DLinkList* list);
DLinkListNode* DLinklist_Pre(DLinkList* list);




#endif
