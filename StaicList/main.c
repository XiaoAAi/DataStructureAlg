#include "StaticList.h"


int main()
{
    StaticList* list = StaticList_Create(10);
    int index = 0;
    int a=1,b=2,c=3,d=4,e=5,f=6;
    int len = 0;
    int* delPtr = NULL;
    int state = -1;

    len = StaticList_Length(list);
    printf("Capacity:%d, Len:%d\n", StaticList_Capacity(list), len);

    if(FALSE == StaticList_Insert(list, &f, 0))
        printf("insert failed\n");
    if(FALSE == StaticList_Insert(list, &b, 0))
        printf("insert failed\n");
    if(FALSE == StaticList_Insert(list, &c, 0))
        printf("insert failed\n");
    if(FALSE == StaticList_Insert(list, &d, 0))
        printf("insert failed\n");
    if(FALSE == StaticList_Insert(list, &e, 0))
        printf("insert failed\n");
    if(FALSE == StaticList_Insert(list, &a, 0))
        printf("insert failed\n");

    len = StaticList_Length(list);
    printf("Len:%d\n", len);

    for(index=0; index<len; index++)
    {
        int* intPtr = (int*)StaticList_Get(list, index);

        printf("%d\t", *intPtr);
    }
    printf("\n");

    delPtr = (int*)StaticList_Delete(list, 3);

    len = StaticList_Length(list);
    printf("Len:%d\n", len);  

    for(index=0; index<len; index++)
    {
        int* intPtr = (int*)StaticList_Get(list, index);

        printf("%d\t", *intPtr);
    }
    printf("\n");

    StaticList_Destroy(list);


    return 0;
}