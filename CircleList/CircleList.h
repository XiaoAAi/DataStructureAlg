#ifndef _CIRCLE_LIST_H_
#define _CIRCLE_LIST_H_

#include "../includes.h"

typedef void CircleList;
typedef struct _tag_CircleListNode CircleListNode;
struct _tag_CircleListNode
{
    CircleListNode* next;   
};


CircleList* CircleList_Create();

void CircleList_Destory(CircleList* list);

void CircleList_Clear(CircleList* list);

int CircleList_Length(CircleList* list);

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





#endif
