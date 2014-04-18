/******************
 *C版本的swap模板
 *只能处理要交焕的数据类型一致的情况
 *
 * ***************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>//memcpy的头文件

void swap(void *vp1, void *vp2, int size)
{
    char buffer[size];
    memcpy(buffer, vp1, size);
    memcpy(vp1, vp2, size);
    memcpy(vp2, buffer, size);
}

int main()
{
    int a = 4, b = 6;
    swap(&a, &b, sizeof(int));
    printf("%d  %d\n", a, b);
    double c = 3.0, d = 4.0;
    swap(&c, &d, sizeof(double));
    printf("%f  %f\n", c, d);
    return 0;
}
