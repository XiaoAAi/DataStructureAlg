#include "CircleList.h"



int main(void)
{
    int nlen = 0;

    CircleList* list = CircleList_Create();
    nlen = CircleList_Length(list);
    printf("len:%d\n", nlen);




    CircleList_Destory(list);
}
