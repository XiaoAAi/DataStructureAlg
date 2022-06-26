#ifndef _LINK_LIST_H_
#define _LINK_LIST_H_
#include "../includes.h"

typedef void LinkList;
typedef struct _tag_LinkListNode LinkListNode;
struct _tag_LinkListNode
{
    LinkListNode* next;
};


LinkList* LinkList_Create();//创建
void LinkList_Destroy(LinkList* list);  //销毁
void LinkList_Clear(LinkList* list);    //清空
int LinkList_GetLength(LinkList* list);     //获取长度
int LinkList_Insert(LinkList* list, LinkListNode* node, int pos);   //插入元素
LinkListNode* LinkList_Get(LinkList* list, int pos);    //获取某一位元素
LinkListNode* LinkList_Delete(LinkList* list, int pos);     //删除某一位元素





#endif
