/**
 * 说明：修改Insert插入链表的方式，使得整个链表首尾相连
*/
#include "CircleList.h"

typedef struct value
{
    CircleListNode header;
    int val;
} CicleListVal;



int main(void)
{
    int nlen = 0, index = 0;
    CicleListVal a, b, c, d, e, f, g;
    CicleListVal* reVal = NULL;
    CircleList* list = CircleList_Create();
    nlen = CircleList_Length(list);
    printf("len1:%d\n", nlen);

    a.val = 1, b.val = 2, c.val = 3, d.val = 4, e.val = 5, g.val = 11, f.val = 12;
    CircleList_Insert(list, (CircleListNode*)&a, 0);
    CircleList_Insert(list, (CircleListNode*)&b, 0);
    CircleList_Insert(list, (CircleListNode*)&c, 0);
    CircleList_Insert(list, (CircleListNode*)&d, 0);
    CircleList_Insert(list, (CircleListNode*)&e, 0);
    CircleList_Insert(list, (CircleListNode*)&f, CircleList_Length(list));
    CircleList_Insert(list, (CircleListNode*)&g, CircleList_Length(list));

    nlen = CircleList_Length(list);
    printf("len2:%d\n", nlen);   

    for(index=0; index<2*nlen+1; index++)
    {
        reVal = (CicleListVal*)CircleList_Get(list, index);
        printf("%d\t", reVal->val);
    }
    printf("\n");

    // reVal = (CicleListVal*)CircleList_Delete(list, 2*nlen+1);
    // printf("deleteVal:%d\n", reVal->val);

    reVal = (CicleListVal*)CircleList_Delete(list, nlen-1);
    printf("deleteVal:%d\n", reVal->val);

    reVal = (CicleListVal*)CircleList_Delete(list, 0);
    printf("deleteVal:%d\n", reVal->val);

    nlen = CircleList_Length(list);
    printf("len2:%d\n", nlen); 

    for(index=0; index<2*nlen+1; index++)
    {
        reVal = (CicleListVal*)CircleList_Get(list, index);
        printf("%d\t", reVal->val);
    }
    printf("\n");

    reVal = (CicleListVal*)CircleList_DeleteNode(list, (CircleListNode*)&c);
    printf("deleteNodeVal:%d\n", reVal->val);

    nlen = CircleList_Length(list);
    printf("len2:%d\n", nlen); 

    CircleList_Reset(list);
    while(nlen--)
    {
        reVal = (CicleListVal*)CircleList_Current(list);
        printf("%d\t", reVal->val);
        CircleList_Next(list);
    }
    printf("\n");

    reVal = (CicleListVal*)CircleList_Reset(list);
    printf("reVal:%d\n", reVal->val);

    CircleList_Destory(list);
}
