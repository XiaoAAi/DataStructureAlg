#ifndef  _SEQLIST_H_
#define  _SEQLIST_H_
#include "../includes.h"

typedef void  SeqList;
typedef void  SeqListNode;


SeqList* SeqList_Create();
void SeqList_Destroy(SeqList* list);
void SeqList_Clear(SeqList* list);
BOOL SeqList_Insert(SeqList* list, SeqListNode* node, int pos);
SeqListNode* SeqList_Pop(SeqList* list, int pos);
SeqListNode* SeqList_Get(SeqList* list, int pos);
int SeqList_Length(SeqList* list);
int SeqList_Capacity(SeqList* list);











#endif
