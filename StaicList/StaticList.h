#ifndef _STATIC_LIST_H_
#define _STATIC_LIST_H_

#include "../includes.h"

typedef void StaticList;
typedef void StaticListNode;

//创建
StaticList* StaticList_Create(int capacity);
//销毁
void StaticList_Destroy(StaticList* list);
//清理
void StaticList_Clear(StaticList* list);
//返回长度
int StaticList_Length(StaticList* list);
//返回最大存储量
int StaticList_Capacity(StaticList* list);
//插入元素
int StaticList_Insert(StaticList* list, StaticListNode* node, int pos);
//获取某一位置的元素
StaticListNode* StaticList_Get(StaticList* list, int pos);
//删除某一位置的元素
StaticListNode* StaticList_Delete(StaticList* list, int pos);




#endif
