#ifndef __COMMON_H_
#define __COMMON_H_

//避免重复包含头文件
#if 0
#define  ELEMENTTYPE void*
#else

typedef void * ELEMENTTYPE;

#endif


typedef struct dynamicArray
{
    ELEMENTTYPE *data;         //数组的空间
    int len;            //数组的大小
    int capacity;       //数组的容量
}dynamicArray;

#endif