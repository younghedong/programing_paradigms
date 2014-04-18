/*****************
 *线性搜索
 *返回第一个满足条件的元素的地址
 *
 *
 * ***************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *lsearch(void *key,/*要查找的元素*/
        void *base,/*查找范围基址*/
        int n,/*元素个数*/
        int elemSize/*每个元素大小*/)
{
    for(int i = 0; i < n; i ++)
    {
        void *elemAddr = (char*)base + i * elemSize;/*char* 是吧base转换为char*类型，这样编译器在处理+ i * elemSize时加的是i*elemSize个sizeof(char)*/
        if(memcmp(key, elemAddr, elemSize) == 0)
            return elemAddr;
    }
    return NULL;
}

int main()
{
    int array[3] = { 1, 2, 3};
    int key = 2;
    int *res = lsearch(&key, array, 3, sizeof(int));
    printf("%d \n", *res);
    return 0;
}
