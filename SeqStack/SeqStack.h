#ifndef  _SEQSTACK_H_
#define  _SEQSTACK_H_
#include "../includes.h"

typedef void  SeqStack;


SeqStack* SeqStack_Create(int capacity);
void SeqStack_Destroy(SeqStack* stack);
void SeqStack_Clear(SeqStack* stack);
int SeqStack_Push(SeqStack* stack, void* item);
SeqStack* SeqStack_Pop(SeqStack* stack);
SeqStack* SeqStack_Top(SeqStack* stack);
int SeqStack_Length(SeqStack* stack);
int SeqStack_Capacity(SeqStack* stack);











#endif
