#ifndef _LINK_STACK_H_
#define _LINK_STACK_H_
#include "../includes.h"

typedef void  LinkStack;


LinkStack* LinkStack_Create();
void LinkStack_Destroy(LinkStack* stack);
void LinkStack_Clear(LinkStack* stack);
int LinkStack_Push(LinkStack* stack, void* item);
LinkStack* LinkStack_Pop(LinkStack* stack);
LinkStack* LinkStack_Top(LinkStack* stack);
int LinkStack_Length(LinkStack* stack);







#endif
