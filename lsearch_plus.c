/*****************
 *lsearch的升级
 *
 *
 *
 * ***************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//比较int类型的cmp实现
int intcmp(void *elem1, void *elem2)
{
    int *ip1 = elem1;
    int *ip2 = elem2;
    return *ip1 - * ip2;
}

void *lsearch(void *key,/*要查找的元素*/
        void *base,/*查找范围基址*/
        int n,/*元素个数*/
        int elemSize,/*每个元素大小*/
        int (*cmp)(void*, void*)/*比较函数*/)
{
    for(int i = 0; i < n; i ++)
    {
        void *elemAddr = (char*)base + i * elemSize;/*char* 是吧base转换为char*类型，这样编译器在处理+ i * elemSize时加的是i*elemSize个sizeof(char)*/
        if(cmp(key, elemAddr) == 0)
            return elemAddr;
    }
    return NULL;
}

int main()
{
    int array[3] = { 1, 2, 3};
    int key = 2;
    int *res = lsearch(&key, array, 3, sizeof(int), intcmp);
    if(res)
        printf("%d \n", *res);
    return 0;
}
